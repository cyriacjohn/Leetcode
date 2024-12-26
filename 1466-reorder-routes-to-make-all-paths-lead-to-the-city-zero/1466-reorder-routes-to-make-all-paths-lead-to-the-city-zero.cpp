class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
           unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& conn : connections) {
            int a = conn[0], b = conn[1];
            graph[a].push_back({b, 1}); 
            graph[b].push_back({a, 0}); 
        }

        unordered_set<int> visited;
        return dfs(0, graph, visited);
    }

private:
    int dfs(int node, unordered_map<int, vector<pair<int, int>>>& graph, unordered_set<int>& visited) {
        visited.insert(node);
        int changes = 0;

        for (auto& neighbor : graph[node]) {
            int next = neighbor.first, needsReversal = neighbor.second;
            if (visited.find(next) == visited.end()) {
                changes += needsReversal; // Count edge reversal
                changes += dfs(next, graph, visited);
            }
        }

        return changes;
    }
};
    