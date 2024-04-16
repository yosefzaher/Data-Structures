/**
************************************************************
**@author :  ENG.Yoesf Zaher
**@breif  :  Data Types independent in any platform
**@File   :  DataType.h
************************************************************
**/

#ifndef _DATATYPE_H_ //File_Guard_PLATFORM_TYPE_H_
#define _DATATYPE_H_

#define CPU_TYPE_8BIT 8
#define CPU_TYPE_16BIT 16
#define CPU_TYPE_32BIT 32
#define CPU_TYPE_64BIT 64


/********************************************/
#define CPU_TYPE (CPU_TYPE_32BIT)
/********************************************/
#if (CPU_TYPE == CPU_TYPE_8BIT)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned int uint16;
typedef signed int int16;
typedef unsigned long uint32;
typedef signed long int32;
typedef unsigned long long uint64;
typedef signed long long int64;
typedef float float16;
typedef double float32;
typedef long double float64;
#elif (CPU_TYPE == CPU_TYPE_16BIT)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned long uint64;
typedef signed long int64;
typedef float float32;
typedef double float64;
typedef long double float96;
#elif (CPU_TYPE == CPU_TYPE_32BIT)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned long uint64;
typedef signed long int64;
typedef float float32;
typedef double float64;
typedef long double float96;
#elif (CPU_TYPE == CPU_TYPE_64BIT)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned int uint16;
typedef signed int int16;
typedef unsigned long uint32;
typedef signed long int32;
typedef unsigned long long uint64;
typedef signed long long int64;
typedef float float16;
typedef double float32;
typedef long double float64;
#endif

#endif // _PLATFORM_TYPE_H


/**
******************************************************************
* @author                @breif                       @date
* ENG.Yosef Zaher        I make this file             20Marsh2024
*******************************************************************
**/



