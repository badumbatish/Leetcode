class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> answer(n);

        std::stack<int> stck;

        for (int curr = 0; curr < n; curr++) {
            int current_temp = temperatures[curr];
            
            while (!stck.empty() && temperatures[stck.top()] < current_temp) {
                int prev_day = stck.top(); stck.pop();
                answer[prev_day] = curr - prev_day;
            }
            stck.push(curr);

        }

        return answer;
    }
};