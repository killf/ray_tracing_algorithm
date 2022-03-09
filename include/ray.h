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
int vector_dot(VectorPtr left, VectorPtr right, VectorPtr out);

/**
 * 向量的归一化
 * */
int vector_normalize(VectorPtr vector, VectorPtr out);

/**
 * 向量的长度
 * */
int vector_len(VectorPtr vector, float *out);

#endif //RAY_TRACING_ALGORITHM_RAY_H
