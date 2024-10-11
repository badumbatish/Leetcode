class Solution {
    std::string result;
    std::vector<std::string> split_by_slashes(std::string &path) {
        std::stringstream ss(path);
        std::vector<std::string> split;        

        std::string temp;
        while (std::getline(ss, temp, '/')) {
            split.push_back(temp);
            std::cout << temp << std::endl;
        }

        return split;

    }
    void pop_while_equals(char ch, int size) {
        while (result.size() > size && result.back() == ch) result.pop_back();
    }
public:
    string simplifyPath(string path) {
        auto paths = split_by_slashes(path);

        std::vector<std::string> result;
        for (auto &path : paths) {
            if (path == "..") {
                if (result.size() >= 1) result.pop_back();
            } else if (path != "" && path != "."){
                result.push_back(path);
            }
        } 

        std::string result_string;
        for (auto r : result) {
            std::cout << r << "-";
            result_string += "/";
            result_string += r;
            
        }
        if (result_string == "") result_string = "/";
        return result_string;
    }
};