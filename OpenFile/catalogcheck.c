#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    // File pointer
    FILE *fp;
    // Open file (w = write mode, r = read mode, a = append mode)
    fp = fopen("fileName.txt","r");

    // Get a character from the file or EOF (end of file)
    int ch = getc(fp);
    while (ch != EOF) {
        // To display the contents of the file on the screen    
        putchar(ch);
        ch = getc(fp);
    }
   
    if (feof(fp)) {
        printf("\n Reached the end of file.");
    } else {
        printf("\n Something gone wrong.");
    }
        
    // Close the file
    fclose(fp);

    getchar();



    FILE * fileName;
    //char ch;
    fileName = fopen("anything.txt","wt");
    // Write formated text on the file
    fprintf(fileName, "%s %s %d", "Welcome", "to",  2018);

    char str1[10], str2[10];
    int yr;
    rewind(fileName);
    fscanf(fileName, "%s %s %d", str1, str2, &yr);
    printf("----------------------------------------------- \n");
    printf("1st word %s \t", str1);
    printf("2nd word  %s \t", str2);
    printf("Year-Name  %d \t", yr);

    // Write de letters D ~ S on the file
    for (ch = 'D' ; ch <= 'S' ; ch++) {
        putc (ch , fileName);
    }
    fclose (fileName);
    
    

    // Write texts on the file
    //fprintf(fp, "%s", "Sample Texts testeaaaaaaaaaaaaaaaa");
    
    return 0; 
}