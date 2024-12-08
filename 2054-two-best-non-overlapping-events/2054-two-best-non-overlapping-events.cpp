class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        //std::ranges::sort(events);

        std::map<int, int> mp;

        for (auto &event : events) {
            auto [a, b, c]= std::tuple{event[0], event[1], event[2]};

            mp[b] = std::max(mp[b], c);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            auto & [end_at, m] = *it;
            mp[end_at] = max(std::prev(it)->second, m);
            //std::cout << end_at << " " << mp[end_at] << std::endl;
        }

        int maxi = 0;
        for (auto &event : events) {
            auto a = event[0], c = event[2];

            auto i = mp.lower_bound(a);
            if (i != mp.begin()) i = std::prev(i);
            if (i->first >= a) maxi = std::max(maxi, c);
            else  maxi = std::max({maxi, c, i->second + c});
            //std::cout << i->first << " " << i->second << std::endl;
            
        }

        return maxi;
    }
};