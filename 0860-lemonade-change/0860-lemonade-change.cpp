class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        std::map<int, int> moolahs;

        for (auto & bill : bills) {
            if (bill == 5) moolahs[5]++;
            else if (bill == 10) {
                if (moolahs[5] != 0) {
                    moolahs[5]--;
                    moolahs[10]++;
                } else return false;
            } else if (bill == 20) {
                if (moolahs[10] >= 1 && moolahs[5] >= 1) {
                    moolahs[10]--;
                    moolahs[5]--;
                    moolahs[20]++;
                } else if (moolahs[5] >= 3) {
                    moolahs[5] -= 3;
                    moolahs[20]++;
                } else return false;
            }
        }

        return true;
    }
};