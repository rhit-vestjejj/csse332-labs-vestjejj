/**
 * Copyright (c) 2025 Rose-Hulman Institute of Technology. All Rights Reserved.
 *
 * Implementation of the memory area with several types.
 *
 * @author <Your name>
 * @date   <Date last modified>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mem.h"

// The length of the header we are using.
#define HLEN 2 * sizeof(int)

/**
 * Implementation of getmem()
 */
void *
getmem(int nc, int ni)
{
  // TODO: Add your code hr
  int *p =  malloc(nc * 1 + ni * 4 + 8);  
  p[0] = nc;
  p[1] = ni;
  return (void *)p;
}

/**
 * Implementation of freemem()
 */
void
freemem(void *mem)
{
  // TODO: Add your code here...
  free(mem);
}

/**
 * Implementation of getnc()
 */
int
getnc(void *mem)
{
  // TODO: Add your code here...
  int *p = (int *) mem;
  return p[0];
}

/**
 * Implementation of getni()
 */
int
getni(void *mem)
{
  // TODO: Add your code here...
  int *p = (int *) mem;
  return p[1];
}

/**
 * Implementation of getstr()
 */
char *
getstr(void *mem)
{
  // TODO: Add your code here...
  
  return mem + 8;
}

/**
 * Implementation of getintptr()
 */
int *
getintptr(void *mem)
{
  // TODO: Add your code here...
  return mem + 8 + getnc(mem);
}

/**
 * Implementation of getint_at()
 */
int
getint_at(void *mem, int idx, int *res)
{
  // TODO: Add your code here...	
  if(idx >= getni(mem) || idx < 0){
    return -1;
  }
  memcpy(res, getintptr(mem) + idx, sizeof(int));
  return 0;
}

/**
 * Implementation of setint_at()
 */
int
setint_at(void *mem, int idx, int val)
{
  // TODO: Add your code here...
  
  if(idx >= getni(mem) || idx < 0){
    return -1;
  }
	
  memcpy(getintptr(mem) + idx, &val, sizeof(int));
  return 0;
}

int min(int a, int b){
  return (a < b) ? a: b;
}

/**
 * Implementation of cpstr()
 */
size_t
cpstr(void *mem, const char *str, size_t len)
{
  // TODO: Add your code here...
  char *p = (char *) mem;
  memcpy(p+8, str, getnc(mem)); 
  return (size_t) min(getnc(mem), (int) len + 1 );
}
