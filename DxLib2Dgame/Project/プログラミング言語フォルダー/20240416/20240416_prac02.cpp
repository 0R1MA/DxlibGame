#include <stdio.h>
int main(void)
{
    int a = 10;                     //ฎ
    long b = 123455678;             //{ธxฎ
    float c = 10.5f;                //ฎญ_
    double d = 3.14159265358979;    //{ฎญ_
    //Char^@ถ^

    printf("a=%f, b=%d \n",(float) (a)+c, b);
    printf("c=%f, d=%f \n", c, d);
    return 0;
}