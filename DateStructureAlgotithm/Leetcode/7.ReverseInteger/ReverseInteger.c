# include <stdio.h>
# include <math.h>

int reverse(int x) {
    int signed_number = pow(2, 31)-1;
    printf("%d\n", x);
    int res[10000];
    int count=0;
    int remain = x;
    long long final=0;
    if (-signed_number<x<signed_number)
        {
            while (remain!=0){
                    res[count] = remain % 10;
                    remain /= 10;
                    count++;
                    //printf("%d ", remain);
            }
            //printf("%d", count);
            //printf("\n");
            for (int n = 0; n < count;n++){
                //printf("%d ", res[n]);
                }
                //printf("\n");
                
            for (int n = 0; n < count;n++){
                //printf("%d %d %d\n", count, n, res[n]);
                final += pow(10,count-1-n) * res[n];
            }
            printf("%lld\n", final);
            printf("%d %d\n", -signed_number, signed_number);

            long long b = 9646324351;
            if(2646324350<b<2646324353){
                printf("123");
            }

            if (-signed_number<final<signed_number){
                printf("@");
                return (int)final;
        }
            else {
                final = 0;
                return (int)final;}
    }else return final;

    }

int main(void){
    int x = 1534236469;
    int result =reverse(x);
    printf("%d", result);
    return 0;
}