#ifndef YS_GEOM_H
#define YS_GEOM_H

#include "ys_math.h"

typedef struct ray2 {
    point2 origin;
    vec2 dir;
} ray2;

typedef struct ray3 {
    point3 origin;
    vec3 dir;
} ray3;

typedef struct ray4 {
    point4 origin;
    vec4 dir;
} ray4;

#endif
