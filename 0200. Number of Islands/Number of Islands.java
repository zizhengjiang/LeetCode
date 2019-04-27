class Solution {
    public void dfs(char[][] grid, int x, int y) {
        if (x < 0 || x == grid.length || y < 0 || y == grid[x].length || grid[x][y] == '0') return;
        grid[x][y] = '0';
        
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
    
    public int numIslands(char[][] grid) {
        int cnt = 0;
        
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return cnt;
    }
}