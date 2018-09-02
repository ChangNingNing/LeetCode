class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<pair<char, int>> st;
        int *valid = (int *)malloc(sizeof(int)*n);
        memset(valid, 0, sizeof(int)*n);
        
        for (int i=0; i<n; i++){
            if (s[i] == '(')
                st.push(pair<char,int>(s[i], i));
            else if (!st.empty() && st.top().first == '('){
                valid[st.top().second] = 1;
                valid[i] = 1;
                st.pop();
            }
        }
        int max = 0, len = 0;
        for (int i=0; i<n; i++){
            if (valid[i]){
                len++;
                if (len > max) max = len;
            }
            else
                len = 0;
        }
        return max;
    }
};
