#include "headers.h"
using namespace std;

class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    bool flag = search(board, word, i, j, 0);
                    if (flag) return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string& word, int i, int j,
                 int matchPos) {
        printf("on pos %d,%d \n",i,j);
        if (matchPos == word.size()) return true;
        if (i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        char match = word[matchPos];
        if (board[i][j]!=match) return false;
        board[i][j]='\0';
        bool flag=search(board,word,i-1,j,matchPos+1)||search(board,word,i+1,j,matchPos+1)||search(board,word,i,j+1,matchPos+1)||search(board,word,i,j-1,matchPos+1);
        board[i][j]=match;
        return flag;
    }
};

// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         unordered_set<string> path;
//         for(int i=0;i<board.size();i++){
//             for(int j=0;j<board[i].size();j++){
//                 if (board[i][j]==word[0]){
//                     string key=to_string(i)+to_string(j);
//                     path.insert(key);
//                     bool flag=search(board,word,i,j,path,1);
//                     if (flag) return true;
//                     path.clear();
//                 }
//             }
//         }
//         return false;
//     }
    
//     bool search(vector<vector<char>>& board,string& word,int i,int j,unordered_set<string>& path,int matchPos){
//         if (matchPos==word.size()) return true;
//         char match=word[matchPos];
//         printf("on pos %d,%d \n",i,j);
//         if (i+1<board.size()&&board[i+1][j]==match){
//             string key=to_string(i+1)+to_string(j);
//             if (path.find(key)== path.end()) {
//                 path.insert(key);
//                 bool flag = search(board,word,i+1,j,path,matchPos+1);
//                 if (flag) return true;
//                 path.erase(key);
//             }
//         }
//         if (i-1>=0&&board[i-1][j]==match){
//             string key=to_string(i-1)+to_string(j);
//             if (path.find(key)== path.end()) {
//                 path.insert(key);
//                 bool flag = search(board,word,i-1,j,path,matchPos+1);
//                 if (flag) return true;
//                 path.erase(key);
//             }
//         }

//         if(j+1<board[i].size()&&board[i][j+1]==match){
//             string key=to_string(i)+to_string(j+1);
//             if (path.find(key)== path.end()) {
//                 path.insert(key);
//                 bool flag = search(board,word,i,j+1,path,matchPos+1);
//                 if (flag) return true;
//                 path.erase(key);
//             }         
//         }
//         if(j-1>=0&&board[i][j-1]==match){
//             string key=to_string(i)+to_string(j-1);
//             if (path.find(key)== path.end()) {
//                 path.insert(key);
//                 bool flag = search(board,word,i,j-1,path,matchPos+1);
//                 if (flag) return true;
//                 path.erase(key);
//             }
//         }
//         return false;
//     }
// };


int main() {
    vector<vector<char>> x(30,vector<char>(30,'a'));
    x[29][29]='b';
    string word =
        "baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    Solution s;
    int w=word.size();
    bool flag=s.exist(x,word);
    return 0;
}