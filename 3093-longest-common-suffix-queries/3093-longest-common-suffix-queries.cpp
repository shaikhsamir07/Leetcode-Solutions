class Solution {
public:
    struct Node {
        int child[26];
        int bestIdx;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
        }
    };

    vector<Node> trie;
    vector<string>* words;

    bool better(int a, int b) {
        if (b == -1) return true;

        int la = (*words)[a].size();
        int lb = (*words)[b].size();

        if (la != lb) return la < lb;
        return a < b;
    }

    void update(int node, int idx) {
        if (better(idx, trie[node].bestIdx))
            trie[node].bestIdx = idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        words = &wordsContainer;

        trie.clear();
        trie.emplace_back(); // root

        for (int i = 0; i < wordsContainer.size(); i++) {
            string &s = wordsContainer[i];

            int cur = 0;
            update(cur, i);

            for (int j = (int)s.size() - 1; j >= 0; --j) {
                int c = s[j] - 'a';

                if (trie[cur].child[c] == -1) {
                    trie[cur].child[c] = trie.size();
                    trie.emplace_back();
                }

                cur = trie[cur].child[c];
                update(cur, i);
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for (string &q : wordsQuery) {
            int cur = 0;
            int res = trie[0].bestIdx;

            for (int j = (int)q.size() - 1; j >= 0; --j) {
                int c = q[j] - 'a';

                if (trie[cur].child[c] == -1)
                    break;

                cur = trie[cur].child[c];
                res = trie[cur].bestIdx;
            }

            ans.push_back(res);
        }

        return ans;
    }
};