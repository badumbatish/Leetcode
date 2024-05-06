class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_elem = *std::max_element(candies.begin(), candies.end());

        std::vector<bool> result;

        for (auto candie : candies) {
            if (candie + extraCandies >= max_elem) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};