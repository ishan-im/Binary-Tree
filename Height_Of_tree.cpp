#include<bits/stdc++.h>
#include<vector>
#include<queue>

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


TreeNode<int> *takeInput(){

    int rootData;
    cout<<"Enter Root data:"<<endl;
    cin>>rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes ;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0){

        TreeNode<int> *frontdata = pendingNodes.front();

        pendingNodes.pop();

        cout<<"Enter number of children of "<<frontdata->data<<endl;

        int numChild;
        cin>>numChild;

        for(int i=0; i<numChild; i++){

            int childData;
            cout<<"Enter "<<i<<"th child of "<<frontdata->data<<endl;

            cin>>childData;

            TreeNode<int> *child = new TreeNode<int>(childData);

            pendingNodes.push(child);
            frontdata->children.push_back(child);
        }

    }

    return root;
}


int heightOfTree(TreeNode<int> *root){

    if(root==NULL){
        return -1;
    }

    int height = 0;

    for(int i=0; i<root->children.size();i++){
        int childHeight = heightOfTree(root->children[i]);    
        height  = max(height,childHeight);
    }
    
    height+=1;

    return height;

}

int main(){
    TreeNode<int>* root = takeInput();
    cout<<heightOfTree(root)<<endl;
    
}