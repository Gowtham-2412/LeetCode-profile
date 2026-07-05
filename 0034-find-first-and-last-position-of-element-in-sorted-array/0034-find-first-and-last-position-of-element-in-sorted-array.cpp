class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findPosition(nums, target, true);
        int second = findPosition(nums, target, false);
        return {first, second};
    }
private:
    int findPosition(vector<int>& nums, int target,  bool isFirst) {
        int left = 0;
        int right = nums.size()-1;
        int pos = -1;
        while(left <= right) {
            int mid = left + (right-mid)/2;
            if(nums[mid] == target) {
                pos = mid;
                isFirst ? right = mid-1 : left = mid+1;
            } else if(nums[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return pos;
    }
};