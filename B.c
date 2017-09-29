#include <stdio.h>

/**
 * 绘制长方形函数
 * @param height 长方形高度
 * @param length 长方形宽度
 * @param ch 绘制用字符
 * @param solid 是否要用字符填充内部
 */
void draw(unsigned height, unsigned length, char ch, int solid) {
    for (unsigned h = 0; h < height; ++h) {
        //如果是首行或者是要用字符填充内部，绘制整行
        if (h == 0 || h == height - 1 || solid == 1) {
            for (unsigned w = 0; w < length; ++w) {
                printf("%c", ch);
            }
        } else {
            //否则绘制两边的字符
            printf("%c", ch);
            //内部用空格填充
            for (unsigned w = 1; w < length - 1; ++w) {
                printf(" ");
            }
            printf("%c", ch);
        }
        printf("\n");
    }
}

int main() {
    unsigned h, l;
    char c;
    int s;
    scanf("%u %u %c %d", &h, &l, &c, &s);
    draw(h, l, c, s);
    return 0;
}

