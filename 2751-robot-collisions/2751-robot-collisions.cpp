class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        std::vector<int> indices(n), result;

        std::stack<int> stck;

        for (int i = 0; i < n; i++) indices[i] = i;

        std::ranges::sort(indices, [&](auto a, auto b) { return positions[a] < positions[b];});

        for (auto index : indices) {
            if (directions[index] == 'R') {
                stck.push(index);
            } else {

            while (!stck.empty() && healths[index] > 0) {
                int top_index = stck.top();
                stck.pop();

                if (healths[top_index] > healths[index]) {
                    healths[top_index] -= 1;
                    healths[index] = 0;
                    stck.push(top_index);
                } else if (healths[top_index] < healths[index]) {
                    healths[index] -= 1;
                    healths[top_index] = 0;
                } else {
                    healths[index] = 0;
                    healths[top_index] = 0;
                }
            }
            }
        }

        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};