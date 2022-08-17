#include"TreeNode.h"
#include<bits/stdc++.h>

using namespace std;

TreeNode<int> *takeInput(){
        int rootData;
        cout<<"Enter root data"<<endl;
        cin>>rootData;

        TreeNode<int> *root = new TreeNode<int>(rootData);

        queue<TreeNode<int> *> pendingNodes;
        pendingNodes.push(root);

        while(pendingNodes.size()!=0){

            TreeNode<int>* frontData = pendingNodes.front();
            pendingNodes.pop();

            cout<<"Enter the number of child of "<<frontData->data<<endl;
            int numChild;
            cin>>numChild;

            for(int i=0; i<numChild;i++){

                int childData;
                cout<<"Enter "<<i<<"th child of "<<frontData->data<<endl;
                cin>>childData;

                TreeNode<int> *child = new TreeNode<int>(childData);

                pendingNodes.push(child);
                frontData->children.push_back(child);
            }
        }
}


TreeNode<int> *maxChildSumNode(TreeNode<int> *root){

    TreeNode<int>* ans = root;

    int sum = root->data;

    for(int i=0; i<root->children.size(); i++){
        sum+= root->children[i]->data;
    } 

    for(int i=0; i<root->children.size();i++){

        TreeNode<int> *child = maxChildSumNode(root->children[i]);

        int childSum = child->data;

        for(int i=0; i<child->children.size();i++){
            childSum+=child->children[i]->data;
        }

        if(sum<childSum){
            sum=childSum;
            ans = child;
        }
    }

    return ans;
}

int main(){

    TreeNode<int>*root = takeInput();
    TreeNode<int> *child = maxChildSumNode(root);
    cout<<child<<endl;
}

//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0