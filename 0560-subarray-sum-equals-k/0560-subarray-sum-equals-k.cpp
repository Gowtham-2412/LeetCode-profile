class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int currentSum = 0;
        int result = 0;
        for(int num: nums) {
            currentSum += num;
            int diff = currentSum - k;
            result += prefixSum[diff];
            prefixSum[currentSum]++;
        }
        return result;
    }
};