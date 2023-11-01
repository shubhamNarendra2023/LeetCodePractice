class Solution {
public:
    int numberOfSubstrings(string s) {
        int c[3]={0,0,0};
        int ans = 0;
        int n = s.size();
        int i=0,j=0;

        while(i<n){
            c[s[i]-'a']++;

            while(c[0]!=0 && c[1]!=0 && c[2]!=0){
                ans += n-i;
                c[s[j]-'a']--;
                j++;
            }
            i++;
        }
        return ans;
    }
};