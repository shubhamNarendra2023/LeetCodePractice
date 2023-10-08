class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> indices;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) indices.emplace_back(i);
        }
        int m = indices.size();
        if (m % 2) return -1;
        if (m == 0) return 0;
        int dp2 = x;
        int dp1 = min(dp2 + x, 2 * (indices[m - 1] - indices[m - 2]));
        for (int i = m - 3; i >= 0; --i) {
            int temp = dp1;
            dp1 = min(dp1 + x, dp2 + 2 * (indices[i + 1] - indices[i]));
            dp2 = temp;
        }
        return dp1 / 2;
    }   
};