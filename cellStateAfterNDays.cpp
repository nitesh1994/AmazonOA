class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        N=N%14;
        
        if(N==0) N=14;
        
        int prev=cells[0];
        int cur=cells[1];
        int next=cells[2];
        
        for(int i=0; i<N;++i){
            for(int j=1; j<7;++j){
                next=cells[j+1];
                cur=cells[j];
                if(j==1 && i>0) prev=0;
                if(prev==next){
                    cells[j]=1;
                }
                else{ cells[j]=0;}
                prev=cur;
            }
            cells[0]=0;
            cells[7]=0;
        }
        
        return cells;
    }
};
