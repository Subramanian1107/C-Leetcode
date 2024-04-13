class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate Rows
        unordered_set<char>st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
                if(st.find(board[i][j])!=st.end() && board[i][j] != '.')
                    return false;
                st.insert(board[i][j]);
            }
            cout<<endl;
            st.clear();
        }
        // Validate Columns
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(st.find(board[j][i]) != st.end() && board[j][i] != '.')
                    return false;
                st.insert(board[j][i]);
            }
            st.clear();
        }
        // Validate Each grid
        for(int p=0;p<3;p++){
            for(int i=0;i<3;i++){
                for(int j=3*p;j<3*(p+1);j++){
                    for(int k=3*i;k<3*(i+1);k++){
                        if(st.find(board[j][k]) != st.end() && board[j][k] != '.')
                            return false;
                        st.insert(board[j][k]);
                    }
                }
                st.clear();
            }
        }
        return true;

    }
};