class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0, n = height.size();
        for (int i=0; i<n; i++){
            while (!st.empty() && height[i] >= height[st.top()]){
                int low = st.top();
                st.pop();
                if (st.empty()) break;
                int dist = i - st.top() - 1;
                int water = min(height[i], height[st.top()]) - height[low];
                ans += water * dist;    
            }
            st.push(i);
        }
        return ans;
    }
};
