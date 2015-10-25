#include<windows.h>
#include<iostream>
using namespace std;

int main( int argc, char *argv[] )
{
    int ans=MessageBox(NULL,"Ban co muon tiep tuc khong?","Thong bao",MB_YESNO);
    switch(ans)
    {
        case IDYES:cout<<"yes";break;
        case IDNO:cout<<"no";break;
    }

}
