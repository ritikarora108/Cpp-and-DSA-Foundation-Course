#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    char val;
    vector<Node*> children;     
    Node(char data)
    {
        this->val=data;
    }
};
vector<char> preorderTraversal(Node *root)   // root then children Nodes from L->R
{
    if(root==NULL) return {};
    if(root->children.size()==0) return {root->val};
    vector<char> ans;
    ans.push_back(root->val);
    for(Node* child:root->children)
    {
        vector<char> v=preorderTraversal(child);
        ans.insert(ans.end(),v.begin(),v.end());

    }
    return ans;

} 
vector<char> inorderTraversal(Node *root)   // Children Nodes from L->R except last Node , then root , then that Last child Node
{
    if(root==NULL) return {};
    if(root->children.size()==0) return {root->val}; //Leaf Node
    vector<char> ans;
    int numOfChildrenNodes=root->children.size();
    for(int i=0;i<numOfChildrenNodes-1;i++)
    {
        vector<char> v=inorderTraversal(root->children[i]);
        ans.insert(ans.end(),v.begin(),v.end());
    }
    ans.push_back(root->val);
    vector<char> v=inorderTraversal(root->children[numOfChildrenNodes-1]);
    ans.insert(ans.end(),v.begin(),v.end());
    return ans;
}
vector<char> postorderTraversal(Node *root) // Children Nodes from L->R , then root Node
{
    if(root==NULL) return {};
    if(root->children.size()==0) return {root->val};
    vector<char> ans;
    for(Node *child:root->children)
    {
        vector<char> v=postorderTraversal(child);
        ans.insert(ans.end(),v.begin(),v.end());
    }
    ans.push_back(root->val);
    return ans;
}
vector<vector<char>> levelorderTraversal(Node *root)
{
    if(root==NULL) return {};
    queue<Node*> q;
    q.push(root);
    vector<vector<char>> ans;
    while(!q.empty())
    {
        int nodesAtCurrentLevel=q.size();
        vector<char> v;
        while(nodesAtCurrentLevel--)
        {
            Node *currNode=q.front();
            q.pop();
            v.push_back(currNode->val);
            if(currNode->children.size()==0) continue; 
            for(Node* child:currNode->children)
            {
                q.push(child);
            }
        }
        ans.push_back(v);
    }
    return ans;
}
void print(vector<char> &v)
{
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
}
int main()
{
    Node *root=new Node('A');
    root->children.push_back(new Node('B'));
    root->children.push_back(new Node('C'));
    root->children.push_back(new Node('D'));
    root->children[0]->children.push_back(new Node('E'));
    root->children[0]->children.push_back(new Node('F'));
    root->children[2]->children.push_back(new Node('G'));
    
    vector<char> preorder=preorderTraversal(root);
    cout<<"PreOrder Traversal : "<<endl;
    print(preorder);

    vector<char> inorder=inorderTraversal(root);
    cout<<"InOrder Traversal : "<<endl;
    print(inorder);

    vector<char> postorder=postorderTraversal(root);
    cout<<"PostOrder Traversal : "<<endl;
    print(postorder);

    vector<vector<char>> levelorder=levelorderTraversal(root);
    cout<<"LevelOrder Traversal: "<<endl;
    for(auto v:levelorder)
    {
        print(v);
    }
    return 0;

}