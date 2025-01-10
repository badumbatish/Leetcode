class Solution {

    std::unordered_map<std::string, std::unordered_map<char, int>> precompute_word_map(std::vector<std::string>& words) {
        std::unordered_map<std::string, std::unordered_map<char, int>> word_map;
        for (auto &word : words) {
            auto &w = word_map[word];
            for (auto &ch : word) w[ch]++;
        }
        std::cout << "Size : " << word_map.size() << std::endl;
        return word_map;
    }
    std::unordered_map<char, int> precompute_candidate(std::vector<std::string>& words) {

        std::unordered_map<char, int> mp; 

        for (auto &word : words) {

            std::unordered_map<char, int> sub_mp;
            for (auto &ch : word) sub_mp[ch]++;
            
            for (auto &[key, value] : sub_mp) mp[key] = std::max(mp[key], value);
        }

        

        return mp;
    }

    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
       std::vector<std::string> result;

       auto word_map= precompute_word_map(words1);
       auto maximum_occ_map = precompute_candidate(words2);

       for (auto &word : words1) {
            auto &w = word_map[word];

            bool qualified = true;
            for (auto [key, value] : maximum_occ_map) {
                if (value > w[key]) {
                    qualified = false;
                    break;
                }
            }
            if (qualified) result.push_back(word);
       }
       return result;
    }

    
};