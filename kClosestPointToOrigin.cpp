class Solution {
public:
    static bool comp(const vector<int>& p, const vector<int>& q){
        return pow(p[0],2)+pow(p[1],2) < pow(q[0],2)+pow(q[1],2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        vector<vector<int>> res;
        
        sort(points.begin(), points.end(), comp);
        if(points.size()==0) return res;
        
        for(int i=0;i<K;++i){
            res.push_back(points[i]);
        }
        
        return res;
    }
};
