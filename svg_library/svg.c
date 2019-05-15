#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include"svg.h"

// -----------------------------------------------------------------------------
// STATIC FUNCTION appendstringtosvg
// -----------------------------------------------------------------------------
static void appendstringtosvg(svg* psvg, char* text)
{
   int l = strlen(psvg->svg) + strlen(text) + 1;
   char* p = realloc(psvg->svg, 1);
   if(p)
   {
      psvg->svg = p;
   }
   strcat(psvg->svg, text);
}

// -----------------------------------------------------------------------------
// STATIC FUNCTION appendnumbertosvg
// -----------------------------------------------------------------------------
static void appendnumbertosvg(svg* psvg, int n)
{
   char sn[16];
   sprintf(sn, "%d", n);
   appendstringtosvg(psvg, sn);
}
