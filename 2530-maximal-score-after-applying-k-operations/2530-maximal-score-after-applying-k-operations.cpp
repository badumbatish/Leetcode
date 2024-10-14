class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, less<>> pq; 

        for (auto num : nums) pq.push(num);

        int64_t max_score = 0;
        for (int i = 0; i < k; i++) {
            auto current = pq.top(); pq.pop();

            max_score += current;

            pq.push(std::ceil(current * 1.0 / 3));
        }

        return max_score;
    }
};