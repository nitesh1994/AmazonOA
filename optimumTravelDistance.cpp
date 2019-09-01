int main() {
    // O(nm) complexity solution
    
    vector<vector<int>> forward={{1,3000},{2,5000},{3,7000},{4,10000}};
    
    vector<vector<int>> returnRo={{1,2000},{2,3000},{3,4000},{4,5000}};
    
    vector<vector<int>> res;
    
    int maxTravelDistance=10000;
    int maxTill=INT_MIN;
    for(int i=0; i<forward.size();++i){
        for(int j=0;j<returnRo.size();++j){
            int sum=forward[i][1]+returnRo[j][1];
            if(sum<=maxTravelDistance){
                if(sum>maxTill ){
                    maxTill=sum;
                    res.clear();
                    //cout<<res.size();
                    res.push_back({forward[i][0],returnRo[j][0]});
                }
                else if(sum==maxTill){
                    res.push_back({forward[i][0], returnRo[j][0]});
                }
                
            }
            
        }
    }
        cout<<maxTill;
        for(int i=0;i<res.size();++i)
        cout<<res[i][0]<<res[i][1]<<'\t';
}
