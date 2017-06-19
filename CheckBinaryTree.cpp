/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/


/* Returns true if the given tree is a BST and its 
 values are >= min and <= max. */ 
int isBSTUtil(Node * root, int min, int max){
    
    if(root == NULL){
        return true;
    }
    if(root->data <= min || root->data>= max){
        return false;
    }
    return isBSTUtil(root->left, min, root->data)&& isBSTUtil(root->right, root->data, max);
    
}
    
    bool checkBST(Node* root) {
      
       
     return(isBSTUtil(root, 0, 100000)); 
   }
