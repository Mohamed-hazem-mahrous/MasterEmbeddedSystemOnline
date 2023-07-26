/*
 * Platform_Types.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Mohamed
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef _Bool                       boolean;
typedef char                        char_t;
typedef signed char                 int8_t;
typedef unsigned char               uint8_t;
typedef signed short                int16_t;
typedef unsigned short              uint16_t;
typedef signed int                  int32_t;
typedef unsigned int                uint32_t;
typedef signed long long int        int64_t;
typedef unsigned long long int      uint64_t;

typedef volatile char                       vchar_t;
typedef volatile signed char                vint8_t;
typedef volatile unsigned char              vuint8_t;
typedef volatile signed short               vint16_t;
typedef volatile unsigned short             vuint16_t;
typedef volatile signed int                 vint32_t;
typedef volatile unsigned int               vuint32_t;
typedef volatile signed long long int       vint64_t;
typedef volatile unsigned long long int     vuint64_t;

typedef float       float32;
typedef double      float64;


#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif

#endif /* PLATFORM_TYPES_H_ */
