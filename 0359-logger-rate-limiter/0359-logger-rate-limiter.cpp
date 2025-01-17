class Logger {
    std::unordered_map<std::string, int> msg_map;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (!msg_map.contains(message) || msg_map[message] + 10 <= timestamp) {
            msg_map[message] = timestamp;
            return true;
        } else return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */