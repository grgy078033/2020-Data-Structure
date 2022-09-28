#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int first_1 = 1;
////////////////////////////////////////////////////
typedef struct node *tree_pointer; // define tree node
typedef struct node{    /* |<-left|name|phone|right->| */
    tree_pointer left;
    char name[20];
    char phone[10];
    tree_pointer right;
    int height;
}node;
////////////////////////////////////////////////////
int max(int a, int b)
{
    return (a > b)? a : b;
}
////////////////////////////////////////////////////
int height(tree_pointer node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
////////////////////////////////////////////////////
tree_pointer newNode(char name[], char phone[])
{
    tree_pointer node = (tree_pointer)malloc(sizeof(node));
    strcpy(node->name, name);
    strcpy(node->phone, phone);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}
////////////////////////////////////////////////////
tree_pointer search(tree_pointer root, char name[]){ // make function "search"
    if(!root) return NULL;
    if(strcmp(name, root->name) == 0) return root;
    if(strcmp(name, root->name) < 0) return search(root->left, name);
    return search(root->right, name);
}
////////////////////////////////////////////////////
tree_pointer rightRotate(tree_pointer node_1)
{
    tree_pointer node_2 = node_1->left;
    tree_pointer tmp = node_2->right;

    node_2->right = node_1;
    node_1->left = tmp;
    node_1->height = max(height(node_1->left), height(node_1->right))+1;
    node_2->height = max(height(node_2->left), height(node_2->right))+1;

    return node_2;
}
////////////////////////////////////////////////////
tree_pointer leftRotate(tree_pointer node_2)
{
    tree_pointer node_1 = node_2->right;
    tree_pointer tmp = node_1->left;

    node_1->left = node_2;
    node_2->right = tmp;

    node_2->height = max(height(node_2->left), height(node_2->right))+1;
    node_1->height = max(height(node_1->left), height(node_1->right))+1;

    return node_1;
}
////////////////////////////////////////////////////
int getBF(tree_pointer node)
{
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}
////////////////////////////////////////////////////
tree_pointer insert(tree_pointer node, char name[], char phone[])
{
    if (node == NULL)
        return(newNode(name, phone));

    if (strcmp(name, node->name) < 0)
        node->left  = insert(node->left, name, phone);
    else if (strcmp(name, node->name) > 0)
        node->right = insert(node->right, name, phone);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int BF = getBF(node);

    if (BF > 1 && strcmp(name, node->left->name) < 0)
        return rightRotate(node);

    if (BF < -1 && strcmp(name, node->right->name) > 0)
        return leftRotate(node);

    if (BF > 1 && strcmp(name, node->left->name) > 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (BF < -1 && strcmp(name, node->right->name) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
////////////////////////////////////////////////////
void pre_order(tree_pointer root)
{
    if(root != NULL)
    {
        if(first_1 == 0) printf(" ");
        printf("%s", root->name);
        first_1 = 0;
        pre_order(root->left);
        pre_order(root->right);
    }
}
////////////////////////////////////////////////////
int main(){
    tree_pointer root = NULL;
    char tmp_name[20], tmp_phone[20];
    char D;
    scanf("%s", &D);
    while(scanf("%s", &tmp_name)){
        if(strcmp(tmp_name, "S") == 0){
            break;
        }
        scanf("%s", &tmp_phone);
        root = insert(root, tmp_name, tmp_phone); 
    }

    pre_order(root);
    printf("\n");

    int first_2 = 0;
    while(scanf("%s", &tmp_name)){
        if(strcmp(tmp_name, "E") == 0){
            break;
        }
        if(first_2 == 1) printf("\n");
        tree_pointer tmp = (tree_pointer)malloc(sizeof(node));
        strcpy(tmp->name, tmp_name);
        printf("%s ", tmp->name);
        tmp = search(root, tmp->name);
        if(tmp == NULL) printf("null");
        else printf("%s", tmp->phone);
        first_2 = 1;
    }
    return 0;
}