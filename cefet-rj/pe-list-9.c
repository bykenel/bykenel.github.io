// CÓDIGO PROPOSTO
#include <stdio.h>
#include <conio.h>

int main() {
    const int records = 256;
    struct TASCII {
        int code;
        char character;
    } ascii;

    FILE * file;
    char c, fileName[80];
    int i;
    char option;

    printf("*******************************\n");
    printf("*** File Manipulation  ***\n");
    printf("*******************************\n\n");
    printf("Enter the name (with path) of the file to be used: ");
    gets(fileName);
    file = fopen(fileName, "wb+");

    printf("\nSTORING DATA IN THE FILE...\n");
    
    for(i = 1; i < records; i = i + 1) {
        ascii.code = i - 1;
        ascii.character = (char)(i - 1);
        fwrite(&ascii, sizeof(struct TASCII), 1, file);
    }

    fseek(file, (records - 1) * sizeof(struct TASCII), 0);
    ascii.code = i - 1;
    ascii.character = (char)(i - 1);
    fwrite(&ascii, sizeof(struct TASCII), 1, file);

    printf("\nREADING DATA FROM THE FILE...\n");
    printf("ASCII Table:\n");
    rewind(file);
    while (1) {
        fread(&ascii, sizeof(struct TASCII), 1, file);
        if (feof(file)) break;
        printf("%d\t%c\n", ascii.code, ascii.character);
    }

    fclose(file);
    printf("\nDo you want to delete the file?\n");
    printf("[Y]es\n");
    printf("[N]o\n");
    printf("[Y/N]: ");
    scanf("\n%c", &option);
    if ((option == 'Y') || (option == 'y'))
        remove(fileName);
    getch();
    return 0;
}


// QUESTÃO 1
/*
#include <stdio.h>

struct TASCII {
    int code;
    char character;
};

int main() {
    FILE *file;
    char fileName[80];

    printf("Enter the name (with path) of the file to be used: ");
    gets(fileName);

    file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END); // Move the cursor to the end of the file
    long fileSize = ftell(file); // Get the current position (size of the file)
    fclose(file);

    int numberOfRecords = fileSize / sizeof(struct TASCII);
    printf("Number of records in the file: %d\n", numberOfRecords);

    return 0;
}
*/


#include <stdio.h>

int main() {
    FILE *originalFile, *copyFile;
    char originalFileName[80], copyFileName[80];
    char byte;

    printf("Enter the name (with path) of the original file: ");
    gets(originalFileName);
    originalFile = fopen(originalFileName, "rb");
    if (originalFile == NULL) {
        printf("Error opening the original file.\n");
        return 1;
    }

    printf("Enter the name (with path) of the new copy file: ");
    gets(copyFileName);
    copyFile = fopen(copyFileName, "wb");
    if (copyFile == NULL) {
        printf("Error creating the copy file.\n");
        fclose(originalFile);
        return 1;
    }

    // Perform the copy of data byte by byte
    while (fread(&byte, 1, 1, originalFile) == 1) {
        fwrite(&byte, 1, 1, copyFile);
    }

    fclose(originalFile);
    fclose(copyFile);
    printf("File copy successful.\n");

    return 0;
}
