/****************************************************************************
*文件说明：与海南小二网络科技有限公司充电通信接口协议相关的数据结构
*版    本：V1.0
*时    间：2016年12月06日
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
    RET_PARAM_ERROR, //参数错误
    RET_OUT_MEM,     //没有足够的内存
    RET_UNKNOWN      //未知错误
}xe_ret_e;

#pragma pack(pop)

UINT32 xe_init(xe_pile_info_s *pile_info);

void xe_quit();

UINT32 xe_start(const UINT8 *p_server, UINT16 server_port);

void xe_stop();

/*******************************************************************************
*函 数 名: xe_get_connect_state
*功  能: 获取桩在线状态
*入  参: 无
*返 回 值: 桩在线状态
*
*时  间:2016年12月07日
********************************************************************************
*/
int xe_get_connect_state();

#endif
