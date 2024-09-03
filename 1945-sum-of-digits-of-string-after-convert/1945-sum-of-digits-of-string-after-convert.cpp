class Solution {
std::array<std::string, 26> smp = {
    "1",  "2",  "3",  "4",  "5",  "6",  "7",  "8",  "9", 
    "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", 
    "20", "21", "22", "23", "24", "25", "26"
};

public:
    int getLucky(string s, int k) {
        std::string first = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            std::cout << s[i] << " " << s[i] - 97 << " " << smp[s[i] - 97]<< std::endl;
            first+=(smp[s[i] - 97]);
        }
        std::cout << first << std::endl;
        while (k--) {
            first = transform(first);
                    std::cout << first << std::endl;

        }
        return std::stoi(first);
    }

    std::string transform(std::string i) {
        int sum = 0;
        for (auto ch : i) {
            sum += ch - '0';
        }

        return std::to_string(sum);
    }
};