class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a
        // palindrome, the first digit of the number also needs to be 0. Only 0
        // satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        size_t revertedNumber = 0;
        {
            size_t test = x;
            while (test) {
                revertedNumber = revertedNumber * 10 + test % 10;
                test /= 10;
        }
        }
        std::cout << revertedNumber << std::endl;

        // When the length is an odd number, we can get rid of the middle digit
        // by revertedNumber/10 For example when the input is 12321, at the end
        // of the while loop we get x = 12, revertedNumber = 123, since the
        // middle digit doesn't matter in palidrome(it will always equal to
        // itself), we can simply get rid of it.
        return x == revertedNumber;
    }
};