class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        
        sort(A.begin(), A.end());
        
        int i=0;
        int j=A.size()-1;
        int S=INT_MIN;
        int start=0;
        int end=0;
        while(i<j){
            int sum=A[i]+A[j];
            if(sum<K){
                
                if(sum > S){
                    S=sum;
                    start=A[i];
                    end=A[j];
                }
                else if(sum==S){
                    if(max(A[i],A[j])>max(start,end)){
                        start=A[i];
                        end=A[j];
                    }
                }
                ++i;
            }
            else if(sum>=K) --j;
            
        }
        
        cout<<start<<end;
        if(S==INT_MIN) return -1;
        return S;
    }
};
