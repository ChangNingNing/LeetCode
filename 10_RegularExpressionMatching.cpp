class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        vector<vector<int>> DP(np+1);
        for (int i=0; i<=np; i++) DP[i] = vector<int>(ns+1, 0);
        
        DP[np][ns] = 1;
        for (int i=np-1; i>=0; i--){
            for (int j=ns; j>=0; j--){
                int match = j < ns && (p[i] == s[j] || p[i] == '.');
                if (i+1 < np && p[i+1]=='*')
                    DP[i][j] = DP[i+2][j] || (match && DP[i][j+1]);
                else
                    DP[i][j] = match && DP[i+1][j+1];
            }
        }
        return DP[0][0];
    }
};
