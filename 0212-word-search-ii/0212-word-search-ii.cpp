class TrieNode {
public:

    TrieNode* children[26];
    bool isEnd;
    string word;

    TrieNode() {

        isEnd = false;
        word = "";

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:

    vector<string> ans;

    void insert(TrieNode* root, string word) {

        TrieNode* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->children[idx] == NULL) {
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i,
             int j,
             TrieNode* node) {

        char ch = board[i][j];

        if (ch == '#' || node->children[ch - 'a'] == NULL)
            return;

        node = node->children[ch - 'a'];

        if (node->isEnd) {

            ans.push_back(node->word);

            // Avoid duplicates
            node->isEnd = false;
        }

        board[i][j] = '#';

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (auto &d : dirs) {

            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 &&
                ni < board.size() &&
                nj < board[0].size()) {

                dfs(board, ni, nj, node);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for (string word : words) {
            insert(root, word);
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};