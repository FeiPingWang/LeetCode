class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        if(len < 2)
            return 0;
        int mask[len];
        int Max = 0;
        int temp;
        memset(mask,0,sizeof(mask));
        for(int i = 0;i<len;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                int bit = words[i][j] - 'a';
                mask[i] |= 1 << bit;
            }
        }
        
        for(int i = 0;i<len;i++)
        {
            for(int j = 0;j<len;j++)
            {
                if(mask[i] & mask[j])
                    continue;
                if((temp = words[i].size() * words[j].size()) > Max)
                    Max = temp;
                
            }
        }
        return Max;
    }
};
