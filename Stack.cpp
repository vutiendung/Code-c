#include <stdio.h>
#include <stdlib.h>

class Stack
{
	public:
		int cout;
		Stack()
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
				int result = *(arr + (cout - 1));
				cout--;
				arr = (int*)realloc(arr,cout*sizeof(int));
				return result;
			}
		}
	private:
		int *arr;

};