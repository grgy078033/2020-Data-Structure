#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int first = 1;
////////////////////////////////////////////////////
typedef struct node *tree_pointer; // define tree node
typedef struct node{    /* |<-left|data|right->| */
    tree_pointer left;
    int data;
    tree_pointer right;
}node;
tree_pointer queue[100]; // for print out the tree
///////////////////////////////////////////////////
tree_pointer max(tree_pointer node) { // make function "find_max"
    if(node){
        while(node->right){
            node = node->right;
        }
    }
    return node;
}
///////////////////////////////////////////////////
tree_pointer insert(tree_pointer node, int data){ // make function "insert"
    if(node == NULL){
        node = (tree_pointer)malloc(sizeof(node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else if(data > node->data)
        node->right = insert(node->right, data);
    else if(data < node->data)
        node->left = insert(node->left, data);
    return node;
}
//////////////////////////////////////////////////
tree_pointer delete_node(tree_pointer node, int data){ // make function "delete_node"
    tree_pointer temp;
    if(data < node->data)
        node->left = delete_node(node->left, data);
    else if(data > node->data)
        node->right = delete_node(node->right, data);
    else{
        if(node->left != NULL && node->right != NULL){
            temp = max(node->left);
            node->data = temp->data;
            node->left = delete_node(node->left, node->data);
        }
        else{
            temp = node;
            if(node->left != NULL)
                node = node->right;
            else
                node = node->left;
            free(temp);
        }
    }
    return node;
}
//////////////////////////////////////////////////
void traversal(tree_pointer root){ // for printing out the tree
    int front = 0;
    int rear = 0;
    if(root == NULL) return;
    queue[rear++] = root; // push
    while(front < rear){
        tree_pointer current = queue[front++]; // pop
        if(current != NULL){
            if(first == 0)
                printf("\n");
            printf("%d", current->data);
            first = 0;
            if(current->left != NULL ||current->right != NULL){
                if(current->left != NULL){
                    queue[rear++] = current->left;
                }
                if(current->right != NULL){
                    queue[rear++] = current->right;
                }
            }
        }
    }
}
//////////////////////////////////////////////////
int main(){
    tree_pointer root = NULL;

    char str_input[100];  // input tree nodes
    scanf("%[^\n]", &str_input);
    int input[strlen(str_input)];
    for (int i = 0; i < strlen(str_input); ++i){
        input[i] = atoi(&str_input[i]);
    }

    for(int i = 0; i < strlen(str_input); ++i){ // build the binary search tree
        if(i == 0){
            root = (tree_pointer)malloc(sizeof(node));
            root->data = input[i];
            root->left = NULL;
            root->right = NULL;
        }
        else {
            insert(root, input[i]);
        }
    }

    int delete; // delete nodes from the tree
    while((scanf("%d", &delete)) != EOF){
        delete_node(root, delete);
    }
    traversal(root);
    return 0;
}