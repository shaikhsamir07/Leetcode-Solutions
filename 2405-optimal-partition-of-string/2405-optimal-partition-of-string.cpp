class Solution {
public:
    int partitionString(string s) {

        unordered_set<char> st;

        int count = 1;

        for (char ch : s) {

            if (st.count(ch)) {

                count++;

                st.clear();
            }

            st.insert(ch);
        }

        return count;
    }
};