#ifndef RAY_TRACING_ALGORITHM_RAY_H
#define RAY_TRACING_ALGORITHM_RAY_H


/**
 * 三维空间中的点
 * */
typedef struct {
    float x, y, z;
} Point, *PointPtr;

/**
 * 三维空间中的向量
 * */
typedef struct {
    float x, y, z;
} Vector, *VectorPtr;

/**
 * 矩阵
 * */
typedef struct {
    int row, col;
    float *data;
} Matrix, *MatrixPtr;

/**
 * 颜色，取值范围0~1
 * */
typedef struct {
    float r, g, b;
} Color, *ColorPtr;


/**
 * 射线
 * */
typedef struct {
    Point origin;
    Vector direction;
} Radial, *RadialPtr;

/**
 * 平面
 * */
typedef struct {
    Point position;
    Vector normal;
} Plane, *PlanePtr;

/**
 * 球
 * */
typedef struct {
    Point position;
    float radius;
} Sphere, *SpherePtr;

/**
 * 摄像机，几个关键的参数：摄像机位置、摄像机朝向、摄像机的角度、摄像机到成像平面的距离、摄像机的视野范围、输出图像的尺寸
 * */
typedef struct {
    Point position;
    Vector direction;
    float angle;
} Camera, *CameraPtr;

/**
 * 点的平移-加法
 * */
int point_add_vector(PointPtr left, VectorPtr right, PointPtr out);

/**
 * 点的平移-减法
 * */
int point_sub_vector(PointPtr left, VectorPtr right, PointPtr out);

/**
 * 点的减法
 * */
int point_sub_point(PointPtr left, PointPtr right, VectorPtr out);

/**
 * 向量加法
 * */
int vector_add_vector(VectorPtr left, VectorPtr right, VectorPtr out);

/**
 * 向量减法
 * */
int vector_sub_vector(VectorPtr left, VectorPtr right, VectorPtr out);

/**
 * 向量的内积
 * */
float vector_dot_(VectorPtr left, VectorPtr right);

/**
 * 向量的内积
 * */
int vector_dot(VectorPtr left, VectorPtr right, float *out);

/**
 * 向量的归一化
 * */
int vector_normalize(VectorPtr vector, VectorPtr out);

/**
 * 向量的长度
 * */
float vector_len_(VectorPtr vector);

/**
 * 向量的长度
 * */
int vector_len(VectorPtr vector, float *out);

/**
 * 矩阵初始化
 * */
int matrix_init(MatrixPtr matrix, int row, int col);

/**
 * 获取矩阵指定位置处的值
 * */
float matrix_get_(MatrixPtr matrix, int row, int col);

/**
 * 获取矩阵指定位置处的值
 * */
int matrix_get(MatrixPtr matrix, int row, int col, float *out);

/**
 * 设置矩阵指定位置处的值
 * */
int matrix_set(MatrixPtr matrix, int row, int col, float value);

/**
 * 释放矩阵
 * */
int matrix_free(MatrixPtr matrix);

/**
 * 矩阵加法
 * */
int matrix_add_scalar(MatrixPtr left, float right, MatrixPtr out);

/**
 * 矩阵加法
 * */
int matrix_add_vector(MatrixPtr left, VectorPtr right, MatrixPtr out);

/**
 * 矩阵加法
 * */
int matrix_add_matrix(MatrixPtr left, MatrixPtr right, MatrixPtr out);

/**
 * 矩阵减法
 * */
int matrix_sub_scalar(MatrixPtr left, float right, MatrixPtr out);

/**
 * 矩阵减法
 * */
int matrix_sub_vector(MatrixPtr left, VectorPtr right, MatrixPtr out);

/**
 * 矩阵减法
 * */
int matrix_sub_matrix(MatrixPtr left, MatrixPtr right, MatrixPtr out);

/**
 * 矩阵乘法
 * */
int matrix_mul_scalar(MatrixPtr left, float right, MatrixPtr out);

/**
 * 矩阵乘法
 * */
int matrix_mul_vector(MatrixPtr left, VectorPtr right, MatrixPtr out);

/**
 * 矩阵乘法
 * */
int matrix_mul_matrix(MatrixPtr left, MatrixPtr right, MatrixPtr out);

/**
 * 矩阵除法
 * */
int matrix_div_scalar(MatrixPtr left, float right, MatrixPtr out);

/**
 * 初始化射线
 * */
int radial_init(RadialPtr radial, PointPtr origin, VectorPtr direction);

/**
 * 初始化平面
 * */
int plane_init(PlanePtr plane, PointPtr position, VectorPtr normal);

/**
 * 射线与平面相交判断
 * */
int radial_intersect_plane(RadialPtr radial, PlanePtr plane, float *out);

/**
 * 射线与球相交判断
 * */
int radial_intersect_sphere(RadialPtr radial, SpherePtr sphere, float *out);


#endif //RAY_TRACING_ALGORITHM_RAY_H
