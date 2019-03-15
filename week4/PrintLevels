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
  
int height(struct node* node) 
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
  
 void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->key); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
}  
  
void printLevel(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
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
  
    printLevel(tree); 
  
    return 0; 
} 
