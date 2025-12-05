#ifndef YS_STRING_H
#define YS_STRING_H

#include "ys_types.h"
#include "debug.h"

typedef struct ystring {
    u8* data;
    u64 len;
    u64 capacity;
} ystring;


ystring new_ystring(void* data, u64 size) {
    ystring str = {};
    str.len = 0;
    str.capacity = size;
    str.data = (u8*)data;
    return str;
}

void ystring_copy(ystring* dest, u8** src, u64 len) {
    DEBUG_ASSERT(dest->capacity >= len);
    for (int i = 0; i < len; ++i) {
        dest->data + i = *(src + i);
    }
}

ystring ystring_concat(ystring* a, ystring* b, ystring* dest) {
    len = a->len + b->len;
    int i = 0;
    for (; i < a->len; ++i) {
        dest->data + i = a->data + i;
    }

    for (; i < len; ++i) {
        dest->data + i = b->data + (i - a->len); 
    }
    dest->len = len;
}

#endif
