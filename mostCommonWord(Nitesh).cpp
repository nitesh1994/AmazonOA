class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> bannedWords(banned.begin(), banned.end());
        
        bannedWords.insert("");
        unordered_map<string, int> mp;
        
        string temp="";
       // mp[" "]=0;
        for(char c: paragraph){
            if((c>='A' && c<='Z') || (c>='a' && c<='z')){
                temp+=tolower(c);
            }
            else{
                if(bannedWords.find(temp)==bannedWords.end()){
                    //cout<<temp;
                    mp[temp]++;
                }
                temp="";
            }
        }
        
        if(!temp.empty()){
            if(bannedWords.find(temp)==bannedWords.end()){
                mp[temp]++;
            }
        }
        int maxT=INT_MIN;
        string word="";
        
        unordered_map<string, int>::iterator it=mp.begin();
        for(;it!=mp.end();++it) {
            cout<<it->first<<it->second<<'\t';
            if(it->second > maxT){
                //cout<<f.first<<f.second;
                maxT=it->second;
                word=it->first;
            }
        }
        
        return word;
    }
};
