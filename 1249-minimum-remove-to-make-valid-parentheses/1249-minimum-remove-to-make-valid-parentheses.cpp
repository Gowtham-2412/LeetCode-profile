class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> p;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(') {
                p.push(i);
            } 
            if(c == ')') {
                if(!p.empty()) {
                    p.pop();
                } else {
                    s[i] = '*';
                }
            }
        }
        if(!p.empty()) {
            while(!p.empty()) {
                s[p.top()] = '*';
                p.pop();
            }
        }
        string result;
        for(char c:s) {
            if(c == '*') {
                continue;
            }
            result.push_back(c);
        }
        return result;
    }
};