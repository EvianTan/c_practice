#include<stdbool.h>
#include<time.h>

// -----------------------------------------------------------------------------
// STRUCT thing
// -----------------------------------------------------------------------------
typedef struct thing
{
    char* name;
    int count;
    double value;
    time_t timestamp;
    bool trueorfalse;
} thing;

// -----------------------------------------------------------------------------
// STRUCT thinglist
// -----------------------------------------------------------------------------
typedef struct thinglist
{
    thing* things;
    int size;
} thinglist;

// -----------------------------------------------------------------------------
// FUNCTION PROTOTYPES
// -----------------------------------------------------------------------------
thinglist* thinglist_new(void);
bool thinglist_append(thinglist* tl, char* name, int count, double value, time_t timestamp, bool trueorfalse);
void thinglist_print(thinglist* tl);
void thinglist_free(thinglist* tl);
bool thinglist_serialize(thinglist* tl, char* filepath);
thinglist* thinglist_deserialize(char* filepath);
