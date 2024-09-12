class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        std::unordered_set<char> st;
        for (auto ch : allowed) st.insert(ch);

        int count = 0;
        int proceed = false;
        for (auto& word : words) {

            for (auto ch : word) {
                proceed = true;
                if (!st.contains(ch)) {
                    proceed = false;
                    break;
                }
            }
            if (proceed) count++;
        }

        return count;
    }
};