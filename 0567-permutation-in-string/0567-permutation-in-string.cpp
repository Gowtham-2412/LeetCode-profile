class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int left = 0;
        bool consist = false;
        int n = s1.size();
        sort(s1.begin(), s1.end());
        int right = left+n-1;
        while(right < s2.size()) {
            string sub = s2.substr(left, n);
            sort(sub.begin(), sub.end());
            if(s1 == sub) return true;
            left++;
            right++;
        }
        return false;
    }
};