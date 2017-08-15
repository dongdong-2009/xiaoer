#ifndef SIGNAL_C_H
#define SIGNAL_C_H



int singalfun()
{
    while(1)
    {
        printf("get signal SIGTERM In HMI\r\n");
        sleep(5000);
    }
}

#ifdef __cplusplus
extern "C" {
#endif
void signal_c()
{
           // signal(SIGTERM,singalfun);
}
#ifdef __cplusplus
}
#endif


#endif // SIGNAL_C_H

