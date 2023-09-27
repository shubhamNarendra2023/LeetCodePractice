class Solution {
public:
    void findCombination(int indx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for(int i = indx; i < arr.size();i++){
            if(i > indx && arr[i] == arr[i - 1]){
                continue;
            }
            if(arr[i] > target){
                break;
            }
            ds.push_back(arr[i]);
            findCombination(i+1,target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};