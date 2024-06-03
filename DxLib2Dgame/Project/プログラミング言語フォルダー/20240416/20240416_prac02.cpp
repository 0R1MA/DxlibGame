#include <stdio.h>
int main(void)
{
    int a = 10;                     //®”
    long b = 123455678;             //”{¸“x®”
    float c = 10.5f;                //•‚“®­”“_
    double d = 3.14159265358979;    //”{•‚“®­”“_
    //CharŒ^@•¶šŒ^

    printf("a=%f, b=%d \n",(float) (a)+c, b);
    printf("c=%f, d=%f \n", c, d);
    return 0;
}