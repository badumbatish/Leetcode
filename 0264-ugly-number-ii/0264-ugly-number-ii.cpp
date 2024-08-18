class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int64_t> dp = {1};
        std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> pq;
        std::set<int64_t> considered = {1};
        pq.push(1);
        for (int i = 1; i <= n; i++)  {
            auto candidate = pq.top(); pq.pop();
            std::cout << candidate << std::endl;
            dp.push_back(candidate);
            considered.insert(candidate);
        
            if (!considered.count(candidate*2)) {
                pq.push(candidate * 2);
                considered.insert(candidate * 2);
            }
            
            if (!considered.count(candidate*3)) {
                pq.push(candidate * 3);
                considered.insert(candidate * 3);

            }
            if (!considered.count(candidate*5)) {
                pq.push(candidate * 5);
                considered.insert(candidate * 5);

            }

        }

        return dp[n];
    }
};