///////////////////////////////////////////////////////////////////////////
//
/// @file	 pub_type.h
/// @brief	 公共结构体定义 
/// @author  
/// @version 0.1
/// @history 修改历史
/// @warning 没有警告
///////////////////////////////////////////////////////////////////////////


#ifndef __PUB_TYPE_H__
#define __PUB_TYPE_H__

#include<stdio.h>

#ifdef __cplusplus		
#define SK_API extern "C"	
#else		
#define SK_API extern	
#endif

#pragma pack(push) //
#pragma pack(4)
  
/// @name  _SK_TIME_
/// @brief 时间描述
typedef struct SK_TIME
{
    unsigned char       sec;        ///< 秒
    unsigned char       min;        ///< 分
    unsigned char       hour;       ///< 时

    unsigned char       wday;       ///< 星期几
    unsigned char       mday;       ///< 某日
    unsigned char       mon;        ///< 某月

    unsigned short      year;       ///< 某年

    int         msec;      		   ///< 豪秒
}SK_TIME;

#pragma pack(pop)//

#endif // __PUB_TYPE_H__
//end
