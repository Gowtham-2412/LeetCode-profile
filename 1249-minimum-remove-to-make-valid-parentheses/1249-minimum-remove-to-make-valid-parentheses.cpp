class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> p;
        vector<int> toRemove;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(c == '(') {
                p.push(i);
            } 
            if(c == ')') {
                if(!p.empty()) {
                    p.pop();
                } else {
                    toRemove.push_back(i);
                }
            }
        }
        if(!p.empty()) {
            while(!p.empty()) {
                toRemove.push_back(p.top());
                p.pop();
            }
        }
        string result;
        for(int i = 0; i < s.size(); i++) {
            if(count(toRemove.begin(), toRemove.end(), i) > 0) {
                continue;
            }
            result.push_back(s[i]);
        }
        return result;
    }
};