class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto sorted_arr = arr;
        std::sort(sorted_arr.begin(), sorted_arr.end());

        int rank = 1;
        std::map<int, int> int_to_rank;
        for (int i = 0; i < sorted_arr.size(); i++) {
            if (i > 0 && sorted_arr[i] != sorted_arr[i-1]){
                rank++;

            }
            int_to_rank[sorted_arr[i]] = rank;
        }


        for (auto & num : arr) {
            num = int_to_rank[num];
        }

        return arr;
    }
};