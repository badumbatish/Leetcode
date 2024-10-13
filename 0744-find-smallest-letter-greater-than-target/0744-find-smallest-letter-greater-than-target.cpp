class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;

        char result = letters.front();

        while (left <= right) {
            int mid = (left + right) / 2;
            // if the current one is equal to target 

            // if the current one is larger than target, then we should shrink our right
            if (letters[mid] > target) {
               right = mid - 1; 
                result = letters[mid];
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};