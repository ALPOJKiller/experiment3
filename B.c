#include <stdio.h>
void draw(unsigned height,unsigned length,char ch,int solid) {
        for(unsigned h=0;h<height;++h) {
            if(h==0 || h==height-1 || solid == 1) {
                for(unsigned w=0;w<length;++w) {
                    printf("%c",ch);
                }   
            } else {
                printf("%c",ch);
                for(unsigned w=1;w<length-1;++w) {
                    printf(" ");
                }   
                printf("%c",ch);
            }   
            printf("\n");
        }   
}
int main(void){
    unsigned h,l;
    char c;
    int s;
    scanf("%u %u %c %d",&h,&l,&c,&s);
    draw(h,l,c,s);
    return 0;
}

