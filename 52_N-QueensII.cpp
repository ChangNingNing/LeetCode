class Solution {
public:
    int totalNQueens(int n) {
        int v1 = 0, v2 = 0, v3 = 0;
        return solve(n, 0, v1, v2, v3);
    }
private:
    int solve(int n, int row, int v1, int v2, int v3){
        if (row >= n) return 1;
        int invalid = v1 | v2 | v3;
        int valid = ~invalid & ((1<<n)-1);
        int ans = 0;
        while (valid != 0){
            int pos = valid & -valid;
            valid ^= pos;
            ans += solve(n, row+1, v1|pos, (v2|pos)<<1, (v3|pos)>>1);
        }
        return ans;
    }
};
