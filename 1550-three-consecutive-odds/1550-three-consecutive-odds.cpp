class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() == 1) return false;
        if (arr.size() == 2) return false;

        bool flag = false;
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] % 2 == 1 && arr[i-1] % 2 == 1 && arr[i+1] % 2 == 1) {
                flag = true;
            }
        }

        return flag;
    }
};