class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = arr.back();
        arr.back() = -1;
        for (int i = arr.size() - 2; i >= 0; i--) {
            auto temp = arr[i];
            
            arr[i] = maxi;
            maxi = std::max(temp, maxi);
        }

        return arr;
    }
};