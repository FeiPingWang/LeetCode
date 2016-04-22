
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1)
            return 0;
            
        int *m = new int[prices.size()];    //m用来存储最小值
        int *p = new int[prices.size()];
        m[0] = prices[0];
        p[0] = 0;
        for(int i = 1;i < prices.size(); i++)
        {
            if(prices[i] <= m[i-1])
            {
                m[i] = prices[i];
                p[i] = p[i-1];
            }
            else
            {
                m[i] = m[i-1];
                if(prices[i] - m[i-1] > p[i-1])
                    p[i] = prices[i] - m[i-1];
                else
                    p[i] = p[i-1];
            }
        }
        return p[prices.size()-1];
        
        
        
    }
};