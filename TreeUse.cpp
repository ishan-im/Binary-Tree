#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

template<typename T>

class TreeNode{

    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data){
        this->data = data;
    }


};


TreeNode<int> * takeInputLevelWise(){

    int rootData;

    cout<<"Enter root data here"<<endl;

    cin>>rootData;

   TreeNode<int> *root = new TreeNode<int>(rootData);

   queue<TreeNode<int>*>pendingNodes;

   pendingNodes.push(root);

   while(pendingNodes.size()!=0){

       TreeNode<int> *frontData = pendingNodes.front();

       pendingNodes.pop();
       
       cout<<"Enter the number of child of "<<frontData->data<<endl;
       int numChild;
       cin>>numChild;

       for(int i=0; i<numChild;i++){
           int childData;
           cout<<"Enter "<<i<<"th child of "<<frontData->data<<endl;
           cin>>childData;

           TreeNode<int>* child = new TreeNode<int>(childData);
            frontData->children.push_back(child);
            pendingNodes.push(child);
       }

   }

    return root;

}


void printTree(TreeNode<int> *root){
    if(root->data==NULL){
        return;
    }

    queue<TreeNode<int>  *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";

        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);

            if(i==front->children.size()-1){
                cout<<front->children[i]->data;
            }
            else{
                cout<<front->children[i]->data<<",";
            }
        }
        cout<<endl;
    }



}

int main(){
    TreeNode<int>*root = takeInputLevelWise();
    printTree(root);
}