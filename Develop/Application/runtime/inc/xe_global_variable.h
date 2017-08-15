/****************************************************************************
*�ļ�˵����ϵͳ�����Ϣ��ͷ�ļ�
*��    ����V1.0
*ʱ    �䣺2016��12��06��
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
#define CARD_NUM_LEN     (6) //BCD���ų���
#define CARD_KEY_LEN     (8) //���Ŵ�������ԿBCD�볤��
#define USER_ACCOUNT_LEN (6) //�û��˺�BCD�볤��
#define USER_TEL_LEN     (6) //�û��ֻ���BCD����
#define SERIAL_NUM_LEN   (12)//��ˮ�ų���
#define ORDER_NUM_LEN    (12)//ԤԼ�����ų���
#define PILE_NUM_LEN     (12)//׮�ŵĳ���
#define PILE_BCD_LEN     (6) //׮�ŵ�BCD�볤��
#define MIN_NEEDED_LEN   (4) //ȷ����Ϣ����������Ҫ���ֽ���
#define MSG_HEADER_LEN   (4) //��Ϣͷ����
#define NON_DATA_LEN     (5) //��Ϣ�з����ݲ��ֵĳ���
#define LOGIN_MSG_LEN    (11)//��¼ע��Ļظ���Ϣ�ĳ���
#define TIME_BCD_LEN     (6) //ʱ��BCD�볤��

#pragma  pack(push)
#pragma  pack(1)

typedef enum cmd_e
{
    //����: �豸->������
    CMD_LOGIN = 0X01,         //ע��
    CMD_HEART_BEAT = 0x02,    //����
    CMD_CHARGE_RECORD = 0x03, //����¼�ϱ�
    CMD_REPORT_CARD = 0x0A,   //ˢ�������ϱ�

    //����: ������->�豸
    CMD_ORDER_PILE = 0x04,   //���׮ԤԼ
    CMD_CANCEL_ORDER = 0x05, //ȡ��ԤԼ
    CMD_START_CHARGE = 0x06, //���׮�����ŵ�
    CMD_STOP_CHARGE = 0x07,  //���׮ֹͣ���
    CMD_TIME_SYNC = 0x08,    //���׮Уʱ
    CMD_CHARGE_PRICE = 0x09, //����·�
    CMD_SHUT_DOWN = 0x0B,    //Զ�̹رյ�׮
    CMD_GUN_CONN_CHECK = 0x0C, //��ǹ���Ӽ��
    CMD_OFFLINE_CHARGE = 0x1B, //���³���ϱ�ѡ��ģʽ
} cmd_e;

typedef struct msg_buf_s
{
    UINT8 buff[MAX_BUFF_LEN]; //�������ݵĻ�����
    UINT32 buff_len;          //buff���ܳ���
    UINT32 data_len;          //ʵ�ʵ����ݳ���
} msg_buf_s;

typedef struct xe_pile_info_s
{
    UINT8 pile_type; //׮����
    UINT8 pile_num[PILE_NUM_LEN]; //׮��
    UINT8 pile_bcd[PILE_BCD_LEN]; //׮�ŵ�BCD��
} xe_pile_info_s;

typedef struct xe_client_s
{
    UINT8 server_ip[20];  //������IP
    UINT16 port;       //�������˿ں�
    UINT32 ser_change; //�������ĵ�ַ�Ƿ�ı�

    UINT32 dev_state;  //�豸����״̬,online/offline
    UINT8 pile_state;  //׮״̬,������/����е�

    xe_pile_info_s pile_info; //׮��Ϣ
    
    UINT32 b_run;      //�߳����б�־
    pthread_t pdt_thread_client; //�߳�ID
    int socket_client; //���Ӿ��

    msg_buf_s recv_buf; //���ջ�����
    msg_buf_s send_buf; //���ͻ�����

    UINT8 gun_port;     //ǹ�˿ں�

    UINT8 order_num[ORDER_NUM_LEN]; //ԤԼ������
    UINT8 order_start_time_bcd[TIME_BCD_LEN];//ԤԼ��ʼʱ��BCD��
    UINT8 order_stop_time_bcd[TIME_BCD_LEN]; //ԤԼ����ʱ��BCD��
    
    UINT8 serial_num[SERIAL_NUM_LEN];     //��ˮ��
    UINT8 card_num[CARD_NUM_LEN];         //����BCD��
    UINT8 card_key[CARD_KEY_LEN];         //�����ֿ���Կ��BCD��
    UINT8 user_account[USER_ACCOUNT_LEN]; //�û��˺�
    UINT8 user_tel_num[USER_TEL_LEN];     //�û��ֻ���BCD��

    UINT32 send_login_flag; //���ͳ��׮ע����Ϣ�ı�ʶ
    UINT32 recv_login_flag; //���յ�ע��ظ���Ϣ�ı�ʶ
    UINT32 last_send_login; //�ϴη���login�����ʱ��
    UINT32 recv_heart_beat; //�ϴν���������ʱ��
    UINT32 last_deal_record;//�ϴν��׼�¼ʱ��
} xe_client_s;

typedef enum pile_state_e
{
    PILE_IDLE            = 0x00, //������
    PILE_BOOKED          = 0x01, //ԤԼ��
    PILE_START_TO_CHAGRE = 0x02, //��ʼ�ŵ�
    PILE_CHARGING        = 0x03, //�����
    PILE_OVER_VOLT       = 0x04, //��ѹ
    PILE_UNDER_VOLT      = 0x05, //Ƿѹ
    PILE_OVER_CURRENT    = 0x06, //����
    PILE_STOP_EMERGENT   = 0x07, //��ͣ
    PILE_CHARGE_COMPLETE = 0x08, //������
    PILE_CONN_FAULT      = 0x09, //��������쳣
    PILE_FAULT           = 0x0A, //��������
    PILE_BMS_FAULT       = 0x0B, //BMSͨ�Ź���, �������漰
    PILE_BMS_CONNECTED   = 0x0C, //BMS������, �������漰
} pile_state_e;

typedef enum dev_online_e
{
    DEV_CLOSE = 0,
    DEV_OFFLINE, //������
    DEV_ONLINE,  //����
} dev_online_e;

#pragma  pack(pop)

#endif

