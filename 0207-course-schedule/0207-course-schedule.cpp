
class Solution {
    using Graph = std::vector<std::vector<int>>;

    Graph make_graph(int n,  vector<vector<int>>& prerequisites) {
        Graph adj(n);

        for(auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        return adj;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph = make_graph(numCourses, prerequisites);
        std::vector<int> indegree(numCourses, 0);

        for (auto preq : prerequisites) {
            indegree[preq[0]]++;
        } 
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) 
            if (indegree[i] == 0) q.push(i);

        int nodesVisited = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();

            nodesVisited++;


            for (auto& neighbor : graph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        } 

        return nodesVisited == numCourses;
    }



};