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
vector<vector<int>> levelOrderTraversal(Node *root)
{
    if(root==NULL) return {};
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty())
    {
        int nodesAtCurrentLevel= q.size();
        vector<int> temp;
        while(nodesAtCurrentLevel--)
        {
            Node *currNode=q.front();
            q.pop();
            temp.push_back(currNode->value);
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    Node *root=new Node(2);         //     2
    root->left=new Node(4);         //   4   10
    root->right=new Node(10);       //  6 5     11
    root->left->left=new Node(6);
    root->left->right=new Node(5);
    root->right->right=new Node(11);
    vector<vector<int>> level= levelOrderTraversal(root);
    for(auto itr: level)
    {
        for(auto i:itr) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}