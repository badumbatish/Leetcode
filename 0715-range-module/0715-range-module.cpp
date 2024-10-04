#include <map>

class RangeModule {
public:
    std::map<int, int> intervals;  // stores [left, right) intervals
    
    RangeModule() {
    }
    
    // Add the range [left, right)
    void addRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        // Merge with the previous interval if needed
        if (it != intervals.begin() && prev(it)->second >= left) {
            it = prev(it);
        }
        
        // Merge all overlapping intervals
        while (it != intervals.end() && it->first <= right) {
            left = std::min(left, it->first);
            right = std::max(right, it->second);
            it = intervals.erase(it);  // Remove the interval
        }
        
        // Add the merged interval [left, right)
        intervals[left] = right;
    }
    
    // Remove the range [left, right)
    void removeRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        if (it != intervals.begin() && prev(it)->second > left) {
            it = prev(it);
        }
        
        // Split and remove overlapping intervals
        while (it != intervals.end() && it->first < right) {
            int l = it->first, r = it->second;
            it = intervals.erase(it);
            // If part of the current interval is before `left`, add [l, left)
            if (l < left) {
                intervals[l] = left;
            }
            // If part of the current interval is after `right`, add [right, r)
            if (r > right) {
                intervals[right] = r;
            }
        }
    }
    
    // Query if the range [left, right) is fully tracked
    bool queryRange(int left, int right) {
        // Find the first interval that starts at or after `left`
        auto it = intervals.lower_bound(left);
        
        // If the `left` is in the middle of an interval, move to that interval
        if (it != intervals.begin() && prev(it)->second > left) {
            it = prev(it);
        }
        
        // Check if the interval starting from `left` fully covers [left, right)
        if (it == intervals.end() || it->first > left || it->second < right) {
            return false;
        }
        
        return true;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
