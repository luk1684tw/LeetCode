class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q; 
        q.push(root);
        int flag=0; // to perform zigzag on its change
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(flag==0){
                    level[i]=node->val; // if flag is 0 that means no need to reverse 
                    //so store it in vector from starting only
                }
                else level[size-1-i]=node->val; // otherwise start filling from back
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag=!flag; // flip the value after every level
            ans.push_back(level);
        }
        return ans;
    }
};