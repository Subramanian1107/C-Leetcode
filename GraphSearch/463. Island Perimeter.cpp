class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>&visited,int* count){
        int n = grid.size();
        int m = grid[0].size();
        int neighRows[4] = {-1,1,0,0};
        int neighCols[4] = {0,0,-1,1};
        *count += 4;
        // cout<<r<<" "<<c<<" "<<(*count)<<" ";
        visited[r][c] = true;
        for(int i=0;i<4;i++){
            int nRow = r+neighRows[i];
            int nCol = c+neighCols[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == 1){
                *count = *count-1;
            }
        }
        // cout<<*count<<endl;
        for(int i=0;i<4;i++){
            int nRow = r+neighRows[i];
            int nCol = c+neighCols[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == 1 && !visited[nRow][nCol]){
                // cout<<nRow<<" "<<nCol<<" "<<visited[nRow][nCol]<<endl;
                dfs(nRow,nCol,grid,visited,count);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    dfs(i,j,grid,visited,&count);
            }
        }
        return count;
    }
};