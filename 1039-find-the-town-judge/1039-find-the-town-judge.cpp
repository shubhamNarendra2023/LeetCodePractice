class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         vector<vector<int>> mat(n, vector<int>(n,0));
         for(vector<int> v : trust){
             mat[v[0]-1][v[1]-1] = 1;
         }

         stack<int> st;
         for(int i = 0;i<n;i++){
             st.push(i);
         }

         while(st.size() > 1){
             int a = st.top();
             st.pop();
             int b = st.top();
             st.pop();

             if(mat[a][b] == 1){
                 st.push(b);
                 continue;
             }
             else{
                 st.push(a);
                 continue;
             }
         }

         int ans = st.top();

         for(int i = 0;i<n;i++){
            if(i==ans)  continue;
            if(mat[ans][i] == 1)    return -1;
            if(mat[i][ans] == 0)    return -1;
         }

         return ans+1;
    }
};