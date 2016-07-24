#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0)
            return path;
        stack<string> st;
        int cur = 0;
        int length = path.size();
        while(cur < length)
        {
            while(path[cur] == '/' && cur < length) //跳过 '/'
                cur++;
            if(cur == length)
                break;
            int start = cur;    //开始
            while(path[cur] != '/' && cur < length)
                cur++;
            int end = cur-1;
            string element = path.substr(start,end-start+1);
            if(element == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(element != ".")
            {
                st.push(element);
            }
        }
        string res;
        while(!st.empty())
        {
            string tmp = st.top();
            st.pop();
            res.insert(0,tmp);
            res.insert(0,"/");
        }
        if(st.empty())
            return "/";
        return res;
    }
};

int main(void)
{
	Solution s;
	string str = "/...";
	string res = s.simplifyPath(str);
	cout << res << endl;
	return 0;
}

