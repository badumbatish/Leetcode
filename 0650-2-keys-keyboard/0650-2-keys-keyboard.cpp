class Solution {
    int n;
public:
    int minSteps(int n) {
        this->n = n;
        if (n == 1) return 0;
        return 1 + rec(1, 1);
    }

    int rec(int current_length, int paste_length ){ 
        if (current_length == n) return 0;
        if (current_length > n) return 100000;
        int opt1 = 2 + rec(current_length * 2, current_length);
        int opt2 = 1 + rec(current_length + paste_length, paste_length);
        return std::min(opt1, opt2);
    }
};