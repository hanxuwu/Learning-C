int removeDuplicates(int* nums, int numsSize) {
    int current;
    int i;
    int j;
    int k;
    int length=numsSize;
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    for(i=0;i<length;i++){  //traverse all the number 
        current = nums[i]; // check the numner from the first to last
        for(j=i+1;j<length;j++){ //compare to the next to the end
            if(nums[j]==current){ // find the same one
                for(k=j+1;k<numsSize;k++){ // the move the next to prev ,from  found to end
                    nums[k-1]=nums[k]; 
                    
                }
                length--;  // change the length
                j--; //check the value again
                
            }
        }
        
    }
    //return nums[length];
    return length;
    
}

int main(void){
    int nums[9]={1,1,2,3,4,5,6,7,7};
    int length = removeDuplicates(nums,9);
    printf("length %d\n",length);
    for(int i=0;i<length;i++){
        printf("%d\n",nums[i]);
    }
    return 0;
}