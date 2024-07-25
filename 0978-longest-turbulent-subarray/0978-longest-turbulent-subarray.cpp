class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 1; // minimum size 
        int anchor = 0;

        for (int i = 1; i < n; i++) {
            int c = get_sign(arr, i);

            if (c == 0) anchor = i;
            else if (i == n - 1 || c * get_sign(arr, i + 1) != -1) {
                // If we're at the end or the sign is not good anymore
                ans = std::max(ans, i - anchor + 1);
                anchor = i;
            }
        }

        return ans;
    }

    int get_sign(std::vector<int>& arr, int i) {
        int c = 0;
            if (arr[i] > arr[i-1]) c = -1;
            else if (arr[i] < arr[i-1]) c = 1;
            else c = 0;

        return c;
    }
};