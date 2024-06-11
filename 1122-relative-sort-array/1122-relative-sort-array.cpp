class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        std::map<int, int> ordering;
        for (int i = 0; i < arr2.size(); i++) {
            ordering[arr2[i]] = arr2.size() - i ;
        }

        std::ranges::sort(arr1, [&ordering](auto a, auto b){ 
            if (ordering[a] == ordering[b] && ordering[a] == 0) return a < b;
            return ordering[a] > ordering[b];
            });


        return arr1;
    }
};