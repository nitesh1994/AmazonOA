// leetcode: 200. Number of Islands
class Solution {
public:
    void un(int i, int j, vector<int> &p) {
        p[find(j, p)] = find(i, p);
    }
    
    int find(int i, vector<int> &p) {
        if(p[i] != i){
            p[i] = find(p[i], p);
        }
        return p[i];
    }
    
    bool isSafe(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >=0 && y < n) return 1;
        return 0;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        unordered_set<int> s;
        vector<int> p(m*n);
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i = 0; i < m*n; i++) p[i] = i;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pos = i*n + j;
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (isSafe(x,y, m,n)) {
                        int newpos = x*n + y;
                        if (grid[i][j] == '1' && grid[x][y] == '1') {
                            un(pos, newpos, p);
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < m*n; i++) {
            if (grid[i/n][i%n] == '1') s.insert(find(i, p));
        }
        return s.size();
    }
};
