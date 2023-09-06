/*
 * BIT_MATH.h
 *
 *  Created on: Jul 22, 2023
 *      Author: shim
 */

#ifndef UTILS_BIT_MATH_H_
#define UTILS_BIT_MATH_H_


#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)



#endif /* UTILS_BIT_MATH_H_ */
