#include<iostream.h>
int ktra(double x)
{
	double tg=(int)x;
	if(x-tg==0) return 1;
	else return 0;
}

void main()
{
	float x=0,z=0;
	while(z*50<=2000)
	{
		int a=2000-z*50;
      cout<<a<<endl;
		while(x*10<=a)
		{
			x+=1;
			float tg=(float)((a-x*10)/20);
			if(ktra(tg)==1)
				cout<<"can "<<x<<" to 10k , "<<tg<<" to 20k "<<z<<" to 50k"<<endl;
		}
		z+=1;
		x=0;
	}
}
