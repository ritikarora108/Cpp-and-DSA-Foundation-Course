//  Root -> Left -> right
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->value=data;
        this->left=this->right=NULL;
    }
};
vector<int> preOrderTraversal(Node *root)
{
    if(root==NULL) return {};
    vector<int> ans;
    ans.push_back(root->value);
    vector<int> l=preOrderTraversal(root->left);
    vector<int> r=preOrderTraversal(root->right);
    if(l.size()) ans.insert(ans.end(),l.begin(),l.end());
    if(r.size()) ans.insert(ans.end(),r.begin(),r.end());
    return ans;
}
int main()
{
    Node *root=new Node(2);                                   //     2
    root->left=new Node(4);                                   //   4   10
    root->right=new Node(10);                                 //  6 5     11
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    vector<int> preOrder=preOrderTraversal(root);
    for(int i:preOrder) cout<<i<<" ";
    return 0;
}