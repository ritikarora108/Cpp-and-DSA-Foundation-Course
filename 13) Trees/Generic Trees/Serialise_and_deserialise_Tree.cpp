// Serialise and De-serialise an N-ary Tree:

// Serializaation is the process of converting an object or data structure into a format
// that can be stored or transmitted .

// De-serialization is the process of converting the serialized string back into an object.

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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
string serializeTree(Node *root){
    if(root==NULL) return "";
    string ans="";
    ans+=to_string(root->val)+":"+to_string(root->children.size())+":";
    for(Node *child:root->children)
    {
        ans+=to_string(child->val)+",";
    }
    if(root->children.size()!=0) ans.pop_back();
    ans+="\n";
    for(Node *child:root->children)
    {
        ans+=serializeTree(child);
    }
    return ans;
}
Node *deserializeTreeHelper(unordered_map<int,string> &mp,int rootNode)
{
    Node *root=new Node(rootNode);
    string str=mp[rootNode];
    int s=0;
    int breakPos=str.find(':',s);
    int numOfChildren=stoi(str.substr(0,breakPos));
    if(numOfChildren==0) return root;
    string childStr=str.substr(breakPos+1);
    s=0;
    for(int i=0;i<numOfChildren;i++)
    {
        breakPos=childStr.find(',',s);
        if(breakPos==string::npos) breakPos=childStr.size();
        int childNode= stoi(childStr.substr(s,breakPos-s));
        root->children.push_back(deserializeTreeHelper(mp,childNode));
        s=breakPos+1;
    }
    return root;
}
Node *deserializeTree(string serializedTree)
{
    if(serializedTree=="") return NULL;
    unordered_map<int,string> mp;
    int start=0;
    for(int i=0;i<serializedTree.length();i++)
    {
        if(serializedTree[i]=='\n')
        {
            string str=serializedTree.substr(start,i-start);
            int s=0;
            int breakPos=str.find(':',s);
            int nodeValue=stoi(str.substr(s,breakPos-s));
            mp[nodeValue]=str.substr(breakPos+1);
            start=i+1;
        }
    }
    int rootNode=stoi(serializedTree.substr(0,serializedTree.find(':',0)));
    return deserializeTreeHelper(mp,rootNode);
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
            for(Node *child:currNode->children)
            {
                q.push(child);
            }
        }
        cout<<endl;
    }
    return;
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
    cout<<endl;
    string serializedTree = serializeTree(root);
    cout<<"Serialised Tree: "<<endl;
    cout<<serializedTree;
    cout<<endl;
    Node *newRoot= deserializeTree(serializedTree);
    levelOrderTraversal(newRoot);
    return 0;
}