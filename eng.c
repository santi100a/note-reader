#include "stdio.h"
#include "windows.h"
#include "string.h"
#include "makesound.h"

int main(int argc, char **argv)
{
    const char *fname = "notes.txt";
    if (argv[2] == "/?") {
        printf("%s\n", "Usage: NOTES [filename] [/?]\nFilename defaults to 'file.txt'.");
        return 0;
    } 
    FILE *file = fopen(fname, "r");
    const int duration = 2000;  
    if (file == NULL || ferror(file))
        fprintf(
            stderr, 
            "Error reading file '%s'. Make sure it exists and it's in the same folder as this program.",
            fname
        );
    while (!feof(file)) {
        const char chr = fgetc(file);
        makesound(chr, duration);
    }
}