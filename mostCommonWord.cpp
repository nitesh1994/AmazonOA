// 819. Most Common Word
class Solution {
public:
    void toLowerCase(string &s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        } 
    }
    
    bool isPunc(char c) {
        if ( c >= 'a' && c <= 'z') return false;
        return true;
    }
    
    string mostCommonWord(string par, vector<string>& banned) {
        toLowerCase(par);
        unordered_set<string> bnd(banned.begin(), banned.end());
        unordered_map<string, int> counts;
        bnd.insert("");
        string word = "";
        for (int i = 0; i < par.length(); i++) {
            if(isPunc(par[i])) {
                if (bnd.find(word) == bnd.end())
                    counts[word]++;
                word = "";
            } else {
                word += par[i];
            }
        }
        
        if(!word.empty()){
            if (bnd.find(word) == bnd.end()) counts[word]++;
        }
        
        int mx = INT_MIN;
        
        for (unordered_map<string, int>::iterator it = counts.begin(); it!= counts.end(); it++) {
            if (it->second > mx) {
                mx = it->second;
                word = it->first;
            }
        }
        
        return word;
    }
};
