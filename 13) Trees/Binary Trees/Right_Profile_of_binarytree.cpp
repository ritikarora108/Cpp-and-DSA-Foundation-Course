// Given the root of a binary tree, imagine yourself standing on the right side of it,
// return the value of the nodes you can see from top to botttom.

#include<iostream>
#include<vector>
#include<queue>
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
vector<int> rightProfile(Node *root)
{
    if(root==NULL) return  {};
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty())
    {
        int nodesAtCurrentLevel=q.size();
        while(nodesAtCurrentLevel)
        {
            Node *currNode=q.front();
            q.pop();
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
            if(nodesAtCurrentLevel==1) ans.push_back(currNode->value);
            nodesAtCurrentLevel--;
        }
    }
    return ans;
}
int main()
{
    Node *root=new Node(2);          //     2
    root->left=new Node(4);          //   4   10
    root->right=new Node(10);        //  6 5     11
    root->left->left=new Node(6);    //     12
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    root->left->right->left=new Node(12);
    vector<int> rightView = rightProfile(root);
    for(int i:rightView) cout<<i<<endl;
    return 0;
}