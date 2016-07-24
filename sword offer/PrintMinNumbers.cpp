#include <iostream>
#include <unistd.h>
#include <memory.h>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
        int hash[length];
		memset(hash,0,sizeof(hash));
        bool res = false;
        for(int i = 0;i<length;i++)
       	{
            if(hash[numbers[i]] == 1)
            {
                *duplication = numbers[i];
                res = true;
                break;
            }
            else
            	hash[numbers[i]]++;
        }
        return res;
   }
   
   int main(void)
   {
	   int *duplication = new int;
	   int numbers[8]={2,3,1,0,2,5,3};
	   cout << duplicate(numbers,7,duplication)<<endl;
	   cout << *duplication << endl;
	   return 0;
   }