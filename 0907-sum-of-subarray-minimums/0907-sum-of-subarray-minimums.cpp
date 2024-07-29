class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        std::stack<int> stck;
        int64_t sum_min = 0;

        for (int i = 0; i <= arr.size(); i++) {
            while (!stck.empty() && (i == arr.size() || arr[stck.top()] >= arr[i])) {
                int mid = stck.top(); stck.pop();

                int left_boundary = stck.empty() ? -1 : stck.top();
                int right_boundary = i;

                int64_t count = (mid - left_boundary) * (right_boundary - mid) % MOD;

                sum_min += (count * arr[mid]) % MOD;
                sum_min %= MOD;
            }
            stck.push(i);
        }

        return sum_min;
    }
};