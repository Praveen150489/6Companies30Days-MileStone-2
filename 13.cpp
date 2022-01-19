// Rotten Oranges Problem.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=q.size();
        int time=0;
        while(count>0){
            for(int i=0;i<count;i++){
                pair<int,int> p=q.front();
                q.pop();
                solve(p,grid,q,n,m);
            }
            count=q.size();
            if(count>0){
                time++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
    void solve(pair<int,int> p,vector<vector<int>>& grid,queue<pair<int,int>>& q,int n,int m){
        int x=p.first;
        int y=p.second;
        if(x-1>=0 && grid[x-1][y]==1){
            grid[x-1][y]=2;
            q.push({x-1,y});
        }
        if(x+1<n && grid[x+1][y]==1){
            grid[x+1][y]=2;
            q.push({x+1,y});
        }
        if(y-1>=0 && grid[x][y-1]==1){
            grid[x][y-1]=2;
            q.push({x,y-1});
        }
        if(y+1<m && grid[x][y+1]==1){
            grid[x][y+1]=2;
            q.push({x,y+1});
        }
    }
};
