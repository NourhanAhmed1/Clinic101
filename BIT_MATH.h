//library for operations on a single bit 
//1-set bit
//2-clear bit
//3-toggle bit
//4-get bit 
#ifndef BIT_MATH
#define	BIT_MATH
//1-set bit
//function set bit takes args reg that has the number to set the bit at and the bit number  
#define		SET_BIT(	REG	,	BIT_NUM) 	(REG |= (	1<<BIT_NUM	)	) //(Reg = REG | ((	1<<BIT_NUM	) ))


//2-clear bit
#define		CLR_BIT(	REG	,	BIT_NUM) 	(REG &= ~(	1<<BIT_NUM	)	) //(Reg = REG & (~(	1<<BIT_NUM	) ))


//3-toggle bit
#define		TGL_BIT(	REG	,	BIT_NUM) 	(REG ^= (	1<<BIT_NUM	)	) //(Reg = REG ^ ((	1<<BIT_NUM	) ))


//4-get bit
#define		GET_BIT(	REG	,	BIT_NUM) 	(  (	REG>>BIT_NUM	)&	1	) //(Reg = REG 1 & ((	REG>>BIT_NUM	) ))
#endif