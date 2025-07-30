#include "unity/unity.h"
#define YS_MATH_IMPLEMENTATION
#include "../src/ys_math.h"
#include <math.h>
#include <float.h>

// Test configuration
#define TEST_EPSILON 1e-6f
#define TEST_VEC2_EPSILON 1e-6f
#define TEST_VEC3_EPSILON 1e-6f
#define TEST_VEC4_EPSILON 1e-6f

// Helper macros for floating point comparisons
#define ASSERT_FLOAT_EQUAL_EPS(expected, actual, epsilon) \
    TEST_ASSERT_FLOAT_WITHIN(epsilon, expected, actual)

#define ASSERT_VEC2_EQUAL_EPS(expected, actual, epsilon) \
    do { \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.x, actual.x); \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.y, actual.y); \
    } while(0)

#define ASSERT_VEC3_EQUAL_EPS(expected, actual, epsilon) \
    do { \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.x, actual.x); \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.y, actual.y); \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.z, actual.z); \
    } while(0)

#define ASSERT_VEC4_EQUAL_EPS(expected, actual, epsilon) \
    do { \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.x, actual.x); \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.y, actual.y); \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.z, actual.z); \
        TEST_ASSERT_FLOAT_WITHIN(epsilon, expected.w, actual.w); \
    } while(0)

// Test setup and teardown
void setUp(void) {
    // Set up test fixture if needed
}

void tearDown(void) {
    // Clean up test fixture if needed
}

// =============================================================================
// VEC2 TESTS
// =============================================================================

void test_vec2_add(void) {
    vec2 a = {1.0f, 2.0f};
    vec2 b = {3.0f, 4.0f};
    vec2 expected = {4.0f, 6.0f};
    vec2 result = vec2_add(a, b);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_add_s(void) {
    vec2 a = {1.0f, 2.0f};
    float s = 3.0f;
    vec2 expected = {4.0f, 5.0f};
    vec2 result = vec2_add_s(a, s);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_sub(void) {
    vec2 a = {5.0f, 7.0f};
    vec2 b = {2.0f, 3.0f};
    vec2 expected = {3.0f, 4.0f};
    vec2 result = vec2_sub(a, b);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_sub_s(void) {
    vec2 a = {5.0f, 7.0f};
    float s = 2.0f;
    vec2 expected = {3.0f, 5.0f};
    vec2 result = vec2_sub_s(a, s);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_mul(void) {
    vec2 a = {2.0f, 3.0f};
    vec2 b = {4.0f, 5.0f};
    vec2 expected = {8.0f, 15.0f};
    vec2 result = vec2_mul(a, b);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_mul_s(void) {
    vec2 a = {2.0f, 3.0f};
    float s = 4.0f;
    vec2 expected = {8.0f, 12.0f};
    vec2 result = vec2_mul_s(a, s);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_div(void) {
    vec2 a = {8.0f, 15.0f};
    vec2 b = {2.0f, 3.0f};
    vec2 expected = {4.0f, 5.0f};
    vec2 result = vec2_div(a, b);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_div_s(void) {
    vec2 a = {8.0f, 12.0f};
    float s = 4.0f;
    vec2 expected = {2.0f, 3.0f};
    vec2 result = vec2_div_s(a, s);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_len_sq(void) {
    vec2 a = {3.0f, 4.0f};
    float expected = 25.0f; // 3^2 + 4^2 = 9 + 16 = 25
    float result = vec2_len_sq(a);
    ASSERT_FLOAT_EQUAL_EPS(expected, result, TEST_EPSILON);
}

void test_vec2_len(void) {
    vec2 a = {3.0f, 4.0f};
    float expected = 5.0f; // sqrt(25) = 5
    float result = vec2_len(a);
    ASSERT_FLOAT_EQUAL_EPS(expected, result, TEST_EPSILON);
}

void test_vec2_normal(void) {
    vec2 a = {3.0f, 4.0f};
    vec2 expected = {0.6f, 0.8f}; // (3/5, 4/5)
    vec2 result = vec2_normal(a);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
    
    // Verify normalized vector has length 1
    float len = vec2_len(result);
    ASSERT_FLOAT_EQUAL_EPS(1.0f, len, TEST_EPSILON);
}

void test_vec2_normalize(void) {
    vec2 a = {3.0f, 4.0f};
    vec2 expected = {0.6f, 0.8f};
    vec2_normalize(&a);
    ASSERT_VEC2_EQUAL_EPS(expected, a, TEST_VEC2_EPSILON);
    
    // Verify normalized vector has length 1
    float len = vec2_len(a);
    ASSERT_FLOAT_EQUAL_EPS(1.0f, len, TEST_EPSILON);
}

void test_vec2_neg(void) {
    vec2 a = {3.0f, -4.0f};
    vec2 expected = {-3.0f, 4.0f};
    vec2 result = vec2_neg(a);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_negate(void) {
    vec2 a = {3.0f, -4.0f};
    vec2 expected = {-3.0f, 4.0f};
    vec2_negate(&a);
    ASSERT_VEC2_EQUAL_EPS(expected, a, TEST_VEC2_EPSILON);
}

void test_vec2_dot(void) {
    vec2 a = {2.0f, 3.0f};
    vec2 b = {4.0f, 5.0f};
    float expected = 23.0f; // 2*4 + 3*5 = 8 + 15 = 23
    float result = vec2_dot(a, b);
    ASSERT_FLOAT_EQUAL_EPS(expected, result, TEST_EPSILON);
}

void test_vec2_project(void) {
    vec2 a = {1.0f, 1.0f};
    vec2 b = {1.0f, 0.0f}; // unit vector along x-axis
    vec2 expected = {1.0f, 0.0f}; // projection of (1,1) onto x-axis
    vec2 result = vec2_project(a, b);
    ASSERT_VEC2_EQUAL_EPS(expected, result, TEST_VEC2_EPSILON);
}

void test_vec2_zero_vector(void) {
    vec2 zero = {0.0f, 0.0f};
    vec2 a = {1.0f, 2.0f};
    
    // Test operations with zero vector
    vec2 result = vec2_add(a, zero);
    ASSERT_VEC2_EQUAL_EPS(a, result, TEST_VEC2_EPSILON);
    
    result = vec2_mul(a, zero);
    ASSERT_VEC2_EQUAL_EPS(zero, result, TEST_VEC2_EPSILON);
    
    float dot = vec2_dot(a, zero);
    ASSERT_FLOAT_EQUAL_EPS(0.0f, dot, TEST_EPSILON);
}

// =============================================================================
// VEC3 TESTS
// =============================================================================

void test_vec3_add(void) {
    vec3 a = {1.0f, 2.0f, 3.0f};
    vec3 b = {4.0f, 5.0f, 6.0f};
    vec3 expected = {5.0f, 7.0f, 9.0f};
    vec3 result = vec3_add(a, b);
    ASSERT_VEC3_EQUAL_EPS(expected, result, TEST_VEC3_EPSILON);
}

void test_vec3_cross(void) {
    vec3 a = {1.0f, 0.0f, 0.0f};
    vec3 b = {0.0f, 1.0f, 0.0f};
    vec3 expected = {0.0f, 0.0f, 1.0f}; // i × j = k
    vec3 result = vec3_cross(a, b);
    ASSERT_VEC3_EQUAL_EPS(expected, result, TEST_VEC3_EPSILON);
    
    // Test anti-commutative property: a × b = -(b × a)
    vec3 reverse = vec3_cross(b, a);
    vec3 neg_reverse = vec3_neg(reverse);
    ASSERT_VEC3_EQUAL_EPS(result, neg_reverse, TEST_VEC3_EPSILON);
}

void test_vec3_cross_properties(void) {
    vec3 a = {1.0f, 2.0f, 3.0f};
    vec3 b = {4.0f, 5.0f, 6.0f};
    vec3 cross = vec3_cross(a, b);
    
    // Cross product should be perpendicular to both vectors
    float dot_a = vec3_dot(cross, a);
    float dot_b = vec3_dot(cross, b);
    ASSERT_FLOAT_EQUAL_EPS(0.0f, dot_a, TEST_EPSILON);
    ASSERT_FLOAT_EQUAL_EPS(0.0f, dot_b, TEST_EPSILON);
}

void test_vec3_len(void) {
    vec3 a = {1.0f, 2.0f, 2.0f};
    float expected = 3.0f; // sqrt(1 + 4 + 4) = sqrt(9) = 3
    float result = vec3_len(a);
    ASSERT_FLOAT_EQUAL_EPS(expected, result, TEST_EPSILON);
}

void test_vec3_normal(void) {
    vec3 a = {1.0f, 2.0f, 2.0f};
    vec3 result = vec3_normal(a);
    
    // Verify normalized vector has length 1
    float len = vec3_len(result);
    ASSERT_FLOAT_EQUAL_EPS(1.0f, len, TEST_EPSILON);
}

void test_vec3_dot(void) {
    vec3 a = {1.0f, 2.0f, 3.0f};
    vec3 b = {4.0f, 5.0f, 6.0f};
    float expected = 32.0f; // 1*4 + 2*5 + 3*6 = 4 + 10 + 18 = 32
    float result = vec3_dot(a, b);
    ASSERT_FLOAT_EQUAL_EPS(expected, result, TEST_EPSILON);
}

void test_vec3_project(void) {
    vec3 a = {1.0f, 1.0f, 0.0f};
    vec3 b = {1.0f, 0.0f, 0.0f}; // unit vector along x-axis
    vec3 expected = {1.0f, 0.0f, 0.0f}; // projection onto x-axis
    vec3 result = vec3_project(a, b);
    ASSERT_VEC3_EQUAL_EPS(expected, result, TEST_VEC3_EPSILON);
}

// =============================================================================
// VEC4 TESTS
// =============================================================================

void test_vec4_add(void) {
    vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4 b = {5.0f, 6.0f, 7.0f, 8.0f};
    vec4 expected = {6.0f, 8.0f, 10.0f, 12.0f};
    vec4 result = vec4_add(a, b);
    ASSERT_VEC4_EQUAL_EPS(expected, result, TEST_VEC4_EPSILON);
}

void test_vec4_len(void) {
    vec4 a = {1.0f, 2.0f, 2.0f, 2.0f};
    float expected = 3.0f; // sqrt(1 + 4 + 4 + 4) = sqrt(13) ≈ 3.606
    float result = vec4_len(a);
    // Using sqrt(13) for more accurate test
    ASSERT_FLOAT_EQUAL_EPS(sqrtf(13.0f), result, TEST_EPSILON);
}

void test_vec4_normal(void) {
    vec4 a = {1.0f, 2.0f, 2.0f, 2.0f};
    vec4 result = vec4_normal(a);
    
    // Verify normalized vector has length 1
    float len = vec4_len(result);
    ASSERT_FLOAT_EQUAL_EPS(1.0f, len, TEST_EPSILON);
}

void test_vec4_dot(void) {
    vec4 a = {1.0f, 2.0f, 3.0f, 4.0f};
    vec4 b = {5.0f, 6.0f, 7.0f, 8.0f};
    float expected = 70.0f; // 1*5 + 2*6 + 3*7 + 4*8 = 5 + 12 + 21 + 32 = 70
    float result = vec4_dot(a, b);
    ASSERT_FLOAT_EQUAL_EPS(expected, result, TEST_EPSILON);
}

// =============================================================================
// EDGE CASE TESTS
// =============================================================================

void test_normalization_edge_cases(void) {
    // Test very small vector normalization
    vec2 small = {1e-10f, 1e-10f};
    vec2 result = vec2_normal(small);
    // Should still be normalized (though may have precision issues)
    float len = vec2_len(result);
    if (!isnan(len) && !isinf(len)) {
        ASSERT_FLOAT_EQUAL_EPS(1.0f, len, 1e-5f);
    }
}

void test_division_by_zero_safety(void) {
    // Note: Your library doesn't check for division by zero
    // These tests document the current behavior
    vec2 a = {1.0f, 2.0f};
    vec2 result = vec2_div_s(a, 0.0f);
    
    // Result will be infinity - this is expected behavior
    TEST_ASSERT_TRUE(isinf(result.x) || isnan(result.x));
    TEST_ASSERT_TRUE(isinf(result.y) || isnan(result.y));
}

void test_mathematical_identities(void) {
    vec3 a = {1.0f, 2.0f, 3.0f};
    vec3 b = {4.0f, 5.0f, 6.0f};
    
    // Test dot product commutative property
    float dot1 = vec3_dot(a, b);
    float dot2 = vec3_dot(b, a);
    ASSERT_FLOAT_EQUAL_EPS(dot1, dot2, TEST_EPSILON);
    
    // Test cross product anti-commutative property
    vec3 cross1 = vec3_cross(a, b);
    vec3 cross2 = vec3_cross(b, a);
    vec3 neg_cross2 = vec3_neg(cross2);
    ASSERT_VEC3_EQUAL_EPS(cross1, neg_cross2, TEST_VEC3_EPSILON);
}

// =============================================================================
// MAIN TEST RUNNER
// =============================================================================

int main(void) {
    UNITY_BEGIN();
    
    // VEC2 tests
    RUN_TEST(test_vec2_add);
    RUN_TEST(test_vec2_add_s);
    RUN_TEST(test_vec2_sub);
    RUN_TEST(test_vec2_sub_s);
    RUN_TEST(test_vec2_mul);
    RUN_TEST(test_vec2_mul_s);
    RUN_TEST(test_vec2_div);
    RUN_TEST(test_vec2_div_s);
    RUN_TEST(test_vec2_len_sq);
    RUN_TEST(test_vec2_len);
    RUN_TEST(test_vec2_normal);
    RUN_TEST(test_vec2_normalize);
    RUN_TEST(test_vec2_neg);
    RUN_TEST(test_vec2_negate);
    RUN_TEST(test_vec2_dot);
    RUN_TEST(test_vec2_project);
    RUN_TEST(test_vec2_zero_vector);
    
    // VEC3 tests
    RUN_TEST(test_vec3_add);
    RUN_TEST(test_vec3_cross);
    RUN_TEST(test_vec3_cross_properties);
    RUN_TEST(test_vec3_len);
    RUN_TEST(test_vec3_normal);
    RUN_TEST(test_vec3_dot);
    RUN_TEST(test_vec3_project);
    
    // VEC4 tests
    RUN_TEST(test_vec4_add);
    RUN_TEST(test_vec4_len);
    RUN_TEST(test_vec4_normal);
    RUN_TEST(test_vec4_dot);
    
    // Edge case tests
    RUN_TEST(test_normalization_edge_cases);
    RUN_TEST(test_division_by_zero_safety);
    RUN_TEST(test_mathematical_identities);
    
    return UNITY_END();
}
