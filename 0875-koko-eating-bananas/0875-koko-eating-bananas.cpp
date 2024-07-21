class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *std::ranges::max_element(piles);

        while (left < right) {
            int middle = left + (right - left) / 2;
            int hour_spent = 0;

            for (int pile : piles) hour_spent += pile / middle + (pile % middle != 0);

            if (hour_spent <= h) right = middle;
            else left = middle + 1;
        }

        return right;
    }
};