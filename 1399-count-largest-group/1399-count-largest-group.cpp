class Solution {
public:
    int countLargestGroup(int n) {
        std::map<int, int> group_map;

        for (int i = 1; i <= n; i++) {
            group_map[count_sum(i)]++;
        }

        int m = std::max_element(group_map.begin(), group_map.end(), [](auto a, auto b) { return a.second < b.second; })->second;

        int c = 0;
        for (auto [sum, count] : group_map) 
            if (count == m) c++;
        return c;
    }

    int count_sum(int num) {
        int sum = 0;
        while (num)  {
            sum += num % 10;
            num /=10;
        }
        return sum;
    }
};