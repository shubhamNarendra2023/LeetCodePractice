class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1 || n==2)
        {
            return 0;
        }
        vector<bool> comp(n,false);
        for(int i=2;i<sqrt(n);i++)
        {
            if(comp[i]==false)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    comp[j]=true;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<comp.size();i++)
        {
            if(comp[i]==false)
            {
                cnt++;
            }
        }
        return cnt;
    }
};