#include "p18_setpara_sub5_dialog.h"
#include "ui_p18_setpara_sub5_dialog.h"
#include "globalhmi.h"

p18_setpara_sub5_dialog::p18_setpara_sub5_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p18_setpara_sub5_dialog)
{
    ui->setupUi(this);
}

p18_setpara_sub5_dialog::~p18_setpara_sub5_dialog()
{
    delete ui;
}
void p18_setpara_sub5_dialog::changeEvent(QEvent *e)
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

void p18_setpara_sub5_dialog::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    ui->label_code->setText(code);
}

float float_18 = 0;
int hour_t,min_t;

QTime t1(0,0,0);
QTime t1_1(0,0,0);
QTime t2(0,0,0);
QTime t2_1(0,0,0);
QTime p1(0,0,0);
QTime p1_1(0,0,0);
QTime p2(0,0,0);
QTime p2_1(0,0,0);
QTime f1(0,0,0);
QTime f1_1(0,0,0);
QTime f2(0,0,0);
QTime f2_1(0,0,0);
QTime g1(0,0,0);
QTime g1_1(0,0,0);
QTime g2(0,0,0);
QTime g2_1(0,0,0);

void ftotime(float num,int*a,int*b)
{
    *a = (int)num;
    float temp = (num-*a)*60;
    *b =(int)temp;
}

void p18_setpara_sub5_dialog::init_page_val()
{
        float_18 = 0;

        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        float max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top1_starttm");
        ft1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top1_stoptm");
        ft1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top2_starttm");
        ft2= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"top2_stoptm");
        ft2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak1_starttm");
        fp1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak1_stoptm");
        fp1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak2_starttm");
        fp2= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"peak2_stoptm");
        fp2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat1_starttm");
        ff1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat1_stoptm");
        ff1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat2_starttm");
        ff2= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"flat2_stoptm");
        ff2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley1_starttm");
        fg1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley1_stoptm");
        fg1_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley2_starttm");
        fg2= read_profile_float(Section_name, Key_name,max_temp,config_path);

        max_temp=0;
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"valley2_stoptm");
        fg2_1= read_profile_float(Section_name, Key_name,max_temp,config_path);

        hour_t = 0;
        min_t = 0;
        ftotime(ft1,&hour_t,&min_t);
        t1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ft2,&hour_t,&min_t);
        t2.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ft1_1,&hour_t,&min_t);
        t1_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ft2_1,&hour_t,&min_t);
        t2_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fp1,&hour_t,&min_t);
        p1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fp2,&hour_t,&min_t);
        p2.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fp1_1,&hour_t,&min_t);
        p1_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fp2_1,&hour_t,&min_t);
        p2_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ff1,&hour_t,&min_t);
        f1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ff2,&hour_t,&min_t);
        f2.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ff1_1,&hour_t,&min_t);
        f1_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(ff2_1,&hour_t,&min_t);
        f2_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fg1,&hour_t,&min_t);
        g1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fg2,&hour_t,&min_t);
        g2.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fg1_1,&hour_t,&min_t);
        g1_1.setHMS(hour_t,min_t,0);
        hour_t = 0;
        min_t = 0;
        ftotime(fg2_1,&hour_t,&min_t);
        g2_1.setHMS(hour_t,min_t,0);
}

void p18_setpara_sub5_dialog::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
}

void p18_setpara_sub5_dialog::timer_handle()
{
     update_page_info();
     update_hmi_page_index();
}

void p18_setpara_sub5_dialog::update_page_info()
{
      if(language_num == 1)
      {
            ui->label_logo->setText(QString::fromUtf8("直 流 充 电 桩"));
         //   ui->label_title->setText(QString::fromUtf8("电 价 设 置"));
            ui->label_stubnum->setText(QString::fromUtf8(" 桩   编   号  :"));
            ui->pbtn_ok->setText(QString::fromUtf8("确         定"));
            ui->pbtn_up->setText(QString::fromUtf8("上  一  页"));
      }
      else  if(language_num == 2)
      {
            ui->label_logo->setText("DC charging pile");
        //    ui->label_title->setText("Set Electricity Price");
            ui->label_stubnum->setText("Pile Number :");
            ui->pbtn_ok->setText("OK");
            ui->pbtn_up->setText("UP");
      }

      ui->timeEdit_t1_1->setTime(t1);
      ui->timeEdit_t1_2->setTime(t1_1);
      ui->timeEdit_p1_1->setTime(p1);
      ui->timeEdit_p1_2->setTime(p1_1);
      ui->timeEdit_f1_1->setTime(f1);
      ui->timeEdit_f1_2->setTime(f1_1);
      ui->timeEdit_g1_1->setTime(g1);
      ui->timeEdit_g1_2->setTime(g1_1);

      ui->timeEdit_t2_1->setTime(t2);
      ui->timeEdit_t2_2->setTime(t2_1);
      ui->timeEdit_p2_1->setTime(p2);
      ui->timeEdit_p2_2->setTime(p2_1);
      ui->timeEdit_f2_1->setTime(f2);
      ui->timeEdit_f2_2->setTime(f2_1);
      ui->timeEdit_g2_1->setTime(g2);
      ui->timeEdit_g2_2->setTime(g2_1);
}

void p18_setpara_sub5_dialog::update_hmi_page_index()
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index_cur),sizeof(hmi_page_index_cur));
    DebugMsg(hmilev,8,"hmi_page_index=[%d]cur[%d]\n",hmi_page_index,hmi_page_index_cur);
    if(hmi_page_index!=hmi_page_index_cur)
    {
        API_Write_DB_Nbyte(PL_HMI_PAGE_INDEX_CUR,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
        if(hmi_page_index==PAGEINDEX_MAIN)
        {
                exit_page_dlg();
        }else if(hmi_page_index==PAGEINDEX_SETPAGE_SIX)
        {
                call_p24_dlg();
        }
        else{
                ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
                exit(1);
        }

    }
}

void p18_setpara_sub5_dialog::call_p24_dlg()
{
    timer->stop();
    emit signal_timer_p18dlg();
    delete p18_dlg;
    p18_dlg = NULL;
}


void p18_setpara_sub5_dialog::exit_page_dlg()
{
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
    timer->stop();
    emit signal_exit_p18dlg();
    delete p18_dlg;
    p18_dlg = NULL;
}

float timetof(int a,int b)
{
    float return_val = 0;
    return_val = (float)b/60 + a;
    return return_val;
}
void p18_setpara_sub5_dialog::on_pbtn_ok_clicked()
{
    t1 = ui->timeEdit_t1_1->time();
    hour_t = t1.hour() ;
    min_t =  t1.minute();
    ft1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_starttm");
    write_profile_float(Section_name,Key_name,ft1,config_path);

    t1_1 = ui->timeEdit_t1_2->time();
    hour_t = t1_1.hour() ;
    min_t =  t1_1.minute();
    ft1_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top1_stoptm");
    write_profile_float(Section_name,Key_name,ft1_1,config_path);

    t2 = ui->timeEdit_t2_1->time();
    hour_t = t2.hour() ;
    min_t =  t2.minute();
    ft2 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_starttm");
    write_profile_float(Section_name,Key_name,ft2,config_path);

    t2_1 = ui->timeEdit_t2_2->time();
    hour_t = t2_1.hour() ;
    min_t =  t2_1.minute();
    ft2_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"top2_stoptm");
    write_profile_float(Section_name,Key_name,ft2_1,config_path);

    p1 = ui->timeEdit_p1_1->time();
    hour_t = p1.hour() ;
    min_t =  p1.minute();
    fp1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_starttm");
    write_profile_float(Section_name,Key_name,fp1,config_path);

    p1_1 = ui->timeEdit_p1_2->time();
    hour_t = p1_1.hour() ;
    min_t =  p1_1.minute();
    fp1_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak1_stoptm");
    write_profile_float(Section_name,Key_name,fp1_1,config_path);

    p2 = ui->timeEdit_p2_1->time();
    hour_t = p2.hour() ;
    min_t =  p2.minute();
    fp2 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_starttm");
    write_profile_float(Section_name,Key_name,fp2,config_path);

    p2_1 = ui->timeEdit_p2_2->time();
    hour_t = p2_1.hour() ;
    min_t =  p2_1.minute();
    fp2_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"peak2_stoptm");
    write_profile_float(Section_name,Key_name,fp2_1,config_path);

    f1 = ui->timeEdit_f1_1->time();
    hour_t = f1.hour() ;
    min_t =  f1.minute();
    ff1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_starttm");
    write_profile_float(Section_name,Key_name,ff1,config_path);

    f1_1 = ui->timeEdit_f1_2->time();
    hour_t = f1_1.hour() ;
    min_t =  f1_1.minute();
    ff1_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat1_stoptm");
    write_profile_float(Section_name,Key_name,ff1_1,config_path);

    f2 = ui->timeEdit_f2_1->time();
    hour_t = f2.hour() ;
    min_t =  f2.minute();
    ff2 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_starttm");
    write_profile_float(Section_name,Key_name,ff2,config_path);

    f2_1 = ui->timeEdit_f2_2->time();
    hour_t = f2_1.hour() ;
    min_t =  f2_1.minute();
    ff2_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"flat2_stoptm");
    write_profile_float(Section_name,Key_name,ff2_1,config_path);

    g1 = ui->timeEdit_g1_1->time();
    hour_t = g1.hour() ;
    min_t =  g1.minute();
    fg1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_starttm");
    write_profile_float(Section_name,Key_name,fg1,config_path);

    g1_1 = ui->timeEdit_g1_2->time();
    hour_t = g1_1.hour() ;
    min_t =  g1_1.minute();
    fg1_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley1_stoptm");
    write_profile_float(Section_name,Key_name,fg1_1,config_path);

    g2 = ui->timeEdit_g2_1->time();
    hour_t = g2.hour() ;
    min_t =  g2.minute();
    fg2 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_starttm");
    write_profile_float(Section_name,Key_name,fg2,config_path);

    g2_1 = ui->timeEdit_g2_2->time();
    hour_t = g2_1.hour() ;
    min_t =  g2_1.minute();
    fg2_1 = timetof(hour_t,min_t);
    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"valley2_stoptm");
    write_profile_float(Section_name,Key_name,fg2_1,config_path);

    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void p18_setpara_sub5_dialog::on_pbtn_up_clicked()
{
    hmi_button_dn_num=PAGEUP_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}
