#include <stdio.h> 
#include <stdlib.h>
struct node 
{ 
 int key;
 struct node* left;
 struct node* right;
 struct node *p;
};
typedef struct node* Node;

//Create a node 
Node newNode(int key) {
 Node node = (Node) malloc(sizeof(struct node));
 node->key = key;
 node->left = NULL;
 node->right = NULL;
 node->p=NULL;
 return(node);
}

// Insert 
void insert(Node* root, Node z) {
 Node x,y;
 y=NULL;
 x=*root;
 while (x!=NULL) {
    y=x;
    if (x->key < z->key)
                x=x->right;
    else
                x=x->left;
    }
 z->p=y;
 if (y==NULL) {
        *root=z;
        }
        else {
        if (z->key<=y->key)
            y->left=z;
        else
            y->right=z;
        }

}


void maxDiffUtil(struct node *ptr, int k, int *min_diff, int *min_diff_key) 
{ 
    if (ptr == NULL) 
        return ; 
  
    // If k 
    if (ptr->key == k) 
    { 
        *min_diff_key = k; 
        return; 
    } 
  
    // update min_diff and min_diff_key by checking 
    // current node value 
    if (*min_diff > abs(ptr->key - k)) 
    { 
        *min_diff = abs(ptr->key - k); 
        *min_diff_key = ptr->key; 
    } 
  
    // if k is less than ptr->key then move in left 
    if (k < ptr->key) 
        maxDiffUtil(ptr->left, k, &(*min_diff), &(*min_diff_key)); 
    else
        maxDiffUtil(ptr->right, k, &(*min_diff), &(*min_diff_key)); 
} 

int maxDiff(struct node *root, int k) 
{ 
    int min_diff = 999999, min_diff_key = -1; //I considered positive values of the keys
  
    maxDiffUtil(root, k, &min_diff, &min_diff_key); 
  
    return min_diff_key; 
} 

 
int main() 
{ 
    Node tree=NULL;
    
     insert(&tree,newNode(8));
    insert(&tree,newNode(2));
    insert(&tree,newNode(15));
    insert(&tree,newNode(1));
    insert(&tree,newNode(5));
    insert(&tree,newNode(10));
    insert(&tree,newNode(20));
    insert(&tree,newNode(4));
    insert(&tree,newNode(7));
    insert(&tree,newNode(18));
    insert(&tree,newNode(22));
    insert(&tree,newNode(3));
    
    
    printf("%d", maxDiff(tree, 17)); 
  
    return 0; 
} 
