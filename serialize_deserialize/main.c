#include<stdio.h>
#include<stdlib.h>

#include"thinglist.h"

// -----------------------------------------------------------------------------
// FUNCTION main
// -----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("------------------------------------------------------------");
    thinglist* tl = thinglist_new();

    if(tl != NULL)
    {
        thinglist_append(tl, "A Thing", 123, 1.234, time(NULL), true);
        thinglist_append(tl, "Another Thing", 234, 2.345, time(NULL), false);
        thinglist_append(tl, "Yet Another Thing", 345, 3.456, time(NULL), true);

        puts("\nData to serialize\n=================\n");

        thinglist_print(tl);

        if(thinglist_serialize(tl, "thinglist1.dat"))
        {
            puts("\nDeserialized data\n=================\n");
        
            thinglist* tld = thinglist_deserialize("thinglist1.dat");

            if(tld != NULL)
            {
                thinglist_print(tld);
                thinglist_free(tld);
            }
        }
        thinglist_free(tl);
    }
    return EXIT_SUCCESS;
}
