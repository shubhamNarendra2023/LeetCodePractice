class Solution {
public:
    void findCombination(int indx, int k, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(target == 0 && ds.size() == k){
            ans.push_back(ds);
            return;
        }

        if(ds.size() < k){
            for(int i = indx;i<=9;i++){
                if(target - i < 0)  break;
                //Pick element
                ds.push_back(i);
                findCombination(i+1,k,target-i,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombination(1,k,n,ans,ds);
        return ans;        
    }
};