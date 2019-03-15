#include <stdio.h>
#include <stdlib.h>

struct node {
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

int isPerfectWithH(struct node* root, int d, int level ) 
{ 
    // An empty tree is perfect 
    if (root == NULL) 
        return 1; 
  
    // If leaf node, then its depth must be same as 
    // depth of all other leaves. 
    if (root->left == NULL && root->right == NULL) 
        return (d == level+1); 
  
    // If internal node and one child is empty 
    if (root->left == NULL || root->right == NULL) 
        return 0; 
  
    // Left and right subtrees must be perfect. 
    return isPerfectWithH(root->left, d, level+1) && 
           isPerfectWithH(root->right, d, level+1); 
} 
  


int height(struct node* node)  
{ 
   if (node==NULL)  
       return 0; 
   else 
   { 
       int lDepth = height(node->left); 
       int rDepth = height(node->right); 
  
       if (lDepth > rDepth)  
           return(lDepth+1); 
       else return(rDepth+1); 
   } 
}  

int isPerfect(struct node *root) 
{ 
   int h = height(root); 
   return isPerfectWithH(root, h, 0); 
} 
  



void Preorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
     /* first print data of node */
     printf("%d ", node->key);   
  
     /* then recur on left sutree */
     Preorder(node->left);   
  
     /* now recur on right subtree */
     Preorder(node->right); 
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
    //insert(&tree,newNode(4));
    //insert(&tree,newNode(7));
    //insert(&tree,newNode(18));
    //insert(&tree,newNode(22));
    //insert(&tree,newNode(3));

    Preorder(tree);//sa se vada ca e ca in exemplu
    
    printf("\n");
    
     if (isPerfect(tree))
        printf("True");
     else
        printf("False");
     
   

}
