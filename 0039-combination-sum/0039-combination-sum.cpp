class Solution {
public:
    void findCombination(int indx, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds){
        //Base case to stop recursion
        if(indx == arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick up the element
        if(arr[indx] <= target){
            ds.push_back(arr[indx]);
            //Pick recursion
            findCombination(indx,target-arr[indx],arr,ans,ds);
            ds.pop_back();
        }

        //Not pick recursion
        findCombination(indx+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0,target,candidates,ans,ds);
        return ans;
    }
};