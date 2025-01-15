class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::unordered_set<int> st;
        std::vector<int> ans;

        for (int i = 0; i < A.size(); i++) {
            st.insert(A[i]);
            st.insert(B[i]);
            ans.push_back(2 * (i+1) - st.size());
        }
        return ans;
    }
};