class Solution {
public:
    string removeDuplicates(string s, int k) {
        // String would be best

        // Make a empty string
        // Push in until at least 3

        // On every push, we check if there is any k removeDuplicates
        // Remove if it does, then check again before push
        // Else continue;

        // return the string
        std::string result = "";

        for (char ch : s) {
            // "" a
            //.   aa 
            //    aaa

            if (result.size() < k - 1) {
                result.push_back(ch);
                continue;
            } 
            if (result.size() > 0 && result.back() != ch) {
                result.push_back(ch);
                continue;
            }

            result.push_back(ch);

            int count = 0;

            // 4 - 3 = 1
            for (int i = 0; i < result.size() + 1 - k ; i++) {
                for (int j = 0; j < k; j++) {
                    
                    if (result[i+j] == ch) count++;
                    else break; 
                }
                std::cout << std::endl;
                if (count == k) break;
                else {
                    count = 0;
                }
            }

            if (count == k) {
                while (count--) result.pop_back();
            }
        }

        return result;
    }
};