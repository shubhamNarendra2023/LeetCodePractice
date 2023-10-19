#include<bits/stdc++.h>
class Solution {
public:
    long long sumSubarrayComp(vector<int>& n, function<bool (int, int)> comp){
        long long res = 0;
        vector<int> s;
        for(int i = 0;i <= n.size(); ++i){
            while(!s.empty() && (i == n.size() || comp(n[s.back()], n[i]))){
                int j = s.back(), k = s.size() < 2 ? -1 : s[s.size() - 2];
                res += (long long)(i - j) * (j - k) * n[j];
                s.pop_back();
            }
            s.push_back(i);
        }
        return res;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayComp(nums, less<int>()) - sumSubarrayComp(nums, greater<int>());
    }
};