class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor==-1){
            return INT_MAX;
        }
        int ans = dividend/divisor;
        if(ans>INT_MAX){
            return INT_MAX-1;
        }
        else if(ans<INT_MIN){
            return INT_MIN;
        }
        return ans;
    }
};