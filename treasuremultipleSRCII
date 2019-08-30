struct point{
    int r;
    int c;
};

bool isSafe(vector<vector<int>> grid, int r, int c){
    
    return r<grid.size() && c<grid[0].size() && r>=0 && c>=0 && grid[r][c]!='D';
    
}
int main() {
    
    
    vector<vector<int>> grid={{ 'S', 'O', 'O', 'S', 'S'},
                              {'D', 'O', 'D', 'O', 'D'},
                              {'O', 'O', 'X', 'O', 'D'},
                              {'D', 'D', 'D', 'O', 'O'},
                              {'X', 'D', 'D', 'D', 'O'}};
       
    //cout<<grid.size();
    
    queue<pair<point, int>> qu;
    
    for(int i=0;i<grid.size();++i){
        for(int j=0;j<grid[0].size();++j){
            if(grid[i][j]=='S'){
                point p;
                p.r=i;
                p.c=j;
                qu.push({p,0});
                grid[i][j]='D';
            }
        }
    }
    
    vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
    
    while(!qu.empty()){
        int size=qu.size();
        
        
        while(size!=0){
            pair<point, int> pp=qu.front();
            qu.pop();
            for(int i=0; i<dir.size();++i){
               point q=pp.first;
               int row=q.r+dir[i][0];
                int col=q.c+dir[i][1];
                
                point now;
                now.r=row;
                now.c=col;
                if(isSafe(grid,row,col)){
                    if(grid[row][col]=='X') {cout<<pp.second+1; return 0;}
                    grid[row][col]='D';
                    qu.push({now,pp.second+1});
                }
                
            }
            
            --size;
        }
    }
    
    
    
}
