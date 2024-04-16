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
typedef unsigned char boolean_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned int uint16_t;
typedef signed int int16_t;
typedef unsigned long uint32_t;
typedef signed long int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef float float16_t;
typedef double float32_t;
typedef long double float64_t;
#elif (CPU_TYPE == CPU_TYPE_16BIT)
typedef unsigned char boolean_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long uint64_t;
typedef signed long int64_t;
typedef float float32_t;
typedef double float64_t;
typedef long double float96_t;
#elif (CPU_TYPE == CPU_TYPE_32BIT)
typedef unsigned char boolean_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef signed short int16_t;
typedef unsigned int uint32_t;
typedef signed int int32_t;
typedef unsigned long uint64_t;
typedef signed long int64_t;
typedef float float32_t;
typedef double float64_t;
typedef long double float96_t;
#elif (CPU_TYPE == CPU_TYPE_64BIT)
typedef unsigned char boolean_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned int uint16_t;
typedef signed int int16_t;
typedef unsigned long uint32_t;
typedef signed long int32_t;
typedef unsigned long long uint64_t;
typedef signed long long int64_t;
typedef float float16_t;
typedef double float32_t;
typedef long double float64_t;
#endif

#endif // _PLATFORM_TYPE_H


/**
******************************************************************
* @author                @breif                       @date
* ENG.Yosef Zaher        I make this file             20Marsh2024
*******************************************************************
**/




