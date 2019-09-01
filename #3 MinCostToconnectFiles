class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        
        
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        
        int res=0;
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            res+=(first+second);
            pq.push(first+second);
        }
        
        return res;
    }
};
