#include<stdio.h> 
#include<stdlib.h> 
  
struct TNode 
{ 
    int data; 
    struct TNode* left; 
    struct TNode* right; 
}; 
  
struct TNode* newNode(int data); 
  
struct TNode* sortedArrayToTree(int arr[], int start, int end) 
{ 
    /* Base Case */
    if (start > end) 
      return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    struct TNode *root = newNode(arr[mid]); 
  
    /* Recursively construct the left subtree and make it 
       left child of root */
    root->left =  sortedArrayToTree(arr, start, mid-1); 
  
    /* Recursively construct the right subtree and make it 
       right child of root */
    root->right = sortedArrayToTree(arr, mid+1, end); 
  
    return root; 
} 
  
struct TNode* newNode(int data) 
{ 
    struct TNode* node = (struct TNode*) 
                         malloc(sizeof(struct TNode)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return node; 
} 
  
  int height(struct TNode* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        int lheight = height(node->left); 
        int rheight = height(node->right); 
  
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
}
    
 void printGivenLevel(struct TNode* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
}  
  
void printLevel(struct TNode* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 10, 15, 18, 20, 22}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    struct TNode *root = sortedArrayToTree(arr, 0, n-1);
    printLevel(root);
   
    return 0; 
} 
