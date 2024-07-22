class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int number_of_people = names.size();

        std::unordered_map<int, std::string> height_to_name_map;

        for (int i = 0; i < number_of_people; i++) {
            height_to_name_map[heights[i]] = names[i];
        }

        std::ranges::sort(heights);

        std::vector<std::string> sorted_names(number_of_people);
        for (int i = number_of_people - 1; i >= 0; i--) {
            sorted_names[number_of_people - i - 1] = 
                height_to_name_map[heights[i]];
        }

        return sorted_names;
    }
};