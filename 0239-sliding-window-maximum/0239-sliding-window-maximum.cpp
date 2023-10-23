class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        for(int i = 0;i<nums.size();i++){
            //pop from front of deque
            if(!dq.empty() && dq.front() == (i-k))  dq.pop_front();
            //pop from back of deque but check recursively
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            //push in deque from back
            dq.push_back(i);
            //Check condition to insert in ans vector
            if(i>=k-1)  ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};