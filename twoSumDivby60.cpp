class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        vector<int> count(60,0);
        
        int res=0;
        count[0]=0;
        for(int i=0;i<time.size();++i){
            int t=time[i]%60;
            int diff=60-t;
            if(diff==60) diff=0;
            res+=count[diff];
            count[t]++;
            
        }
        
        return res;
    }
};
