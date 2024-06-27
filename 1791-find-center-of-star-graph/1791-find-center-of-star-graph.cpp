class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_map<int, int> ump;

        for (auto& edge : edges) {
            ump[edge[0]]++;
            ump[edge[1]]++;

    
        }

        int node = 0;
        int max = 0;

        for (auto & [n, degree] : ump) {
            if (max < degree ) {
                max = degree; 
                node = n;
            }
         }

        return node;
    }
};