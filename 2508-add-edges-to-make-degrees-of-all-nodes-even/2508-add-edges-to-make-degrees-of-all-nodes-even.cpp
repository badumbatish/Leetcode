class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        // get the degrees of each node into a map

        // count number of odd degrees.

        // if 0 -> true
        // if 2 -> true 

        // if 4 -> check

        std::map<int, std::set<int>> adj_list;
        for (auto edge : edges) {
            adj_list[edge[0]].insert(edge[1]);
            adj_list[edge[1]].insert(edge[0]);
        }

        std::vector<int> odds;
        for (auto &[node, children] : adj_list) {
            if (children.size() % 2 == 1) odds.push_back(node);
        }

        if (odds.size() == 0) return true;
        if (odds.size() == 2) {
            auto node_1 = odds[0], node_2 = odds[1];
            
            if (!adj_list[node_2].contains(node_1)) return true;

            for (int i = 1; i <= n; i++) 
                if (!adj_list[i].contains(node_1) && !adj_list[i].contains(node_2))
                    return true;
        }
        if (odds.size() == 4) {
            auto node_1 = odds[0], node_2 = odds[1], node_3 = odds[2], node_4 = odds[3];

            if (!adj_list[node_2].contains(node_1) && !adj_list[node_4].contains(node_3)) 
                return true;
            if (!adj_list[node_3].contains(node_1) && !adj_list[node_4].contains(node_2)) 
                return true;
            if  (!adj_list[node_4].contains(node_1) && !adj_list[node_3].contains(node_2)) 
                return true;
        }

        return false;
    }
};