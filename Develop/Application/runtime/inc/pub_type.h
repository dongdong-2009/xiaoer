///////////////////////////////////////////////////////////////////////////
//
/// @file	 pub_type.h
/// @brief	 �����ṹ�嶨�� 
/// @author  
/// @version 0.1
/// @history �޸���ʷ
/// @warning û�о���
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
/// @brief ʱ������
typedef struct SK_TIME
{
    unsigned char       sec;        ///< ��
    unsigned char       min;        ///< ��
    unsigned char       hour;       ///< ʱ

    unsigned char       wday;       ///< ���ڼ�
    unsigned char       mday;       ///< ĳ��
    unsigned char       mon;        ///< ĳ��

    unsigned short      year;       ///< ĳ��

    int         msec;      		   ///< ����
}SK_TIME;

#pragma pack(pop)//

#endif // __PUB_TYPE_H__
//end
