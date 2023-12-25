class Solution {
public:
    vector<int> leftTree(Node *root,unordered_set<Node*> &s)
    {
        vector<int> ans;
        while(root!=NULL)
        {
            ans.push_back(root->data);
            s.insert(root);
            if(root->left!=NULL) root=root->left;
            else root=root->right;
        }
        return ans;
    }
    vector<int> rightTree(Node *root,unordered_set<Node*> &s)
    {
        vector<int> ans;
        while(root!=NULL)
        {
            if(!s.count(root))
            {
                ans.push_back(root->data);
                s.insert(root);
            }
            if(root->right!=NULL) root=root->right;
            else root=root->left;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void leafNodes(Node *root,vector<int> &leafNodesOfTree,unordered_set<Node*> &s)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) 
        {
            if(!s.count(root))
            {
                leafNodesOfTree.push_back(root->data);
                s.insert(root);
                return;
            }
        }
        leafNodes(root->left,leafNodesOfTree,s);
        leafNodes(root->right,leafNodesOfTree,s);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        unordered_set<Node*> s;
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {root->data};
        vector<int> ans;
        ans.push_back(root->data);
        vector<int> leftTreeNodes=leftTree(root->left,s);
        int i=0;
        if(leftTreeNodes.size()) 
        {
            ans.insert(ans.end(),leftTreeNodes.begin(),leftTreeNodes.end());
        }
        if(leftTreeNodes.size()>1) i=1;
        vector<int> leafNodesOfTree;
        leafNodes(root,leafNodesOfTree,s);
        if(leafNodesOfTree.size()) ans.insert(ans.end(),leafNodesOfTree.begin(),leafNodesOfTree.end());
        vector<int> rightTreeNodes=rightTree(root->right,s);
        
        if(rightTreeNodes.size()) ans.insert(ans.end(),rightTreeNodes.begin(),rightTreeNodes.end());
        
        return ans;
        
    }
};