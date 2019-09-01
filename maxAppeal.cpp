int main() {
    
    
    vector<int> num={1, 6, 1,1,1,1,7};
    int max1=INT_MIN;
    int max2=INT_MIN;
    
    int index1=-1;
    int index2=-1;
    
    if(num.size()==0) cout<<"-1"<<"-1";
    
    for(int i=0;i<num.size();++i){
        int curr1=num[i]+i;
        int curr2=num[i]-i;
        
        if(curr1>max1){
            max1=curr1;
            index1=i;
        }
        if(curr2>max2){
            max2=curr2;
            index2=i;
        }
        
    }
    
    cout<<index1<<index2;
    
    
}
