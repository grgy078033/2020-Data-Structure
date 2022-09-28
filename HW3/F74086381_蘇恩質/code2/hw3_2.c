#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct solitaire *solitaire_pointer;
typedef struct solitaire{
    char card[2];
    int number;
     solitaire_pointer next;
}solitaire;

int main(){
    int output_num = 13;
    solitaire_pointer head = NULL;
    solitaire_pointer current;
    char card_input[2];
    while(scanf("%s", card_input) != EOF){
        if(strcmp(card_input, "K") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "K");
            current->number = 13;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
        else if(strcmp(card_input, "Q") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "Q");
            current->number = 12;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
        else if(strcmp(card_input, "J") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "J");
            current->number = 11;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
        else if(strcmp(card_input, "10") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "10");
            current->number = 10;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "9") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "9");
            current->number = 9;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "8") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "8");
            current->number = 8;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "7") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "7");
            current->number = 7;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "6") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "6");
            current->number = 6;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "5") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "5");
            current->number = 5;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "4") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "4");
            current->number = 4;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "3") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "3");
            current->number = 3;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "2") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "2");
            current->number = 2;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
	else if(strcmp(card_input, "A") == 0){
            current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, "A");
            current->number = 1;
            if(head == NULL)
                head = current;
            else{
                solitaire_pointer temp = head;
                while(temp->next != NULL)
                    temp = temp->next;
                temp->next = current;
            }
        }
    }
    ///////////////////////////////////////////////////////////////////
    do{
        solitaire_pointer temp = head;
        while(temp != NULL){
            printf("%s" , temp->card);
            temp = temp->next;
            if(temp == NULL){
                if(head->next != NULL){
                    printf("\n");
                }
            }
            else
                printf(" ");
        }

        if(head->number == output_num){
            solitaire_pointer temp = head;
            head = head->next;
            free(temp);
            output_num--;
        }
        else{
            solitaire_pointer current = (solitaire_pointer)malloc(sizeof(solitaire));
            strcpy(current->card, head->card);
            current->number = head->number;
            current->next = NULL;
            solitaire_pointer temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = current;
            temp = head;
            head = head->next;
            free(temp);
        }
    }while(head != NULL);
    return 0;
}
