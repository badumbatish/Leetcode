class Solution {
public:
    int minSwaps(string s) {
        stack<char> stack;
        int unbalanced = 0;
        for (char ch : s) {
            // If an opening bracket is encountered, push it in the stack.
            if (ch == '[') stack.push(ch);
            else {
                // If the stack is not empty, pop it.
                if (!stack.empty()) stack.pop();
                // Otherwise increase the count of unbalanced brackets.
                else
                    unbalanced++;
            }
        }
        return (unbalanced + 1) / 2;
    }
};