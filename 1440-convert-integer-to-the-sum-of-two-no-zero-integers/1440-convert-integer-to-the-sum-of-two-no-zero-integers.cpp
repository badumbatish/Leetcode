class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int first = 0;
        int power = 1; 
        
        while (power <= n) {
            int digit = (n / power) % 10; 
            
            if (digit == 1) {
                if (power * 10 > n) break; 
                first += 2 * power;
                n -= 2 * power;
            } else {
                first += power;
                n -= power;
            }
            std::cout << first << " " << n << std::endl;
            power *= 10;
        }
        
        return {first, n}; 
    }
};