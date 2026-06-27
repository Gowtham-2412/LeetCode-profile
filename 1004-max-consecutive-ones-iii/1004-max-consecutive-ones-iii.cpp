class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int n = A.size();
        int left = 0, maxLength = 0;
        int zeroes = 0;
        for(int right = 0; right < n; right++) {
            if(A[right] == 0) {
                zeroes++;
            }
            while(zeroes > k) {
                if(A[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            maxLength = max(maxLength, (right-left+1));
        }
        return maxLength;
    }
};