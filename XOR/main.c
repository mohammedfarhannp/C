// Standard Header Files
#include <stdio.h>
#include <string.h>
#include <malloc.h>

// Custom Header Files
#include "input.h"
#include "xor.h"
#include "rw.h"

// Definitions
#define KEY_MAX 64
#define STR_MAX 4096

// Main
int main(int argc, char *argv[]) {
    char* String;
    int input_length;

    if(argc == 2 && strcmp(argv[1], "-f") == 0) {
        char* File_In = (char*) malloc(KEY_MAX);
        char_pointer_input("Enter File Path: ", KEY_MAX, File_In);

        input_length = get_size(File_In);

        String = (char*) malloc(input_length);
        if(String == NULL) {
            printf("ERROR: Pointer Init Failure!\n");
            return 1;
        }

        Read(File_In, String);

        free(File_In);

    } else if (argc == 1) {
        String = (char*) malloc(STR_MAX);
        char_pointer_input("Enter Text for XOR Convertion: ", STR_MAX, String);

        input_length = (int) strlen(String);

    } else {
        printf("Usage:\n\n%s -> Input String from User\n%s -f -> Input String from File\n", argv[0]);
        return 1;
    }

    char* Key = (char*) malloc(KEY_MAX);
    char_pointer_input("Enter a Key: ", KEY_MAX, Key);

    char* Truncated_Key = truncate_key(Key, (size_t) input_length);

    if (Truncated_Key == NULL) {
        printf("Error: Key not Truncated Error\n");

        free(String);
        free(Key);

        return 1;
    }

    char* XOR_Str = Apply_XOR(Truncated_Key, String, (size_t) input_length);
    if(XOR_Str == NULL)
    {
        printf("ERROR: XOR Result NULL Error\n");
        return 1;
    }

    char* File_Out = "./Output_XOR.dat";
    Write(File_Out, XOR_Str, input_length);

    printf("Output written to %s!\n", File_Out);

    free(XOR_Str);
    free(String);
    free(Truncated_Key);
    free(Key);

    return 0;
}


