class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::string num = "123456789";

        int n = num.size();
        int low_len = std::to_string(low).size();
        int high_len = std::to_string(high).size();

        std::vector<int> result;
        for(int length = low_len; length <= high_len; length++) {
            for (int start = 0; start < n - length + 1; start++) {
                int number = std::stoi(num.substr(start, length ));
                std::cout << num.substr(start, length ) << std::endl;
                if (number >= low && number <= high) result.push_back(number);
            }
        }
        return result;
    }

    
};