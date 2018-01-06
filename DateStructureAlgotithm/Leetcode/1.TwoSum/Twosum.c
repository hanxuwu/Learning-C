/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

# include <stdio.h>
# include <malloc.h>

int* twoSum(int* nums, int numsSize, int target);

int main(void){
    int nums[] = {3,2,4};
    int target = 6;
    int *result;
    result = twoSum(nums, 3, target);
    for (int k=0; k < 2;k++){
        printf("%d ", result[k]);
    }
    getchar();
    return 0;
}
//wrong
/*
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int * array;
    //array = (int *)malloc(sizeof(array[2]));//wrong!
    
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if ((nums[i]+nums[j])==target){
                array[0]=i;
                array[1]=j;
                return array;
            }
                
        }
    }
    
}
*/


int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int * array;
    array = (int *)malloc(2*sizeof(int));
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if ((nums[i]+nums[j])==target){
                array[0]=i;
                array[1]=j;
                return array;
            }
                
        }
    }
    return 0;
}