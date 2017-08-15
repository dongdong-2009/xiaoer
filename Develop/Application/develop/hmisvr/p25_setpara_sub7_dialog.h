#ifndef P25_SETPARA_SUB7_DIALOG_H
#define P25_SETPARA_SUB7_DIALOG_H

#include <QDialog>

namespace Ui {
class p25_setpara_sub7_dialog;
}

class p25_setpara_sub7_dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit p25_setpara_sub7_dialog(QWidget *parent = 0);
    ~p25_setpara_sub7_dialog();
    
private:
    Ui::p25_setpara_sub7_dialog *ui;

protected:
    void changeEvent(QEvent *e);

private:
    QTimer *timer;
    int line_check;

private slots:
    void init_page_dlg(void);
    void init_page_val(void);
    void start_timer(void);
    void timer_handle(void);
    void exit_page_dlg(void);
    void btn_press(void);


    void on_pbtn_ok_clicked();
    void on_pbtn_go_clicked();
    void on_pbtn_up_clicked();
    void on_pbtn_down_clicked();

    void on_yidong_2g_btn_clicked();

    //void on_yidong_3g_btn_clicked();

    void on_yidong_4g_btn_clicked();

    void on_liantong_2g_btn_clicked();

    void on_liantong_3g_btn_clicked();

    void on_liantong_4g_btn_clicked();

    //void on_dianxin_2g_btn_clicked();

    void on_dianxin_3g_btn_clicked();

    void on_dianxin_4g_btn_clicked();

    void on_wifi_btn_clicked();

    void on_online_btn_clicked();

    //void on_toserialport_btn_clicked();

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

signals:

    void signal_timer_p16dlg();
    
    void signal_exit_p25dlg();
};

#endif // P25_SETPARA_SUB7_DIALOG_H
