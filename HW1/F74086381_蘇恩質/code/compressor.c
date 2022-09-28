#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <getopt.h>
#include <string.h>
int power(int x, int y){
    int result = 1;
    for(int i = 0; i < y; ++i){
        result *= x;
    }
    return result;
}

int main(int argc, char **argv){
    int i, j, k;
    int tmp = 2;//-i -o
    char str[10000];//for fgets()
    FILE *Fptr_input, *Fptr_output;//file pointer
    char *string = "i:o:";//for getopt()

    tmp = getopt(argc, argv, string);
    Fptr_input = fopen(optarg, "r");//open input.txt
    tmp = getopt(argc, argv, string);
    Fptr_output = fopen(optarg, "w");//open output.txt

    while((fgets(str, 10000, Fptr_input))!=NULL){
        int length = strlen(str)-1;
        int temp = length;
        int record_0;
        if((length % 6) != 0){
            if((length % 6) == 2)
                record_0 = 2;
            else if((length % 6) == 4)
                record_0 = 1;
            length += 6 - (length % 6);
        }
        int decimal[length];
        for(i = 0; i < length; ++i){//hex to decimal & fill with 0
            if(i >= temp)
                decimal[i] = 0;
            else{
                switch(str[i]){
                    case '0':
                        decimal[i] = 0;
                        break;
                    case '1':
                        decimal[i] = 1;
                        break;
                    case '2':
                        decimal[i] = 2;
                        break;
                    case '3':
                        decimal[i] = 3;
                        break;
                    case '4':
                        decimal[i] = 4;
                        break;
                    case '5':
                        decimal[i] = 5;
                        break;
                    case '6':
                        decimal[i] = 6;
                        break;
                    case '7':
                        decimal[i] = 7;
                        break;
                    case '8':
                        decimal[i] = 8;
                        break;
                    case '9':
                        decimal[i] = 9;
                        break;
                    case 'A':
                        decimal[i] = 10;
                        break;
                    case 'B':
                        decimal[i] = 11;
                        break;
                    case 'C':
                        decimal[i] = 12;
                        break;
                    case 'D':
                        decimal[i] = 13;
                        break;
                    case 'E':
                        decimal[i] = 14;
                        break;
                    case 'F':
                        decimal[i] = 15;
                        break;
                }
            }
        }

        int dec_bit_first[length/6][6][4];// let (4bit(k) * 6(j)) as a group, then we have (length/6)(i) groups
        for(i = 0; i < length/6; ++i){//decimal to binary
            for(j = 0; j < 6; ++j){
                for(k = 3; k >= 0; --k){
                    dec_bit_first[i][j][k] = decimal[i*6+j] % 2;
                    decimal[i*6+j] /= 2;
                }
            }
        }
        
        int dec_bit_second[length/6][4][6];// let 6bit * 4(j) as a group, then we have (length/6)(i) groups
        int *dec_ptr = &dec_bit_first[0][0][0];
        for(i = 0; i < length/6; ++i){
            for(j = 0; j < 4; ++j){
                for(k = 0; k < 6; ++k){
                    dec_bit_second[i][j][k] = *dec_ptr;
                    ++dec_ptr;
                }
            }
        }

        int base64_index[length/6][4];// 3byte = 3 * 8 = 24bit, 24bit / 6bit = 4(j), and we have length/6(i) groups
        for(i = 0; i < length/6; ++i){//6bit => base64 index;
            for(j = 0; j < 4; ++j){
                base64_index[i][j] = 0;
                for(k = 5; k >= 0; --k){
                    if(dec_bit_second[i][j][k] == 1){
                        base64_index[i][j] += power(2, 5-k);
                    }
                    else if(dec_bit_second[i][j][k] == 0)
                        continue;
                }
            }
        }

        for(i = 0; i < length/6; ++i){
            for(j = 0; j < 4; ++j){
                if((base64_index[i][j]) <= 25)
                    str[i*4+j] = base64_index[i][j]+65;
                else if((base64_index[i][j] > 25) && (base64_index[i][j] <= 51))
                    str[i*4+j] = base64_index[i][j]+71;
                else if((base64_index[i][j] > 51) && (base64_index[i][j] <= 61))
                    str[i*4+j] = base64_index[i][j]-4;
                else if(base64_index[i][j] == 62)
                    str[i*4+j] = '+';
                else if(base64_index[i][j] == 63)
                    str[i*4+j] = '/';
                if(i == length/6-1){
                    if(record_0 == 2){
                        str[i*4+2] = '=';
                        str[i*4+3] = '=';
                    }
                    else if(record_0 == 1)
                        str[i*4+3] = '=';
                }
            }
        }
        for(i = length/6*4; i < temp; ++i)
            str[i] = ' ';

        fputs(str, Fptr_output);//output to output.txt
    }
    
    fclose(Fptr_input);//close input.txt
    fclose(Fptr_output);//close output.txt
    return 0;
}
