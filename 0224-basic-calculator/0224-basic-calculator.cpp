class Solution {
public:
    int calculate(string s) {

        stack<long long> st;

        long long result = 0;
        long long number = 0;
        long long sign = 1;

        for (int i = 0; i < s.length(); i++) {

            char c = s[i];

            // Build number
            if (isdigit(c)) {

                number = number * 10 + (c - '0');
            }

            else if (c == '+') {

                result += sign * number;
                number = 0;
                sign = 1;
            }

            else if (c == '-') {

                result += sign * number;
                number = 0;
                sign = -1;
            }

            else if (c == '(') {

                // Save current result and sign
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (c == ')') {

                result += sign * number;
                number = 0;

                // Apply sign before bracket
                result *= st.top();
                st.pop();

                // Add previous result
                result += st.top();
                st.pop();
            }
        }

        // Add remaining number
        result += sign * number;

        return (int)result;
    }
};