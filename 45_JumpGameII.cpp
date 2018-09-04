class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int far = 0, r = 0, nS = 0;
        for (int i=0; i<n-1; i++){
            far = i+nums[i]>far? i+nums[i]: far;
            if (i >= r){
                nS++;
                r = far;
            }
        }
        return nS;
    }
};
