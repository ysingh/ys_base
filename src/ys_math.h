#ifndef YS_MATH_H
#define YS_MATH_H

#ifndef SQRTF
#include <math.h>
#define SQRTF sqrtf
#endif

#include "ys_types.h"

/*
 *  === DATA DEFINITIONS ===
*/

typedef union vec2 {
    struct { f32 x; f32 y; };
    f32 e[2];
} vec2;

typedef union vec3 {
    struct { f32 x; f32 y; f32 z; };
    struct { f32 r; f32 g; f32 b; };
    f32 e[3];
} vec3;


typedef union vec4 {
    struct { f32 x; f32 y; f32 z; f32 w; };
    struct { f32 r; f32 g; f32 b; f32 a; };
    f32 e[4];
} vec4;

typedef union mat2 {
    struct { 
        f32 m00; f32 m10; 
        f32 m01; f32 m11; 
    };
    f32 e[4];
    f32 m[2][2];
} mat2;

typedef union mat3 {
    struct { 
        f32 m00; f32 m10; f32 m20;
        f32 m01; f32 m11; f32 m21;
        f32 m02; f32 m12; f32 m22;
    };
    f32 e[9];
    f32 m[3][3];
} mat3;

typedef union mat4 {
    struct { 
        f32 m00; f32 m10; f32 m20; f32 m30;
        f32 m01; f32 m11; f32 m21; f32 m31;
        f32 m02; f32 m12; f32 m22; f32 m32;
        f32 m03; f32 m13; f32 m23; f32 m33;
    };
    f32 e[16];
    f32 m[4][4];
} mat4;

typedef vec2 point2;
typedef vec3 point3;
typedef vec4 point4;
typedef vec2 color2;
typedef vec3 color3;
typedef vec4 color4;


/*
 * === VEC2 INTERFACE ===
*/
vec2 vec2_add(const vec2 a, const vec2 b);
vec2 vec2_add_s(const vec2 a, const f32 s);
vec2 vec2_sub(const vec2 a, const vec2 b);
vec2 vec2_sub_s(const vec2 a, const f32 s);
vec2 vec2_mul(const vec2 a, const vec2 b);
vec2 vec2_mul_s(const vec2 a, const f32 s);
vec2 vec2_div(const vec2 a, const vec2 b);
vec2 vec2_div_s(const vec2 a, const f32 s);
f32 vec2_len_sq(const vec2 a);
f32 vec2_len(const vec2 a);
vec2 vec2_normal(const vec2 a);
void vec2_normalize(vec2* a);
vec2 vec2_neg(const vec2 a);
void vec2_negate(vec2* a);
f32 vec2_dot(const vec2 a, const vec2 b);
vec2 vec2_project(const vec2 a, const vec2 b);


/*
 * === VEC3 INTERFACE ===
*/
vec3 vec3_add(const vec3 a, const vec3 b);
vec3 vec3_add_s(const vec3 a, const f32 s);
vec3 vec3_sub(const vec3 a, const vec3 b);
vec3 vec3_sub_s(const vec3 a, const f32 s);
vec3 vec3_mul(const vec3 a, const vec3 b);
vec3 vec3_mul_s(const vec3 a, const f32 s);
vec3 vec3_div(const vec3 a, const vec3 b);
vec3 vec3_div_s(const vec3 a, const f32 s);
f32 vec3_len_sq(const vec3 a);
f32 vec3_len(const vec3 a);
vec3 vec3_normal(const vec3 a);
void vec3_normalize(vec3* a);
vec3 vec3_neg(const vec3 a);
void vec3_negate(vec3* a);
f32 vec3_dot(const vec3 a, const vec3 b);
vec3 vec3_cross(const vec3 a, const vec3 b);
vec3 vec3_project(const vec3 a, const vec3 b);


/*
 * === VEC4 INTERFACE ===
*/
vec4 vec4_add(const vec4 a, const vec4 b);
vec4 vec4_add_s(const vec4 a, const f32 s);
vec4 vec4_sub(const vec4 a, const vec4 b);
vec4 vec4_sub_s(const vec4 a, const f32 s);
vec4 vec4_mul(const vec4 a, const vec4 b);
vec4 vec4_mul_s(const vec4 a, const f32 s);
vec4 vec4_div(const vec4 a, const vec4 b);
vec4 vec4_div_s(const vec4 a, const f32 s);
f32 vec4_len_sq(const vec4 a);
f32 vec4_len(const vec4 a);
vec4 vec4_normal(const vec4 a);
void vec4_normalize(vec4* a);
vec4 vec4_neg(const vec4 a);
void vec4_negate(vec4* a);
f32 vec4_dot(const vec4 a, const vec4 b);
vec4 vec4_project(const vec4 a, const vec4 b);


/*
 * === MAT2 INTERFACE ===
*/
inline mat2 mat2_add(const mat2 a, const mat2 b);
inline mat2 mat2_sub(const mat2 a, const mat2 b);
inline mat2 mat2_mul_s(const mat2 a, const f32 s);
inline mat2 mat2_div_s(const mat2 a, const f32 s);
inline mat2 mat2_transpose(const mat2 a);
inline mat2 mat2_mul(const mat2 a, const mat2 b);
inline mat2 mat2_identity(void);
inline mat2 mat2_inverse(const mat2 a);
inline f32 mat2_trace(const mat2 a);
inline f32 mat2_det(const mat2 a);


/*
 * === MAT3 INTERFACE ===
*/
inline mat3 mat3_add(const mat3 a, const mat3 b);
inline mat3 mat3_sub(const mat3 a, const mat3 b);
inline mat3 mat3_mul_s(const mat3 a, const f32 s);
inline mat3 mat3_div_s(const mat3 a, const f32 s);
inline mat3 mat3_transpose(const mat3 a);
inline mat3 mat3_mul(const mat3 a, const mat3 b);
inline mat3 mat3_identity(void);
inline f32 mat3_trace(const mat3 a);
inline f32 mat3_det(const mat3 a);
inline mat3 mat3_inverse(const mat3 a);

/*
 * === MAT4 INTERFACE ===
*/
inline mat4 mat4_add(const mat4 a, const mat4 b);
inline mat4 mat4_sub(const mat4 a, const mat4 b);
inline mat4 mat4_mul_s(const mat4 a, const f32 s);
inline mat4 mat4_div_s(const mat4 a, const f32 s);
inline mat4 mat4_transpose(const mat4 a);
inline mat4 mat4_mul(const mat4 a, const mat4 b);
inline mat4 mat4_identity(void);
inline f32 mat4_trace(const mat4 a);
inline f32 mat4_det(const mat4 a);
inline mat4 mat4_inverse(const mat4 a);
inline mat4 mat4_translation_x(const f32 tx);
inline mat4 mat4_translation_y(const f32 ty);
inline mat4 mat4_translation_z(const f32 tz);
inline mat4 mat4_translation(const f32 tx, const f32 ty, const f32 tz);
inline mat4 mat4_translation_vec3(const vec3 a);
inline mat4 mat4_translation_vec4(const vec4 a);
inline mat4 mat4_rotation_x(const f32 xr);
inline mat4 mat4_rotation_y(const f32 yr);
inline mat4 mat4_rotation_z(const f32 zr);
inline mat4 mat4_rotation(const f32 xr, f32 yr, f32 zr);
inline mat4 mat4_scale_x(const f32 sx);
inline mat4 mat4_scale_y(const f32 sy);
inline mat4 mat4_scale_z(const f32 sz);
inline mat4 mat4_scale(const f32 sx, const f32 sy, const f32 sz);


#ifdef YS_MATH_IMPLEMENTATION


/*
 * ==== VEC2 IMPLEMENTATION =======
*/

inline vec2 vec2_add(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}

inline vec2 vec2_add_s(const vec2 a, const f32 s) {
    vec2 r;
    r.x = a.x + s;
    r.y = a.y + s;
    return r;
}

inline vec2 vec2_sub(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

inline vec2 vec2_sub_s(const vec2 a, const f32 s) {
    vec2 r;
    r.x = a.x - s;
    r.y = a.y - s;
    return r;
}

inline vec2 vec2_mul(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    return r;
}

inline vec2 vec2_mul_s(const vec2 a, const f32 s) {
    vec2 r;
    r.x = a.x * s;
    r.y = a.y * s;
    return r;
}

inline vec2 vec2_div(const vec2 a, const vec2 b) {
    vec2 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    return r;
}

inline vec2 vec2_div_s(const vec2 a, const f32 s) {
    vec2 r;
    f32 inv_s = 1.0f/s;
    r.x = a.x * inv_s;
    r.y = a.y * inv_s;
    return r;
}

inline f32 vec2_len_sq(const vec2 a) {
    return a.x * a.x + a.y * a.y; 
}

inline f32 vec2_len(const vec2 a) {
    return SQRTF(vec2_len_sq(a));
}

inline vec2 vec2_normal(const vec2 a) {
    vec2 r;
    f32 inv_len = 1.0f/vec2_len(a);
    r.x = a.x * inv_len;
    r.y = a.y * inv_len;
    return r;
}

inline void vec2_normalize(vec2* a) {
    f32 inv_len = 1.0f/vec2_len(*a);
    a->x *= inv_len;
    a->y *= inv_len;
}

inline vec2 vec2_neg(const vec2 a) {
    vec2 r;
    r.x = -a.x;
    r.y = -a.y;
    return r;
}

inline void vec2_negate(vec2* a) {
    a->x = -a->x;
    a->y = -a->y;
}

inline f32 vec2_dot(const vec2 a, const vec2 b) {
    return a.x * b.x + a.y * b.y;
}

inline vec2 vec2_project(const vec2 a, const vec2 b) {
    f32 dot = vec2_dot(a, b);
    return vec2_mul_s(b, dot/vec2_len_sq(b));
}


/*
 * ==== VEC3 IMPLEMENTATION =======
*/

inline vec3 vec3_add(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

inline vec3 vec3_add_s(const vec3 a, const f32 s) {
    vec3 r;
    r.x = a.x + s;
    r.y = a.y + s;
    r.z = a.z + s;
    return r;
}

inline vec3 vec3_sub(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    return r;
}

inline vec3 vec3_sub_s(const vec3 a, const f32 s) {
    vec3 r;
    r.x = a.x - s;
    r.y = a.y - s;
    r.z = a.z - s;
    return r;
}

inline vec3 vec3_mul(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    return r;
}

inline vec3 vec3_mul_s(const vec3 a, const f32 s) {
    vec3 r;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
    return r;
}

inline vec3 vec3_div(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    return r;
}

inline vec3 vec3_div_s(const vec3 a, const f32 s) {
    vec3 r;
    f32 inv_s = 1.0f/s;
    r.x = a.x * inv_s;
    r.y = a.y * inv_s;
    r.z = a.z * inv_s;
    return r;
}

inline f32 vec3_len_sq(const vec3 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

inline f32 vec3_len(const vec3 a) {
    return SQRTF(vec3_len_sq(a));
}

inline vec3 vec3_normal(const vec3 a) {
    vec3 r;
    f32 inv_len = 1.0f/vec3_len(a);
    r.x = a.x * inv_len;
    r.y = a.y * inv_len;
    r.z = a.z * inv_len;
    return r;
}

inline void vec3_normalize(vec3* a) {
    f32 inv_len = 1.0f/vec3_len(*a);
    a->x *= inv_len;
    a->y *= inv_len;
    a->z *= inv_len;
}

inline vec3 vec3_neg(const vec3 a) {
    vec3 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    return r;
}

inline void vec3_negate(vec3* a) {
    a->x = -a->x;
    a->y = -a->y;
    a->z = -a->z;
}

inline f32 vec3_dot(const vec3 a, const vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec3 vec3_cross(const vec3 a, const vec3 b) {
    vec3 r;
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
    return r;
}

inline vec3 vec3_project(const vec3 a, const vec3 b) {
    f32 dot = vec3_dot(a, b);
    return vec3_mul_s(b, dot/vec3_len_sq(b));
}


/*
 * ==== VEC4 IMPLEMENTATION =======
*/

inline vec4 vec4_add(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    r.w = a.w + b.w;
    return r;
}

inline vec4 vec4_add_s(const vec4 a, const f32 s) {
    vec4 r;
    r.x = a.x + s;
    r.y = a.y + s;
    r.z = a.z + s;
    r.w = a.w + s;
    return r;
}

inline vec4 vec4_sub(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
    return r;
}

inline vec4 vec4_sub_s(const vec4 a, const f32 s) {
    vec4 r;
    r.x = a.x - s;
    r.y = a.y - s;
    r.z = a.z - s;
    r.w = a.w - s;
    return r;
}

inline vec4 vec4_mul(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x * b.x;
    r.y = a.y * b.y;
    r.z = a.z * b.z;
    r.w = a.w * b.w;
    return r;
}

inline vec4 vec4_mul_s(const vec4 a, const f32 s) {
    vec4 r;
    r.x = a.x * s;
    r.y = a.y * s;
    r.z = a.z * s;
    r.w = a.w * s;
    return r;
}

inline vec4 vec4_div(const vec4 a, const vec4 b) {
    vec4 r;
    r.x = a.x / b.x;
    r.y = a.y / b.y;
    r.z = a.z / b.z;
    r.w = a.w / b.w;
    return r;
}

inline vec4 vec4_div_s(const vec4 a, const f32 s) {
    vec4 r;
    f32 inv_s = 1.0f/s;
    r.x = a.x * inv_s;
    r.y = a.y * inv_s;
    r.z = a.z * inv_s;
    r.w = a.w * inv_s;
    return r;
}

f32 inline vec4_len_sq(const vec4 a) {
    return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

f32 inline vec4_len(const vec4 a) {
    return SQRTF(vec4_len_sq(a));
}

inline vec4 vec4_normal(const vec4 a) {
    vec4 r;
    f32 inv_len = 1.0f/vec4_len(a);
    r.x = a.x * inv_len;
    r.y = a.y * inv_len;
    r.z = a.z * inv_len;
    r.w = a.w * inv_len;
    return r;
}

inline void vec4_normalize(vec4* a) {
    f32 inv_len = 1.0f/vec4_len(*a);
    a->x *= inv_len;
    a->y *= inv_len;
    a->z *= inv_len;
    a->w *= inv_len;
}

inline vec4 vec4_neg(const vec4 a) {
    vec4 r;
    r.x = -a.x;
    r.y = -a.y;
    r.z = -a.z;
    r.w = -a.w;
    return r;
}

inline void vec4_negate(vec4* a) {
    a->x = -a->x;
    a->y = -a->y;
    a->z = -a->z;
    a->w = -a->w;
}

inline f32 vec4_dot(const vec4 a, const vec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline vec4 vec4_project(const vec4 a, const vec4 b) {
    f32 dot = vec4_dot(a, b);
    return vec4_mul_s(b, dot/vec4_len_sq(b));
}


/*
 * ==== MAT 2 =======
*/

inline mat2 mat2_add(const mat2 a, const mat2 b) {
    mat2 r;
    for (int i = 0; i < 4; ++i) {
        r.e[i] = a.e[i] + b.e[i];
    }
    return r;
}

inline mat2 mat2_sub(const mat2 a, const mat2 b) {
    mat2 r;
    for (int i = 0; i < 4; ++i) {
        r.e[i] = a.e[i] - b.e[i];
    }
    return r;
}

inline mat2 mat2_mul_s(const mat2 a, const f32 s) {
    mat2 r;
    for (int i = 0; i < 4; ++i) {
        r.e[i] = a.e[i] * s;
    }
    return r;
}

inline mat2 mat2_div_s(const mat2 a, const f32 s) {
    f32 inv_s = 1.0f/s;
    return mat2_mul_s(a, inv_s);
}

inline mat2 mat2_transpose(const mat2 a) {
    mat2 r;
    r.m00 = a.m00;
    r.m10 = a.m01;
    r.m01 = a.m10;
    r.m11 = a.m11;
    return r;
}

inline mat2 mat2_mul(const mat2 a, const mat2 b) {
    mat2 r;
    r.m00 = a.m00 * b.m00 + a.m01 * b.m10;
    r.m10 = a.m10 * b.m00 + a.m11 * b.m10;
    r.m01 = a.m00 * b.m01 + a.m01 * b.m11;
    r.m11 = a.m10 * b.m01 + a.m11 * b.m11;
    return r;
}

inline mat2 mat2_identity(void) {
    mat2 r;
    r.m00 = 1;
    r.m10 = 0;
    r.m01 = 0;
    r.m11 = 1;
    return r;
}

inline mat2 mat2_inverse(const mat2 a) {
    f32 s = 1.0f/(a.m00 * a.m11 - a.m01 * a.m10);
    mat2 r;
    r.m00 = a.m11 * s;
    r.m10 = - a.m10 * s;
    r.m01 = -a.m01 * s;
    r.m11 = a.m00 * s;
    return r;
}

inline f32 mat2_trace(const mat2 a) {
    return a.m00 + a.m11;
}

inline f32 mat2_det(const mat2 a) {
    return a.m00 * a.m11 - a.m01 * a.m10;
}
/*
 * ==== MAT 3 =======
*/

inline mat3 mat3_add(const mat3 a, const mat3 b) {
    mat3 r;
    for (int i = 0; i < 9; ++i) {
        r.e[i] = a.e[i] + b.e[i];
    }
    return r;
}

inline mat3 mat3_sub(const mat3 a, const mat3 b) {
    mat3 r;
    for (int i = 0; i < 9; ++i) {
        r.e[i] = a.e[i] - b.e[i];
    }
    return r;
}

inline mat3 mat3_mul_s(const mat3 a, const f32 s) {
    mat3 r;
    for (int i = 0; i < 9; ++i) {
        r.e[i] = a.e[i] * s;
    }
    return r;
}

inline mat3 mat3_div_s(const mat3 a, const f32 s) {
    f32 inv_s = 1.0f/s;
    return mat3_mul_s(a, inv_s);
}

inline mat3 mat3_transpose(const mat3 a) {
    mat3 r;
    r.m00 = a.m00;
    r.m01 = a.m10;
    r.m02 = a.m20;
    r.m10 = a.m01;
    r.m11 = a.m11;
    r.m12 = a.m21;
    r.m20 = a.m02;
    r.m21 = a.m12;
    r.m22 = a.m22;
    return r;
}

inline mat3 mat3_mul(const mat3 a, const mat3 b) {
    mat3 r;
    r.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20;
    r.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21;
    r.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22;
    r.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20;
    r.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21;
    r.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22;
    r.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20;
    r.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21;
    r.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22;
    return r;
}

inline mat3 mat3_identity(void) {
    mat3 r;
    r.m00 = 1;
    r.m01 = 0;
    r.m02 = 0;
    r.m10 = 0;
    r.m11 = 1;
    r.m12 = 0;
    r.m20 = 0;
    r.m21 = 0;
    r.m22 = 1;
    return r;
}

inline f32 mat3_trace(const mat3 a) {
    return a.m00 + a.m11 + a.m22;
}

inline f32 mat3_det(const mat3 a) {
    return a.m00 * a.m11 * a.m22 
        + a.m01 * a.m12 * a.m20
        + a.m02 * a.m10 * a.m21
        - a.m02 * a.m11 * a.m20 
        - a.m01 * a.m10 * a.m22
        - a.m00 * a.m12 * a.m21;
}

inline mat3 mat3_inverse(const mat3 a) {
    // TODO: IMPLEMENT
    return a;
}
/*
 * ==== MAT 4 =======
*/
inline mat4 mat4_add(const mat4 a, const mat4 b) {
    mat4 r;
    for (int i = 0; i < 16; ++i) {
        r.e[i] = a.e[i] + b.e[i];
    }
    return r;
}

inline mat4 mat4_sub(const mat4 a, const mat4 b) {
    mat4 r;
    for (int i = 0; i < 16; ++i) {
        r.e[i] = a.e[i] - b.e[i];
    }
    return r;
}

inline mat4 mat4_mul_s(const mat4 a, const f32 s) {
    mat4 r;
    for (int i = 0; i < 16; ++i) {
        r.e[i] = a.e[i] * s;
    }
    return r;
}

inline mat4 mat4_div_s(const mat4 a, const f32 s) {
    f32 inv_s = 1.0f/s;
    return mat4_mul_s(a, inv_s);
}

inline mat4 mat4_transpose(const mat4 a) {
    mat4 r = {};
    r.m00 = a.m00;
    r.m01 = a.m10;
    r.m02 = a.m20;
    r.m03 = a.m30;
    r.m10 = a.m01;
    r.m11 = a.m11;
    r.m12 = a.m21;
    r.m13 = a.m31;
    r.m20 = a.m02;
    r.m21 = a.m12;
    r.m22 = a.m22;
    r.m23 = a.m32;
    r.m30 = a.m03;
    r.m31 = a.m13;
    r.m32 = a.m23;
    r.m33 = a.m33;
    return r;
}

inline mat4 mat4_mul(const mat4 a, const mat4 b) {
    mat4 r;
    
    r.m00 = a.m00 * b.m00 + a.m01 * b.m10 + a.m02 * b.m20 + a.m03 * b.m30;
    r.m01 = a.m00 * b.m01 + a.m01 * b.m11 + a.m02 * b.m21 + a.m03 * b.m31;
    r.m02 = a.m00 * b.m02 + a.m01 * b.m12 + a.m02 * b.m22 + a.m03 * b.m32;
    r.m03 = a.m00 * b.m03 + a.m01 * b.m13 + a.m02 * b.m23 + a.m03 * b.m33;
    
    r.m10 = a.m10 * b.m00 + a.m11 * b.m10 + a.m12 * b.m20 + a.m13 * b.m30;
    r.m11 = a.m10 * b.m01 + a.m11 * b.m11 + a.m12 * b.m21 + a.m13 * b.m31;
    r.m12 = a.m10 * b.m02 + a.m11 * b.m12 + a.m12 * b.m22 + a.m13 * b.m32;
    r.m13 = a.m10 * b.m03 + a.m11 * b.m13 + a.m12 * b.m23 + a.m13 * b.m33;
    
    r.m20 = a.m20 * b.m00 + a.m21 * b.m10 + a.m22 * b.m20 + a.m23 * b.m30;
    r.m21 = a.m20 * b.m01 + a.m21 * b.m11 + a.m22 * b.m21 + a.m23 * b.m31;
    r.m22 = a.m20 * b.m02 + a.m21 * b.m12 + a.m22 * b.m22 + a.m23 * b.m32;
    r.m23 = a.m20 * b.m03 + a.m21 * b.m13 + a.m22 * b.m23 + a.m23 * b.m33;

    r.m30 = a.m30 * b.m00 + a.m31 * b.m10 + a.m32 * b.m20 + a.m33 * b.m30;
    r.m31 = a.m30 * b.m01 + a.m31 * b.m11 + a.m32 * b.m21 + a.m33 * b.m31;
    r.m32 = a.m30 * b.m02 + a.m31 * b.m12 + a.m32 * b.m22 + a.m33 * b.m32;
    r.m33 = a.m30 * b.m03 + a.m31 * b.m13 + a.m32 * b.m23 + a.m33 * b.m33;

    return r;
}

inline mat4 mat4_identity(void) {
    mat4 r;
    r.m00 = 1;
    r.m01 = 0;
    r.m02 = 0;
    r.m03 = 0;
    r.m10 = 0;
    r.m11 = 1;
    r.m12 = 0;
    r.m13 = 0;
    r.m20 = 0;
    r.m21 = 0;
    r.m22 = 1;
    r.m23 = 0;
    r.m30 = 0;
    r.m31 = 0;
    r.m32 = 0;
    r.m33 = 1;
    return r;
}

inline f32 mat4_trace(const mat4 a) {
    return a.m00 + a.m11 + a.m22 + a.m33;
}

// Since the 4x4 matrices we use are homogeneous
// we can take the determinant of the upper left 3x3 submatrix
inline f32 mat4_det(const mat4 a) {
    mat3 r;
    r.m00 = a.m00;
    r.m10 = a.m10;
    r.m20 = a.m20;
    r.m01 = a.m01;
    r.m11 = a.m11;
    r.m21 = a.m21;
    r.m02 = a.m02;
    r.m12 = a.m12;
    r.m22 = a.m22;
    return mat3_det(r);
}

inline mat4 mat4_inverse(const mat4 a) {
    // TODO: IMPLEMENT
    return a;
}

inline mat4 mat4_translation_x(const f32 tx) {
    mat4 a = {0};
    a.m03 = tx;
    return a;
}

inline mat4 mat4_translation_y(const f32 ty) {
    mat4 a = {0};
    a.m13 = ty;
    return a;

}

inline mat4 mat4_translation_z(const f32 tz) {
    mat4 a = {0};
    a.m23 = tz;
    return a;

}
inline mat4 mat4_translation(const f32 tx, const f32 ty, const f32 tz) {
    mat4 a = {0};
    a.m03 = tx;
    a.m13 = ty;
    a.m23 = tz;
    return a;

}

inline mat4 mat4_translation_vec3(const vec3 a) {
    mat4 r = {0};
    r.m03 = a.x;
    r.m13 = a.y;
    r.m23 = a.z;
    return r;

}

inline mat4 mat4_translation_vec4(const vec4 a) {
    mat4 r = {0};
    r.m03 = a.x;
    r.m13 = a.y;
    r.m23 = a.z;
    return r;

}

inline mat4 mat4_rotation_x(const f32 xr) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_rotation_y(const f32 yr) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_rotation_z(const f32 zr) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_rotation(const f32 xr, f32 yr, f32 zr) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_scale_x(const f32 sx) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_scale_y(const f32 sy) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_scale_z(const f32 sz) {
    // TODO: IMPLEMENT

}

inline mat4 mat4_scale(const f32 sx, const f32 sy, const f32 sz) {
    // TODO: IMPLEMENT

}

#endif
#endif
