class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<vector<int>> DP(np+1, vector<int>(ns+2, 0));
        DP[np][ns] = 1;
        
        for (int i=np-1; i>=0; i--){
            for (int j=ns; j>=0; j--){
                if (p[i]=='?' || (j!=ns && p[i]==s[j]))
                    DP[i][j] = DP[i+1][j+1];
                else if (p[i]=='*')
                    DP[i][j] = DP[i+1][j] | DP[i+1][j+1] | DP[i][j+1];
            }
        }
        return DP[0][0];
    }
};
