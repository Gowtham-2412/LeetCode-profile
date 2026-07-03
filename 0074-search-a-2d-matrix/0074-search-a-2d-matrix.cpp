class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i<m; i++) {
            int left = 0;
            int right = n-1;
            if(target > matrix[i][right]) {
                continue;
            } else {
                while(left <= right) {
                    int mid = left + (right-left)/2;
                    if(target == matrix[i][mid]) {
                        return true;
                    } else if(target < matrix[i][mid]) {
                        right = mid-1;
                    } else {
                        left = mid+1;
                    }
                }
            }
        }
        return false;
    }
};