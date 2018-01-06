/*
(Arrays) 
Write a C-function that returns the inner product of two n-dimensional vectors a and b, 
encoded as 1-dimensional arrays of n floating point numbers. 
Use the function prototype float innerProduct(float a[], float b[], int n). 
Hint: The inner product of two vectors is calculated as `sum_(i=1..n)bb"a"_(i)*bb"b"_(i)` 

*/

# include <stdio.h>

float innerProduct(float a[], float b[], int n);
int main(void){
    int n=5;
    float product=0;
    float a[5] = {1,1,1,1,1};
    float b[5] = {2,2,2,2,2};

    product = innerProduct(a, b, n);
    printf("%f", product);

    return 0;
}

float innerProduct(float a[],float b[],int n){
    int product = 0;
    for (int i = 0; i < n;i++)
    {
        product += a[i] * b[i];
    }
    return product;
}