class Solution {
public:

    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {

        if (mp.find(node) != mp.end())
            return mp[node];

        Node* cloneNode = new Node(node->val);

        mp[node] = cloneNode;

        for (auto neighbor : node->neighbors) {

            cloneNode->neighbors.push_back(dfs(neighbor));
        }

        return cloneNode;
    }

    Node* cloneGraph(Node* node) {

        if (!node)
            return NULL;

        return dfs(node);
    }
};