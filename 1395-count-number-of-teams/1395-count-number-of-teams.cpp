class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        std::vector<std::vector<int>> increasing_cache(n, std::vector<int>(4, -1));
        std::vector<std::vector<int>> decreasing_cache(n, std::vector<int>(4, -1));

        for (int start = 0; start < n; start++) {
            teams +=
                count_insc(rating, start, 1, increasing_cache) +
                count_desc(rating, start, 1, decreasing_cache);
            std::cout << teams << std::endl;
        }

        return teams;
    }

    int count_insc(const std::vector<int>& rating, int curr, int team_size, std::vector<std::vector<int>>& cache) {
        int n = rating.size();
        if (curr == n) return 0;
        if (team_size == 3) return 1;

        if (cache[curr][team_size] != -1) return cache[curr][team_size];
        
        int valid_teams = 0;

        for (int next = curr + 1; next < n; next++) {
            if (rating[next] > rating[curr]) {
                valid_teams += count_insc(rating, next, team_size + 1, cache);
            }
        }
        

        return cache[curr][team_size] = valid_teams;
    }
int count_desc(const std::vector<int>& rating, int curr, int team_size, std::vector<std::vector<int>>& cache) {
        int n = rating.size();
        if (curr == n) return 0;
        if (team_size == 3) return 1;

        if (cache[curr][team_size] != -1) return cache[curr][team_size];
        
        int valid_teams = 0;

        for (int next = curr + 1; next < n; next++) {
            if (rating[next] < rating[curr]) {
                valid_teams += count_desc(rating, next, team_size + 1, cache);
            }
        }
        cache[curr][team_size] = valid_teams;

        return cache[curr][team_size] = valid_teams;
    }
    
};