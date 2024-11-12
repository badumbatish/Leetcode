class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        std::sort(items.begin(), items.end());

        std::vector<int> maxy = {0};
        
        for (auto item : items) {
            maxy.push_back(std::max(maxy.back(), item[1]));
        }
        std::vector<int> result;
        for (auto query : queries) {
            size_t less_equal_price = std::upper_bound(items.begin(), items.end(), query, [](auto &a, auto &b) {
               return a < b[0]; 
            }) - items.begin();

            result.push_back(maxy[less_equal_price]);
            std::cout << result.back() << std::endl;
        }

        return result;
    }
};