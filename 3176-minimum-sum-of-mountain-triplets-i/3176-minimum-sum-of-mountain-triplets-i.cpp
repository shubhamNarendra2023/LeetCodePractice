class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int minSum=INT_MAX;
        if(n<3) return -1;
        
        vector<int> left_min(n);
        left_min[0] = nums[0];
        for(int i = 1;i<n;i++){
            left_min[i] = min(left_min[i-1],nums[i]);
        }

        vector<int> right_min(n);
        right_min[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            right_min[i] = min(right_min[i+1],nums[i]);
        }

        for(int i = 1;i<n-1;i++){
            if(nums[i]>left_min[i-1] && nums[i]>right_min[i+1]){
                minSum = min(minSum,left_min[i-1]+nums[i]+right_min[i+1]);
            }
        }
        
        if(minSum==INT_MAX){
            return -1;
        }
        
        return minSum;        
    }
};