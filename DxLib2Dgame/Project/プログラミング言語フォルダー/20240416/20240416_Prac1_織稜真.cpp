#include <stdio.h>
int main(void)
{
    int r = 5;              //���a
    double p = 3.14f;       //�~����
    double L = 2 * r * p;   //�~��
    double S = r * r * p;   //�~�̖ʐ�

    int x = 10;             //�c
    int y = 15;             //��

    printf("�~��%f,�~�̖ʐ�%f\n", L,S);   //�~���Ɩʐς̕\��
    printf("�����`�̖ʐ�%d\n", x * y);    //�ʐόv�Z�ƕ\��
    return 0;
}