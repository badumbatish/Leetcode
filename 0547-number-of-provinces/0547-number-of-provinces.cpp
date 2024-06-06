class Solution {
private:
    std::map<int, bool> visited;
    int n = 0;
public:
    void dfs(int node, vector<vector<int>>& isConnected) {
        visited[node] = true;
        for (int i = 0; i < n; i++) {
            if (isConnected[node][i] && visited[i] == false) {
                dfs(i, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int numberOfComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numberOfComponents++;
                dfs(i, isConnected);
            }
        }

        return numberOfComponents;
    }
};