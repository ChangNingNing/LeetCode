class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = n1 + n2, pn = n / 2;

        int l = 0, r = n1, m1, m2;
        while (l <= r){
            m1 = (l + r) >> 1;
            m2 = pn - m1;
            if (m1 > pn){
                r = m1 - 1;
                continue;
            }
            if (m2 > n2){
                l = m1 + 1;
                continue;
            }
            if (m1 != 0 && m2 != n2 && nums1[m1-1] > nums2[m2]){
                r = m1 - 1;
                continue;
            }
            if (m2 != 0 && m1 != n1 && nums2[m2-1] > nums1[m1]){
                l = m1 + 1;
                continue;
            }
            break;
        }
        
        if (n&1)
            ans = m1==n1? nums2[m2]: m2==n2? nums1[m1]: Min(nums1[m1], nums2[m2]);
        else {
            int max = m1==0? nums2[m2-1]: m2==0? nums1[m1-1]: Max(nums1[m1-1], nums2[m2-1]);
            int min = m1==n1? nums2[m2]: m2==n2? nums1[m1]: Min(nums1[m1], nums2[m2]);
            ans = (double)(max + min) / 2;
        }
        return ans;
    }
private:
    int Max(int a, int b){ return a>b? a: b; }
    int Min(int a, int b){ return a<b? a: b; }
};
