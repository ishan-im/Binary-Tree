#include"TreeNode.h"

#include<bits/stdc++.h>

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


bool findX(TreeNode<int> *root, int x){

    if(root==NULL){
        return -1;
    }

    if(root->data == x){
        return true;
    }
    
    bool ans = false;

    for(int i=0; i<root->children.size();i++){
        bool  tempAns = findX(root->children[i],x);
        if(tempAns!=ans ){
            ans = true;
        }
       }

    return ans;
}

int main(){
    TreeNode<int> *root = takeInput();

    int find;
    cout<<"Enter data to check: "<<endl;
    cin>>find;

    cout<<findX(root,find)<<endl;
}