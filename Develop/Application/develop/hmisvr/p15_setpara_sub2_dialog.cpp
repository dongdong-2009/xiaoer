#include "p15_setpara_sub2_dialog.h"
#include "ui_p15_setpara_sub2_dialog.h"
#include "globalhmi.h"

#define  ERR_FILE  "/usr/data/warning.txt"

p15_setpara_sub2_dialog::p15_setpara_sub2_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::p15_setpara_sub2_dialog)
{
    ui->setupUi(this);
}

p15_setpara_sub2_dialog::~p15_setpara_sub2_dialog()
{
    delete ui;
}

void p15_setpara_sub2_dialog::changeEvent(QEvent *e)
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


char temp_sub2_buf[30][50]={0};
int temp_add_sub2 = 0;
int num_15=0;
  //char Section_name[BUFFERLEN_32];
  //char Key_name[BUFFERLEN_32];
  //char Tempor_name[BUFFERLEN_32];
BOOL farip_flg=FALSE;
BOOL port_flg=FALSE;
BOOL localip_flg=FALSE;
BOOL mask_flg=FALSE;
BOOL guan_flg=FALSE;
BOOL mac_flg=FALSE;

struct  _partbuf_0x97 array_errfile[500]={0};//the max num is 500;
int err_sum = 0;
int Err_file_analysis(const char *file_name, struct _partbuf_0x97  *partbuf_0x97_OutPt);

 void p15_setpara_sub2_dialog::on_pbtn_history_clicked()
 {
     history_setpage=1;
     hmi_button_dn_num=HISTORYCHECK_BUTTON;
     API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
 }

 void p15_setpara_sub2_dialog::on_pbtn_error_clicked()
{

     ui->frame_6->move(55,800);
     ui->frame->move(35,86);
     ui->frame_2->move(40,800);
     ui->frame_3->move(20,800);
     ui->frame_5->move(35,800);
}

 void p15_setpara_sub2_dialog::on_pbtn_error_net_clicked()
 {
     ui->frame_6->move(55,800);
     ui->frame->move(35,86);
     ui->frame_2->move(40,800);
     ui->frame_3->move(20,800);
     ui->frame_5->move(35,800);
 }

  void p15_setpara_sub2_dialog::on_pbtn_cancel_clicked()
  {
      ui->frame_6->move(55,800);
      ui->frame->move(40,800);
      ui->frame_2->move(40,800);
      ui->frame_3->move(30,100);
      ui->frame_5->move(460,100);
  }

void p15_setpara_sub2_dialog::on_pbtn_err_clicked()
{
    err_sum = Err_file_analysis(ERR_FILE,array_errfile);
     ui->lbl_errnum->setNum(err_sum);

     memcpy(&time,&array_errfile[lbl_num-1].OccurTm,sizeof(SYNCHRO_TIME_S));
     memcpy(&time_2,&array_errfile[lbl_num_2-1].OccurTm,sizeof(SYNCHRO_TIME_S));
     memcpy(&time_3,&array_errfile[lbl_num_3-1].OccurTm,sizeof(SYNCHRO_TIME_S));
     memcpy(&time_4,&array_errfile[lbl_num_4-1].OccurTm,sizeof(SYNCHRO_TIME_S));
     memcpy(&time_5,&array_errfile[lbl_num_5-1].OccurTm,sizeof(SYNCHRO_TIME_S));

     err_code = array_errfile[lbl_num-1].errcode;
     err_code_2 = array_errfile[lbl_num_2-1].errcode;
     err_code_3 = array_errfile[lbl_num_3-1].errcode;
     err_code_4 = array_errfile[lbl_num_4-1].errcode;
     err_code_5 = array_errfile[lbl_num_5-1].errcode;

     memcpy(lbl_txt, &temp_sub2_buf[llbl_num-1],sizeof(temp_sub2_buf[llbl_num-1]));
     memcpy(lbl_txt_2,& temp_sub2_buf[llbl_num_2-1],sizeof(temp_sub2_buf[llbl_num_2-1]));
     memcpy(lbl_txt_3, &temp_sub2_buf[llbl_num_3-1],sizeof(temp_sub2_buf[llbl_num_3-1]));
     memcpy(lbl_txt_4, &temp_sub2_buf[llbl_num_4-1],sizeof(temp_sub2_buf[llbl_num_4-1]));
     memcpy(lbl_txt_5, &temp_sub2_buf[llbl_num_5-1],sizeof(temp_sub2_buf[llbl_num_5-1]));

    ui->frame_6->move(55,100);
     ui->frame->move(35,860);
    ui->frame_3->move(20,800);
    ui->frame_5->move(35,800);
    ui->frame_2->move(40,800);
}

void p15_setpara_sub2_dialog::on_pbtn_down_2_clicked()
{
    if(lbl_num < err_sum)
    {
        lbl_num=lbl_num+5;
        lbl_num_2=lbl_num_2+5;
        lbl_num_3=lbl_num_3+5;
        lbl_num_4=lbl_num_4+5;
        lbl_num_5=lbl_num_5+5;

        memcpy(&time,&array_errfile[lbl_num-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_2,&array_errfile[lbl_num_2-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_3,&array_errfile[lbl_num_3-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_4,&array_errfile[lbl_num_4-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_5,&array_errfile[lbl_num_5-1].OccurTm,sizeof(SYNCHRO_TIME_S));

        err_code = array_errfile[lbl_num-1].errcode;
        err_code_2 = array_errfile[lbl_num_2-1].errcode;
        err_code_3 = array_errfile[lbl_num_3-1].errcode;
        err_code_4 = array_errfile[lbl_num_4-1].errcode;
        err_code_5 = array_errfile[lbl_num_5-1].errcode;

       }
    else
    {

    }
}

void p15_setpara_sub2_dialog::on_pbtn_up_2_clicked()
{
    if(lbl_num-5>0)
     {
             lbl_num=lbl_num-5;
             lbl_num_2=lbl_num_2-5;
             lbl_num_3=lbl_num_3-5;
             lbl_num_4=lbl_num_4-5;
             lbl_num_5=lbl_num_5-5;

             memcpy(&time,&array_errfile[lbl_num-1].OccurTm,sizeof(SYNCHRO_TIME_S));
             memcpy(&time_2,&array_errfile[lbl_num_2-1].OccurTm,sizeof(SYNCHRO_TIME_S));
             memcpy(&time_3,&array_errfile[lbl_num_3-1].OccurTm,sizeof(SYNCHRO_TIME_S));
             memcpy(&time_4,&array_errfile[lbl_num_4-1].OccurTm,sizeof(SYNCHRO_TIME_S));
             memcpy(&time_5,&array_errfile[lbl_num_5-1].OccurTm,sizeof(SYNCHRO_TIME_S));

             err_code = array_errfile[lbl_num-1].errcode;
             err_code_2 = array_errfile[lbl_num_2-1].errcode;
             err_code_3 = array_errfile[lbl_num_3-1].errcode;
             err_code_4 = array_errfile[lbl_num_4-1].errcode;
             err_code_5 = array_errfile[lbl_num_5-1].errcode;

    }
     else
     {

     }
}

void p15_setpara_sub2_dialog::on_pbtn_back_2_clicked()
{
    ui->frame->move(30,800);
    ui->frame_2->move(40,800);
    ui->frame_3->move(30,100);
    ui->frame_5->move(460,100);
}

void p15_setpara_sub2_dialog::on_pbtn_back_3_clicked()
{
    memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
    temp_add_sub2 = 0;
    ui->frame_2->move(36,800);
    ui->frame->move(35,86);
}

int   Err_analysis(int error_state_flag)
{
    if(language_num == 1)
    {
        temp_add_sub2 = 0;
        if( (error_state_flag & (1<<0)) || (error_state_flag &(1<<24)) || (error_state_flag & (1<<1))  || (error_state_flag & (1<<25)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"读 卡 器 故 障",sizeof("读 卡 器 故 障"));
        }
        if( (error_state_flag & (1<<20)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"电 表 通 讯 故 障",sizeof("电 表 通 讯 故 障"));
        }
        if( (error_state_flag & (1<<3)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"显 示 屏 通 讯 故 障",sizeof("显 示 屏 通 讯 故 障"));
        }
        if( (error_state_flag & (1<<23)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"网 络 连 接 故 障",sizeof("网 络 连 接 故 障"));
        }

        if( (error_state_flag & (1<<8)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"主 板 软 件 故 障",sizeof("主 板 软 件 故 障"));
        }
        if( (error_state_flag & (1<<21)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"急停按钮被按下,请恢复",sizeof("急停按钮被按下,请恢复"));
        }
        if( (error_state_flag & (1<<7)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"主 板 硬 件 故 障",sizeof("主 板 硬 件 故 障"));
        }
        if( (error_state_flag & (1<<4)) ||(error_state_flag & (1<<5)))
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"交流接触器故障",sizeof("交流接触器故障"));
        }
        if( (error_state_flag & (1<<10)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"模块通讯故障",sizeof("模块通讯故障"));
        }
        if( (error_state_flag & (1<<30)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"输入过压",sizeof("输入过压"));
        }
        if( (error_state_flag & (1<<31)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"输入欠压",sizeof("输入欠压"));
        }
        if( (error_state_flag & (1<<18)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"电磁锁故障",sizeof("电磁锁故障"));
        }
        if( (error_state_flag & (1<<11)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"数据传输错误",sizeof("数据传输错误"));
        }
        if( (error_state_flag & (1<<12)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"输出过流",sizeof("输出过流"));
        }
        if( (error_state_flag & (1<<13)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"输出短路",sizeof("输出短路"));
        }
        if( (error_state_flag & (1<<14)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"出风口温度过高",sizeof("出风口温度过高"));
        }
        if( (error_state_flag & (1<<15)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"存储器已满",sizeof("存储器已满"));
        }
    }
    else  if(language_num == 2)
    {

        temp_add_sub2 = 0;
        if( (error_state_flag & (1<<0)) || (error_state_flag &(1<<24)) || (error_state_flag & (1<<1))  || (error_state_flag & (1<<25)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"card reader error",sizeof("card reader error"));
        }
        if( (error_state_flag & (1<<23)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"net link error",sizeof("net link error"));
        }
        if( (error_state_flag & (1<<20)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"meter error",sizeof("meter error"));
        }
        if( (error_state_flag & (1<<8)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"software in board error",sizeof("software in board error"));
        }
        if( (error_state_flag & (1<<21)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"emergency is pressed,please recover it",sizeof("emergency is pressed,please recover it"));
        }
        if( (error_state_flag & (1<<7)) )
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"hardware in board error",sizeof("hardware in board error"));
        }
        if( (error_state_flag & (1<<4)) ||(error_state_flag & (1<<5)))
        {
            memcpy(&temp_sub2_buf[temp_add_sub2++],"ac contactor error",sizeof("ac contactor error"));
        }
    }
    else
    {

    }
    return temp_add_sub2;
}

void p15_setpara_sub2_dialog::on_pbtn_1_clicked()
{
    memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
    temp_add_sub2 = 0;
    Err_analysis(err_code);
    ui->frame_2->move(36,87);
    ui->frame->move(30,800);
}
void p15_setpara_sub2_dialog::on_pbtn_2_clicked()
{
    memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
    temp_add_sub2 = 0;
    Err_analysis(err_code_2);
    ui->frame_2->move(36,87);
    ui->frame->move(30,800);
}
void p15_setpara_sub2_dialog::on_pbtn_3_clicked()
{
    memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
    temp_add_sub2 = 0;
    Err_analysis(err_code_3);
    ui->frame_2->move(36,87);
    ui->frame->move(30,800);
}
void p15_setpara_sub2_dialog::on_pbtn_4_clicked()
{
    memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
    temp_add_sub2 = 0;
    Err_analysis(err_code_4);
    ui->frame_2->move(36,87);
    ui->frame->move(30,800);
}
void p15_setpara_sub2_dialog::on_pbtn_5_clicked()
{
    memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
    temp_add_sub2 = 0;
    Err_analysis(err_code_5);
    ui->frame_2->move(36,87);
    ui->frame->move(30,800);
}

void p15_setpara_sub2_dialog::init_page_dlg()
{
    init_page_val();
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(SETPAGE_FLUSH_TIMER);
    btn_press();
    ui->label_stubnum->setText(QString::fromUtf8("桩编号："));
    ui->label_phone->setText(QString::fromUtf8("客服热线："));
    ui->label_code->setText(code);
    ui->label_num1->setText(phonenum);
    ui->label_num2->setText(phonenum_2);
}

char temp_err_array[50] = {0};

char* p15_setpara_sub2_dialog::itos(struct SYNCHRO_TIME  time)
{
    memset(temp_err_array,0,sizeof(temp_err_array));
    snprintf(temp_err_array,50,"%4d-%02d-%02d %02d:%02d:%02d",time.uwYear,time.ucMonth,time.ucDay,time.ucHour,time.ucMinute,time.ucSecond);
    char *temp = temp_err_array;
    return temp;
}

int Err_file_analysis(const char *file_name, struct _partbuf_0x97  *partbuf_0x97_OutPt)
{
    int num_add = 0;
    unsigned char linedatabuf[100] ;
    FILE *fp_file;
    unsigned  int startpos=0;
    //one line total len
    unsigned  int  readLen=0;

    //singal for each split
    unsigned  int Sectionindex=0;
    //store the char for each split
    unsigned char SectionBuf[50];
    //pos for each split
    unsigned  int  SectiondataPos=0;

    //flag for getting the start index of history
    unsigned  int  startInsertFlag=0;
       //insert history count
    unsigned  int  TempInsertCount=0;
    struct _partbuf_0x97 tempWaring ;
    int tempeventtype=0;
    int linetotal=0;
    fp_file = fopen(file_name, "r");
    if(fp_file ==0)//open file error
    {
        perror("open warning.txt: ");
        return 0;
    }
    else
    {
        printf("open warningfile success\r\n");
    }
    if(partbuf_0x97_OutPt==NULL)
    {
        fclose(fp_file);
        return 0;
    }
    memset(linedatabuf,0,100);
    TempInsertCount=0;
      //  while (fgets((char *)linedatabuf, sizeof(linedatabuf), fp_file))
    while (!feof(fp_file))
    {
        fgets((char *)linedatabuf, sizeof(linedatabuf), fp_file);
        if(feof(fp_file))
        {
                     //at the end of file ,stopping get historyrecord
               startInsertFlag=0;
            break;
        }

        readLen=strlen((char *)linedatabuf);
        if(readLen<=3)
        {
            continue;
        }


        //please tar the string buf for your struct
        //tile of the text
        printf("####read linenumber=%d,%s\r\n",linetotal,linedatabuf);
        if( linedatabuf[startpos]=='i'&& linedatabuf[startpos+1]=='d'&&linedatabuf[startpos+2]=='x')
        {
            continue;
        }
        if( linedatabuf[startpos]=='#'&& linedatabuf[startpos+1]=='#'&&linedatabuf[startpos+2]=='#')
        {
            continue;
        }
           linetotal++;

        memset(SectionBuf,0,50);
        Sectionindex=0;
        SectiondataPos=0;
        for(startpos=0;startpos<readLen;startpos++)
        {

            if(linedatabuf[startpos]==0x0d||linedatabuf[startpos]==0x0a)
            {
                //break;
                continue;
            }
            if(linedatabuf[startpos]==0x7c)//"|"
            {
                     // printf("1111111111111\r\n");
                if(Sectionindex==0)//record index
                {
                    tempeventtype=atoi((char *)SectionBuf);
                    if(tempeventtype== 1)//find the startindex wo need
                    {
                      // tempWaring.index=linetotal;
                        //add by mj_1_29
                        num_add++;
                        tempWaring.index=num_add;
                       //tempWaring.type_inquire=tempeventtype;
                       startInsertFlag=1;
                    }
                    else
                    {
                        startInsertFlag=0;
                        continue;
                    }

                // printf("%d\r\n",tempHistoryRecord.RecordIndex);
                }//end of if(Sectionindex==0)//record index
                else if(Sectionindex==1)//record index
                {
                    tempWaring.modnum=atoi((char *)SectionBuf);
                }//end of if(Sectionindex==0)//record index
                else if(Sectionindex==2)//record index
                {
                    //tempWaring.errcode=atoi((char *)SectionBuf);
                    strcat((char *)SectionBuf,"-");
                    TimeAnanisis(&tempWaring.OccurTm,SectionBuf);

                }//end of if(Sectionindex==0)//record index
                else if(Sectionindex==3)//errcode
                {
                       tempWaring.errcode=atoi((char *)SectionBuf);
                }

                memset(SectionBuf,0,50);
                SectiondataPos=0;
                Sectionindex++;
                continue;
            }//end of if(linedatabuf[startpos]==0x7c)//"|"
            else
            {
                          if(SectiondataPos<50)
                            {
                                  SectionBuf[SectiondataPos++]=linedatabuf[startpos];
                            }

            }

       }//end of for(startpos=0;startpos<readLen;startpos++)

        Sectionindex=0;
        // printf("\r\n");
        memset(linedatabuf,0,100);
        if(startInsertFlag==1&&TempInsertCount<500)//start insert history
        {
                memcpy(&partbuf_0x97_OutPt[TempInsertCount],&tempWaring,sizeof(struct _partbuf_0x97));
                //partbuf_0x96_OutPt[TempEventInsertCount].RecordIndex=linetotal;
                TempInsertCount++;
        }//end of  if(startInsertFlag==1)//start insert history
        memset(&tempWaring,0,sizeof(struct _partbuf_0x97));

    }//end of  while (fgets(linedatabuf, sizeof(linedatabuf), fp_file))

    fclose(fp_file);
    return TempInsertCount;
}


void p15_setpara_sub2_dialog::init_page_val()
{
        UINT8 data = NO_BUTTON;
        API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));

        err_sum = 0;

         farip_len=0;
         localip_len=0;
         art_len=0;
         ma_len=0;
         guan_len=0;
         mac_len=0;

         memset(temp_sub2_buf,0,sizeof(temp_sub2_buf));
         temp_add_sub2 = 0;

         memset(farip,0,sizeof(farip));
         memset(localip,0,sizeof(localip));
         memset(art,0,sizeof(art));
         memset(guan,0,sizeof(guan));
         memset(ma,0,sizeof(ma));
         memset(mac,0,sizeof(mac));

         memset(Tempor_name,0,sizeof(Tempor_name));
         Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
         Inibuf_init(Key_name,BUFFERLEN_32,"serverip");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(farip,Tempor_name,sizeof(farip));
            farip_flg=TRUE;
        }
        else
        {
            memset(farip,0,sizeof(farip));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
        Inibuf_init(Key_name,BUFFERLEN_32,"serverport");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(art,Tempor_name,sizeof(art));
            port_flg=TRUE;
        }
        else
        {
            memset(art,0,sizeof(art));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"ipaddr");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(localip,Tempor_name,sizeof(localip));
            localip_flg=TRUE;
        }
        else
        {
            memset(localip,0,sizeof(localip));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"mask");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(ma,Tempor_name,sizeof(ma));
            mask_flg=TRUE;
        }
        else
        {
            memset(ma,0,sizeof(ma));
        }

         memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"getway");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(guan,Tempor_name,sizeof(guan));
            guan_flg=TRUE;
        }
        else
        {
            memset(guan,0,sizeof(guan));
        }

        memset(Tempor_name,0,sizeof(Tempor_name));
        Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
        Inibuf_init(Key_name,BUFFERLEN_32,"sysmac");

        if(read_profile_string(Section_name, Key_name, Tempor_name, INIFILE_LININBUF_SIZE,"",config_path))
        {
            memcpy(mac,Tempor_name,sizeof(mac));
            mac_flg=TRUE;
        }
        else
        {
            memset(ma,0,sizeof(mac));
        }

        memset(array_errfile,0,sizeof(array_errfile));
        //err_sum = Err_file_analysis(ERR_FILE,array_errfile);
        //ui->lbl_errnum->setNum(err_sum);

        lbl_num=1;
        lbl_num_2=2;
        lbl_num_3=3;
        lbl_num_4=4;
        lbl_num_5=5;

        llbl_num=1;
        llbl_num_2=2;
        llbl_num_3=3;
        llbl_num_4=4;
        llbl_num_5=5;
/*
        memcpy(lbl_txt, &temp_sub2_buf[llbl_num-1],sizeof(temp_sub2_buf[llbl_num-1]));
        memcpy(lbl_txt_2,& temp_sub2_buf[llbl_num_2-1],sizeof(temp_sub2_buf[llbl_num_2-1]));
        memcpy(lbl_txt_3, &temp_sub2_buf[llbl_num_3-1],sizeof(temp_sub2_buf[llbl_num_3-1]));
        memcpy(lbl_txt_4, &temp_sub2_buf[llbl_num_4-1],sizeof(temp_sub2_buf[llbl_num_4-1]));
        memcpy(lbl_txt_5, &temp_sub2_buf[llbl_num_5-1],sizeof(temp_sub2_buf[llbl_num_5-1]));

        memcpy(&time,&array_errfile[lbl_num-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_2,&array_errfile[lbl_num_2-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_3,&array_errfile[lbl_num_3-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_4,&array_errfile[lbl_num_4-1].OccurTm,sizeof(SYNCHRO_TIME_S));
        memcpy(&time_5,&array_errfile[lbl_num_5-1].OccurTm,sizeof(SYNCHRO_TIME_S));

        err_code = array_errfile[lbl_num-1].errcode;
        err_code_2 = array_errfile[lbl_num_2-1].errcode;
        err_code_3 = array_errfile[lbl_num_3-1].errcode;
        err_code_4 = array_errfile[lbl_num_4-1].errcode;
        err_code_5 = array_errfile[lbl_num_5-1].errcode;
*/
        ui->frame->move(40,800);
        ui->frame_2->move(40,800);
        ui->frame_3->move(30,100);
        ui->frame_5->move(460,100);
        ui->frame_6->move(40,800);
}

void p15_setpara_sub2_dialog::start_timer()
{
    init_page_val();
    timer->start(PAGE_FLUSH_TIMER);
}


void p15_setpara_sub2_dialog::timer_handle()
{

     update_page_info();
     update_hmi_page_index();
}


void p15_setpara_sub2_dialog::btn_press()
{

    QPushButton* array[16]={0};
    array[0] = ui->pbtn_num0;
    array[1] = ui->pbtn_num1;
    array[2] = ui->pbtn_num2;
    array[3] = ui->pbtn_num3;
    array[4] = ui->pbtn_num4;
    array[5] = ui->pbtn_num5;
    array[6] = ui->pbtn_num6;
    array[7] = ui->pbtn_num7;
    array[8] = ui->pbtn_num8;
    array[9] = ui->pbtn_num9;
    array[10] = ui->pbtn_dot;
    array[11] = ui->pbtn_back;
    array[12] = ui->pbtn_go;
    array[13] = ui->pbtn_ok;
    array[14] = ui->pbtn_up;
    array[15] = ui->pbtn_down;
    int num = 0;
    for(num = 0; num < 16;num++)
    {
        array[num]->setStyleSheet("QPushButton{border-image: url(:/icon/qrc/keyboard-b/T.png);}\
                                  QPushButton:pressed{border-image: url(:/icon/qrc/keyboard-b/T_press.png);}");
    }

}

void p15_setpara_sub2_dialog::update_page_info()
{
    if(language_num == 1)
    {
        //  ui->label_logo->setText(QString::fromUtf8("交 流 充 电 桩"));
      //   ui->label_stubnum->setText(QString::fromUtf8(" 客  服  电  话  :"));
    }
    else  if(language_num == 2)
    {
          //ui->label_logo->setText("AC charging pile");
          ui->label_stubnum->setText("Telephone :");
    }

    ui->lbl_farip->setText(farip);
    ui->lbl_art->setText(art);
    ui->lbl_localip->setText(localip);
    ui->lbl_ma->setText(ma);
    ui->lbl_guan->setText(guan);
    ui->lbl_mac->setText(mac);

    if(err_code)
    {
       ui->label_num->setNum(lbl_num);
        ui->label_txt->setText(itos(time));
        ui->pbtn_1->move(510,70);
    }
    else
    {
         ui->label_num->setText(NULL);
         ui->label_txt->setText(NULL);
         ui->pbtn_1->move(510,700);
    }
    if(err_code_2)
    {
       ui->label_num_2->setNum(lbl_num_2);
       ui->label_txt_2->setText(itos(time_2));
       ui->pbtn_2->move(510,110);
    }
    else
    {
         ui->label_num_2->setText(NULL);
         ui->label_txt_2->setText(NULL);
         ui->pbtn_2->move(510,700);
    }
    if(err_code_3)
    {
       ui->label_num_3->setNum(lbl_num_3);
       ui->label_txt_3->setText(itos(time_3));
       ui->pbtn_3->move(510,150);
    }
    else
    {
         ui->label_num_3->setText(NULL);
         ui->label_txt_3->setText(NULL);
         ui->pbtn_3->move(510,700);
    }
    if(err_code_4)
    {
       ui->label_num_4->setNum(lbl_num_4);
       ui->label_txt_4->setText(itos(time_4));
       ui->pbtn_4->move(510,190);
    }
    else
    {
         ui->label_num_4->setText(NULL);
         ui->label_txt_4->setText(NULL);
         ui->pbtn_4->move(510,700);
    }
    if(err_code_5)
    {
       ui->label_num_5->setNum(lbl_num_5);
       ui->label_txt_5->setText(itos(time_5));
       ui->pbtn_5->move(510,230);
    }
    else
    {
         ui->label_num_5->setText(NULL);
         ui->label_txt_5->setText(NULL);
         ui->pbtn_5->move(510,700);
    }

#if 1
    memcpy(lbl_txt, &temp_sub2_buf[llbl_num-1],sizeof(temp_sub2_buf[llbl_num-1]));
    memcpy(lbl_txt_2,& temp_sub2_buf[llbl_num_2-1],sizeof(temp_sub2_buf[llbl_num_2-1]));
    memcpy(lbl_txt_3, &temp_sub2_buf[llbl_num_3-1],sizeof(temp_sub2_buf[llbl_num_3-1]));
    memcpy(lbl_txt_4, &temp_sub2_buf[llbl_num_4-1],sizeof(temp_sub2_buf[llbl_num_4-1]));
    memcpy(lbl_txt_5, &temp_sub2_buf[llbl_num_5-1],sizeof(temp_sub2_buf[llbl_num_5-1]));

    ui->label_txt_6->setText(QString::fromUtf8(lbl_txt));
    ui->label_txt_7->setText(QString::fromUtf8(lbl_txt_2));
    ui->label_txt_8->setText(QString::fromUtf8(lbl_txt_3));
    ui->label_txt_9->setText(QString::fromUtf8(lbl_txt_4));
    ui->label_txt_10->setText(QString::fromUtf8(lbl_txt_5));

    if(lbl_txt[0])
    {
         ui->label_num_6->setNum(llbl_num);
    }
    else
    {
         ui->label_num_6->setText(NULL);
    }

    if(lbl_txt_2[0])
    {
       ui->label_num_7->setNum(llbl_num_2);
    }
    else
    {
        ui->label_num_7->setText(NULL);
    }

    if(lbl_txt_3[0])
    {
         ui->label_num_8->setNum(llbl_num_3);
    }
    else
    {
         ui->label_num_8->setText(NULL);
    }

    if(lbl_txt_4[0])
    {
        ui->label_num_9->setNum(llbl_num_4);
    }
    else
    {
         ui->label_num_9->setText(NULL);
    }

    if(lbl_txt_5[0])
    {
       ui->label_num_10->setNum(llbl_num_5);
    }
    else
    {
         ui->label_num_10->setText(NULL);
    }
#endif

}

void p15_setpara_sub2_dialog::update_hmi_page_index()
{   
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
    if(hmi_page_index != PAGEINDEX_SETPAGE_TWO)
    {
        exit_page_dlg();
    }
    else
    {

    }
}

void p15_setpara_sub2_dialog::call_p14_dlg()
{
    /*
    timer->stop();
    if(p14_dlg){
            delete p14_dlg;
            p14_dlg = NULL;
            handle_dlg_p14--;
    }
    p14_dlg = new  p14_setpara_sub1_dialog;
    p14_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p14++;

    connect(this,SIGNAL(signal_enable_p14dlg_timer()),p14_dlg,SLOT(init_page_dlg()));
    connect(p14_dlg,SIGNAL(signal_exit_p14dlg()),this,SLOT(exit_page_dlg()));

    emit signal_enable_p14dlg_timer();

    p14_dlg->exec();
    */   
    timer->stop();
    emit signal_timer_p15dlg();
    //init_page_val();
   // delete ui->pbtn_down;
   // ui->pbtn_down=NULL;
    delete p15_dlg;
    p15_dlg = NULL;
}

void p15_setpara_sub2_dialog::call_p16_dlg()
{
    timer->stop();
    if(p16_dlg){
            delete p16_dlg;
            p16_dlg = NULL;
            handle_dlg_p16--;
    }
    p16_dlg = new  p16_setpara_sub3_dialog;
    p16_dlg->setWindowFlags(Qt::FramelessWindowHint);
    handle_dlg_p16++;

    connect(this,SIGNAL(signal_enable_p16dlg_timer()),p16_dlg,SLOT(init_page_dlg()));
    connect(p16_dlg,SIGNAL(signal_exit_p16dlg()),this,SLOT(exit_page_dlg()));
    connect(p16_dlg,SIGNAL(signal_timer_p16dlg()),this,SLOT(start_timer()));
    emit signal_enable_p16dlg_timer();

    p16_dlg->exec();
}

void p15_setpara_sub2_dialog::exit_page_dlg()
{
    DebugMsg(hmilev,8,"exit_page_dlg\n");
    init_page_val();
    timer->stop();
    emit signal_exit_p15dlg();
}


void p15_setpara_sub2_dialog::on_btn_1_clicked()
{
  num_15=1;

}
void p15_setpara_sub2_dialog::on_btn_3_clicked()
{
  num_15=2;

}
void p15_setpara_sub2_dialog::on_btn_4_clicked()
{
  num_15=3;

}
void p15_setpara_sub2_dialog::on_btn_5_clicked()
{
  num_15=4;

}
void p15_setpara_sub2_dialog::on_btn_6_clicked()
{
  num_15=5;

}
void p15_setpara_sub2_dialog::on_btn_7_clicked()
{
  num_15=6;

}

void p15_setpara_sub2_dialog::on_pbtn_num0_clicked()
{
    switch(num_15)
    {
        case 1:
        if(farip_flg)
        {
            memset(farip,0,sizeof(farip));
            farip_flg=FALSE;
        }
            farip[farip_len++]='0';
            break;

        case 2:
        if(port_flg)
        {
            memset(art,0,sizeof(art));
            port_flg=FALSE;
        }
              art[art_len++]='0';
               break;

        case 3:
        if(localip_flg)
        {
            memset(localip,0,sizeof(localip));
            localip_flg=FALSE;
        }
                  localip[localip_len++]='0';
                   break;

        case 4:
        if(mask_flg)
        {
            memset(ma,0,sizeof(ma));
            mask_flg=FALSE;
        }
                  ma[ma_len++]='0';
                   break;

        case 5:
        if(guan_flg)
        {
            memset(guan,0,sizeof(guan));
            guan_flg=FALSE;
        }
                  guan[guan_len++]='0';
                   break;

        case 6:
        if(mac_flg)
        {
            memset(mac,0,sizeof(mac));
            mac_flg=FALSE;
        }
                  mac[mac_len++]='0';
                   break;
       // default:

                //

    }



}

void p15_setpara_sub2_dialog::on_pbtn_num1_clicked()
{
     switch(num_15)
    {
     case 1:
     if(farip_flg)
     {
         memset(farip,0,sizeof(farip));
         farip_flg=FALSE;
     }
         farip[farip_len++]='1';
         break;

     case 2:
     if(port_flg)
     {
         memset(art,0,sizeof(art));
         port_flg=FALSE;
     }
           art[art_len++]='1';
            break;

     case 3:
     if(localip_flg)
     {
         memset(localip,0,sizeof(localip));
         localip_flg=FALSE;
     }
               localip[localip_len++]='1';
                break;

     case 4:
     if(mask_flg)
     {
         memset(ma,0,sizeof(ma));
         mask_flg=FALSE;
     }
               ma[ma_len++]='1';
                break;

     case 5:
     if(guan_flg)
     {
         memset(guan,0,sizeof(guan));
         guan_flg=FALSE;
     }
               guan[guan_len++]='1';
                break;
     case 6:
     if(mac_flg)
     {
         memset(mac,0,sizeof(mac));
         mac_flg=FALSE;
     }
               mac[mac_len++]='1';
                break;

        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num2_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='2';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='2';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='2';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='2';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='2';
               break;

    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='2';
               break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num3_clicked()
{
     switch(num_15)
    {
     case 1:
     if(farip_flg)
     {
         memset(farip,0,sizeof(farip));
         farip_flg=FALSE;
     }
         farip[farip_len++]='3';
         break;

     case 2:
     if(port_flg)
     {
         memset(art,0,sizeof(art));
         port_flg=FALSE;
     }
           art[art_len++]='3';
            break;

     case 3:
     if(localip_flg)
     {
         memset(localip,0,sizeof(localip));
         localip_flg=FALSE;
     }
               localip[localip_len++]='3';
                break;

     case 4:
     if(mask_flg)
     {
         memset(ma,0,sizeof(ma));
         mask_flg=FALSE;
     }
               ma[ma_len++]='3';
                break;

     case 5:
     if(guan_flg)
     {
         memset(guan,0,sizeof(guan));
         guan_flg=FALSE;
     }
               guan[guan_len++]='3';
                break;
     case 6:
     if(mac_flg)
     {
         memset(mac,0,sizeof(mac));
         mac_flg=FALSE;
     }
               mac[mac_len++]='3';
                break;
       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num4_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='4';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='4';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='4';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='4';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='4';
               break;
    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='4';
               break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num5_clicked()
{
     switch(num_15)
    {
     case 1:
     if(farip_flg)
     {
         memset(farip,0,sizeof(farip));
         farip_flg=FALSE;
     }
         farip[farip_len++]='5';
         break;

     case 2:
     if(port_flg)
     {
         memset(art,0,sizeof(art));
         port_flg=FALSE;
     }
           art[art_len++]='5';
            break;

     case 3:
     if(localip_flg)
     {
         memset(localip,0,sizeof(localip));
         localip_flg=FALSE;
     }
               localip[localip_len++]='5';
                break;

     case 4:
     if(mask_flg)
     {
         memset(ma,0,sizeof(ma));
         mask_flg=FALSE;
     }
               ma[ma_len++]='5';
                break;

     case 5:
     if(guan_flg)
     {
         memset(guan,0,sizeof(guan));
         guan_flg=FALSE;
     }
               guan[guan_len++]='5';
                break;

     case 6:
     if(mac_flg)
     {
         memset(mac,0,sizeof(mac));
         mac_flg=FALSE;
     }
               mac[mac_len++]='5';
                break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num6_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='6';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='6';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='6';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='6';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='6';
               break;

    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='6';
               break;
        //default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num7_clicked()
{

    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='7';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='7';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='7';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='7';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='7';
               break;
    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='7';
               break;

       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num8_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='8';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='8';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='8';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='8';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='8';
               break;

    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='8';
               break;
       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_num9_clicked()
{
    switch(num_15)
    {
    case 1:
    if(farip_flg)
    {
        memset(farip,0,sizeof(farip));
        farip_flg=FALSE;
    }
        farip[farip_len++]='9';
        break;

    case 2:
    if(port_flg)
    {
        memset(art,0,sizeof(art));
        port_flg=FALSE;
    }
          art[art_len++]='9';
           break;

    case 3:
    if(localip_flg)
    {
        memset(localip,0,sizeof(localip));
        localip_flg=FALSE;
    }
              localip[localip_len++]='9';
               break;

    case 4:
    if(mask_flg)
    {
        memset(ma,0,sizeof(ma));
        mask_flg=FALSE;
    }
              ma[ma_len++]='9';
               break;

    case 5:
    if(guan_flg)
    {
        memset(guan,0,sizeof(guan));
        guan_flg=FALSE;
    }
              guan[guan_len++]='9';
               break;
    case 6:
    if(mac_flg)
    {
        memset(mac,0,sizeof(mac));
        mac_flg=FALSE;
    }
              mac[mac_len++]='9';
               break;
       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_dot_clicked()
{
   switch(num_15)
    {
   case 1:
   if(farip_flg)
   {
       memset(farip,0,sizeof(farip));
       farip_flg=FALSE;
   }
       farip[farip_len++]='.';
       break;

   case 2:
   if(port_flg)
   {
       memset(art,0,sizeof(art));
       port_flg=FALSE;
   }
         art[art_len++]='.';
          break;

   case 3:
   if(localip_flg)
   {
       memset(localip,0,sizeof(localip));
       localip_flg=FALSE;
   }
             localip[localip_len++]='.';
              break;

   case 4:
   if(mask_flg)
   {
       memset(ma,0,sizeof(ma));
       mask_flg=FALSE;
   }
             ma[ma_len++]='.';
              break;

   case 5:
   if(guan_flg)
   {
       memset(guan,0,sizeof(guan));
       guan_flg=FALSE;
   }
             guan[guan_len++]='.';
              break;
   case 6:
   if(mac_flg)
   {
       memset(mac,0,sizeof(mac));
       mac_flg=FALSE;
   }
             mac[mac_len++]='.';
              break;

       // default:

                //

    }
}

void p15_setpara_sub2_dialog::on_pbtn_back_clicked()
{
        switch(num_15)
        {
        case 1:

            if(farip_len>0)
            {
                farip_len--;
                farip[farip_len]=0;
            }
            else
            {
                farip_len=0;
            }
        break;

        case 2:
        if(art_len>0)
        {
            art_len--;
            art[art_len]=0;
        }
        else
        {
            art_len=0;
        }
        break;

        case 3:
        if(localip_len>0)
        {
            localip_len--;
            localip[localip_len]=0;
        }
        else
        {
            localip_len=0;
        }
        break;

        case 4:
        if(ma_len>0)
        {
            ma_len--;
            ma[ma_len]=0;
        }
        else
        {
            ma_len=0;
        }
        break;

        case 5:
        if(guan_len>0)
        {
            guan_len--;
            guan[guan_len]=0;
        }
        else
        {
            guan_len=0;
        }
        break;

        case 6:
        if(mac_len>0)
        {
            mac_len--;
            mac[mac_len]=0;
        }
        else
        {
            mac_len=0;
        }
        break;

        default:
        break;
        //

    }

}

void p15_setpara_sub2_dialog::on_pbtn_up_clicked()
{

     DebugMsg(hmilev,5,"on_pbtn_up_clicked\n");

    hmi_button_dn_num=PAGEUP_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}

void p15_setpara_sub2_dialog::on_pbtn_down_clicked()
{

     DebugMsg(hmilev,5,"on_pbtn_down_clicked\n");

     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"serverip");
     if(farip_len>0)
     {
         write_profile_string(Section_name,Key_name,farip,config_path);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
     Inibuf_init(Key_name,BUFFERLEN_32,"serverport");
     if(art_len>0)
     {
         write_profile_string(Section_name,Key_name,art,config_path);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     static char buf_sys[64]={};

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"ipaddr");
     if(localip_len>0)
     {
         write_profile_string(Section_name,Key_name,localip,config_path);
         sprintf(buf_sys,"ifconfig eth0 %s",localip);
         system(buf_sys);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"mask");
     if(ma_len>0)
     {
         write_profile_string(Section_name,Key_name,ma,config_path);
         sprintf(buf_sys,"ifconfig eth0 netmask %s",ma);
         system(buf_sys);
     }
     else
     {
          //ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"getway");
     if(guan_len>0)
     {
         write_profile_string(Section_name,Key_name,guan,config_path);
         sprintf(buf_sys,"route add default gw %s",guan);
         system(buf_sys);
     }
     else
     {
         // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

     Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
     Inibuf_init(Key_name,BUFFERLEN_32,"sysmac");
     if(mac_len>0)
     {
         write_profile_string(Section_name,Key_name,mac,config_path);
        // sprintf(buf_sys,"ifconfig eth0 netmask %s",mac);
        // system(buf_sys);
     }
     else
     {
         // ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
     }

    hmi_button_dn_num=PAGEDOWN_BUTTON ;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}

void p15_setpara_sub2_dialog::on_pbtn_go_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_cancel_clicked\n");

    //btn_passwd_pos=0;
    //memset(btn_passwd,0,sizeof(btn_passwd));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


}

void p15_setpara_sub2_dialog::on_pbtn_ok_clicked()
{

    DebugMsg(hmilev,5,"on_pbtn_enter_clicked\n");

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"serverip");
    if(farip_len>0)
    {
        write_profile_string(Section_name,Key_name,farip,config_path);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"SYSTEMINFOR");
    Inibuf_init(Key_name,BUFFERLEN_32,"serverport");
    if(art_len>0)
    {
        write_profile_string(Section_name,Key_name,art,config_path);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    static char buf_sys[64]={};

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"ipaddr");
    if(localip_len>0)
    {
        write_profile_string(Section_name,Key_name,localip,config_path);
        sprintf(buf_sys,"ifconfig eth0 %s",localip);
        system(buf_sys);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"mask");
    if(ma_len>0)
    {
        write_profile_string(Section_name,Key_name,ma,config_path);
        sprintf(buf_sys,"ifconfig eth0 netmask %s",ma);
        system(buf_sys);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"getway");
    if(guan_len>0)
    {
        write_profile_string(Section_name,Key_name,guan,config_path);
        sprintf(buf_sys,"route add default gw %s",guan);
        system(buf_sys);
    }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }

    Inibuf_init(Section_name,BUFFERLEN_32,"NETWORK");
    Inibuf_init(Key_name,BUFFERLEN_32,"sysmac");
    if(mac_len>0)
    {
        write_profile_string(Section_name,Key_name,mac,config_path);
/*
        system("ifconfig eth0 down");
        memset(buf_sys,0,100);
        snprintf(buf_sys,100,"ifconfig eth0 hw  ether %s",mac);
        system(buf_sys);
        system("ifconfig eth0 up");
  */
  }
    else
    {
         ErrMsg("hmi_page_index error[%d]\n",hmi_page_index);
    }
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));


    //API_Write_DB_Nbyte(PL_HMI_CARD_PASSWD,(INT8 *)(&btn_passwd),sizeof(btn_passwd));
}
