#include "ray.h"

#include <math.h>
#include <malloc.h>

int point_add_vector(PointPtr left, VectorPtr right, PointPtr out) {
    out->x = left->x + right->x;
    out->y = left->y + right->y;
    out->z = left->z + right->z;
    return 0;
}

int point_sub_vector(PointPtr left, VectorPtr right, PointPtr out) {
    out->x = left->x - right->x;
    out->y = left->y - right->y;
    out->z = left->z - right->z;
    return 0;
}

int point_sub_point(PointPtr left, PointPtr right, VectorPtr out) {
    out->x = left->x - right->x;
    out->y = left->y - right->y;
    out->z = left->z - right->z;
    return 0;
}

int vector_add_vector(VectorPtr left, VectorPtr right, VectorPtr out) {
    out->x = left->x + right->x;
    out->y = left->y + right->y;
    out->z = left->z + right->z;
    return 0;
}

int vector_sub_vector(VectorPtr left, VectorPtr right, VectorPtr out) {
    out->x = left->x - right->x;
    out->y = left->y - right->y;
    out->z = left->z - right->z;
    return 0;
}

inline float vector_dot_(VectorPtr left, VectorPtr right) {
    return left->x * right->x + left->y * right->y + left->z * right->z;
}

int vector_dot(VectorPtr left, VectorPtr right, float *out) {
    *out = vector_dot_(left, right);
    return 0;
}

int vector_normalize(VectorPtr vector, VectorPtr out) {
    float len = sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
    if (len < 1e-6)return -1;
    out->x = vector->x / len;
    out->y = vector->y / len;
    out->z = vector->z / len;
    return 0;
}

inline float vector_len_(VectorPtr vector) {
    return sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
}

int vector_len(VectorPtr vector, float *out) {
    *out = vector_len_(vector);
    return 0;
}

int matrix_init(MatrixPtr matrix, int row, int col) {
    matrix->row = row;
    matrix->col = col;
    matrix->data = malloc(sizeof(float) * row * col);
    return 0;
}

inline float matrix_get_(MatrixPtr matrix, int row, int col) {
    return matrix->data[matrix->col * row + col];
}

int matrix_get(MatrixPtr matrix, int row, int col, float *out) {
    if (row < 0 || row >= matrix->row)return -1;
    if (col < 0 || col >= matrix->col)return -1;
    *out = matrix_get_(matrix, row, col);
    return 0;
}

int matrix_set(MatrixPtr matrix, int row, int col, float value) {
    if (row < 0 || row >= matrix->row)return -1;
    if (col < 0 || col >= matrix->col)return -1;
    matrix->data[matrix->col * row + col] = value;
    return 0;
}

int matrix_free(MatrixPtr matrix) {
    matrix->col = 0;
    matrix->row = 0;
    if (matrix->data) free(matrix->data);
}

int matrix_add_scalar(MatrixPtr left, float right, MatrixPtr out) {
    if (left->row != out->row || left->col != out->col)return -1;

    for (int r = 0; r < out->row; r++) {
        for (int c = 0; c < out->col; c++) {
            int i = out->col * r + c;
            out->data[i] = left->data[i] + right;
        }
    }
    return 0;
}

int matrix_add_vector(MatrixPtr left, VectorPtr right, MatrixPtr out) {
    if (left->row != out->row || left->col != out->col)return -1;

    // TODO 未实现
    return 0;
}

int radial_init(RadialPtr radial, PointPtr origin, VectorPtr direction) {
    radial->origin = *origin;
    vector_normalize(direction, &radial->direction);
    return 0;
}

int plane_init(PlanePtr plane, PointPtr position, VectorPtr normal) {
    plane->position = *position;
    vector_normalize(normal, &plane->normal);
    return 0;
}

int radial_intersect_plane(RadialPtr radial, PlanePtr plane, float *out) {
    float sum = vector_dot_(&radial->direction, &plane->normal);
    if (fabsf(sum) < 1e-6)return -1; // 直线与平面平行

    Vector QO;
    point_sub_point(&radial->origin, &plane->position, &QO);

    *out = vector_dot_(&QO, &plane->normal) / sum;
    return 0;
}

int radial_intersect_sphere(RadialPtr radial, SpherePtr sphere, float *out) {
    Vector PO;
    point_sub_point(&radial->origin, &sphere->position, &PO);

    float PK_len = vector_dot_(&PO, &radial->direction);
    float PO_len = vector_len_(&PO);

    float OK_2 = PO_len * PO_len - PK_len * PK_len;
    float r_2 = sphere->radius * sphere->radius;
    if (OK_2 > r_2)return -1; // 射线与球没有焦点

    float RK = sqrtf(r_2 - OK_2);
    *out = PK_len - RK;
    return 0;
}

