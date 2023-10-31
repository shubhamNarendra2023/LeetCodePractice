class Solution {
public:

    int solve(vector<int>& arr, int k){
        int l=0,c=0,total=0;
        for(int r=0;r<arr.size();r++){
            if(arr[r]%2!=0) c++;
            while(c>k){
                if(arr[l]%2!=0) c--;
                l++;
            }
            total += (r-l+1);
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};