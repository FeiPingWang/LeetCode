class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.size() == 0 || guess.size() == 0)
            return 0;
        int A=0,B=0;
        vector<int> vA(10),vB(10);
        for(int i = 0;i < guess.size();i++)
        {
            if(guess[i] == secret[i])
                A++;
            else
            {
                vA[guess[i]-'0']++;
                vB[secret[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++)
        {
            B += min(vA[i],vB[i]);          //important
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
};