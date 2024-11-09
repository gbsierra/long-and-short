#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//Main Function
int main(int argc, char *argv[]){

    //make sure program is ran with 3 arguments
    if(argc < 3){
        printf("Must enter 3 arguments!\n");
        exit(1);
    }

    //open file using 'read'
    FILE *file1 = fopen(argv[1], "r");

    //check if file1 is empty
    if(!file1){
        printf("Could not open file1!/n");
        exit(1);
    }


    //open other 2 files using 'write'
    FILE *file2 = fopen(argv[2], "w");
    FILE *file3 = fopen(argv[3], "w");

    //check if files 2 and 3 are empty
    if(!file2){
        printf("Could not open file2!/n");
        exit(1);
    }
    //check if file is empty
    if(!file3){
        printf("Could not open file3!/n");
        exit(1);
    }

    int amt1=0;
    int amt2=0;
    char str[255];
    //while not at end of file
    while(!feof(file1)){

        //get line of text
        fgets(str, 255, file1);

        //if line of text less than 20 characters
        if(strlen(str) < 20 ){

            //for all letters in the line of text
            for(int i=0; i<strlen(str); i++){
                //convert to uppercase
                str[i] = toupper(str[i]);
            }
            //write to file2
            fprintf(file2, "%s", str);
            amt1++;
        }
        //otherwise
        else{
            //for all letters in the line of text
            for(int i=0; i<strlen(str); i++){
                //convert to lowercase
                str[i] = tolower(str[i]);
            }
            //write to file3
            fprintf(file3, "%s", str);
            amt2++;
        }

    }

    //display information
    printf("%d lines written to %s\n", amt1, argv[2]);
    printf("%d lines written to %s\n", amt2, argv[3]);  //prints out '12 lines' for 'greeneggs.txt' as it reads blank lines as well.

    //close 3 files
    fclose(file1);
    fclose(file2);
    fclose(file3);

    
}