class Solution {
    using Graph = std::vector<std::vector<int>>;
    using Visited = std::vector<int>;

    Graph make_graph(int n, vector<vector<int>>& edges) {
        Graph graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    } 

    void dfs(int i, Graph &graph, Visited &v) {
        v[i] = 0;

        for (auto neighbor : graph[i]) {
            if (v[neighbor] == -1) {
                dfs(neighbor, graph, v);
            }
        }
    }
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        Graph graph = make_graph(n, edges);     
        Visited visited(n, -1);
        int connected_components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                dfs(i, graph, visited);
                connected_components++;
            }
        }

        return connected_components;
    }
};