#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{FALSE, TRUE}BOOL;
int bit = 0;//全局小数点哨兵
char buffer_num[18];
unsigned char zero[] = "０", one[] = "１", nine[] = "９", two[] = "２", three[] = "３", four[] = "４", five[] = "５", six[] = "６", seven[] = "７", eight[] = "８", ch_dot[] = "．";
void addnum(char c)
{
    int len = strlen(buffer_num);
    buffer_num[len] = c;
}
/***********************************************************************/
unsigned char text[1024*1024];//全封\0
//重点：：：：必须用unsigned，否则比较的时候会解释成负数！！！！！
/***********************************************************************/

char B[] = "十百千万十百千亿十百千万十百千";
void printengnum(char);//将ASCII数字打出汉字
char vertch_eng(int);//将text第i~i+1位表示的中文数字变为ASCII数字
void printtotalnum();//分两种case，小数点前和后
BOOL ifprint(int len, int j)//确定该位是零用不用输出位名，用为true；
{
    BOOL result = FALSE;
    if(len >= 5 && len <= 8 && j == (len - 5)) result = TRUE;
    else if(len >= 9 && len <= 12 && (j == (len - 9) || j == (len - 5))) result = TRUE;
    else if(len >= 13 && len <= 17 && (j == (len - 13) || j == (len - 9) || j == (len - 5))) result = TRUE;
    else;
    return result;
}
BOOL is_special_zero(int len, int j)//确定该位是零是不是特殊位置的零（不能输出），是为true；
{
    BOOL result = FALSE;
    if(len >= 5 && len <= 8 && j == (len - 5)) result = TRUE;
    else if(len >= 9 && len <= 12 && (j == (len - 9) || j == (len - 5))) result = TRUE;
    else if(len >= 13 && len <= 17 && (j == (len - 13) || j == (len - 9) || j == (len - 5))) result = TRUE;
    else;
    return result;
}
BOOL if_compensate_zero(int len, int j)//确定用不用在位后补输出零，用为true；j为当前非零位；
{
    BOOL result = FALSE;
    if(is_special_zero(len, (j - 1)))
    {
        if(buffer_num[j] != '0' && buffer_num[j - 1] =='0')
        {
            result = TRUE;
        }
    }
    return result;
}
int main()
{
    
    char s[100];
    printf("请输入文件名：");
    scanf("%s", s);
    FILE * fp = fopen(s, "rb");//**重点：fread必须用二进制打开，否则出bug！！！！！！
    if(!fp)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    int len = fread(text, 1, 1024*1024, fp);
    if(text[1024*1023] != '\0')
    {
        printf("文件太大,要求小于1MB!");
        exit(0);
    }
    fclose(fp);
    char * seek = text;//读写头
    for(int i = 0; i < len; i++)
    {
        if(text[i] >= '0' && text[i] <= '9')
        {
            addnum(text[i]);
            text[i] = '\0';
            printf("%s", seek);
            seek = &text[i + 1];
        }
        else if(text[i] >= zero[0] && text[i + 1] >= zero[1] && text[i] <= nine[0] && text[i + 1] <= nine[1])
        {
            addnum(vertch_eng(i));
            text[i] = '\0', text[i + 1] = '\0';
            printf("%s", seek);
            seek = &text[i + 2];
            i++;//虽然没有用，但是会触发循环条件！
        }
        else
        {
            if(buffer_num[0] != '\0')
            {
                printtotalnum(); //printf("%d", bit);
                memset(buffer_num, 0, 16);
            }
            if(text[i] == '.')
            {
                bit = 1;
                text[i] = '\0';
                printf("%s", seek);
                seek = &text[i + 1]; 
                printf("点");
            }
            else if(text[i] == ch_dot[0] && text[i + 1] == ch_dot[1])
            {
                bit = 1;
                text[i] = '\0', text[i + 1] = '\0';
                printf("%s", seek);
                seek = &text[i + 2];
                i++;//必须把低八位中国点跳过去，不然小数点记忆哨兵重置了 
                printf("点");
            }
            else
            {
                bit = 0;
            }
        }
    }
    printf("%s", seek);
    if(buffer_num[0] != '\0') printtotalnum();
    return 0;
}
void printengnum(const char num)//将ASCII数字打出汉字
{
    switch(num){
        case '0': printf("零"); break;
        case '1': printf("一"); break;
        case '2': printf("二"); break;
        case '3': printf("三"); break;
        case '4': printf("四"); break;
        case '5': printf("五"); break;
        case '6': printf("六"); break;
        case '7': printf("七"); break;
        case '8': printf("八"); break;
        case '9': printf("九"); break;
    }
}
char vertch_eng(int i)//将text第i~i+1位表示的中文数字变为ASCII数字
{
    char eng;
    if(text[i+1] == zero[1]) eng = '0';
    else if(text[i+1] == one[1]) eng = '1';
    else if(text[i+1] == two[1]) eng = '2';
    else if(text[i+1] == three[1]) eng = '3';
    else if(text[i+1] == four[1]) eng = '4';
    else if(text[i+1] == five[1]) eng = '5';
    else if(text[i+1] == six[1]) eng = '6';
    else if(text[i+1] == seven[1]) eng = '7';
    else if(text[i+1] == eight[1]) eng = '8';
    else if(text[i+1] == nine[1]) eng = '9';
    return eng;
}
void printtotalnum()//分两种case，小数点前和后
{
    int len = strlen(buffer_num);
    switch(bit)
    {
        case 0:
        {
            int t = 2 * len - 4, m;
            for(int j = 0; j < len; j++)
            {
                if(if_compensate_zero(len, j) || (len == 1 && buffer_num[0] == '0')) printf("零");
                if(buffer_num[j] == '0' && ((buffer_num[j + 1] == '0'  || buffer_num[j + 1] == '\0') || is_special_zero(len, j)));//有预留封\0，不用检查越界；这里是连零只读一个
                else
                {
                    printengnum(buffer_num[j]);
                }
                
                if(((m = t - (2 * j)) >= 0) && (buffer_num[j] != '0' || ifprint(len, j)))  printf("%.2s", (B + m));//一般情况读位：有零不读位;特殊情况：万、亿、万亿读位；
            }
            break;
        }
        case 1:
        {
            for(int j = 0; j < len; j++)
            {
                printengnum(buffer_num[j]);
            }
            break;
        }
    }
}