#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>

#define RAD2DEG(x)   x*180/M_PI
#define DEG2RAD(x)   x*M_PI/180

typedef struct
{
    double x;
    double y;
    double theta;
} Pose2D;

typedef struct
{
    double x;
    double y;
} Point2D;

Pose2D base_link_origin;
Point2D base_link_Point2D, base_link_map_Point2D;

double angle_degree;
double angle_radian;
double Rotation_matrix[2][2];
double Rotation_matrix_inverse[2][2];

void set_rotation_matrix(double m_angle_degree)
{
    angle_radian = DEG2RAD(m_angle_degree);
    Rotation_matrix[0][0] = cos(angle_radian);      Rotation_matrix[0][1] = -sin(angle_radian);
    Rotation_matrix[1][0] = sin(angle_radian);      Rotation_matrix[1][1] = cos(angle_radian);

    // Calculate the inverse (transpose) of the rotation matrix
    Rotation_matrix_inverse[0][0] = Rotation_matrix[0][0];      Rotation_matrix_inverse[0][1] = Rotation_matrix[1][0];
    Rotation_matrix_inverse[1][0] = Rotation_matrix[0][1];      Rotation_matrix_inverse[1][1] = Rotation_matrix[1][1];
}

void TF_base_link_base_link_map(Point2D base_link_point2d, Point2D* base_link_map_point2d, Pose2D base_link_origin)
{
    // Apply 2D rotation
    double rotated_x = Rotation_matrix[0][0] * base_link_point2d.x + Rotation_matrix[0][1] * base_link_point2d.y;
    double rotated_y = Rotation_matrix[1][0] * base_link_point2d.x + Rotation_matrix[1][1] * base_link_point2d.y;

    // Apply translation
    base_link_map_point2d->x = rotated_x + base_link_origin.x;
    base_link_map_point2d->y = rotated_y + base_link_origin.y;
}

int main()
{
    base_link_origin.x = 1.0;
    base_link_origin.y = 2.0;
    base_link_origin.theta = 90;

    base_link_Point2D.x = 1;
    base_link_Point2D.y = 1;

    set_rotation_matrix(base_link_origin.theta);

    printf("Rotation Matrix:\n");
    printf("%6.3lf  %6.3lf\n", Rotation_matrix[0][0], Rotation_matrix[0][1]);
    printf("%6.3lf  %6.3lf\n", Rotation_matrix[1][0], Rotation_matrix[1][1]);

    printf("Inverse Rotation Matrix (Transpose):\n");
    printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[0][0], Rotation_matrix_inverse[0][1]);
    printf("%6.3lf  %6.3lf\n", Rotation_matrix_inverse[1][0], Rotation_matrix_inverse[1][1]);

    // Calculate base_link_map_Point2D
    Point2D base_link_map_Point2D;
    TF_base_link_base_link_map(base_link_Point2D, &base_link_map_Point2D, base_link_origin);

    printf("Base_link_origin: (%.3lf, %.3lf, %.3lf degrees)\n", base_link_origin.x, base_link_origin.y, base_link_origin.theta);
    printf("Base_link: (%.3lf, %.3lf)\n", base_link_Point2D.x, base_link_Point2D.y);
    printf("Base_link_map: (%.3lf, %.3lf)\n", base_link_map_Point2D.x, base_link_map_Point2D.y);

    return 0;
}