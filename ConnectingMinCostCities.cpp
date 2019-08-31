// Leetcode: 1135. Connecting Cities With Minimum Cost
class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2) {
        return v1[2]<=v2[2];
    }
    
    void union1(int i, int j, vector<int> &parent){
        parent[j] = find(i, parent);
    }
    
    int find(int i, vector<int> &parent) {
        if (parent[i] != i) {
            parent[i] = find(parent[i], parent);
        }
        return parent[i];
    }
    
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), comp);
        vector<int> parent(N+1);
        for(int i = 0; i <= N; i++) {
            parent[i] = i;
        }
        
        int result = 0;
        int count = 1;
        int l = connections.size();
        for(int i = 0; i < l; i++) {
            int a = connections[i][0];
            int b = connections[i][1];
            int p1 = find(a, parent);
            int p2 = find(b, parent);
            if(p1 != p2) {
                result += connections[i][2];
                union1(p1, p2, parent);
                count++;
                if(count == N) return result;
            }
        }
        return -1;
    }
};
