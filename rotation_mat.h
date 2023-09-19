#include <math.h>
/**
 * @brief matrix multiplication 
 * @param mat_1 double array 
 * @param mat_2 double array 
 * @param rows_1 rows of matrix 1
 * @param cols_2 columns of matrix 2
 * @param common columns or matrix 1 or rows of matrix 2
 * @return double array => a the result of matrix multiplication 
 */
double **mat_mul(double** mat_1 ,double** mat_2 ,int rows_1 ,int cols_2  ,int common){
    double result [rows_1]  [cols_2];

    for (int i=0; i<rows_1; i++){
        for (int j=0; j<cols_2; j++){
            double sum = 0;
            for (int k=0; k<common; k++){
                sum += mat_1[i] [k] * mat_2[k] [j];
            }
            result [i] [j] = sum;
        } 
    }

    return result;
}

double **get_global_2d_vector(double rotation_angle ,double  x ,double y){
    double rotation_matrix [2] [2]= {
                                {cos(rotation_angle) , -sin(rotation_angle)},
                                {sin(rotation_angle) , cos(rotation_angle)}
                                };

    double original_mat[2] ={
                            {x},
                            {y}
                            };
    
    return mat_mul(rotation_matrix  , original_mat , 2 , 2  , 2); 

}



