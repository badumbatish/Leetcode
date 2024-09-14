class Solution {
    std::string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

private:
    std::string get_rand_str() {
        int i = rand() % (alphabet.size() - 6);
        return alphabet.substr(i, 6);
    }
public:
    std::unordered_map<std::string, std::string> mp;
    // Encodes a URL to a shortened URL.


    string encode(string longUrl) {
        std::string key = "";
        while (true) {
            auto key = get_rand_str();
            if (mp.contains(key)) continue;
            else break;
        }

        mp[key] = longUrl;

        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        std::string tinyurl = "http://tinyurl.com/";
        return mp[shortUrl.substr(tinyurl.size())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));