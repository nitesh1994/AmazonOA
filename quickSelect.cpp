class Solution {
public:
    int partition(vector<int>& nums, int l, int r, int k){
        
        int pivot=r;
        
        int i=l-1;
        // Go until pivot element not including pivot
        for(int j=l;j<r;++j){
            
            if(nums[j]<=nums[pivot]){
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[i+1], nums[pivot]);
        
        return i+1;
    }
    
    int quickselect(vector<int>& nums, int l, int r, int k){
        
        if(l<=r){
            
            int pi=partition(nums, l, r, k);
            cout<<pi;
            if(pi==k) return nums[pi];
            
            if(pi>k) return quickselect(nums, l, pi-1, k);
            
            return quickselect(nums, pi+1, r, k);
        }
        
        return 0;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        if(k>n) return -1;
        k=n-k;
       // cout<<k;
        return quickselect(nums, 0, nums.size()-1, k);
    }
};
