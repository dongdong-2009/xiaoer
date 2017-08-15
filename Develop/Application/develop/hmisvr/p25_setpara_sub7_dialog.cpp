#include "p25_setpara_sub7_dialog.h"
#include "ui_p25_setpara_sub7_dialog.h"
#include "globalhmi.h"

p25_setpara_sub7_dialog::p25_setpara_sub7_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p25_setpara_sub7_dialog)
{
    ui->setupUi(this);
}

p25_setpara_sub7_dialog::~p25_setpara_sub7_dialog()
{
    delete ui;
}

void p25_setpara_sub7_dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void p25_setpara_sub7_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    init_page_val();
    btn_press();
    //ui->label_stubnum->setText(QString::fromUtf8("??????"));
    //ui->label_phone->setText(QString::fromUtf8("????????"));
    //ui->label_code->setText(code);
    //ui->label_num1->setText(phonenum);
    //ui->label_num2->setText(phonenum_2);
}

void p25_setpara_sub7_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
        //API_Read_DB_Nbyte(PL_SOFT_TIME,(INT8 *)(&softtime),sizeof(softtime));
/*
        change_num = 0;
         soft_len=0;
         btn_devwd_len=0;
         cost_len=0;
         source_len=0;
         money_len=0;
         memset(soft,0,sizeof(soft));
         memset(cost,0,sizeof(cost));
         memset(source,0,sizeof(source));
         memset(btn_devwd,0,sizeof(btn_devwd));
         memset(money,0,sizeof(money));
*/
        // ui->lbl_ch_time->setText(QString::fromLocal8Bit(softtime));
         int net_temp;
         net_temp=0;

        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
        line_check= read_profile_int(Section_name, Key_name,net_temp,config_path);

}

void p25_setpara_sub7_dialog::btn_press()
{
    QPushButton* array[4]={0};
    array[0] = ui->pbtn_go;
    array[1] = ui->pbtn_ok;
    array[2] = ui->pbtn_up;
    array[3] = ui->pbtn_down;
    int num = 0;
    for(num = 0; num < 4;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/icon/qrc/keyboard-b/T.png);}\
                                  QPushButton:pressed{border-image: url(:/icon/qrc/keyboard-b/T_press.png);}");
    }

}
void p25_setpara_sub7_dialog::start_timer()
{
    timer->start(SETPAGE_FLUSH_TIMER);
}


void p25_setpara_sub7_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}
void p25_setpara_sub7_dialog::update_page_info()
{
/*
    ??? 4 3 2
    button -> yidong_4g_btn,yidong_3g_btn,yidong_2g_btn
    ?? 4 3 2
    button->liantong_4g_btn,liantong_3g_btn,liantong_2g_btn
    ???? 4 3 2
    button->dianxin_4g_btn,dianxin_3g_btn,dianxin_2g_btn
    ?????
    button->online_btn
    wifi
    button->wifi_btn

*/
        if(line_check)
        {
            //
            //移动2G
            if(line_check==DATATRANSFORM_BYTDSCDMA_2G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(TRUE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

            }
            /*
            //移动3G
            else if(line_check==DATATRANSFORM_BYTDSCDMA_3G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(TRUE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            */
            //移动4G
            else if(line_check==DATATRANSFORM_BYTDSCDMA_4G)
            {
                ui->yidong_4g_btn->setChecked(TRUE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
               // ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            //联通 2G
            else if(line_check==DATATRANSFORM_BYWCDMA_2G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(TRUE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            //联通3G
            else if(line_check==DATATRANSFORM_BYWCDMA_3G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(TRUE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            //联通4G
            else if(line_check==DATATRANSFORM_BYWCDMA_4G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(TRUE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            /*
            //电信 2G
            else if(line_check==DATATRANSFORM_BYCDMA2000_2G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(TRUE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                ui->toserialport_btn->setChecked(FALSE);
            }
            */
            //电信 3G
            else if(line_check==DATATRANSFORM_BYCDMA2000_3G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(TRUE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            //电信 4G
            else if(line_check==DATATRANSFORM_BYCDMA2000_4G)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(TRUE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            //wifi
            else if(line_check==DATATRANSFORM_BYWIFI)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(TRUE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            //socket
            else if(line_check==DATATRANSFORM_BYSOCKET)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(TRUE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(FALSE);
            }
            /*
            //?????????
            else if(line_check==DATATRANSFORM_BYHYALINE)
            {
                ui->yidong_4g_btn->setChecked(FALSE);
                //ui->yidong_3g_btn->setChecked(FALSE);
                ui->yidong_2g_btn->setChecked(FALSE);

                ui->liantong_4g_btn->setChecked(FALSE);
                ui->liantong_3g_btn->setChecked(FALSE);
                ui->liantong_2g_btn->setChecked(FALSE);

                ui->dianxin_4g_btn->setChecked(FALSE);
                ui->dianxin_3g_btn->setChecked(FALSE);
                //ui->dianxin_2g_btn->setChecked(FALSE);

                ui->online_btn->setChecked(FALSE);

                ui->wifi_btn->setChecked(FALSE);

                //ui->toserialport_btn->setChecked(TRUE);
            }
            */
            else
            {

            }
        }
}
void p25_setpara_sub7_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_SETPAGE_SEVEN)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p25_setpara_sub7_dialog::on_yidong_2g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=13;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

/*
void p25_setpara_sub7_dialog::on_yidong_3g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=12;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}
*/
void p25_setpara_sub7_dialog::on_yidong_4g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=11;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

void p25_setpara_sub7_dialog::on_liantong_2g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=16;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

void p25_setpara_sub7_dialog::on_liantong_3g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=15;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

void p25_setpara_sub7_dialog::on_liantong_4g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=14;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}
/*
void p25_setpara_sub7_dialog::on_dianxin_2g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=19;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}
*/
void p25_setpara_sub7_dialog::on_dianxin_3g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=18;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

void p25_setpara_sub7_dialog::on_dianxin_4g_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=17;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

void p25_setpara_sub7_dialog::on_wifi_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=10;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}

void p25_setpara_sub7_dialog::on_online_btn_clicked()
{
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"DataPackTranformWay");
    line_check=2;
    write_profile_int(Section_name,Key_name,line_check,config_path);
}


void p25_setpara_sub7_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p25_setpara_sub7_dialog::on_pbtn_up_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_up_clicked\n");

    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p25_setpara_sub7_dialog::on_pbtn_down_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");

    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

    ui->label_speaker->setText(QString::fromUtf8("已经是最后一页!"));
}

void p25_setpara_sub7_dialog::on_pbtn_ok_clicked()
{
    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));

}

void p25_setpara_sub7_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p25dlg();
}



