class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 0;
        for(int weight: weights) {
            right += weight;
        }
        while(left < right) {
            int mid = left + (right-left)/2;
            int current = 0;
            int daysNeeded = 1;
            for(int weight: weights) {
                if(current + weight > mid) {
                    daysNeeded++;
                    current = weight;
                } else {
                    current += weight;
                }
            }
            if(daysNeeded <= days) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};