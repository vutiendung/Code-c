#include <cstring>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>

int length(char s[254])
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

int main(void)
{
    char s[254];
    std::cout<<"Nhap chuoi vao: ";gets(s);
    int prev=0,totalPoint=0,i=0,current=0;
    while(i<length(s))
    {
        if(s[i]=='N' || s[i]=='n')
            prev=0;
        else
        {
            current=prev+1;
            prev=current;
            totalPoint+=current;
        }
        i++;
    }
    std::cout<<"Diem="<<totalPoint;
}
