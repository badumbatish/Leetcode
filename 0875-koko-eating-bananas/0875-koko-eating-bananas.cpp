class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        uint64_t left = 1, right = *std::ranges::max_element(piles);
        uint64_t candidate = right;
        while (left <= right) {
            uint64_t middle = left + (right - left) / 2;
            uint64_t hour_spent = 0;

            for (auto pile : piles) hour_spent += pile / middle + (pile % middle != 0);

            if (hour_spent == h) {
                right = middle - 1;
                candidate = middle;
            }  else if (hour_spent < h) {
                right = middle - 1;
                candidate = middle;
            }
            else left = middle + 1;
        }

        return candidate;
    }
};