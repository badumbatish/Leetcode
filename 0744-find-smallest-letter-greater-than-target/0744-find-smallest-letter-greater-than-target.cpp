class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;

        char result = letters.front();

        while (left <= right) {
            int mid = (left + right) / 2;

            if (target < letters[mid]) {
                result = letters[mid];
                right = mid - 1;
            } else left = mid + 1;
        }
        return result; 
    }
};