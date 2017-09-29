#include <stdio.h>
double f(double x) {
    if(0 <= x&&x < 5) {
        return -x+2.5;
    } else if(5 <= x&& x < 10) {
        return 2-1.5*(x-3)*(x-3);
    } else if(10 <= x && x < 20) {
        return x/2-1.5;
    }   
}
int main(void){
    double d;
    scanf("%lf",&d);
    printf("%.3f",f(d));
    return 0;
}
