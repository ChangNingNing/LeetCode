class Solution {
public:
    int firstMissingPositive(vector<int>& v) {
        int n = v.size();
        for (int i=0; i<n; i++){
            if (v[i] != i+1 && v[i] >= 1 && v[i] <= n){
                if (v[i]!=v[v[i]-1]){
                    swap(v, i, v[i]-1);
                    i--;
                }
            }
        }
        int miss = n+1;
        for (int i=0; i<n; i++){
            if (v[i] != i+1 || v[i] < 1 || v[i] > n){
                miss = i + 1;
                break;
            }
        }
        return miss;
    }
private:
    void swap(vector<int>& v, int x, int y){
        int tmp = v[x];
        v[x] = v[y], v[y] = tmp;
    }
};
