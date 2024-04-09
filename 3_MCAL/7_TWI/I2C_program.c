/*
 * I2C_program.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Administrator
 */
#include"STD_Types.h"
#include"BIT_CALC.h"
#include"DIO_interface.h"
#include"I2C_config.h"
#include"I2C_interface.h"
#include"I2C_private.h"

void I2C_void_Init_Master(void)
{
	// SCL Freq = ( F_CPU ) / ( 16 + 2 * TWBR * (4 ^ TWSR) )
	//          = ( 8 * 10 ^ 6 ) / ( 16 + 2 * 192 * (4 ^ 0) )
	//          = 20000 Hz = 20 KHz

	// prescaler=1
	I2C_U8_TWSR=0;
	Set_Bit(I2C_U8_TWBR,7);			// Bit Rate Register
	Set_Bit(I2C_U8_TWBR,6);
}
u8 I2C_U8_start(u8 slave_address)
{
	u8 status ;
	Set_Bit(I2C_U8_TWCR,7);						//  Clear TWI Interrupt flag
	Set_Bit(I2C_U8_TWCR,5);					    // Generate start condition
	Set_Bit(I2C_U8_TWCR,2);						// Enable TWI

	while(Get_Bit(I2C_U8_TWCR,7)==0);   		// Wait until TWI finish its current job
	status = I2C_U8_TWSR & 0b11111000;			// Read TWI status register - The 5 MSB
	 if(status != 0x08)							// Check START condition transmitted or not ?!
	    return 0;							    // Return 0 to indicate start condition fail

		I2C_U8_TWDR = slave_address ;			// Write SLA+W in TWI data register

		Set_Bit(I2C_U8_TWCR,7);   				// Clear TWI Interrupt flag
		Set_Bit(I2C_U8_TWCR,2);
		Clear_Bit(I2C_U8_TWCR,5);

	while(Get_Bit(I2C_U8_TWCR,7)==0);   		// Wait until TWI finish its current job
	status = I2C_U8_TWSR & 0b11111000;			// Read TWI status register - The 5 MSB
		if(status == 0x18)						// Check for SLA+W transmitted & ACK received
			return 1;							// Return 1 to indicate ACK received
			if(status == 0x20)					// Check for SLA+W transmitted & NACK received
			return 2;							// Return 2 to indicate NACK received
			else
			return 3;							// // loser atrbituation-->Else return 3 to indicate SLA+W failed

}
u8 I2C_U8_repeated_start(u8 slave_address)
{
		u8 status ;
		Set_Bit(I2C_U8_TWCR,7);						//  Clear TWI Interrupt flag
		Set_Bit(I2C_U8_TWCR,5);					    // Generate start condition
		Set_Bit(I2C_U8_TWCR,2);						// Enable TWI

		while(Get_Bit(I2C_U8_TWCR,7)==0);   		// Wait until TWI finish its current job
		status = I2C_U8_TWSR & 0b11111000;			// Read TWI status register - The 5 MSB
		 if(status != 0x10)							// Check for repeated start transmitted or not ?!
		    return 0;							    // Return 0 for repeated start condition fail

		 I2C_U8_TWDR = slave_address ;			// Write SLA+R in TWI data register

			Set_Bit(I2C_U8_TWCR,7);   				// Clear TWI Interrupt flag
		    Set_Bit(I2C_U8_TWCR,2);
		    Clear_Bit(I2C_U8_TWCR,5);

		while(Get_Bit(I2C_U8_TWCR,7)==0);   		// Wait until TWI finish its current job
		status = I2C_U8_TWSR & 0b11111000;			// Read TWI status register - The 5 MSB

		if(status == 0x40)						// Check for SLA+R transmitted & ACK received
				return 1;							// Return 1 to indicate ACK received
		if(status == 0x48)						// Check for SLA+R transmitted & NACK received
				return 2;							// Return 2 to indicate NACK received
		else
				return 3;							// Else return 3 to indicate SLA+W failed
}

u8 I2C_U8_Master_Transmit(u8 data)
{
	 u8 status;
	 I2C_U8_TWDR= data ;							// Copy data in TWI data register

	 Set_Bit(I2C_U8_TWCR,7);   						// Clear TWI Interrupt flag
	 Set_Bit(I2C_U8_TWCR,2);
	 Clear_Bit(I2C_U8_TWCR,5);

	 while(Get_Bit(I2C_U8_TWCR,7)==0);   			// Wait until TWI finish its current job
	status = I2C_U8_TWSR & 0b11111000;				// Read TWI status register - The 5 MSB

	if(status == 0x28)								// Check for data transmitted & ACK received
			return 0;								// Return 0 to indicate ACK received
	if(status == 0x30)								// Check for data transmitted & NACK received
		    return 1;								// Return 1 to indicate NACK received
	else
	        return 2;

}
u8 I2C_Master_Receive_Ack(void)
{
	Set_Bit(I2C_U8_TWCR,7);   						// Clear TWI Interrupt flag
	Set_Bit(I2C_U8_TWCR,2);
    Clear_Bit(I2C_U8_TWCR,5);
    Set_Bit(I2C_U8_TWCR,6); 						// Enable ACK

    while(Get_Bit(I2C_U8_TWCR,7) == 0);		// Wait until TWI finish its current job
    return I2C_U8_TWDR;						// Return received data
}
u8 I2C_Master_Receive_Nack(void)
{
	Set_Bit(I2C_U8_TWCR,7);   				// Clear TWI Interrupt flag
	Set_Bit(I2C_U8_TWCR,2);
    Clear_Bit(I2C_U8_TWCR,5);

    while(Get_Bit(I2C_U8_TWCR,7) == 0);		// Wait until TWI finish its current job
    return I2C_U8_TWDR;						// Return received data
}

void I2C_Stop(void)
{
	Set_Bit(I2C_U8_TWCR,7);   				// Clear TWI Interrupt flag
	Set_Bit(I2C_U8_TWCR,2);					// Enable TWI
	Set_Bit(I2C_U8_TWCR,4);					//// Generate stop condition

	while(Get_Bit(I2C_U8_TWCR,4) == 1);		// Wait until stop condition execution

}
/**************************/
void I2C_Slave_Init(u8 slave_address)
{
	I2C_U8_TWAR = slave_address ;

	Set_Bit(I2C_U8_TWCR,7);   						// Clear TWI Interrupt flag
	Set_Bit(I2C_U8_TWCR,2);							// Enable TWI
    Set_Bit(I2C_U8_TWCR,6); 						// Enable ACK

}

u8 I2C_Slave_Listen(void)
{
	 while(1)
	    {
	    	u8 status;
	    	 while(Get_Bit(I2C_U8_TWCR,7)==0);  			// Wait to be addressed
	    	status = I2C_U8_TWSR & 0b11111000;				// Read TWI status register - The 5 MSB
			if(status == 0x60 || status == 0x68)			// Own SLA+W received & ACK returned
				return 0;									// Return 0 to indicate ACK returned
			if(status == 0xA8 || status == 0xB0)			// Own SLA+R received & ACK returned
				return 1;									// Return 1 to indicate ACK returned
			if(status == 0x70 || status == 0x78)			// General call received & ACK returned
				return 2;									// Return 2 to indicate ACK returned
	    	else
	    		continue;
	     }
}

s8 I2C_Slave_Transmit(u8 data)
{

	u8 status;
		 I2C_U8_TWDR= data ;							// Copy data in TWI data register

		 Set_Bit(I2C_U8_TWCR,7);   						// Clear TWI Interrupt flag
		 Set_Bit(I2C_U8_TWCR,2);						// Enable TWI
		 Clear_Bit(I2C_U8_TWCR,5);

		 while(Get_Bit(I2C_U8_TWCR,7)==0);   			// Wait until TWI finish its current job
		status = I2C_U8_TWSR & 0b11111000;				// Read TWI status register - The 5 MSB

		   if(status == 0xA0)							// Check for STOP / REPEATED START received
		    {
		    	Set_Bit(I2C_U8_TWCR,7);					// Clear interrupt flag & return -1
		    	return -1;
		    }
		   if(status == 0xB8)							// Check for data transmitted & ACK received
		      return 0;									// If yes then return 0
		      if(status == 0xC0)						// Check for data transmitted & NACK received
		      {
		      	Set_Bit(I2C_U8_TWCR,7);						// Clear interrupt flag & return -2
		      	return -2;
		      }
		      if(status == 0xC8)						// Last byte transmitted with ACK received
		      return -3;								// If yes then return -3
		      else										// else return -4
		      return -4;
}


s8 I2C_Slave_Receive(void)
{
	 u8 status;
	 Set_Bit(I2C_U8_TWCR,7);   						// Clear TWI Interrupt flag
   	 Set_Bit(I2C_U8_TWCR,2);
	 Clear_Bit(I2C_U8_TWCR,5);
	 Set_Bit(I2C_U8_TWCR,6); 						// Enable ACK

	 while(Get_Bit(I2C_U8_TWCR,7)==0);   			// Wait until TWI finish its current job
	status = I2C_U8_TWSR & 0b11111000;				// Read TWI status register - The 5 MSB

	 if(status == 0x80 || status == 0x90)	// Check for data received & ACK returned
	    return I2C_U8_TWDR;							// If yes then return received data

	    // Check for data received, NACK returned & switched to not addressed slave mode
	    if(status == 0x88 || status == 0x98)
	    return I2C_U8_TWDR;							// If yes then return received data
	    if(status == 0xA0)						// Check for STOP / REPEATED START received
	    {
	    	Set_Bit(I2C_U8_TWCR,7);					// Clear interrupt flag & return -1
	    	return -1;
	    }
	    else
	    return -2;								// Else return -2 }


}





