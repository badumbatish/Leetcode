class Solution {
    std::vector<std::vector<int>> memo;
    int shelfWidth;
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memo = std::vector<std::vector<int>>(books.size(), std::vector<int>(shelfWidth + 1, 0));
        this->shelfWidth = shelfWidth;

        return dp_helper(books, 0, shelfWidth, 0);
    }

    int dp_helper(std::vector<std::vector<int>> &books, int i, int remaining_shelf_width, int max_height) {
        std::vector<int> current_book = books[i];
        int max_height_updated = max(max_height, current_book[1]);

        if (i == books.size() - 1) {
            if (remaining_shelf_width >= current_book[0]) return max_height_updated;
            return max_height + current_book[1];
        }

        if (memo[i][remaining_shelf_width] != 0) return memo[i][remaining_shelf_width];

        int option_1_height = max_height + dp_helper(books, i+1, shelfWidth - current_book[0], current_book[1]);
        if (remaining_shelf_width >= current_book[0]) {
            int option_2_height = dp_helper(books, i+1, remaining_shelf_width - current_book[0], max_height_updated);
            memo[i][remaining_shelf_width] = min(option_1_height, option_2_height);
            return memo[i][remaining_shelf_width];
        }
        memo[i][remaining_shelf_width] = option_1_height;
        return memo[i][remaining_shelf_width];
    }
};