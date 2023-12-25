#include<iostream>
#include<stack>
#include<queue>
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
vector<int> reverseLevelOrder(Node *root)
{
    if(root==NULL) return {};
    queue<Node*> q;
    q.push(root);
    vector<int> ans;
    stack<int> s;
    while(!q.empty())
    {
        int nodesAtCurrentLevel=q.size();
        while(nodesAtCurrentLevel--)
        {
            Node *currNode=q.front();
            q.pop();
            if(currNode->right) q.push(currNode->right);
            if(currNode->left) q.push(currNode->left);
            s.push(currNode->value);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
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
    vector<int> v=reverseLevelOrder(root);
   
    for(auto j:v) cout<<j<<" ";
    cout<<endl;
    
    return 0;
}