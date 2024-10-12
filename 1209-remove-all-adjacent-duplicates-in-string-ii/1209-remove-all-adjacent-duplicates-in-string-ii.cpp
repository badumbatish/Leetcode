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

        int check_from = 0;
        for (char ch : s) {
            // "" a
            //.   aa 
            //    aaa

            if (result.size() < k - 1 ) {
                result.push_back(ch);
                continue;
            }
            result.push_back(ch);

            int count = 0;

            // 4 - 3 = 1
            for (int i = check_from; i < result.size() + 1 - k ; i++, check_from++) {
                for (int j = 0; j < k; j++) {
                    
                    if (result[i+j] == ch) count++;
                    else break; 
                }
                if (count == k) break;
                else {
                    count = 0;
                }
            }
            // checks up to k and nothing happens
            // do we really need to recheck up to k again?
            if (count == k) {
                result.resize(result.size() - count);
                check_from = 0;
            } 
        }

        return result;
    }
};