class Solution {
    int n;
    std::vector<std::vector<int>> memo;
public:
    int minSteps(int n) {
        this->n = n;
        memo = std::vector<std::vector<int>>(n+1, std::vector<int>(n/2 + 1, 0));
        if (n == 1) return 0;
        return 1 + rec(1, 1);
    }

    int rec(int current_length, int paste_length ){ 
        if (current_length == n) return 0;
        if (current_length > n) return 100000;

        if (memo[current_length][paste_length] != 0) return memo[current_length][paste_length];
        int opt1 = 2 + rec(current_length * 2, current_length);
        int opt2 = 1 + rec(current_length + paste_length, paste_length);
        memo[current_length][paste_length] =  std::min(opt1, opt2);
        return memo[current_length][paste_length];
    }
};