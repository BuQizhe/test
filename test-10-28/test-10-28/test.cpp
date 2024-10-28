#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

#define MAX_SIZE 5 //染色体二进制编码位数
#define MAX_PAIR 4 //染色体条数

typedef struct Chrom        //结构体类型，为单个染色体结构
{
    short int bit[MAX_SIZE];//一共5bit来对染色体进行编码，其中1位为符号位，取值范围0~31
    int fit;//适应度
    double rfit;//选择概率，即所占的百分比
    double cfit;//累计概率
}chrom;

//定义将会用到的函数
void evpop(chrom popcurrent[MAX_PAIR]);//进行种群的初始化
int btod(chrom popcurrent);//二进制->十进制
int fitness(int x);//计算适应度
void pickchroms_Roulette(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]);//轮盘赌法算子选择
void pickchroms_Ranking(chrom popcurrent[MAX_PAIR]);//冒泡排序算子选择
void pickchroms_Tournament(chrom popcurrent[MAX_PAIR]);//锦标赛法算子选择
void crossover(chrom popnext[MAX_PAIR]);//交叉操作
void mutation(chrom popnext[MAX_PAIR]);//突变
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR], int loop);//循环进行选择交叉变异
double uniform(double a, double b, long int* seed);//产生a~b均匀分布的随机数

int main()//主函数
{
    chrom popcurrent[MAX_PAIR];//初始种群规模
    chrom popnext[MAX_PAIR];//更新后种群规模
    int loop, Max;

    printf("请输入迭代数：");
    scanf("%d", &loop);
    srand(time(0));
    printf("\n初始化种群为：\n");
    evpop(popcurrent);//初始化种群
    mian_loop(popcurrent, popnext, loop);//进行循环
    Max = btod(popcurrent[0]);//期望已完成收敛
    printf("\n最终结果为：%d\n", Max);

    system("pause");
    return 0;
}

void evpop(chrom popcurrent[MAX_PAIR]) //函数：随机生成初始种群：
{
    int i, j, value;
    int random;
    double sum = 0;

    for (j = 0; j < MAX_PAIR; j++) //从染色体的第1个基因到第6个
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            random = rand(); //产生一个随机值
            random = random % 2; //随机产生0或1
            popcurrent[j].bit[i] = random; //随机产生染色体上每一个值
        }

        value = btod(popcurrent[j]); //二进制->十进制
        popcurrent[j].fit = fitness(btod(popcurrent[j])); //计算染色体适应度值
        sum = sum + popcurrent[j].fit;
        printf("popcurrent[%d]=%d%d%d%d%d   value=%d    fitness = %d\n", j, popcurrent[j].bit[0], popcurrent[j].bit[1], popcurrent[j].bit[2], popcurrent[j].bit[3], popcurrent[j].bit[4], value, popcurrent[j].fit);
        //输出整条染色体的编码情况
    }
    //计算适应值的百分比，改参数是在用轮盘赌选择法时需要用到的
    for (j = 0; j < MAX_PAIR; j++)
    {
        popcurrent[j].rfit = popcurrent[j].fit / sum;
        popcurrent[j].cfit = 0;//初始化
    }
    printf("\n");
}

int btod(chrom popcurrent) //二进制->十进制
{
    int d = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        d = d + popcurrent.bit[i] * pow(2, MAX_SIZE - 1 - i);
    }
    return d;
}

int fitness(int x)//求个体的适应度
{
    int fit = x * x + 5;
    return fit;
}
//基于轮盘赌法进行染色体选择（算子选择）
void pickchroms_Roulette(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR])//计算概率
{
    int men;
    int i, j;
    double p; //生成4个0~1的随机值
    double sum = 0.0; //find the total fitness of the population
    long int seed = 13579;

    for (men = 0; men < MAX_PAIR; men++)//计算总适应度
    {
        sum = sum + popcurrent[men].fit;
    }

    for (men = 0; men < MAX_PAIR; men++)//计算选择概率
    {
        popcurrent[men].rfit = popcurrent[men].fit / sum;
    }
    //计算累计概率
    popcurrent[0].cfit = popcurrent[0].rfit;
    for (men = 1; men < MAX_PAIR; men++)
    {
        popcurrent[men].cfit = popcurrent[men - 1].cfit + popcurrent[men].rfit;
    }

    for (i = 0; i < MAX_PAIR; i++)//输出累计概率（调试用）
    {
        printf("popcurrent[%d].cfit=%f\n", i, popcurrent[i].cfit);
    }

    for (i = 0; i < MAX_PAIR; i++)//生成若干个0~1随机数，根据累计概率进行选择（轮盘赌法核心）
    {//产生0~1之间的随机数
        p = uniform(0, 1, &seed);//通过函数生成0~1之间均匀分布的数字
        //p = rand() * 1.0 / (RAND_MAX + 1.0);
        printf("random is %f\n", p);//输出随机数（调试用）
        if (p < popcurrent[0].cfit)
        {
            popnext[i] = popcurrent[0];
        }
        else
        {
            for (j = 0; j < MAX_PAIR - 1; j++)
            {
                if (popcurrent[j].cfit <= p && p < popcurrent[j + 1].cfit)
                {
                    popnext[i] = popcurrent[j + 1];
                }
            }
        }
        popnext[i].fit = fitness(btod(popnext[i]));//计算下一代染色体的适应度
    }


    for (i = 0; i < MAX_PAIR; i++)//打印轮盘赌法选择出的下一代染色体
    {
        printf("popnext[%d]=%d%d%d%d%d fitness=%d\n", i, popnext[i].bit[0], popnext[i].bit[1], popnext[i].bit[2], popnext[i].bit[3], popnext[i].bit[4], popnext[i].fit);
    }
}
//基于冒泡排序法进行染色体选择（算子选择）
void pickchroms_Ranking(chrom popcurrent[MAX_PAIR])
{
    //
}
//基于锦标赛法进行染色体选择（算子选择）
void pickchroms_Tournament(chrom popcurrent[MAX_PAIR])
{
    //
}
//交叉操作
void crossover(chrom popnext[MAX_PAIR])
{
    double pc = 0.95;//进行交叉的概率
    double rpc = 0.0;//随机交叉
    int random;//交叉点
    int i;
    short int temp;
    //rpc = rand()%100*0.01;//产生0~1的两位小数
    //if (rpc <= 0.95)//以0.95的概率进行交叉操作
    //{暂时100%交叉
    random = rand() % 5 + 1;//产生1~5的随机数，即交叉点位置
    //random = 2;
    //printf("\nCross point is %d\n",random);//输出交叉点，调试用
    for (i = MAX_SIZE - random; i < MAX_SIZE; i++)
    {
        //将染色体0与3号交叉
        temp = popnext[0].bit[i];
        popnext[0].bit[i] = popnext[3].bit[i];
        popnext[3].bit[i] = temp;
        temp = 0;//清零
        //将染色体1与2号交叉
        temp = popnext[1].bit[i];
        popnext[1].bit[i] = popnext[2].bit[i];
        popnext[2].bit[i] = temp;
        temp = 0;
    }
    //}
    for (i = 0; i < MAX_PAIR; i++)
    {
        popnext[i].fit = fitness(btod(popnext[i]));//更新适应度
    }

    for (i = 0; i < MAX_PAIR; i++)//输出交叉后的染色体
    {
        printf("CrossOver popnext[%d]=%d%d%d%d%d\n", i, popnext[i].bit[0], popnext[i].bit[1], popnext[i].bit[2], popnext[i].bit[3], popnext[i].bit[4]);
    }
}
//变异操作
void mutation(chrom popnext[MAX_PAIR])
{
    int random;
    int i, j, num;//第i个染色体的第j个基因
    random = rand() % 50;//产生0~49个随机数
    if (random == 25)//即2%的几率产生变异
    {
        i = rand() % 4;//对应某一个染色体
        j = rand() % 6;//对应染色体上的基因
        if (popnext[i].bit[j] == 0)
            popnext[i].bit[j] = 1;
        else
            popnext[i].bit[j] = 0;
        popnext[i].fit = fitness(btod(popnext[i]));//更新适应度
    }

    for (num = 0; num < 4; num++)//输出变异后的染色体
    {
        printf("chrom[%d]=%d%d%d%d%d  value = %d    fitness = %d\n", num, popnext[num].bit[0], popnext[num].bit[1], popnext[num].bit[2], popnext[num].bit[3], popnext[num].bit[4], btod(popnext[num]), popnext[num].fit);
    }
}
//循环函数
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR], int loop)
{
    int i, j;
    for (i = 0; i < loop; i++)
    {
        printf("第%d次迭代：\n", i);
        pickchroms_Roulette(popcurrent, popnext);//选择for(i = 0; i < MAX_PAIR ; i++)//打印轮盘赌法选择出的下一代染色体
        crossover(popnext);//交叉
        mutation(popnext);//变异

        for (j = 0; j < MAX_PAIR; j++)//更新下一代
        {
            popcurrent[j] = popnext[j];
        }
    }
}
//产生a~b均匀分布的随机数
double uniform(double a, double b, long int* seed)
{
    double result;
    *seed = 2045 * (*seed) + 1;
    *seed = (*seed) % 1048576;
    result = (*seed) / 1048576.0;
    result = a + (b - a) * result;
    return result;
}