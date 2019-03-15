#include <stdio.h> 
#include <stdlib.h> 
#define MAX_SIZE 20 //I choose this
  
struct node 
{ 
    int val; 
    struct node *left, *right; 
}; 
  
struct Stack 
{ 
    int size; 
    int top; 
    struct node* *array; 
}; 
  
struct Stack* createStack(int size) 
{ 
    struct Stack* stack = 
        (struct Stack*) malloc(sizeof(struct Stack)); 
    stack->size = size; 
    stack->top = -1; 
    stack->array = 
        (struct node**) malloc(stack->size * sizeof(struct node*)); 
    return stack; 
} 
  
int isFull(struct Stack* stack) 
{   return stack->top - 1 == stack->size;  } 
  
int isEmpty(struct Stack* stack) 
{   return stack->top == -1;   } 
  
void push(struct Stack* stack, struct node* node) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = node; 
} 
  
struct node* pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return NULL; 
    return stack->array[stack->top--]; 
} 
  
int isPairPresent(struct node *root, int target) 
{ 
    // Create two stacks. s1 is used for normal inorder traversal 
    // and s2 is used for reverse inorder traversal 
    struct Stack* s1 = createStack(MAX_SIZE); 
    struct Stack* s2 = createStack(MAX_SIZE); 
  
    // 1 values for inorder  
    // 2 values for reverse inorder
    int done1 = 0, done2 = 0; 
    int val1 = 0, val2 = 0; 
    struct node *curr1 = root, *curr2 = root; 
  
    while (1) 
    { 
        while (done1 == 0) 
        { 
            if (curr1 != NULL) 
            { 
                push(s1, curr1); 
                curr1 = curr1->left; 
            } 
            else
            { 
                if (isEmpty(s1)) 
                    done1 = 1; 
                else
                { 
                    curr1 = pop(s1); 
                    val1 = curr1->val; 
                    curr1 = curr1->right; 
                    done1 = 1; 
                } 
            } 
        } 
  
        while (done2 == 0) 
        { 
            if (curr2 != NULL) 
            { 
                push(s2, curr2); 
                curr2 = curr2->right; 
            } 
            else
            { 
                if (isEmpty(s2)) 
                    done2 = 1; 
                else
                { 
                    curr2 = pop(s2); 
                    val2 = curr2->val; 
                    curr2 = curr2->left; 
                    done2 = 1; 
                } 
            } 
        } 
  
        if ((val1 != val2) && (val1 + val2) == target) 
        { 
            printf("%d + %d = %d\n", val1, val2, target); 
            return 1; 
        } 
  
        else if ((val1 + val2) < target) 
            done1 = 0 ; 
  
        else if ((val1 + val2) > target) 
            done2 = 0; 
  
        if (val1 >= val2) //no pair
            return 0; 
    } 
} 
  
struct node * NewNode(int val) 
{ 
    struct node *tmp = (struct node *)malloc(sizeof(struct node)); 
    tmp->val = val; 
    tmp->right = tmp->left =NULL; 
    return tmp; 
} 
  
int main() 
{ 
    struct node *root =  NewNode(8); 
    root->left = NewNode(2); 
    root->right = NewNode(15); 
    root->left->left = NewNode(1); 
    root->left->right = NewNode(5); 
    root->right->left = NewNode(10); 
    root->right->right = NewNode(20); 
    root->left->right->left = NewNode(4); 
    root->left->right->right = NewNode(7);
    root->right->right->left = NewNode(18);
    root->right->right->right = NewNode(22);
    root->left->right->left->left = NewNode(3); 
    
  
    int SearchedSum = 19; 
    if (isPairPresent(root, SearchedSum) == 0) 
        printf("\n No such values are found\n"); 
  
    return 0; 
} 
