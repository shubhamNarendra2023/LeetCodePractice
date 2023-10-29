class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,c=0,ans=0;
        vector<int> temp(28);

        for(int r=0;r<s.size();r++){
            temp[s[r]-'A']++;
            c=max(c,temp[s[r]-'A']);
            while(r-l+1-c>k){
                temp[s[l]-'A']--;
                l++;
            }
            ans = max(ans,r-l+1);
        }

        return ans;
    }
};