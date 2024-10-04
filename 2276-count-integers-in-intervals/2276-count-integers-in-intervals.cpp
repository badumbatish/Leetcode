#include <map>

class CountIntervals {
private:
    std::map<int, int> intervals;
    int totalCount;

public:
    CountIntervals() : totalCount(0) {}
    
    void add(int left, int right) {
        auto it = intervals.lower_bound(left);
        
        // Move 'it' back if it's not the first interval and might overlap with [left, right]
        if (it != intervals.begin() && prev(it)->second >= left) {
            --it;
        }
        
        // Merge overlapping intervals and update the total count
        while (it != intervals.end() && it->first <= right) {
            left = std::min(left, it->first);
            right = std::max(right, it->second);
            totalCount -= (it->second - it->first + 1); // Remove current interval from the count
            it = intervals.erase(it); // Remove the overlapping interval
        }
        
        // Add the new merged interval
        intervals[left] = right;
        totalCount += (right - left + 1); // Add the new merged interval to the count
    }
    
    int count() {
        return totalCount;
    }
};
