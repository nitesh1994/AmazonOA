int main() {
    std::cout << "Hello World!\n";
    
    
    vector<int> arr={1,0,0,1,1};
    
    int totalSum=0;
    
    for(int i=0;i<arr.size();++i){
        
        if(arr[i]==1) totalSum++;
        else totalSum--;
    }
    
    int currSum=0;
    
    for(int i=0;i<arr.size();++i){
        
        if(currSum>totalSum) {
            cout<<i;  // answer
            break;
        }
        currSum+=(arr[i]==0?-1:1);
        totalSum-=(arr[i]==0?-1:1);
    }
    
    cout<<arr.size();
}
