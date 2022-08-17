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
        this->data=data;
    }

};

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


void printDepthWise(TreeNode<int> *root, int k){

        if(root==NULL){
            return ;
        }

        if(k==0){

            cout<<root->data<<endl;
            
        }

        for(int i=0; i<root->children.size();i++){
            printDepthWise(root->children[i],k-1);
        }
}

int main(){

    TreeNode<int> *root = takeInput();
    // int level;
    // cout<<"Enter tree level for print"<<endl;
    // cin>>level;
    printDepthWise(root,2);
}