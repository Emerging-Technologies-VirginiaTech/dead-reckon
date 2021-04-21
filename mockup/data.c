#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    FILE* stream = fopen("../data/data-example.csv", "r");

    char header[1024];
    char line[1024];

    fgets(header, 1024, stream);

    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
        printf("Time ms: %s\n", getfield(tmp, 1));
        free(tmp);
    }
}