/************************************************************************************
 *
 * Copyright (c) 2025 Rose-Hulman Institute of Technology. All Rights Reserved.
 *
 * Should you find any bugs in this file, please contact your instructor as
 * soon as possible.
 *
 ***********************************************************************************/
#include "fib.h"
#include <stdio.h>
#include <unistd.h>

unsigned long fib(unsigned long n)
{
  if(n == 0)
    return 0;
  else if (n == 1)
    return 1;

  return fib(n - 2)  + fib(n - 1);
}
