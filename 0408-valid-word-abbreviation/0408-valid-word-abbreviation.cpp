class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j =0;
        int m = word.size(), n = abbr.size();
        while ( i <  m && j < n) {
            if (word[i] == abbr[j]) {
                i++;
                j++;

            }  else if (abbr[j] - '0' == 0) {
                return false;
            } else {
                int current_number = 0;

                do {
                    current_number = current_number * 10 + (abbr[j]- '0');
                    j++;
                } while (isdigit(abbr[j]));

                std::cout << "i : " << i << std::endl;
                i += current_number;
            }
        }

        return i == m && j == n;
    }
};