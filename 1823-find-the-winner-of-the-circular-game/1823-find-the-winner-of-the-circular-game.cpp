class Solution {
public:
    int findTheWinner(int n, int k) {
        std::queue<int> q;

        for (int i = 1; i <= n; i++) q.push(i);
        
        while (q.size() > 1) {
            for (int u = 0; u < k - 1; u++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();


    }
};