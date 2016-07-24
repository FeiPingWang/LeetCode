#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 0)
			return false;
		vector<string> str;
		string tmp;
		for(int i = 0;i<preorder.size();i++)
		{
		    if(preorder[i] != ',')
		    {
		        tmp += preorder[i];
		    }
		    else
		    {
		        str.push_back(tmp);
		        tmp.clear();
		    }
		  
		}
		str.push_back(tmp);
		stack<string> st;
		for(int i = 0;i < str.size();i++)
		{
			st.push(str[i]);
			while(st.size() >= 3)
			{
				string t1 = st.top();
				st.pop();
				string t2 = st.top();
				st.pop();
				string t3 = st.top();
				st.pop();
				if(t1 == "#" && t2 == "#" && t3 != "#")
				{
				    st.push("#");
				  //  break;
				}
				else{
					st.push(t3);
					st.push(t2);
					st.push(t1);
					break;
				}
			}
		}
		if(st.size() == 1 && st.top() == "#")
			return true;
		return false;
    }
};

int main(void)
{
	Solution s;
	string preorder="9,#,92,#,#";
	cout << s.isValidSerialization(preorder) << endl;
	return  0;
}