int main() {
    std::cout << "Hello World!\n";
    
    vector<int> sale={2,3,3,1,2,3,4,2};
    
    stack<int> st;
    
    int n=sale.size();
    
    vector<int> res(n,0);
    
    for(int i=0; i<sale.size();++i){
        
        while(!st.empty() && sale[st.top()]>=sale[i]){
            res[st.top()]=sale[i];
            st.pop();
        }
        st.push(i);
    }
    
    for(int i=0;i<n;++i){
        res[i]=sale[i]-res[i];
    }
    
    int ans=0;
    
    for(int x:res) ans+=x;
    
    cout<<ans;
}
