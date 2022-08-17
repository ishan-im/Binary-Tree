#include<bits/stdc++.h>
#include<queue>
#include<vector>

using namespace std;

template<typename T>

class TreeNode{

    public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i=0; i<children.size(); i++){
            delete children[i];
        }
    }
};


TreeNode<int> *takeInput(){

    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;

    TreeNode<int>*root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>*frontData = pendingNodes.front();

        pendingNodes.pop();

        cout<<"Enter number of child of :"<<frontData->data<<endl;

        int numChild;
        cin>>numChild;

        for(int i=0; i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<frontData->data<<endl;
            cin>>childData;

            TreeNode<int>*child = new TreeNode<int>(childData);
            frontData->children.push_back(child);
            pendingNodes.push(child);
        }

    }

    return root;
}

void preOrder(TreeNode<int> *root){

        if(root==NULL){
            return;
        }

        cout<<root->data<<" ";

        for(int i=0; i<root->children.size();i++){
            preOrder(root->children[i]);
        }
}


void postOrder(TreeNode<int> *root){
    if(root==NULL){
        return;
    }

    for(int i=0; i<root->children.size();i++){
        
        postOrder(root->children[i]);
    }

    cout<<root->data<<" ";
}

void deleteTree(TreeNode<int> *root){
    for(int i=0 ; i<root->children.size();i++){
        deleteTree(root->children[i]);
    }

    delete root;
}


int main(){
    TreeNode<int> * root = takeInput();
    postOrder(root);
    delete root;
}