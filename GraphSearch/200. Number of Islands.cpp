class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid,vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        int neighRows[4] = {-1,1,0,0};
        int neighCols[4] = {0,0,-1,1};
        visited[r][c] = true;
        for(int i=0;i<4;i++){
            int nRow = r + neighRows[i];
            int nCol = c + neighCols[i];
            if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && grid[nRow][nCol] == '1' && !visited[nRow][nCol])
                dfs(nRow,nCol,grid,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    num+=1;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return num;
    }
};