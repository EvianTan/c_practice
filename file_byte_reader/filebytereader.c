#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

// -----------------------------------------------------------------------------
// FUNCTION PROTOTYPES
// -----------------------------------------------------------------------------
void readfile(char* filepath);
void populate_mappings(char** mappings);
void set_value(char** array, int index, char* value);

// -----------------------------------------------------------------------------
// FUNCTION main
// -----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("------------------------------------------------------\n");
    puts("| Read file by byte |\n");
    puts("------------------------------------------------------\n");

    if(argc != 2)
    {
        printf("Warning - Input file must be specified!");
    }
    else
    {
        printf("File: %s\n\n", argv[1]);
        readfile(argv[1]);
    }
    return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
// FUNCTION readfile
// -----------------------------------------------------------------------------
void readfile(char* filepath)
{
    char* mappings[128];
    populate_mappings(mappings);

    // attempt to open the file
    FILE* fpinput;
    fpinput = fopen(filepath, "r");
    
    char c;
    int i = 1;
    
    if(fpinput != NULL)
    {
        puts("------------------------------------------------------");
        puts("| Pos   | Code | Printable? | Character              |");
        puts("------------------------------------------------------");

        // iterate the input file, and print corresponding values from mappings
        while((c = fgetc(fpinput)) != EOF)
        {
            if(c >= 0 && c <= 127)
            {
                printf("| %-5d | %-4d | %-10s | %-22s |\n", i, c, isprint(c) ? "Yes" : "No",  mappings[c]);
            }
            else
            {
                printf("| %-5d | %-4s | %-10s | %-22s |\n", i, "", "",  "Outside ASCII range");
            }
            i++;
        }
        fclose(fpinput);
        puts("------------------------------------------------------");
    }
    else
    {
        printf("Cannot open %s\n", filepath);
    }

    // free up malloc'ed memory
    for (int i = 0; i <= 127; i++)
    {
        free(mappings[i]);
    }
}

// -----------------------------------------------------------------------------
// FUNCTION populate_mappings
// -----------------------------------------------------------------------------
void populate_mappings(char** mappings)
{
    // initialize to default values
    for(int i = 0; i <= 127; i++)
    {
        mappings[i] = malloc(2);

        sprintf(mappings[i], "%c", i);
    }
    // replace non-printable characters with descriptions
    set_value(mappings, 0, "[null]");
    set_value(mappings, 1, "[start of heading]");
    set_value(mappings, 2, "[start of text]");
    set_value(mappings, 3, "[end of text]");
    set_value(mappings, 4, "[end of transmission]");
    set_value(mappings, 5, "[enquiry]");
    set_value(mappings, 6, "[acknowledge]");
    set_value(mappings, 7, "[bell]");
    set_value(mappings, 8, "[backspace]");
    set_value(mappings, 9, "[tab]");
    set_value(mappings, 10, "[line feed]");
    set_value(mappings, 11, "[vertical tab]");
    set_value(mappings, 12, "[form feed]");
    set_value(mappings, 13, "[carriage return]");
    set_value(mappings, 14, "[shift out]");
    set_value(mappings, 15, "[shift in]");
    set_value(mappings, 16, "[data link escape]");
    set_value(mappings, 17, "[device control 1]");
    set_value(mappings, 18, "[device control 2]");
    set_value(mappings, 19, "[device control 3]");
    set_value(mappings, 20, "[device control 4]");
    set_value(mappings, 21, "[negative acknowledge]");
    set_value(mappings, 22, "[synchronous idle]");
    set_value(mappings, 23, "[end of trans. block]");
    set_value(mappings, 24, "[cancel]");
    set_value(mappings, 25, "[end of medium]");
    set_value(mappings, 26, "[substitute]");
    set_value(mappings, 27, "[escape]");
    set_value(mappings, 28, "[file separator]");
    set_value(mappings, 29, "[group separator]");
    set_value(mappings, 30, "[record separator]");
    set_value(mappings, 31, "[unit separator]");
    set_value(mappings, 32, "[space]");
    set_value(mappings, 127, "[delete]");
}

// -----------------------------------------------------------------------------
// FUNCTION set_value
// -----------------------------------------------------------------------------
void set_value(char** array, int index, char* value)
{
   array[index] = realloc(array[index], strlen(value)+1);
   strcpy(array[index], value);
}
