class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<pair<int, int>, int>> q; // ((row, col), time)
    int fresh_oranges = 0;
    int minutes = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                q.push({{r, c}, 0}); 
            } else if (grid[r][c] == 1) {
                fresh_oranges++; 
            }
        }
    }

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int row = front.first.first;
        int col = front.first.second;
        minutes = front.second;

        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 2; 
                fresh_oranges--; 
                q.push({{newRow, newCol}, minutes + 1}); 
            }
        }
    }

    return fresh_oranges > 0 ? -1 : minutes;
}

    
};