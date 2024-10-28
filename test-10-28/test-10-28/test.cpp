#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

#define MAX_SIZE 5 //Ⱦɫ������Ʊ���λ��
#define MAX_PAIR 4 //Ⱦɫ������

typedef struct Chrom        //�ṹ�����ͣ�Ϊ����Ⱦɫ��ṹ
{
    short int bit[MAX_SIZE];//һ��5bit����Ⱦɫ����б��룬����1λΪ����λ��ȡֵ��Χ0~31
    int fit;//��Ӧ��
    double rfit;//ѡ����ʣ�����ռ�İٷֱ�
    double cfit;//�ۼƸ���
}chrom;

//���彫���õ��ĺ���
void evpop(chrom popcurrent[MAX_PAIR]);//������Ⱥ�ĳ�ʼ��
int btod(chrom popcurrent);//������->ʮ����
int fitness(int x);//������Ӧ��
void pickchroms_Roulette(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR]);//���̶ķ�����ѡ��
void pickchroms_Ranking(chrom popcurrent[MAX_PAIR]);//ð����������ѡ��
void pickchroms_Tournament(chrom popcurrent[MAX_PAIR]);//������������ѡ��
void crossover(chrom popnext[MAX_PAIR]);//�������
void mutation(chrom popnext[MAX_PAIR]);//ͻ��
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR], int loop);//ѭ������ѡ�񽻲����
double uniform(double a, double b, long int* seed);//����a~b���ȷֲ��������

int main()//������
{
    chrom popcurrent[MAX_PAIR];//��ʼ��Ⱥ��ģ
    chrom popnext[MAX_PAIR];//���º���Ⱥ��ģ
    int loop, Max;

    printf("�������������");
    scanf("%d", &loop);
    srand(time(0));
    printf("\n��ʼ����ȺΪ��\n");
    evpop(popcurrent);//��ʼ����Ⱥ
    mian_loop(popcurrent, popnext, loop);//����ѭ��
    Max = btod(popcurrent[0]);//�������������
    printf("\n���ս��Ϊ��%d\n", Max);

    system("pause");
    return 0;
}

void evpop(chrom popcurrent[MAX_PAIR]) //������������ɳ�ʼ��Ⱥ��
{
    int i, j, value;
    int random;
    double sum = 0;

    for (j = 0; j < MAX_PAIR; j++) //��Ⱦɫ��ĵ�1�����򵽵�6��
    {
        for (i = 0; i < MAX_SIZE; i++)
        {
            random = rand(); //����һ�����ֵ
            random = random % 2; //�������0��1
            popcurrent[j].bit[i] = random; //�������Ⱦɫ����ÿһ��ֵ
        }

        value = btod(popcurrent[j]); //������->ʮ����
        popcurrent[j].fit = fitness(btod(popcurrent[j])); //����Ⱦɫ����Ӧ��ֵ
        sum = sum + popcurrent[j].fit;
        printf("popcurrent[%d]=%d%d%d%d%d   value=%d    fitness = %d\n", j, popcurrent[j].bit[0], popcurrent[j].bit[1], popcurrent[j].bit[2], popcurrent[j].bit[3], popcurrent[j].bit[4], value, popcurrent[j].fit);
        //�������Ⱦɫ��ı������
    }
    //������Ӧֵ�İٷֱȣ��Ĳ������������̶�ѡ��ʱ��Ҫ�õ���
    for (j = 0; j < MAX_PAIR; j++)
    {
        popcurrent[j].rfit = popcurrent[j].fit / sum;
        popcurrent[j].cfit = 0;//��ʼ��
    }
    printf("\n");
}

int btod(chrom popcurrent) //������->ʮ����
{
    int d = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        d = d + popcurrent.bit[i] * pow(2, MAX_SIZE - 1 - i);
    }
    return d;
}

int fitness(int x)//��������Ӧ��
{
    int fit = x * x + 5;
    return fit;
}
//�������̶ķ�����Ⱦɫ��ѡ������ѡ��
void pickchroms_Roulette(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR])//�������
{
    int men;
    int i, j;
    double p; //����4��0~1�����ֵ
    double sum = 0.0; //find the total fitness of the population
    long int seed = 13579;

    for (men = 0; men < MAX_PAIR; men++)//��������Ӧ��
    {
        sum = sum + popcurrent[men].fit;
    }

    for (men = 0; men < MAX_PAIR; men++)//����ѡ�����
    {
        popcurrent[men].rfit = popcurrent[men].fit / sum;
    }
    //�����ۼƸ���
    popcurrent[0].cfit = popcurrent[0].rfit;
    for (men = 1; men < MAX_PAIR; men++)
    {
        popcurrent[men].cfit = popcurrent[men - 1].cfit + popcurrent[men].rfit;
    }

    for (i = 0; i < MAX_PAIR; i++)//����ۼƸ��ʣ������ã�
    {
        printf("popcurrent[%d].cfit=%f\n", i, popcurrent[i].cfit);
    }

    for (i = 0; i < MAX_PAIR; i++)//�������ɸ�0~1������������ۼƸ��ʽ���ѡ�����̶ķ����ģ�
    {//����0~1֮��������
        p = uniform(0, 1, &seed);//ͨ����������0~1֮����ȷֲ�������
        //p = rand() * 1.0 / (RAND_MAX + 1.0);
        printf("random is %f\n", p);//���������������ã�
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
        popnext[i].fit = fitness(btod(popnext[i]));//������һ��Ⱦɫ�����Ӧ��
    }


    for (i = 0; i < MAX_PAIR; i++)//��ӡ���̶ķ�ѡ�������һ��Ⱦɫ��
    {
        printf("popnext[%d]=%d%d%d%d%d fitness=%d\n", i, popnext[i].bit[0], popnext[i].bit[1], popnext[i].bit[2], popnext[i].bit[3], popnext[i].bit[4], popnext[i].fit);
    }
}
//����ð�����򷨽���Ⱦɫ��ѡ������ѡ��
void pickchroms_Ranking(chrom popcurrent[MAX_PAIR])
{
    //
}
//���ڽ�����������Ⱦɫ��ѡ������ѡ��
void pickchroms_Tournament(chrom popcurrent[MAX_PAIR])
{
    //
}
//�������
void crossover(chrom popnext[MAX_PAIR])
{
    double pc = 0.95;//���н���ĸ���
    double rpc = 0.0;//�������
    int random;//�����
    int i;
    short int temp;
    //rpc = rand()%100*0.01;//����0~1����λС��
    //if (rpc <= 0.95)//��0.95�ĸ��ʽ��н������
    //{��ʱ100%����
    random = rand() % 5 + 1;//����1~5����������������λ��
    //random = 2;
    //printf("\nCross point is %d\n",random);//�������㣬������
    for (i = MAX_SIZE - random; i < MAX_SIZE; i++)
    {
        //��Ⱦɫ��0��3�Ž���
        temp = popnext[0].bit[i];
        popnext[0].bit[i] = popnext[3].bit[i];
        popnext[3].bit[i] = temp;
        temp = 0;//����
        //��Ⱦɫ��1��2�Ž���
        temp = popnext[1].bit[i];
        popnext[1].bit[i] = popnext[2].bit[i];
        popnext[2].bit[i] = temp;
        temp = 0;
    }
    //}
    for (i = 0; i < MAX_PAIR; i++)
    {
        popnext[i].fit = fitness(btod(popnext[i]));//������Ӧ��
    }

    for (i = 0; i < MAX_PAIR; i++)//���������Ⱦɫ��
    {
        printf("CrossOver popnext[%d]=%d%d%d%d%d\n", i, popnext[i].bit[0], popnext[i].bit[1], popnext[i].bit[2], popnext[i].bit[3], popnext[i].bit[4]);
    }
}
//�������
void mutation(chrom popnext[MAX_PAIR])
{
    int random;
    int i, j, num;//��i��Ⱦɫ��ĵ�j������
    random = rand() % 50;//����0~49�������
    if (random == 25)//��2%�ļ��ʲ�������
    {
        i = rand() % 4;//��Ӧĳһ��Ⱦɫ��
        j = rand() % 6;//��ӦȾɫ���ϵĻ���
        if (popnext[i].bit[j] == 0)
            popnext[i].bit[j] = 1;
        else
            popnext[i].bit[j] = 0;
        popnext[i].fit = fitness(btod(popnext[i]));//������Ӧ��
    }

    for (num = 0; num < 4; num++)//���������Ⱦɫ��
    {
        printf("chrom[%d]=%d%d%d%d%d  value = %d    fitness = %d\n", num, popnext[num].bit[0], popnext[num].bit[1], popnext[num].bit[2], popnext[num].bit[3], popnext[num].bit[4], btod(popnext[num]), popnext[num].fit);
    }
}
//ѭ������
void mian_loop(chrom popcurrent[MAX_PAIR], chrom popnext[MAX_PAIR], int loop)
{
    int i, j;
    for (i = 0; i < loop; i++)
    {
        printf("��%d�ε�����\n", i);
        pickchroms_Roulette(popcurrent, popnext);//ѡ��for(i = 0; i < MAX_PAIR ; i++)//��ӡ���̶ķ�ѡ�������һ��Ⱦɫ��
        crossover(popnext);//����
        mutation(popnext);//����

        for (j = 0; j < MAX_PAIR; j++)//������һ��
        {
            popcurrent[j] = popnext[j];
        }
    }
}
//����a~b���ȷֲ��������
double uniform(double a, double b, long int* seed)
{
    double result;
    *seed = 2045 * (*seed) + 1;
    *seed = (*seed) % 1048576;
    result = (*seed) / 1048576.0;
    result = a + (b - a) * result;
    return result;
}