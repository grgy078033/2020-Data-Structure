#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 13
#define PRIME 7
///////////////////////////////////////////
int hash1(int key){ // two hash functions
    return (key % TABLE_SIZE);
}
int hash2(int key){
    return (PRIME - (key % PRIME));
}
///////////////////////////////////////////
int main(){
    int temp[TABLE_SIZE]; // save the data
    for (int i = 0; i < TABLE_SIZE; ++i)
        scanf("%d", &temp[i]);

    int hash_table[TABLE_SIZE]; // hash
    
    for (int i = 0; i < TABLE_SIZE; ++i){
        hash_table[i] = 0;
    }
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        int j = 0;
        int index = (hash1(temp[i]) + j * hash2(temp[i])) % TABLE_SIZE;
        while (hash_table[index] != 0) // collation happened
            index = (hash1(temp[i]) + (++j) * hash2(temp[i])) % TABLE_SIZE;
        hash_table[index] = temp[i];
    }

    for (int i = 0; i < TABLE_SIZE; ++i) { // print out the hash table
        if(i == TABLE_SIZE - 1){
            printf("%d->%d", i, hash_table[i]);
            break;
        }
        printf("%d->%d\n", i, hash_table[i]);
    }
    return 0;
}