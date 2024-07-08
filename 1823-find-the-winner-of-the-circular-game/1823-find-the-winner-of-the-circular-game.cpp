class Solution {
public:
    int findTheWinner(int n, int k) {
        std::vector<int> circle;

        for (int i =  1; i <= n; i++) {
            circle.push_back(i);
        }

        int start_index = 0;

        while (circle.size() > 1) {
            int removal_index = (start_index + k - 1) % circle.size();
            circle.erase(circle.begin() + removal_index);

            start_index = removal_index;
        }

        return circle.front();
    }
};