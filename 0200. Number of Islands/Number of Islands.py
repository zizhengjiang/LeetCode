class Solution:
    def dfs(self, grid: List[List[str]], x: int, y: int) -> None:
        if x < 0 or x == len(grid) or y < 0 or y == len(grid[x]) or grid[x][y] == '0':
            return;
        grid[x][y] = '0'
        
        self.dfs(grid, x + 1, y)
        self.dfs(grid, x - 1, y)
        self.dfs(grid, x, y + 1)
        self.dfs(grid, x, y - 1)
    
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0;
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if (grid[i][j] == '1'):
                    res += 1
                    self.dfs(grid, i, j)
        return res