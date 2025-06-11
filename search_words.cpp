#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

struct Node{
    bool isEnd = false;
    bool visit = false;
    Node* children[26] = {nullptr};
};

class SearchWords{
private:
    Node* root;
    vector<pair<int, int>> mov = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_set<string> res;

public:
    SearchWords(){
        root = new Node();
        res = unordered_set<string>();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();

        trie(root, words);

        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx = board[i][j] - 'a';
                if(root->children[idx]){
                    string word = "";
                    dfs(board, root, i, j, word, visit);
                }
            }
        }

        return vector<string>(res.begin(), res.end());
        
    }
    void dfs(vector<vector<char>>& board, Node* root, int r, int c, string& word, vector<vector<bool>>& visit){

        if(r < 0 || c < 0 || r >= board.size() || 
            c >= board[0].size()) return;
        
        char ch = board[r][c];
        int idx = ch - 'a';

        if(!root->children[idx] || visit[r][c]) return;

        word += ch;
        root = root->children[idx];
        visit[r][c] = true;

        if(root->isEnd){
            res.insert(word);
        }

        for(auto m : mov){
            int nr = r + m.first;
            int nc = c + m.second;
            dfs(board, root, nr, nc, word, visit);
        }
        
        word.pop_back();
        visit[r][c] = false;

    }

    void trie(Node* root, vector<string>& words){
        for(string word : words){
            Node* node = root;
            for(char c : word){
                int idx = c - 'a';
                if(!node->children[idx]) node->children[idx] = new Node();
                node = node->children[idx];
            }
            node->isEnd = true;
        }
    }

    void show_result(const vector<string>& result){
        for(const string& s : result){
            cout<< s << " ";
        }
    }
};