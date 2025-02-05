class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        // Step 1: Construct nodes and establish parent-child relationships
        for (auto& desc : descriptions) {
            int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];

            // Create parent node if not already created
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }

            // Create child node if not already created
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }

            // Establish the parent-child relationship
            if (isLeft) {
                nodeMap[parentVal]->left = nodeMap[childVal];
            } else {
                nodeMap[parentVal]->right = nodeMap[childVal];
            }

            // Track child nodes
            children.insert(childVal);
        }

        // Step 2: Find the root (a node that is never a child)
        TreeNode* root = nullptr;
        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            if (children.find(parentVal) == children.end()) {
                root = nodeMap[parentVal];
                break;
            }
        }

        return root;
    }
};

