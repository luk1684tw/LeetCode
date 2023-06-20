class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<Node*> traverse;
        Node* head = root;
        int power = 1;
        int count = 1;
        int next_border = 3;
        while (head != nullptr) {
            traverse.push(head->left);
            traverse.push(head->right);

            if (head->left != nullptr) {
                head->left->next = head->right;
            }

            head = traverse.front();
            count++;
            traverse.pop();
            if (head != nullptr) {
                if (count != next_border) {
                    head->next = traverse.front();
                } else {
                    next_border += (2 << power);
                    power ++;
                }
            }
        }
        return root;
    }
};