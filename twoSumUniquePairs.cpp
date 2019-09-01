int main() {
    
    vector<int> num={1,1};
    
    int target=2;
    
    unordered_map<int, int> vis;
    
    for(int x:num) vis[x]++;
    
    map<pair<int, int>, int> pi;
    
    int count=0;
    for(int i=0;i<num.size();++i){
        
        int complement=target-num[i];
        
        if(vis.find(complement)!=vis.end() && pi[{num[i],complement}]==0){
            count++;
        }
        
        pi[{num[i],complement}]++;
        pi[{complement, num[i]}]++;
        
    }
    
    
    cout<<"Count of unique pairs of sum is"<<count;
}
