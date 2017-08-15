#include "dialog_checkcaed.h"
#include "ui_dialog_checkcaed.h"
#include "globalhmi.h"

Dialog_checkcaed::Dialog_checkcaed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_checkcaed)
{
    ui->setupUi(this);
}

Dialog_checkcaed::~Dialog_checkcaed()
{
    delete ui;
}

void Dialog_checkcaed::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

void Dialog_checkcaed::init_page_val()
{
    //ui->label_stubnum->setText(QString::fromUtf8("桩编号："));
    ui->label_phone->setText(QString::fromUtf8("客服热线："));
    //ui->label_code->setText(code);
    ui->label_num1->setText(phonenum);
    //ui->label_num2->setText(phonenum_2);
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void Dialog_checkcaed::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

static int  num_add_end = 0;
void Dialog_checkcaed::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}

char err_flag = 0;
void Dialog_checkcaed::update_page_info()
{
 //   ui->lbl_sysdate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd"));
//    ui->lbl_systime->setText(QTime::currentTime().toString("hh:mm:ss"));

    if(language_num == 1)
    {


       // 1、账户不存在，2、账户异常（冻结，黑名单，挂失，销户），3余额不足 4、该卡存在未结账记录 6，桩停用

         API_Read_DB_Nbyte(PL_CARD_UNUSE_FLAG,&err_flag,sizeof(err_flag));
         switch(err_flag)
         {
		 	case 0:
                ui->label_check->setText(QString::fromUtf8("网络异常, 请稍候再试"));
                break;

             case 1:
                ui->label_check->setText(QString::fromUtf8("账户不存在"));
                break;
             case 2:
                ui->label_check->setText(QString::fromUtf8("账户异常"));
                break;
             case 3:
                ui->label_check->setText(QString::fromUtf8("余额不足"));
                break;
             case 4:
                ui->label_check->setText(QString::fromUtf8("存在未结账记录"));
                break;
             case 6:
                ui->label_check->setText(QString::fromUtf8("桩停用"));
                break;

             default:
                ui->label_check->setText(QString::fromUtf8("正在验证,请稍候"));
                break;

         }
     //    ui->label_check->setText(QString::fromUtf8("正在验证,请稍候"));



         //ui->label_stubnum->setText(QString::fromUtf8("桩编号:"));
    }
    else  if(language_num == 2)
    {
         // ui->label_logo->setText("AC charging pile");
          ui->label_check->setText("Please waiting for checking the card");
          ui->label_stubnum->setText("Telephone  :");
    }
    else
    {

    }
}

void Dialog_checkcaed::update_hmi_page_index(void)
{
        API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
       if(hmi_page_index != PAGEINDEX_CHECKCARD)
       {
           exit_page_dlg();
       }
       else
       {

       }
}

void Dialog_checkcaed::exit_page_dlg()
{
    init_page_val();
    timer->stop();
    emit  signal_exit_checkcarddlg();
  //  delete checkcard_dlg;
  //  checkcard_dlg = NULL;
}
