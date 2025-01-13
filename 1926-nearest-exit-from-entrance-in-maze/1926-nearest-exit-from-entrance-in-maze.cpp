class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int m = maze.size();
    int n = maze[0].size();
    queue<pair<int, int>> q; // Queue to perform BFS
    q.push({entrance[0], entrance[1]});
    maze[entrance[0]][entrance[1]] = '+'; // Mark the entrance as visited
    int steps = 0;

    // Directions for moving up, down, left, and right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto [row, col] = q.front();
            q.pop();

            // Check if the current cell is an exit
            if ((row == 0 || row == m - 1 || col == 0 || col == n - 1) &&
                !(row == entrance[0] && col == entrance[1])) {
                return steps;
            }

            // Explore the neighbors
            for (auto [dr, dc] : directions) {
                int newRow = row + dr;
                int newCol = col + dc;

                // Check if the move is valid
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && maze[newRow][newCol] == '.') {
                    q.push({newRow, newCol});
                    maze[newRow][newCol] = '+'; // Mark the cell as visited
                }
            }
        }

        steps++;
    }

    return -1; // If no exit is found
}

int main() {
    vector<vector<char>> maze = {
        {'+', '+', '.', '+'},
        {'.', '.', '.', '+'},
        {'+', '+', '+', '.'}
    };

    vector<int> entrance = {1, 2};

    int result = nearestExit(maze, entrance);

    cout << "Steps to nearest exit: " << result << endl;

    return 0;
}
    }
};