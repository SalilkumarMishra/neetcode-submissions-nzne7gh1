/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Helper for serialization
    void dfs(TreeNode* root, string &res) {
        if (!root) {
            res += "N,";
            return;
        }

        res += to_string(root->val) + ",";
        dfs(root->left, res);
        dfs(root->right, res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfs(root, res);
        return res;
    }

    // Helper for deserialization
    TreeNode* build(vector<string> &nodes, int &i) {
        if (nodes[i] == "N") {
            i++;
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root->left = build(nodes, i);
        root->right = build(nodes, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        // Split string by ','
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int i = 0;
        return build(nodes, i);
    }
};
