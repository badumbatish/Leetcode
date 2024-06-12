#if PARALLEL
#include <execution>
#define SEQ std::execution::seq,
#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return std::reduce(PAR nums.begin(), nums.end(), 0, std::bit_xor<int>());
    }
};