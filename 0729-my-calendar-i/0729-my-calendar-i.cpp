class MyCalendar {
    std::vector<std::pair<int, int>> calendar;
public:
    MyCalendar() {
     
    }
    
    bool book(int startTime, int endTime) {
        for (const auto [s, e] : calendar) {
            if (startTime < e && s < endTime) return false;
        }
        calendar.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */