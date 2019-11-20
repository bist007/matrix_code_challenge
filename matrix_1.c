/*

2D matrix of numbers from 0 to 9 with variable width and height. 
This code can find the square submatrix with the highest sum of boundary elements.

Author: BIST

*/

#include <stdio.h>

int main () {
    int r, c, m, n, sub_m, sub_n, k, l;
    
    int sum=0, sum_temp=0, r1, c1;
    
    printf ("Enter the matrix dimensions in R C format :\n");

    scanf ("%d %d",&m,&n);                                                                   //  Matrix dimension 
    
    int mat_col[m][n], mat_1[m][n], mat_2[m][n];
    
    if (m==0 || n==0){
        printf ("error : enter value greater the zero value\n");
        return 0;
    }
    printf ("Enter matrix with %dx%d dimensions :\n",m,n);                                  //  Matrix input
    for (r=0;r<m;r++) {
        for (c=0;c<n;c++) {
            scanf ("%d",&mat_1[r][c]);
        }
    }

//  print user given matrix
    
    printf ("user entered matrix :\n");
    for (r=0;r<m;r++) {
        for (c=0;c<n;c++){
            printf ("%d\t",mat_1[r][c]);
        }
        printf ("\n");
    }

    printf ("Enter the sub-matrix dimensions in R C format :\n");           //  user defined sub matrix dimension
    scanf ("%d %d",&sub_m,&sub_n);                                          //  Matrix dimension
    printf ("\n");
    if (sub_m==0 || sub_n==0){
        printf ("error : enter value greater the zero value\n");
        return 0;                                                           //printf ("error"); and exit
    }

    
//    u, v for controlling new line print statement
    int u=0, v=0;


        for (int i=0; i<=m; i++) {                                              //  loop for sub-matrix selectionn
        
            for (int j=0; j<=n; j++) {
            
                for (r=i, r1=0, k=sub_m; ((i<=(m-sub_m)) && (k-->0) && (r<m)); r++, r1++) {
                
                    for (c=j, c1=0, l=sub_n; ((j<=(n-sub_n)) && (l-->0) && (c<n)); c++, c1++){        //loop ends when j reaches (n-sub_n)
                        
                        mat_col[r1][c1]=mat_1[r][c];
                        u=printf ("%d\t",mat_col[r1][c1]);
                        
                    } if (u!=0){v=printf ("\n"); /*u=0;*/}
                    
                } if (v!=0){printf ("\n"); u=0; v=0;}
            
        /*############################# code to calculate sum of boundary element for the sub-matrix  ################################## */        
                
                if (sub_m==1 && sub_n==1){
                    sum_temp=mat_col[sub_m-1][sub_n-1];
                }
                
                else {
                    for(c=0,sum_temp=0; c<sub_n; c++){
                        sum_temp = sum_temp + mat_col[0][c] + mat_col[sub_m-1][c];                     
                    }
                    for (r=0; r<sub_m; r++){                      
                        sum_temp = sum_temp + mat_col[r][sub_n-1] + mat_col[r][0];                        
                    }  
                    sum_temp = sum_temp - (mat_col[0][0]+mat_col[0][sub_n-1]+mat_col[sub_m-1][0]+mat_col[sub_m-1][sub_n-1]);
                }
                
        /*############################# sub-matrix selection w.r.to max summation ################################## */                
                if (sum_temp>sum) {
                    sum=sum_temp;
                    
                    for (r=0;r<sub_m;r++) {
                        for (c=0;c<sub_n;c++) {
                            mat_2[r][c] = mat_col[r][c];
                        }
                    }
                }
                
            }//printf ("\n\t\tloop 4\n"); 
        } 
    
        
    //  max sum Sub-Matrix output
    printf ("the sub matrix is :\n");
    for (r=0;r<sub_m;r++) {
        for (c=0;c<sub_n;c++) {
            printf("%d\t",mat_2[r][c]);
        }
        printf ("\n");
    }

  
    return 0;
} 

/* ----------------------------------- X --- X --- X ---------------------------------------------- */
