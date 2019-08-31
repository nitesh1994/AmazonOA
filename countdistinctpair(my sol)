int main() {
    vector<int> num={1,2,3,5,10};
    
    map<pair<int,int>, int> freq;
    
    map<int, int> mp;
    int count=0;
    for(int x:num) mp[x]++;
    
    for(int i=0;i<num.size()-1;++i){
        for(int j=i+1;j<num.size();++j){
            
            int sum=num[i]+num[j];
            
            if(mp[sum]>0 && freq[{num[i],num[j]}]==0){
                count++;
            }
            
            freq[{num[i],num[j]}]++;
            freq[{num[j],num[i]}]++;
        }
    }
    cout<<count;
    
}
