/****************************************************************************
*�ļ�˵�����뺣��С������Ƽ����޹�˾���ͨ�Žӿ�Э����ص����ݽṹ
*��    ����V1.0
*ʱ    �䣺2016��12��06��
*****************************************************************************
*/

#ifndef   __XIAO_ER_H__
#define   __XIAO_ER_H__

#include "xe_global_variable.h"
#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#pragma pack(push) 
#pragma pack(1)


typedef enum  xe_ret_e
{
    RET_OK = 0,      //ok
    RET_PARAM_ERROR, //��������
    RET_OUT_MEM,     //û���㹻���ڴ�
    RET_UNKNOWN      //δ֪����
}xe_ret_e;

#pragma pack(pop)

UINT32 xe_init(xe_pile_info_s *pile_info);

void xe_quit();

UINT32 xe_start(const UINT8 *p_server, UINT16 server_port);

void xe_stop();

/*******************************************************************************
*�� �� ��: xe_get_connect_state
*��  ��: ��ȡ׮����״̬
*��  ��: ��
*�� �� ֵ: ׮����״̬
*
*ʱ  ��:2016��12��07��
********************************************************************************
*/
int xe_get_connect_state();

#endif
