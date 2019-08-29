set<string> findsubstrings(string st, int k){
    
    int start=0;
    int end=0;
    unordered_set<char> window;
    set<string> res;
    for(;end<st.size();++end){
        while(start<end && window.find(st[end])!=window.end()) window.erase(st[start++]);
        
        window.insert(st[end]);
        
        if(window.size()==k){
            res.insert(st.substr(start,end-start+1));
            window.erase(st[start]);
            start++;
        }
    }
    
    return res;
    
    
}
