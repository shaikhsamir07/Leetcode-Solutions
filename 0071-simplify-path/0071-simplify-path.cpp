class Solution {
public:
    string simplifyPath(string path) {

        vector<string> stack;
        string current;

        stringstream ss(path);

        // Split by '/'
        while (getline(ss, current, '/')) {

            if (current == "" ||
                current == ".") {

                continue;
            }

            // Go to parent directory
            if (current == "..") {

                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else {

                stack.push_back(current);
            }
        }

        // Build simplified path
        string result = "";

        for (string dir : stack) {

            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};