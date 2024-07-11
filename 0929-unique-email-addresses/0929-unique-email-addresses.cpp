class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::set<std::pair<std::string, std::string>> distinct_emails;

        for (auto email : emails) {
            int at = email.find("@");
            auto local_name = email.substr(0, at);
            auto ok = email.substr(at);

            int plus = local_name.find("+");
            auto not_ignore = local_name.substr(0, plus);

            std::string s;
            for (auto ch : not_ignore) {
                if (ch != '.') s+=ch;
            }
            distinct_emails.insert({s, ok});
        }

        return distinct_emails.size();
    }
};