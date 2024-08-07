#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[i].size(); j++){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if(index == word.length())
            return true;
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[index])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool found = dfs(board, i - 1, j, word, index + 1) ||
                     dfs(board, i + 1, j, word, index + 1) ||
                     dfs(board, i, j - 1, word, index + 1) ||
                     dfs(board, i, j + 1, word, index + 1);
        
        board[i][j] = temp;
        
        return found;
    }
};

int main(){
    Solution S;
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word = "ABCCED";
    cout << S.exist(board, word) << endl; // Output: true
    return 0;
}