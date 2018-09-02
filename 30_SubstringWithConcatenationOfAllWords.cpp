class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size();
        int m = words.size(), len = m > 0? words[0].size(): 0;
        
        map<int,int> substr;
        int *check = (int *)malloc(sizeof(int)*m);
        int *repeat = (int *)malloc(sizeof(int)*m);
        memset(repeat, 0, sizeof(int)*m);
        
        vector<string> a_w;
        int a_m = 0;
        for (int i=0; i<m; i++){
            if (repeat[i] < 0) continue;
            repeat[i]++;
            for (int j=i+1; j<m; j++)
                if (words[i].compare(0, len, words[j]) == 0)
                    repeat[i]++, repeat[j] = -1;
            a_w.push_back(words[i]);
            repeat[a_m++] = repeat[i];
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<a_m; j++)
                if (s.compare(i, len, a_w[j]) == 0)
                    substr[i] = j;
        }

        queue<pair<int,int>> que;
        while (!substr.empty()){
            memset(check, 0, sizeof(int)*m);
            while (!que.empty()) que.pop();
            map<int,int>::iterator it = substr.begin();
            for (int i=it->first; ; i+=len){
                map<int,int>::iterator tmp = substr.find(i);
                if (tmp != substr.end()){
                    check[tmp->second] += 1;
                    que.push(pair<int,int>(tmp->first, tmp->second));
                    if (check[tmp->second] > repeat[tmp->second]){
                        while (que.front().second != tmp->second)
                            check[que.front().second] -= 1, que.pop();
                        check[que.front().second] -= 1, que.pop();
                    }
                    substr.erase(tmp);
                    if (que.size()==m)
                        ans.push_back(que.front().first);
                }
                else break;
            }
        }
        return ans;
    }
};
