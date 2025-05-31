#include <stdio.h>
#include <stdlib.h>

// Returns the size of a file in bytes
int get_size(const char File_Name[]) {
    FILE* File_Pointer = fopen(File_Name, "rb");
    if (File_Pointer == NULL) {
        perror("ERROR: Couldn't open file to get size");
        return 0;
    }

    fseek(File_Pointer, 0, SEEK_END);
    long size = ftell(File_Pointer);
    fclose(File_Pointer);

    return (size >= 0) ? (int)size : 0;
}

// Reads `size` bytes from a file into `Buffer`
void Read(const char File_Name[], char* Buffer) {
    FILE* File_Pointer = fopen(File_Name, "rb");
    if (File_Pointer == NULL) {
        perror("ERROR: Couldn't open file for reading");
        return;
    }

    int size = get_size(File_Name);
    fread(Buffer, 1, size, File_Pointer);

    fclose(File_Pointer);
}

// Writes `size` bytes from `Buffer` into a file
void Write(const char File_Name[], const char* Buffer, size_t size) {
    FILE* File_Pointer = fopen(File_Name, "wb");
    if (File_Pointer == NULL) {
        perror("ERROR: Couldn't open file for writing");
        return;
    }

    fwrite(Buffer, 1, size, File_Pointer);

    fclose(File_Pointer);
}

// Appends `size` bytes from `Buffer` into a file
void Append(const char File_Name[], const char* Buffer, size_t size) {
    FILE* File_Pointer = fopen(File_Name, "ab");
    if (File_Pointer == NULL) {
        perror("ERROR: Couldn't open file for appending");
        return;
    }

    fwrite(Buffer, 1, size, File_Pointer);

    fclose(File_Pointer);
}

