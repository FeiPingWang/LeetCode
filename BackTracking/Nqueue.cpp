#include <iostream>
#include <vector>

using namespace std;

class Queens {
public:
    int nQueens(int n) {
        // write code here
		vector<int> col(n,0);
		int res = 0;
		helper(col,n,0,res);
		return res;
    }
	
	void helper(vector<int>& col,int n,int k,int& res)
	{
		if(k >= n)
		{
			res++;
			return;
		}
		for(int i = 0;i < n;i++)	//0到n列
		{
			if(isCanPlace(col,k,i))	//可以放置
			{
				col[k] = i;
				helper(col,n,k+1,res);
			}
		}
	}
	
	bool isCanPlace(vector<int>& col,int k,int c){
		for(int i = 0;i<k;i++)
		{
			if(col[i] == c || (abs(c - col[i]) == abs(k-i)))
				return false;
		}
		return true;
	}
};

int main(void){
	Queens q;
	int n ;
	cin >> n;
	cout << q.nQueens(n) << endl;
}