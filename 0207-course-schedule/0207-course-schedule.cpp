
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

        for (auto preq : prerequisites) indegree[preq[0]]++;

        std::queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int course_learned = 0;
        while (!q.empty()) {
            course_learned++;

            auto course = q.front(); q.pop(); 
            for (auto preq : graph[course]) {
                indegree[preq]--;
                if (indegree[preq] == 0) q.push(preq);
            }
        }

        return course_learned == numCourses;
    }



};