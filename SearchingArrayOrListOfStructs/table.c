#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//#include "stdint.h"
//#include "stdbool.h"

// Structures / Types / Enums / Constants 
typedef struct {
    char name[20];
    int command;
    char type[30];
} machine;

// Function Prototypes
void printMachine(const machine *m);
machine * searchMachine(const char *pTarget, machine machines[], int length);
machine * loadMachine(char *filename, int *size);


int main(int argc, char *argv[]) {
    // Check the number of arguments
    if(argc < 2) {
        fprintf(stderr, "Usage %s filename\n", argv[0]);
        exit(1);
    }

    // Load machines
    machine *machines;
    int count;
    machines = loadMachine(argv[1], &count);
    
    // Print the array data
    for(int i = 0; i < count; i++) {
        printf("%d: ", i);
        printMachine(&machines[i]);
        printf("\n");
    }

    // Search the data in the array corresponding to a specific item
    char target[20];
    printf("Enter the name of a machine to find: ");
    fgets(target, 20, stdin);

    // Trim newline
    char *nl = strchr(target, '\n');
    if(nl) *nl = '\0';

    // Do linear search
    machine *found = searchMachine(target, machines, count);
    if(found) {
        printf("Found: ");
        printMachine(found);
        printf("\n");
    } else {
        printf("Didn't find it!\n");
    }

    return 0;
}


void printMachine(const machine *pMachine) {
    printf("Name: %s, Command: %d, Type: %s", pMachine->name, pMachine->command, pMachine->type);
}

/** Given the name of the target machine to find,
 * the array of machines to search through,
 * and the length of the array
 * Return the found machine or NULL.  
 */
machine * searchMachine(const char *pTarget, machine machines[], int length) {
    for(int i = 0; i < length; i++) {
        // Compare target name with name from machines array
        if(strcmp(pTarget, machines[i].name) == 0) {
            return &machines[i];
        }
    }
    return NULL;
}

machine * loadMachine(char *filename, int *size) {
    // Open the file
    FILE *pFile = fopen(filename, "r");
    if(!pFile) {
        fprintf(stderr, "Can't open %s for reading: ", filename);
        perror(NULL);
        exit(1);
    }

    machine *machines = malloc(10 * sizeof(machine));
    int count = 0;

    char line[100];
    while(fgets(line, 100, pFile) != NULL) {
        // Read each line from .txt file and store in the array
        sscanf(line, "%[^,],%d,%[^\n]", machines[count].name, &machines[count].command, machines[count].type); // Instead of %s -> %[~,] to split each string with commas
        count++;
    }

    // Close the file
    fclose(pFile);

    // Return machines array
    *size = count;
    return machines;
}

// Compile: gcc table.c -o table
// Execute: ./table filename.txt
