class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> matching = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char c : s) {
            if (matching.count(c)) {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (top != matching[c]) {
                    return false;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};