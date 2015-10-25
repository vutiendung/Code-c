#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

int a[200];
int main()
{
    //random mang va gia tri
    int i;
    srand(time(NULL));// dung ham nay de random khong bi lap lai
    for (i=0;i<200;i++)
        a[i]=rand();
    i=100;
    a[i]=rand()% (100-0+1)+0;
    int j=0;
    while(i<=120)
    {
        a[i+1]=a[i]+1;
        i++;
    }
    //tim day con lon nhat co gia ti lien tiep nhau
    int max=0,start=0,end=0;
    for(i=0;i<200;)
    {
            int dem=0;
            j=i;
            while(a[j]==a[j+1]-1)
            {
                j++;
                dem++;
            }
            if(dem>max)
            {
                start=i;
                end=i+dem;
                max=dem;
            }
            else //nhay luon toi cuoi doan neu day con nay khong phai day lon nhat.
                if(dem>0)
                {
                    i=j;
                }
            i++;
    }
    //in day con lon nhat co gia ti lien tiep nhau
    if(max>0)
        for(i=start;i<=end;i++)
            cout<<a[i]<<" ";

}
