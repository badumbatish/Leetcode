class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        std::sort(products.begin(), products.end());

        std::vector<std::vector<std::string>> result;

        std::string prefix;

        int start = 0, bsStart = 0, n = products.size();
        for (char ch : searchWord) 
        {
            prefix += ch;

            // Get the index where we'll start searching
            start = std::lower_bound(products.begin() , products.end(), prefix) -  products.begin();

            result.push_back({});

            // For each of the following three, compare the substring of the products[i] to prefix (in the same length context or less)
            // <= 0 if the products[i] is less than or equal.
            for (int i = start; i < min(start + 3, n) && products[i].compare(0, prefix.length(), prefix) <= 0; i++) 
            {
                result.back().push_back(products[i]);
            }

            //bsStart = start;
        }

        return result;
    }
};