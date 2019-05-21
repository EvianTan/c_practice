#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include"thinglist.h"

// -----------------------------------------------------------------------------
// FUNCTION thinglist_new
// -----------------------------------------------------------------------------
thinglist* thinglist_new(void)
{
    thinglist* tl = malloc(sizeof(thinglist));
    if(tl != NULL)
    {
        *tl = (thinglist){.things = NULL, .size = 0};
        return tl;
    }
    else
    {
        return NULL;
    }
}

// -----------------------------------------------------------------------------
// FUNCTION thinglist_append
// -----------------------------------------------------------------------------
bool thinglist_append(thinglist* tl, char* name, int count, double value, time_t timestamp, bool trueorfalse)
{
    if(tl->things == NULL)
    {
        tl->things = malloc(sizeof(thing));
    }
    else
    {
        tl->things = realloc(tl->things, sizeof(thing) * (tl->size + 1));
    }

    if(tl->things != NULL)
    {
        *(tl->things + (tl->size)) = (thing){.name = NULL, .count = count, .value = value, .timestamp = timestamp, .trueorfalse =  trueorfalse};
        (tl->things + (tl->size))->name = malloc(strlen(name) + 1);
        if((tl->things + (tl->size))-> name != NULL)
        {
            strcpy((tl->things + (tl->size))->name, name);
            tl->size++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// -----------------------------------------------------------------------------
// FUNCTION thinglist_print
// -----------------------------------------------------------------------------
void thinglist_print(thinglist* tl)
{
    for(int i=0; i< tl->size; i++)
    {
        printf("name:           %-32s\n", (tl->things + i)->name);
        printf("count:          %d\n", (tl->things + i)->count);
        printf("value:          %lf\n", (tl->things + i)->value);
        printf("timestamp:      %ld\n", (tl->things + i)->timestamp);
        printf("date and time:  %s\n", ctime(&((tl->things + i)->timestamp)));
        printf("trueorfalse:    %-32s\n", (tl->things + i)->trueorfalse == true ? "true" : "false");

        printf("-------------------------------------------------\n");
    }
}

// -----------------------------------------------------------------------------
// FUNCTION thinglist_free
// -----------------------------------------------------------------------------
void thinglist_free(thinglist* tl)
{
    for(int i = 0; i< tl->size; i++)
    {
        free((tl->things + i)->name);
    }
    free(tl->things);
    free(tl);
}

// -----------------------------------------------------------------------------
// FUNCTION thinglist_serialize
// -----------------------------------------------------------------------------
bool thinglist_serialize(thinglist* tl, char* filepath)
{
    FILE* fp;
    fp = fopen(filepath, "w");
    if(fp != NULL)
    {
        for(int i = 0; i < tl->size; i++)
        {
            fprintf(fp,
                    "%s\n%d\n%lf\n%ld\n%d\n",
                    (tl->things + i)->name,
                    (tl->things + i)->count,
                    (tl->things + i)->value,
                    (tl->things + i)->timestamp,
                    (tl->things + i)->trueorfalse);
        }
        fclose(fp);
        return true;
    }
    else
    {
        return false;
    }
}

// -----------------------------------------------------------------------------
// FUNCTION thinglist_deserialize
// -----------------------------------------------------------------------------
thinglist* thinglist_deserialize(char* filepath)
{
    char name[256];
    int count;
    double value;
    time_t timestamp;
    int trueorfalse;

    FILE* fp;
    fp = fopen(filepath, "r");
    if(fp != NULL)
    {
        thinglist* tl = thinglist_new();
        if(tl != NULL)
        {
            while(!feof(fp))
            {
                fscanf(fp,
                       "%256[^\n]\n%d\n%lf\n%ld\n%d\n",
                       name,
                       &count,
                       &value,
                       &timestamp,
                       &trueorfalse);

                thinglist_append(tl, name, count, value, timestamp, trueorfalse);
            }
            fclose(fp);
            return tl;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
