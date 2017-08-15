/****************************************************************************
*文件说明：系统相关信息的头文件
*版    本：V1.0
*时    间：2016年12月06日
*****************************************************************************
*/
#ifndef  __XE_GLOBAL_VARIABLE_H__
#define  __XE_GLOBAL_VARIABLE_H__

#include "pub_type.h"
#include "DB_Unity.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define MAX_BUFF_LEN     (1032)
#define START_CODE       (0x68)
#define CARD_NUM_LEN     (6) //BCD卡号长度
#define CARD_KEY_LEN     (8) //卡号纯数字秘钥BCD码长度
#define USER_ACCOUNT_LEN (6) //用户账号BCD码长度
#define USER_TEL_LEN     (6) //用户手机号BCD长度
#define SERIAL_NUM_LEN   (12)//流水号长度
#define ORDER_NUM_LEN    (12)//预约订单号长度
#define PILE_NUM_LEN     (12)//桩号的长度
#define PILE_BCD_LEN     (6) //桩号的BCD码长度
#define MIN_NEEDED_LEN   (4) //确定消息长度最少需要的字节数
#define MSG_HEADER_LEN   (4) //消息头长度
#define NON_DATA_LEN     (5) //消息中非数据部分的长度
#define LOGIN_MSG_LEN    (11)//登录注册的回复消息的长度
#define TIME_BCD_LEN     (6) //时间BCD码长度

#pragma  pack(push)
#pragma  pack(1)

typedef enum cmd_e
{
    //单向: 设备->服务器
    CMD_LOGIN = 0X01,         //注册
    CMD_HEART_BEAT = 0x02,    //心跳
    CMD_CHARGE_RECORD = 0x03, //充电记录上报
    CMD_REPORT_CARD = 0x0A,   //刷卡卡号上报

    //单向: 服务器->设备
    CMD_ORDER_PILE = 0x04,   //充电桩预约
    CMD_CANCEL_ORDER = 0x05, //取消预约
    CMD_START_CHARGE = 0x06, //充电桩开启放电
    CMD_STOP_CHARGE = 0x07,  //充电桩停止充电
    CMD_TIME_SYNC = 0x08,    //充电桩校时
    CMD_CHARGE_PRICE = 0x09, //电价下发
    CMD_SHUT_DOWN = 0x0B,    //远程关闭电桩
    CMD_GUN_CONN_CHECK = 0x0C, //电枪连接检查
    CMD_OFFLINE_CHARGE = 0x1B, //线下充电上报选择模式
} cmd_e;

typedef struct msg_buf_s
{
    UINT8 buff[MAX_BUFF_LEN]; //接收数据的缓冲区
    UINT32 buff_len;          //buff的总长度
    UINT32 data_len;          //实际的数据长度
} msg_buf_s;

typedef struct xe_pile_info_s
{
    UINT8 pile_type; //桩类型
    UINT8 pile_num[PILE_NUM_LEN]; //桩号
    UINT8 pile_bcd[PILE_BCD_LEN]; //桩号的BCD码
} xe_pile_info_s;

typedef struct xe_client_s
{
    UINT8 server_ip[20];  //服务器IP
    UINT16 port;       //服务器端口号
    UINT32 ser_change; //服务器的地址是否改变

    UINT32 dev_state;  //设备连接状态,online/offline
    UINT8 pile_state;  //桩状态,空闲中/充电中等

    xe_pile_info_s pile_info; //桩信息
    
    UINT32 b_run;      //线程运行标志
    pthread_t pdt_thread_client; //线程ID
    int socket_client; //连接句柄

    msg_buf_s recv_buf; //接收缓冲区
    msg_buf_s send_buf; //发送缓冲区

    UINT8 gun_port;     //枪端口号

    UINT8 order_num[ORDER_NUM_LEN]; //预约订单号
    UINT8 order_start_time_bcd[TIME_BCD_LEN];//预约起始时间BCD码
    UINT8 order_stop_time_bcd[TIME_BCD_LEN]; //预约结束时间BCD码
    
    UINT8 serial_num[SERIAL_NUM_LEN];     //流水号
    UINT8 card_num[CARD_NUM_LEN];         //卡号BCD码
    UINT8 card_key[CARD_KEY_LEN];         //纯数字卡秘钥的BCD码
    UINT8 user_account[USER_ACCOUNT_LEN]; //用户账号
    UINT8 user_tel_num[USER_TEL_LEN];     //用户手机号BCD码

    UINT32 send_login_flag; //发送充电桩注册消息的标识
    UINT32 recv_login_flag; //接收到注册回复消息的标识
    UINT32 last_send_login; //上次发送login请求的时间
    UINT32 recv_heart_beat; //上次接收心跳的时间
    UINT32 last_deal_record;//上次交易记录时间
} xe_client_s;

typedef enum pile_state_e
{
    PILE_IDLE            = 0x00, //空闲中
    PILE_BOOKED          = 0x01, //预约中
    PILE_START_TO_CHAGRE = 0x02, //开始放电
    PILE_CHARGING        = 0x03, //充电中
    PILE_OVER_VOLT       = 0x04, //过压
    PILE_UNDER_VOLT      = 0x05, //欠压
    PILE_OVER_CURRENT    = 0x06, //过流
    PILE_STOP_EMERGENT   = 0x07, //急停
    PILE_CHARGE_COMPLETE = 0x08, //充电完成
    PILE_CONN_FAULT      = 0x09, //充电连接异常
    PILE_FAULT           = 0x0A, //充电机故障
    PILE_BMS_FAULT       = 0x0B, //BMS通信故障, 交流不涉及
    PILE_BMS_CONNECTED   = 0x0C, //BMS已连接, 交流不涉及
} pile_state_e;

typedef enum dev_online_e
{
    DEV_CLOSE = 0,
    DEV_OFFLINE, //不在线
    DEV_ONLINE,  //在线
} dev_online_e;

#pragma  pack(pop)

#endif

