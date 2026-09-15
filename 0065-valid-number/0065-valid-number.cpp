class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool digitAfterExp = true;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Digit
            if (isdigit(c)) {
                digit = true;

                if (exp)
                    digitAfterExp = true;
            }

            // Dot
            else if (c == '.') {
                // Dot cannot appear twice or after exponent
                if (dot || exp)
                    return false;

                dot = true;
            }

            // Exponent
            else if (c == 'e' || c == 'E') {
                // Exponent can appear only once
                // and there must be a digit before it
                if (exp || !digit)
                    return false;

                exp = true;
                digitAfterExp = false;
            }

            // Sign
            else if (c == '+' || c == '-') {
                // Sign is valid only at beginning
                // or immediately after e/E
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }

            // Anything else is invalid
            else {
                return false;
            }
        }

        return digit && digitAfterExp;
    }
};