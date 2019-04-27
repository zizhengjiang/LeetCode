class Solution {
    void bfs(vector<vector<char>> &grid, int x, int y) {
        grid[x][y] = '0';
        
        queue<pair<int, int>> que;
        que.emplace(x, y);
        
        while(!que.empty()) {
            int tx = que.front().first;
            int ty = que.front().second;
            que.pop();
            
            if (tx + 1 < grid.size() && grid[tx + 1][ty] == '1') {
                grid[tx + 1][ty] = '0';
                que.emplace(tx + 1, ty);
            }
            
            if (tx - 1 >= 0 && grid[tx - 1][ty] == '1') {
                grid[tx - 1][ty] = '0';
                que.emplace(tx - 1, ty);
            }
            
            if (ty + 1 < grid[0].size() && grid[tx][ty + 1] == '1') {
                grid[tx][ty + 1] = '0';
                que.emplace(tx, ty + 1);
            }
            
            if (ty - 1 >= 0 && grid[tx][ty - 1] == '1') {
                grid[tx][ty - 1] = '0';
                que.emplace(tx, ty - 1);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        
        return res;
    }
    
//     void dfs(vector<vector<char>> &grid, int x, int y) {
//          if (x < 0 || x == grid.size() || y < 0 || y == grid[x].size() || grid[x][y] == '0') return;
//          grid[x][y] = '0';
        
//         dfs(grid, x + 1, y);
//         dfs(grid, x - 1, y);
//         dfs(grid, x, y + 1);
//         dfs(grid, x, y - 1);
//     }
};