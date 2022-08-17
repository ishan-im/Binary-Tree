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
        this->data=data;
    }

};


TreeNode<int> *takeInput(){
    
    int rootData;
    cout<<"Enter Root data"<<endl;
    cin>>rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){

        TreeNode<int>* frontData = pendingNodes.front();
        pendingNodes.pop();

        cout<<"Enter number of children of: "<<frontData->data<<endl;

        int numChild;
        cin>>numChild;

        for(int i=0;i<numChild;i++){

            int childData;
            cout<<"Enter "<<i<<"th child of "<<frontData->data<<endl;

            cin>>childData;

            TreeNode<int>* childNode = new TreeNode<int>(childData);

            pendingNodes.push(childNode);

            frontData->children.push_back(childNode);

        }
    }

    return root;

}


TreeNode<int> *largestNode(TreeNode<int> *root){

   

    TreeNode<int> *maxData = new TreeNode<int>(root->data);

    for(int i=0;i<root->children.size();i++){
       
       TreeNode<int>* childData = largestNode(root->children[i]);

       if(childData->data > maxData->data){
           maxData = childData;
       }

    
        
    }

    

    return maxData;

}


int main(){
    TreeNode<int> *root = takeInput();
    cout<<largestNode(root)->data<<endl;
}
