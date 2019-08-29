class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        
        int L, R, pos = 0, len = -1, ss = s.size();
        char sr;

        for(int i = 0; i < ss; i++)
        {
            L = R = i;
            
            sr = s[R];
            
            while(R+1 <= ss && (sr == s[R+1]))
                R++;
         
            i = R;
        
            while(R+1 <= ss && L-1 >= 0 && (s[R+1] == s[L-1]))
            {
                R++;
                L--;
            } 
            
            if(len < R-L+1 )
            {
                len = R-L+1;
                pos = L;
            }
        }
        return s.substr(pos, len);
    }
};
