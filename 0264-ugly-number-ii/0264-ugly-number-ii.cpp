class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int64_t> dp = {1};
        std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
        std::set<int64_t> considered = {1};

        std::vector<int64_t> multiplier = {2, 3, 5};
        pq.push(1);
        for (int i = 1; i <= n; i++)  {
            auto candidate = pq.top(); pq.pop();
            std::cout << candidate << std::endl;
            dp.push_back(candidate);

            for (auto mult : multiplier) {
                if (!considered.count(candidate*mult)) {
                    pq.push(candidate * mult);
                    considered.insert(candidate * mult);
                }
            }
            
    

        }

        return dp[n];
    }
};