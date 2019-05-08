class Solution:
    def deepFirstSearch(self, grid: List[List[int]], x: int, y: int) -> int:
        if x < 0 or x == len(grid) or y < 0 or y == len(grid[x]) or grid[x][y] == 0:
            return 0
        grid[x][y] = 0
        return 1 + self.deepFirstSearch(grid, x + 1, y) + self.deepFirstSearch(grid, x - 1, y) + \
                   self.deepFirstSearch(grid, x, y + 1) + self.deepFirstSearch(grid, x, y - 1)
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, self.deepFirstSearch(grid, i, j))
        
        return maxArea