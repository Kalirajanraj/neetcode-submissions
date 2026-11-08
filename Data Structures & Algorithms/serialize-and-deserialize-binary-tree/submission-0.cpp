
class Codec {
public:
    string str;

    void serializeHelper(TreeNode* root, string& str)
    {
        if (root == nullptr)
        {
            str.append("N,");
            return;
        }

        str.append(to_string(root->val) + ",");

        serializeHelper(root->left, str);
        serializeHelper(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        str.clear();

        serializeHelper(root, str);

        return str;
    }

    vector<string> tokens;
    int index = 0;

    TreeNode* build()
    {
        string value = tokens[index++];

        if (value == "N") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = build();
        root->right = build();

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        tokens.clear();
        index = 0;

        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        return build();
    }
};
