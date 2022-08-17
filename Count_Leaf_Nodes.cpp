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

int numOfLeafNodes(TreeNode<int> *root){

    int count = 0;

    if (root == NULL)
    {
        count++;
    }

    for(int i=0; i<root->children.size();i++){
       
       
      numOfLeafNodes(root->children[i]);
       
    }
    
    return count;

    }
    

    //1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    


int main(){

    TreeNode<int> *root = takeInput();
    cout<<numOfLeafNodes(root)<<endl;
}