class Solution {
public:

    bool searchNext(vector<vector<char>>& board, string word, int row,int col, int index, int n, int m){
        //Base case
        if(index == word.length()){
            return true;
        }

        //False case checking
        if(row<0 || col<0 || row==n || col==m || board[row][col] != word[index] || board[row][col] == '!'){
            return false;
        }

        //Not resusing character
        char c = board[row][col];
        board[row][col] = '!';

        //top backtrack
        bool top = searchNext(board,word,row-1,col,index+1,n,m);
        //bottom backtrack
        bool bottom = searchNext(board,word,row+1,col,index+1,n,m);
        //right backtrack
        bool right = searchNext(board,word,row,col+1,index+1,n,m);
        //left backtrack
        bool left = searchNext(board,word,row,col-1,index+1,n,m);

        board[row][col] = c;

        return top || bottom || left || right;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); // row size
        int m = board[0].size(); // column size

        int index = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[index]){
                    if(searchNext(board,word,i,j,index,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};