#include"TreeNode.h"

#include<bits/stdc++.h>

using namespace std;

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

int countNodes(TreeNode<int> *root, int x){

    if(root == NULL){
        return 0;
    }

    int ans = 0;

    if(root->data>x){
        ans++;
    }

    for(int i = 0 ; i<root->children.size();i++){
       ans +=  countNodes(root->children[i],x);
       
    }
    return ans;
}

int main(){
    TreeNode<int> *root = takeInput();
    cout<<countNodes(root, 3);
}

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0