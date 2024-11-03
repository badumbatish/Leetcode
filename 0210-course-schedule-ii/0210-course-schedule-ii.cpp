class Solution {
    using Graph = std::vector<std::vector<int>>;

    Graph make_graph(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g(numCourses, std::vector<int>(0));

        for (auto preq : prerequisites) {
            g[preq[1]].push_back(preq[0]);
        }

        return g;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        auto graph = make_graph(numCourses, prerequisites);

        std::vector<int> indegree(numCourses, 0);
        for (auto preq : prerequisites) indegree[preq[0]]++;

        std::vector<int> order;


        std::queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) 
                q.push(i);
        } 

        while (!q.empty()) {
            int course = q.front(); q.pop();

            order.push_back(course);
            for (auto course_after : graph[course]) {
                indegree[course_after]--;
                if (indegree[course_after] == 0) q.push(course_after);
            }
        }

        if (order.size() != numCourses) return {};
        return order;
    
    }
};