//119. Pascal's Triangle II 
//这一题需要注意是索引，从0开始，只用o(k)空间，可以迭代替换tmp = res;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res,tmp;
        if(rowIndex < 0)
            return res;
        for(int i=0;i<=rowIndex;i++)
        {
            res.push_back(1);
            for(int j = 1;j < i;j++)
                res.push_back(tmp[j-1] + tmp[j]);
            if(i != 0)
                res.push_back(1);
            tmp = res;          //tihuan
            res.clear();
        }
        return tmp;
    }
};