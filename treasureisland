#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

struct point{
	int r;
	int c;
};
bool isSafe(vector<vector<char> >& grid, int r, int c){

	return r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]!='D';
}
int findTreasure(vector<vector<char> >& grid){

	queue<pair<point,int> > qu;
	point p;
	p.r=0;
	p.c=0;
	grid[p.r][p.c]='D';
	qu.push(make_pair(p,0));

	vector<vector<int> > dir;
	vector<int> temp;
	temp.push_back(0);
	temp.push_back(1);

	dir.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(0);

	dir.push_back(temp);
	temp.clear();
	temp.push_back(-1);
	temp.push_back(0);

	dir.push_back(temp);
	temp.clear();
	temp.push_back(0);
	temp.push_back(-1);

	dir.push_back(temp);
	temp.clear();
	int steps=0;
	while(!qu.empty()){
		int size=qu.size();

	while(size!=0){
		pair<point, int> pp=qu.front();
		qu.pop();
	
		for(int i=0; i<dir.size();++i){	
		
			point q=pp.first;
			int r=q.r+dir[i][0];
			int c=q.c+dir[i][1];

			point pi;
			pi.r=r;
			pi.c=c;
			if(isSafe(grid, r, c)){ 
				if(grid[r][c]=='X') return pp.second+1;
				grid[r][c]='D';
				qu.push(make_pair(pi, pp.second+1));

			}
		}		
	
		--size;
	}
	}

	return steps;

}

int main(){

	vector<vector<char> > grid;
	vector<char> temp;
	temp.push_back('O');
	temp.push_back('O');
	temp.push_back('O');
	temp.push_back('O');
	grid.push_back(temp);
	temp.clear();

	temp.push_back('D');
	temp.push_back('O');
	temp.push_back('D');
	temp.push_back('O');
	grid.push_back(temp);
	temp.clear();


	temp.push_back('O');
	temp.push_back('O');
	temp.push_back('O');
	temp.push_back('O');
	grid.push_back(temp);
	temp.clear();

	temp.push_back('O');
	temp.push_back('D');
	temp.push_back('D');
	temp.push_back('X');
	grid.push_back(temp);
	temp.clear();

	int minSteps=findTreasure(grid);

	cout<<minSteps;
}
