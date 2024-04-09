/*
 * I2C_private.h
 *
 *  Created on: Nov 11, 2023
 *      Author: Administrator
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

#define I2C_U8_TWAR 	 *((volatile u8*)0x22)
#define I2C_U8_TWBR 	 *((volatile u8*)0x20)
#define I2C_U8_TWCR 	 *((volatile u8*)0x56)
#define I2C_U8_TWDR 	 *((volatile u8*)0x23)
#define I2C_U8_TWSR 	 *((volatile u8*)0x21)

#endif /* I2C_PRIVATE_H_ */
