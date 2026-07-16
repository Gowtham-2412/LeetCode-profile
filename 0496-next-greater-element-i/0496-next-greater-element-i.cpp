class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>
            nextGreater; // value in nums2 -> next greater value
        stack<int> st;   // will store values from nums2

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int x = nums2[i];

            // Pop all elements <= current; they cannot be next greater for x
            while (!st.empty() && st.top() <= x) {
                st.pop();
            }

            // If stack not empty, its top is the next greater; else -1
            nextGreater[x] = st.empty() ? -1 : st.top();

            // Push current element onto stack
            st.push(x);
        }

        // Build answer for nums1
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1) {
            ans.push_back(nextGreater[x]);
        }

        return ans;
    }
};