#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

#define x_max 3
#define y_max 3
#define dead 0
#define alive 1
#define check_range_around_all_num 9 //检查该格子周围check_range*check_range的数目格子（含该检查的格子）。

const int  check_range=((unsigned int)sqrt(check_range_around_all_num)) /2;

unsigned char world[x_max][y_max];  //设置世界以及打印大小范围
unsigned char delay_time=500;   //全局通用延时
unsigned long unit_interval=0;

void printf_introduce(void);    //界面上方时刻介绍信息部分

int main(void){

    if(number % 2 == 0)(printf(){}//检查设置的检查格子周围个数的数目是否正确（为偶数）
    else{printf("the check range number is wrong");return 0;}//错误则提示并结束程序



    printf_introduce();

    for(int i=0;i<x_max;i++){
        for(int j=0;j<y_max;j++){
            world[x_max][y_max]=(unsigned char)rand()%2;
            printf(" %d ",world[x_max][y_max]);

            Sleep(delay_time);   //延时1000毫秒
        }
        printf("\n");
    }
    Sleep(delay_time);   //延时1000毫秒
    system("CLS");



    while(1){
         printf_introduce();



        for(int i=0;i<x_max;i++){
            for(int j=0;j<y_max;j++){
                if()
                printf(" %d ",world[x_max][y_max]);

                Sleep(delay_time);   //延时1000毫秒
            }
            printf("\n");
        }
        Sleep(delay_time);   //延时1000毫秒
        system("CLS");

       /*
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

            }
        }*/
    }
    return 0;
}

void printf_introduce(void){
    printf("It's  %d moment world:",unit_interval);
    unit_interval++;
    printf("\n");
    printf("\n");
}
unsigned char check_the_one_condition(unsigned int x_coordinates,unsigned int y_coordinates){ //第一个参数传入x坐标，第二个参数传入y坐标吗，函数返回值为该各自的生死状态
    unsigned int i,j;
    unsigned int around_alive_num;  //
    unsigned int around_dead_num;  //

    if(x_coordinates==0 || y_coordinates==0 || x_coordinates==x_max || y_coordinates==y_max){   //四个方向，四种情况。用或关系原因：有一种满足则可判断待判点处在边缘四个角所在的行或列上。
        //由于待判点处于边缘的四个角所在的行或列上，所以啥都不做
    }
    else {  //只有当不处于边缘四个角所在的行或列上才判断
        for(i=0;i<check_range;i++){
            for(j=0;j<check_range;j++){
                if(world[(0-)x_coordinates-i][y_coordinates-j])
            }
        }





    }

}


