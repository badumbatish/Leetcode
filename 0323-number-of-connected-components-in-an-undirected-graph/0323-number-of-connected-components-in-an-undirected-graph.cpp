class UnionFind{
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:

    UnionFind(int n) {
        parent = std::vector<int>(n);
        rank = std::vector<int>(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
        
    
    int find(int u) {
        int v = u;
        while (parent[u] != u) {
            u = parent[u];
        }
        parent[v] = u; 

        return u;
    }
    

    // Return false if we have to union them (they are not already union)
    // Return false if we don't have to union them (they are already union)
    bool unite(int a, int b) {
        auto pa = find(a);
        auto pb = find(b);

        if (pa != pb) {
            auto& ra = rank[pa], rb = rank[pb];

            if (ra <= rb) {
                parent[pb] = pa;
                ra += rb;
            }
            else if (ra > rb) {
                parent[pa] = pb;
                rb += rb;
            }

            return true;
        }

        return false;
    }

    int size() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) count++;
        }
        return count;
    }


};
class Solution {

public:

    int countComponents(int n, vector<vector<int>>& edges) {
        auto uf = UnionFind(n);
        for (auto edge : edges) {
           uf.unite(edge[0], edge[1]);
        }

        return uf.size();
    }
};