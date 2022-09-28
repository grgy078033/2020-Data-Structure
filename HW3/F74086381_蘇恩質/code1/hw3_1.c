#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10000000
typedef struct stack *stack_pointer;
typedef struct stack{
    int data;
    stack_pointer next;
}stack;
stack_pointer top_plate[MAX_SIZE];
   
typedef struct queue *queue_pointer;
typedef struct queue{
    int data;
    queue_pointer next;
}queue;
queue_pointer front_A[MAX_SIZE], rear_A[MAX_SIZE];
queue_pointer front_B[MAX_SIZE], rear_B[MAX_SIZE];

void add_plate(stack_pointer *top, int plate){
    stack_pointer temp = (stack_pointer)malloc(sizeof(stack));
    temp->data = plate;
    temp->next = *top;
    *top = temp;
}
int delete_plate(stack_pointer *top){
    stack_pointer temp = *top;
    int data;
    data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}
void enqueue(queue_pointer *front, queue_pointer *rear, int data){
    queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
    temp->data = data;
    temp->next = NULL;
    if(*front)
        (*rear)->next = temp;
    else
        *front = temp;
    *rear = temp;
}
int dequeue(queue_pointer *front){
    queue_pointer temp = *front;
    int data;
    data = temp->data;
    *front = temp->next;
    free(temp);
    return data;
}

int main(){
    char operation[100];
    while(scanf("%s\n", operation) != EOF){
        if(strcmp(operation, "PUSH") == 0){ // PUSH N
            int N;
            scanf("%d", &N);
            add_plate(top_plate, N);
        }
        else if(strcmp(operation, "POP") == 0){ // POP
            continue;
        }
        else if(strcmp(operation, "ENQUEUE") == 0){ // ENQUEUE
            char AorB[1];
            scanf("%s", AorB);
            if(strcmp(AorB, "A") == 0){ // ENQUEUE A
                enqueue(front_A, rear_A, delete_plate(top_plate));
            }
            else if(strcmp(AorB, "B") == 0){ // ENQUEUE B
                enqueue(front_B, rear_B, delete_plate(top_plate));
            }
        }
      else if(strcmp(operation, "DEQUEUE") == 0){ // DEQUEUE
            char AorB[1];
            scanf("%s", AorB);
            if(strcmp(AorB, "A") == 0){ // DEQUEUE A
                printf("%d\n", dequeue(front_A));
            }
            else if(strcmp(AorB, "B") == 0){ // DEQUEUE B
                printf("%d\n", dequeue(front_B));
            }
        }
    }
    return 0;
}
