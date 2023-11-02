class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int i=0;
        int j = n-k;
        int sum = 0;
        //First calculate sum of last k numbers
        for(int j=n-k;j<n;j++){
            sum += cardPoints[j];
        }
        int ans = 0;
        ans = max(ans,sum);

        while(j<n){
            sum -= cardPoints[j];
            sum += cardPoints[i];
            i++;
            j++;
            ans = max(sum,ans);
        }
        return ans;
    }
};