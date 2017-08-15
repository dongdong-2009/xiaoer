#ifndef P18_SETPARA_SUB5_DIALOG_H
#define P18_SETPARA_SUB5_DIALOG_H

#include <QDialog>

namespace Ui {
    class p18_setpara_sub5_dialog;
}

class p18_setpara_sub5_dialog : public QDialog {
    Q_OBJECT
public:
    p18_setpara_sub5_dialog(QWidget *parent = 0);
    ~p18_setpara_sub5_dialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::p18_setpara_sub5_dialog *ui;

private:
        QTimer *timer;
        float ft1;
        float ft2;
        float fp1;
        float fp2;
        float ff1;
        float ff2;
        float fg1;
        float fg2;
        float ft1_1;
        float ft2_1;
        float fp1_1;
        float fp2_1;
        float ff1_1;
        float ff2_1;
        float fg1_1;
        float fg2_1;

private slots:
        void init_page_dlg(void);
        void init_page_val(void);
        void start_timer(void);
        void timer_handle(void);
        void exit_page_dlg(void);
        void call_p24_dlg(void);

private:
    void update_page_info(void);
    void update_hmi_page_index(void);

private slots:

    void on_pbtn_ok_clicked();
    void on_pbtn_up_clicked();

signals:

    void signal_timer_p18dlg();
    void signal_exit_p18dlg();
};

#endif
