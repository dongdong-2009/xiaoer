#include "dialog_carnum.h"
#include "ui_dialog_carnum.h"
#include "globalhmi.h"

#define MAX_CARNUM   50
#define BYTE_5                5
#define BYTE_4                4
#define BYTE_2                2
Dialog_carnum::Dialog_carnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_carnum)
{
    ui->setupUi(this);
}

Dialog_carnum::~Dialog_carnum()
{
    delete ui;
}

void Dialog_carnum::init_page_dlg()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timer_handle()));
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
    btn_press();
}

char buf_GB[40][BYTE_5]={"BEA9","BDF2","BCBD","BBA6","D4C1","CDEE","CBD5","D5E3","C2B3","B6F5"};

char buf_change1[40][BYTE_4]={"京","津","冀","沪","粤","皖","苏","浙","鲁","鄂",
                        "黑","吉","辽","晋","渝","闽","赣","豫","湘","桂",
                        "云","贵","川","陕","蒙","甘","琼","藏","青","宁",
                        "新","港","澳","台"};
char buf_change2[30][BYTE_2]={"A","B","C","D","E","F","G","H","I","J",
                         "K","L","M","N","O","P","Q","R","S","T",
                         "U","V","W","X","Y","Z"};
char buf_change3[10][BYTE_2]={"1","2","3","4","5","6","7","8","9","0"};

int change1_num_add=0;
int change2_num_add=0;
int change3_num_add=0;

void Dialog_carnum::on_pbtn_change1_clicked()
{
    change_carnum=1;
    change1_num_add=0;
}

void Dialog_carnum::on_pbtn_change2_clicked()
{
    change_carnum=2;
    change2_num_add=0;
}

void Dialog_carnum::on_pbtn_change3_clicked()
{
    change_carnum=3;
    change3_num_add=0;
}

void Dialog_carnum::on_pbtn_num1_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add]);
                strcat(gb_buf,buf_GB[change1_num_add]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add]);
                strcat(gb_buf,buf_change2[change2_num_add]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add]);
                strcat(gb_buf,buf_change3[change3_num_add]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num2_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+1]);
                strcat(gb_buf,buf_GB[change1_num_add+1]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+1]);
                strcat(gb_buf,buf_change2[change2_num_add+1]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+1]);
                strcat(gb_buf,buf_change3[change3_num_add+1]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num3_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+2]);
                strcat(gb_buf,buf_GB[change1_num_add+2]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+2]);
                   strcat(gb_buf,buf_change2[change2_num_add+2]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+2]);
                   strcat(gb_buf,buf_change3[change3_num_add+2]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num4_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+3]);
                  strcat(gb_buf,buf_GB[change1_num_add+3]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+3]);
                 strcat(gb_buf,buf_change2[change2_num_add+3]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+3]);
                 strcat(gb_buf,buf_change3[change3_num_add+3]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num5_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+4]);
                  strcat(gb_buf,buf_GB[change1_num_add+4]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+4]);
                   strcat(gb_buf,buf_change2[change2_num_add+4]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+4]);
                   strcat(gb_buf,buf_change3[change3_num_add+4]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num6_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+5]);
                 strcat(gb_buf,buf_GB[change1_num_add+5]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+5]);
                strcat(gb_buf,buf_change2[change2_num_add+5]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+5]);
                  strcat(gb_buf,buf_change3[change3_num_add+5]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num7_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+6]);
                  strcat(gb_buf,buf_GB[change1_num_add+6]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+6]);
                 strcat(gb_buf,buf_change2[change2_num_add+6]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+6]);
                strcat(gb_buf,buf_change3[change3_num_add+6]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num8_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+7]);
                strcat(gb_buf,buf_GB[change1_num_add+7]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+7]);
                  strcat(gb_buf,buf_change2[change2_num_add+7]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+7]);
                 strcat(gb_buf,buf_change3[change3_num_add+7]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num9_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+8]);
                  strcat(gb_buf,buf_GB[change1_num_add+8]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+8]);
                  strcat(gb_buf,buf_change2[change2_num_add+8]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+8]);
                   strcat(gb_buf,buf_change3[change3_num_add+8]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::on_pbtn_num0_clicked()
{
    if(carnum_len>=MAX_CARNUM)
    {
        carnum_len=MAX_CARNUM;
    }
    else
    {
        if(change_carnum == 1)
        {
                strcat(carnum_buf,buf_change1[change1_num_add+9]);
                  strcat(gb_buf,buf_GB[change1_num_add+9]);
                carnum_len += BYTE_4;
        }
        else if(change_carnum == 2)
        {
                strcat(carnum_buf,buf_change2[change2_num_add+9]);
                  strcat(gb_buf,buf_change2[change2_num_add+9]);
                carnum_len += BYTE_2;
        }
        else if(change_carnum == 3)
        {
                strcat(carnum_buf,buf_change3[change3_num_add+9]);
                strcat(gb_buf,buf_change3[change3_num_add+9]);
                carnum_len += BYTE_2;
        }
    }
}

void Dialog_carnum::init_page_val()
{

    memset(gb_buf,0,sizeof(gb_buf));
    memset(carnum_buf,0,sizeof(carnum_buf));
    carnum_len = 0;
    change_carnum=1;
    ui->label_stubnum->setText(QString::fromUtf8("桩编号："));
    ui->label_phone->setText(QString::fromUtf8("客服热线："));
    ui->label_code->setText(code);
    ui->label_num1->setText(phonenum);
    ui->label_num2->setText(phonenum_2);
    UINT8 data = NO_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&data),sizeof(data));
}

void Dialog_carnum::start_timer()
{
    timer->start(PAGE_FLUSH_TIMER);
    init_page_val();
}

static int  num_add_end = 0;
void Dialog_carnum::timer_handle()
{
    update_page_info();
    update_hmi_page_index();
}

void Dialog_carnum::btn_press()
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

void Dialog_carnum::update_page_info()
{
    QPushButton* array[10]={0};
    array[0] = ui->pbtn_num1;
    array[1] = ui->pbtn_num2;
    array[2] = ui->pbtn_num3;
    array[3] = ui->pbtn_num4;
    array[4] = ui->pbtn_num5;
    array[5] = ui->pbtn_num6;
    array[6] = ui->pbtn_num7;
    array[7] = ui->pbtn_num8;
    array[8] = ui->pbtn_num9;
    array[9] = ui->pbtn_num0;
    int num_add = 0;
    switch(change_carnum)
    {
        case 1:
            for(num_add;num_add<10;num_add++)
            {
                array[num_add]->setText(QString::fromUtf8(buf_change1[change1_num_add+num_add]));
            }
            break;
        case 2:
            for(num_add;num_add<10;num_add++)
            {
                array[num_add]->setText(buf_change2[change2_num_add+num_add]);
            }
            break;
        case 3:
            for(num_add;num_add<10;num_add++)
            {
                array[num_add]->setText(buf_change3[change3_num_add+num_add]);
            }
            break;
        default:
            break;
    }

    ui->label_carnum->setText(QString::fromUtf8(carnum_buf));

    char temp_flag = 0;
    API_Read_DB_Nbyte(PL_CHRPASSWRDERR_FLAG,(INT8 *)(&temp_flag),sizeof(temp_flag));
    if(temp_flag == 1)
    {
        ui->label_speaker->setText(QString::fromUtf8("车牌验证中。。。"));
    }
    else if(temp_flag == 2)
    {
        ui->label_speaker->setText(QString::fromUtf8("车牌验证失败"));
    }
    else
    {
        ui->label_speaker->setText("");
    }
}

void Dialog_carnum::update_hmi_page_index(void)
{
    API_Read_DB_Nbyte(PL_HMI_PAGE_INDEX,(INT8 *)(&hmi_page_index),sizeof(hmi_page_index));
   if(hmi_page_index != PAGEINDEX_CARNUM)
   {
       exit_page_dlg();
   }
   else
   {

   }
}

void Dialog_carnum::exit_page_dlg()
{
    init_page_val();
    timer->stop();
    emit  signal_exit_dlg();
    //delete end_dlg;
    //end_dlg = NULL;
}

void Dialog_carnum::on_pbtn_dot_clicked()
{

}

void Dialog_carnum::on_pbtn_back_clicked()
{
    if(carnum_len <= 0)
    {
        carnum_len = 0;
    }
    else
    {
        if(change_carnum==1)
        {
            memset( carnum_buf,0,sizeof( carnum_buf));
             memset( gb_buf,0,sizeof( gb_buf));
            carnum_len = 0;
        }
        else
        {
            carnum_len=strlen(carnum_buf);
            carnum_len--;
            memset( &carnum_buf[carnum_len],0,2);
            memset( &gb_buf[carnum_len],0,2);
        }
    }
}

void Dialog_carnum::on_pbtn_down_clicked()
{
    switch(change_carnum)
    {
        case 1:
        if(change1_num_add <30)
        {
            change1_num_add+=10;
        }
        break;
        case 2:
        if(change2_num_add <20)
        {
            change2_num_add+=10;
        }
        break;
        case 3:
        if(change3_num_add <10)
        {
            //change3_num_add+=10;
        }
        break;
        default:
        break;
    }
}

void Dialog_carnum::on_pbtn_up_clicked()
{
    switch(change_carnum)
    {
        case 1:
        if(change1_num_add >0)
        {
            change1_num_add-=10;
        }
        break;
        case 2:
        if(change2_num_add >0)
        {
            change2_num_add-=10;
        }
        break;
        case 3:
        if(change3_num_add >0)
        {
            //change3_num_add-=10;
        }
        break;
        default:
        break;
    }
}

void Dialog_carnum::on_pbtn_ok_clicked()
{
     API_Write_DB_Nbyte(PL_HMI_CAR_NUM,(INT8 *)(&gb_buf),sizeof(gb_buf));
    hmi_button_dn_num=OK_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}

void Dialog_carnum::on_pbtn_go_clicked()
{
    carnum_len=0;
    memset(carnum_buf,0,sizeof(carnum_buf));

    hmi_button_dn_num=CANCEL_BUTTON;
    API_Write_DB_Nbyte(PL_HMI_BUTTON_DOWN,(INT8 *)(&hmi_button_dn_num),sizeof(hmi_button_dn_num));
}
