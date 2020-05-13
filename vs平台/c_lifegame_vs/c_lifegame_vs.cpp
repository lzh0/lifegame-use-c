#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>


#define x_max 64
#define y_max 64
#define dead 0
#define alive 1
#define check_range_around_all_num 9 //检查该格子周围check_range*check_range的数目格子（含该检查的格子）。
#define rule_alive_max 8    //被检测格子周围最多可存活单位数量，不含被检测格子，含等于该数目情况，为活。
#define rule_dead_max 3     //被检测格子周围最少不存在单位数量，不含被检测格子，含等于该数目情况，为死。

const int check_range = ((unsigned int)sqrt(check_range_around_all_num) - 1) / 2;

unsigned char world[x_max][y_max];  //设置世界以及打印大小范围
unsigned int delay_time = 5000;   //全局通用延时
unsigned long unit_interval = 0;

void printf_introduce(void);    //界面上方时刻介绍信息部分
unsigned char check_the_one_condition(unsigned int x_coordinates, unsigned int y_coordinates);   //判断执行死活或生的行为 //第一个参数传入x坐标，第二个参数传入y坐标吗，函数返回值为该各自的生死状态

int main(void) {

    if ((check_range_around_all_num % 2) != 0) {  //检查设置的检查格子周围个数的数目是否正确（为奇数）
        printf("check_range_around_all_num is right.");
        printf("\n");
    }
    else { printf("the check range number is wrong"); return 0; }//若check_range_around_all_num为偶数，则错误则提示并结束程序
    printf("check_range : %d ", check_range);
    printf("\n");



    printf_introduce();

    for (int i = 0; i < x_max; i++) {
        for (int j = 0; j < y_max; j++) {
            world[i][j]=(unsigned char)rand()%2;
            //world[i][j] = 1;
            printf(" %d ", world[i][j]);
        }
        printf("\n");
    }

    //sleep(delay_time);   //延时1000毫秒
    getchar();
    system("CLS");






    while (1) {
        printf_introduce();



        for (int i = 0 ; i < x_max ; i++) {
            for (int j = 0 ; j < y_max ; j++) {
                world[i][j] = check_the_one_condition(i, j);

                /*
                if(check_the_one_condition(i,j)!=3){
                    if(check_the_one_condition(i,j)==dead){world[i][j]=dead;}//如果检测结果为死，则执行该检测单元状态更新为死
                    else{
                        //world[i][j]=alive;//如果该格子活下来了，则随机向周围判定范围内传播一格生
                    }
                }*/

                //test
                /*
                if(check_the_one_condition(i,j)==3){
                    world[i][j]=3;
                }
                if(check_the_one_condition(i,j)==dead){world[i][j]=dead;}//如果检测结果为死，则执行该检测单元状态更新为死
                else{
                        //world[i][j]=alive;//如果该格子活下来了，则随机向周围判定范围内传播一格生
                }
                */



                printf(" %d ", world[i][j]);
            }
            printf("\n");
        }
        //sleep(delay_time);   //延时1000毫秒
        getchar();
        system("CLS");

    }






    return 0;
}

void printf_introduce(void) {
    printf("It's  %ld moment world:", unit_interval);
    unit_interval++;
    printf("\n");
    printf("\n");
}
unsigned char check_the_one_condition(unsigned int x_coordinates, unsigned int y_coordinates) { //第一个参数传入x坐标，第二个参数传入y坐标吗，函数返回值为该各自的生死状态
    int i, j;
    unsigned int around_alive_num=0;  //
    unsigned int around_dead_num=0;  //

    if (x_coordinates == 0 || y_coordinates == 0 || x_coordinates == x_max - 1 || y_coordinates == y_max - 1) {   //四个方向，四种情况。用或关系原因：有一种满足则可判断待判点处在边缘四个角所在的行或列上。x_max和y_max是不包含的....
        return 3;//由于待判点处于边缘的四个角所在的行或列上，所以啥都不做
    }
    else {  //只有当不处于边缘四个角所在的行或列上才判断
        for (i = (x_coordinates - check_range); i < (x_coordinates + check_range); i++) {
            for (j = (x_coordinates - check_range); j < (x_coordinates + check_range); j++) {
                if ((world[i][j]) == alive) { around_alive_num++; }
                else { around_dead_num++; }
            }
        }
    }

    if (world[x_coordinates][y_coordinates] == alive) { around_alive_num--; }
    else { around_dead_num--; }


    //检测数值返回部分
    if (around_alive_num >= rule_alive_max || around_dead_num <= rule_dead_max) { return dead; }    //若生的格子数大于等于规定数量，则返回状态死。且若死的格子小于等于规定数量，则返回状态死。
    else { return alive; } //否则返回状态生

}


