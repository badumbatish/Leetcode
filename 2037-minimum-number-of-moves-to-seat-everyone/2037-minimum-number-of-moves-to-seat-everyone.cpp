class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::ranges::sort(seats);
        std::ranges::sort(students);

        int count = 0;
        for (int i = 0; i < seats.size(); i++) {
            count += std::abs(seats[i] - students[i]);
        }

        return count;
    }
};