class Solution {
    std::map<int, int> memory;

public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;

        for (int i = 3; i >= 1; i--) {
            if (memory.find(n-i) == memory.end()) {
                memory[n-i] = tribonacci(n-i);
            }
        }
       
        return memory[n-1] + memory[n-2] + memory[n-3];
    }
};