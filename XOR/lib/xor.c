#include <stdio.h>
#include <string.h>
#include <malloc.h>

char* Apply_XOR(char* Key, char* String, size_t len)
{

    char* XOR_String = (char*) malloc(len + 1);
    if(XOR_String == NULL) return NULL;

    for(size_t i = 0; i < len; i++)
    {
        XOR_String[i] = String[i] ^ Key[i];
    }

    XOR_String[len] = '\0';

    return XOR_String;
}


char* truncate_key(char* key, size_t str_length)
{
    if(key == NULL) return NULL;

    size_t key_length = strlen(key);
    if(key_length == 0) return NULL;

    char* truncated_key = (char*) malloc(str_length + 1);
    if(truncated_key == NULL) return NULL;

    for(size_t i = 0; i < str_length; i++)
    {
        truncated_key[i] = key[i % key_length];
    }

    truncated_key[str_length] = '\0';

    return truncated_key;
}

