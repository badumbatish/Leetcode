class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int64_t sum = 0;

        int finish_time = 0;

        for (auto &customer : customers) {
            finish_time = max(finish_time, customer[0]) + customer[1];

            sum += finish_time - customer[0];
            

            std::cout << sum << " " << finish_time << std::endl;
            
        }

        
        return sum * 1.0 / customers.size();
    }
};