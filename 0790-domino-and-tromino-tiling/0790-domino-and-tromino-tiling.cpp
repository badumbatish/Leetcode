class Solution {
    static constexpr int64_t MOD = 1'000'000'007;
    std::unordered_map<int64_t, int64_t> full_board_cache;
    std::unordered_map<int64_t, int64_t> partial_board_cache;

    int64_t full(int n) {
        if (full_board_cache.find(n) != full_board_cache.end()) {
            return full_board_cache[n];
        }

        int64_t val;
        if (n == 1 || n == 2) val = n;
        else val = (full(n-1) + full(n-2) + 2 * partial(n-1)) % MOD;

        full_board_cache[n] = val;

        return val;
    }

    int64_t partial(int n) {
         if (partial_board_cache.find(n) != partial_board_cache.end()) {
            return partial_board_cache[n];
        }

        int64_t val;
        if (n == 1 || n == 2) val = n-1;
        else val = (full(n-2) + partial(n-1)) % MOD;

        partial_board_cache[n] = val;

        return val;
    }
public:
    int numTilings(int n) {
        return full(n);
    }
};