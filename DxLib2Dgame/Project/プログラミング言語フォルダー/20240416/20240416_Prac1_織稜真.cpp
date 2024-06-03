#include <stdio.h>
int main(void)
{
    int r = 5;              //”¼Œa
    double p = 3.14f;       //‰~ü—¦
    double L = 2 * r * p;   //‰~ü
    double S = r * r * p;   //‰~‚Ì–ÊÏ

    int x = 10;             //c
    int y = 15;             //‰¡

    printf("‰~ü%f,‰~‚Ì–ÊÏ%f\n", L,S);   //‰~ü‚Æ–ÊÏ‚Ì•\¦
    printf("’·•ûŒ`‚Ì–ÊÏ%d\n", x * y);    //–ÊÏŒvZ‚Æ•\¦
    return 0;
}