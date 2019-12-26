//this is our first library :'D 
//file gurd prevents the repetition of file excution
//to include in your c code write #include "STD_TYPES.h" 
#ifndef STD_TYPES	 //if STD_TYPES not defined 
#define STD_TYPES	 // define 
//char
typedef	unsigned	char	u8; // to use in code  write u8 x ; where x is unsigned char 
typedef	signed	char	s8;
//short int
typedef	unsigned	short	int	u16;
typedef	signed	short	int	s16;
//long int
typedef	unsigned	long	int	u32;
typedef	signed	long	int	s32;
//float & double
typedef float	f32;
typedef double	f64;
typedef long double f96;

typedef void(*pf)(void); //to use it use it in code write pf x = fun(); were x is pointer to function func 
#endif