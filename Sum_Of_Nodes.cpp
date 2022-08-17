#include<bits/stdc++.h>
#include<vector>
#include<queue>

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
    cout<<"Enter Root data:"<<endl;

    cin>>rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes ;

    pendingNodes.push(root);


    while(pendingNodes.size()!=0){

        TreeNode<int>* frontData = pendingNodes.front();

        pendingNodes.pop();

        cout<<"Enter the number of child of "<<frontData->data<<endl;

        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++){

            int childData;
            cout<<"Enter "<<i<<"th child of "<<frontData->data<<endl;
            cin>>childData;

            TreeNode<int> *child = new TreeNode<int>(childData);

            pendingNodes.push(child);
            
            frontData->children.push_back(child);
        }
    }

    return root;

}


int sumOfNodes(TreeNode<int> *root){

    int rootData = root->data;

    for(int i=0; i<root->children.size();i++){
        rootData+=sumOfNodes(root->children[i]);
    }

   return rootData;
}



int main(){

    TreeNode<int>*root = takeInput();
    cout<<sumOfNodes(root)<<endl;
}