// Time Complexity: O(n)
// Space Complexity: O(h)
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    vector<Node*> children;     
    Node(int data)
    {
        this->val=data;
    }
};
void justGreaterNodeHelper(Node *root,int x,Node *&minDiffNode)
{
    if(root==NULL) return;
    if((root->val > x) && (minDiffNode==NULL || root->val < minDiffNode->val)) minDiffNode=root;

    for(Node* child:root->children) 
    {
        justGreaterNodeHelper(child,x,minDiffNode);
    }
}
Node *justGreaterNode(Node *root,int x)
{
    Node *minDiffNode=NULL;
    justGreaterNodeHelper(root,x,minDiffNode);
    return minDiffNode;
}
int main()
{
    Node *root=new Node(20);
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(22));
    root->children[0]->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(12));
    root->children[0]->children[1]->children.push_back(new Node(10));
    root->children[0]->children[1]->children.push_back(new Node(14));

    int x=10;
    Node *ans=justGreaterNode(root,x);
    if(ans) cout<<ans->val<<" :)"<<endl;
    else cout<<"NULL :("<<endl;
    return 0;
}