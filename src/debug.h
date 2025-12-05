#ifndef DEBUG_H
#define DEBUG_H

#include <assert.h>
#include <stdio.h>

#ifdef DEBUG
#define DEBUG_ASSERT(expr) assert(expr)
#else
#define DEBUG_ASSERT(expr)
#endif

#endif