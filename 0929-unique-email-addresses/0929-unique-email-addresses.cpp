class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;

        for (string email : emails) {
            string local = "";
            string domain = "";

            int at = email.find('@');

            local = email.substr(0, at);
            domain = email.substr(at + 1);

            string cleaned = "";

            for (char ch : local) {
                if (ch == '+') {
                    break;  // Ignore everything after '+'
                }

                if (ch != '.') {
                    cleaned += ch;
                }
            }

            uniqueEmails.insert(cleaned + "@" + domain);
        }

        return uniqueEmails.size();
    }
};