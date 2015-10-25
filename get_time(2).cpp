#include<dos.h>
#include<iostream.h>
#include<conio.h>
#include<windows.h>


int main(void)
{
		struct time a;
		gettime(&a);
		cout<<"Bay gio la: ";
		if((int)a.ti_hour>12) cout<<(int)a.ti_hour-12<<":"<<(int)a.ti_min<<":"<<(int)a.ti_sec<<" PM";
			else  cout<<(int)a.ti_hour<<":"<<(int)a.ti_min<<":"<<(int)a.ti_sec<<" AM";
		if((int)a.ti_sec==59) break;
      clrscr();
		return 0;
}