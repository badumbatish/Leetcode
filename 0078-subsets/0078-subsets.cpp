class Solution {
    int n;
    using Subset = std::vector<int>;
    std::vector<Subset> result;
private:
    void print_subset(Subset& s) {
        for (auto i : s) std::cout << i << " ";

        std::cout << std::endl;
    }
    void backtrack(int index, std::vector<int>& nums, Subset& s) {
        print_subset(s);
        result.push_back(s);
        if (index == n) return;

        for (int i = index; i < n; i++) {
            s.push_back(nums[i]);
            backtrack(i+1, nums, s);
            s.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       this->n = nums.size(); 

        Subset s;
        backtrack(0, nums, s);

        return result;
    }

};