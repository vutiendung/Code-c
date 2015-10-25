#include <stdio.h>
#include <stdlib.h>

class Queue
{
	public:
		int *arr;
		int cout;
		Queue()
		{
			cout = 0;
		}
		void Add(int i)
		{
			if(cout == 0)
			{
				arr = new int;
				cout ++;
				*(arr + (cout - 1)) = i;
			}
			else
			{
				cout ++;
				arr = (int*)realloc(arr,cout*sizeof(int));
				*(arr + (cout - 1)) = i;
			}

		}
		int Get()
		{
			if(cout > 0)
			{
				int result = *(arr + 0);
				for(int i =0; i < cout - 1; i++)
				{
					*(arr + i) = *(arr +(i + 1));
				}
				cout--;
				arr = (int*)realloc(arr,cout*sizeof(int));
				return result;
			}
		}

};