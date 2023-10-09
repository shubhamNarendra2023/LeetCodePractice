class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
        int start=0;
        int end=n-1;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());

        int t1, t2;

        while(start<end){
            if(temp[start]+temp[end]==target){
                    t1=temp[start];
                    t2=temp[end];
                    break;
            }
            else if(temp[start]+temp[end]<target){
                start++;
            }
            else{
                end--;
            }
        }

        vector<int> ans;

        for(int i=0; i<n;i++){
            if(nums[i]==t1){
                ans.push_back(i);
            }
        }

        for(int i=0; i<n;i++){
            if(nums[i]==t2 && t1!=t2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};