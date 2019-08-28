#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) {
            return s;
        }
        
        unordered_map<char, int> cnt;
        for (auto ch : s) {
            ++cnt[ch];
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto& pr : cnt) {
            pq.push({pr.second, pr.first});
        }
        
        string res;
        while (pq.size() >= (size_t)k) {
            vector<pair<int, char>> vec;
            for (int i = 0; i < k; ++i) {
                auto pr = pq.top();
                pq.pop();
                res.push_back(pr.second);
                --pr.first;
                vec.push_back(pr);
            }
            
            for (auto& pr : vec) {
                if (pr.first > 0) {
                    pq.push(pr);
                }
            }
        }
        
        while (!pq.empty()) {
            auto pr = pq.top();
            pq.pop();
            
            if (pr.first > 1) {
                return "";
            }
            res.push_back(pr.second);
        }
        return res;
    }
};
