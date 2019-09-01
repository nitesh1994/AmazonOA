vector<int> partitionLabels(string S) {
        int last[26];
        
        vector<int> res;
        
        if(S.size() == 0)
            return res;
        
        for(int i=0; i< S.size(); ++i)
        {
            last[S[i] - 'a']=i;
        }
        
        int start=0, end=0;
        for(int i=0; i<S.size(); ++i)
        {
            end = max(last[S[i] - 'a'],end);
            
            // We have traversed all the characters in this partition
            if( i == end)
            {
                res.push_back( end - start + 1);
                start = i+1;
            }
        }
        return res;
    }
};
