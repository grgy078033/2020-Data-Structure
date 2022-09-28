#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10000
int plate_stack[MAX_SIZE];
void add_plate(int top, int plate){
    plate_stack[top] = plate;
}
int delete_plate(int top){
    return plate_stack[top];
}
void enqueue(int queue[], int rear, int plate){
    queue[rear] = plate;
}
int dequeue(int queue[], int front){
    return queue[front];
}
int main(){
    int top_plate = -1;
    int rear_A = -1;
    int front_A = -1;
    int rear_B = -1;
    int front_B = -1;
    int queue_A[MAX_SIZE];
    int queue_B[MAX_SIZE];
    FILE *f_input = fopen("input.txt", "r");
    FILE *f_output = fopen("output.txt", "w");
    char operation[100];
    while(fscanf(f_input, "%s", operation) != EOF){
        if(strcmp(operation, "PUSH") == 0){ // PUSH N
            int N;
            fscanf(f_input, "%d", &N);
            add_plate(top_plate, N);
            ++top_plate;
        }
        else if(strcmp(operation, "POP") == 0){ // POP
            continue;
        }
        else if(strcmp(operation, "ENQUEUE") == 0){ // ENQUEUE X
            char AorB[1];
            fscanf(f_input, "%s", AorB);
            if(strcmp(AorB, "A") == 0){ // ENQUEUE A
                --top_plate;
                rear_A = (rear_A+1) % MAX_SIZE;
                enqueue(queue_A, rear_A, delete_plate(top_plate));
            }
            else if(strcmp(AorB, "B") == 0){ // ENQUEUE B
                --top_plate;
                rear_B = (rear_B+1) % MAX_SIZE;
                enqueue(queue_B, rear_B, delete_plate(top_plate));
            }
        }
        else if(strcmp(operation, "DEQUEUE") == 0){ // DEQUEUE X
            char AorB[1];
            fscanf(f_input, "%s", AorB);
            if(strcmp(AorB, "A") == 0){ // DEQUEUE A
                front_A = (front_A+1) % MAX_SIZE;
                fprintf(f_output, "%d\n", dequeue(queue_A, front_A));
            }
            else if(strcmp(AorB, "B") == 0){ // DEQUEUE B
                front_B = (front_B+1) % MAX_SIZE;
                fprintf(f_output, "%d\n", dequeue(queue_B, front_B));
            }

        }
    }
    fclose(f_input);
    fclose(f_output);
    return 0;
}
