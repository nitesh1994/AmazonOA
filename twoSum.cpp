class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        vec<int> res;
        for(int i=0; i<nums.size(); ++i){
            
            int complement=target-nums[i];
            
            if(mp.find(complement)!=mp.end()){
                res.push_back(i);
                res.push_back(mp.find(complement)->second);
                return res;
            }
            
            mp.insert(make_pair(nums[i],i));
        }
        
        return res;
    }
};
