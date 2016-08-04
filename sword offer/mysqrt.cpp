#include <stdio.h>


int mySqrt(int x) {
        if(x < 0 )
            return 0x80000000;
        int l = 1;
        int r = x;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            if(mid > x/mid)
                r = mid-1;
            else if(mid == x/mid)
               return l;
			else
				l = mid+1;
        }
        return l-1;
        
}

int main(void)
{
	int n = 8;
	mySqrt(8);
	return 0;
}