class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
                unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0];
            string B = equations[i][1];
            double value = values[i];
            graph[A][B] = value;
            graph[B][A] = 1.0 / value;
        }

      
        auto bfs = [&](const string& start, const string& end) -> double {
            if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
                return -1.0;
            }
            if (start == end) {
                return 1.0;
            }

            queue<pair<string, double>> q;
            unordered_map<string, bool> visited;
            q.push({start, 1.0});
            visited[start] = true;

            while (!q.empty()) {
                auto [current, value] = q.front();
                q.pop();

                if (current == end) {
                    return value;
                }

                for (auto& [neighbor, weight] : graph[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, value * weight});
                    }
                }
            }

            return -1.0;
        };

        
        vector<double> results;
        for (const auto& query : queries) {
            results.push_back(bfs(query[0], query[1]));
        }
        return results;
    }
};

    
