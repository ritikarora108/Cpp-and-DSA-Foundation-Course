#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
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
void mirror(Node *root)
{
    if(root==NULL || root->children.size()==0) return;
    for(Node *child:root->children)
    {
        mirror(child);
    }
    reverse(root->children.begin(),root->children.end());
}
void levelOrderTraversal(Node *root)
{
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int nodesAtCurrentLevel=q.size();
        while(nodesAtCurrentLevel--)
        {
            Node *currNode=q.front();
            q.pop();
            cout<<currNode->val<<" ";
            for(Node* child:currNode->children)
            {
                q.push(child);
            }
        }
        cout<<endl;
    }
}
int main()
{
    Node *root=new Node(10);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(56));
    root->children.push_back(new Node(100));
    root->children[1]->children.push_back(new Node(1));
    root->children[3]->children.push_back(new Node(7));
    root->children[3]->children.push_back(new Node(8));
    root->children[3]->children.push_back(new Node(9));
    levelOrderTraversal(root);
    cout<<endl<<"After Mirroring: "<<endl;
    mirror(root);
    levelOrderTraversal(root);
    return 0;
}