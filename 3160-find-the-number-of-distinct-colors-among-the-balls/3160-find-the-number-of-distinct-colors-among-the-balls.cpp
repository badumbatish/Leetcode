class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        std::unordered_set<int> distinct_color;
        std::unordered_map<int, int> color_directory, color_count;

        std::vector<int> query_answer;
        for (auto q : queries) {
            auto ball = q[0], color = q[1];
            if (!color_directory.contains(ball)) {
                color_directory[ball] = color;
                color_count[color]++;
            } else {
                auto ball_color = color_directory[ball];
                if (ball_color != color) {
                    color_count[ball_color]--;
                    if (color_count[ball_color] == 0) color_count.erase(ball_color);
                    color_count[color]++;
                } 
                color_directory[ball] = color;
            }


            query_answer.push_back(color_count.size());
        }    
        return query_answer;
    }
};