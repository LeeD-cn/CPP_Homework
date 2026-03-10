#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
typedef struct NodeWord{
    char * word;
    int word_frequency;
    struct NodeWord * next;
}NodeWord;
void addword(char * word);//创建新单词结点同时初始化词频为1,为了省事头插入
NodeWord * findword(char * word);//在已有结点中查单词，返回目标单词结点，没有返回NULL
int nodecmp(const void * a, const void * b);
void printAndfreenode(NodeWord * arr[]);
int nodecount;//一共有几个单词
NodeWord * head = NULL;//为了让函数用
int main()
{
    printf("请输入文件名或路径，不带引号\n");
    FILE * fp;
    char article[256];
    scanf("%s", article);
    if((fp = fopen(article, "r")) == NULL)
    {
        printf("无法打开文件！\n");
        exit(0);
    }
    else
    {
        printf("读取中。。。\n");
    }
    int ch;
    char word[50];
    int i = 0;
    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch) || (ch == '-' && i > 0 && isalpha(word[i-1])))
        {
            word[i++] = tolower(ch);
        }
        else
        {
            if(i > 0)
            {
                word[i] = '\0';
                //开始处理得到的单词
                NodeWord * np;
                if((np = findword(word)) == NULL)
                {
                    addword(word);
                    nodecount++;
                }
                else
                {
                    np->word_frequency++;
                }
                i = 0;
            }
        }
    }
    if(i > 0)//处理最后一个单词（如果最后没有标点）
    {
        word[i] = '\0';
        NodeWord * np;
        if((np = findword(word)) == NULL)
        {
            addword(word);
            nodecount++;
        }
        else 
        {
            np->word_frequency++;
        }
    }
    if(head == NULL) //空文件处理
    {
        printf("文件不含单词或字母！\n");
        exit(0);
    }
    //开始对结点排序，利用指针数组，要不太麻烦了
    NodeWord ** arr = (NodeWord **)malloc(sizeof(NodeWord *) * nodecount);
    if(arr == NULL)
    {
        printf("内存分配失败！\n");
        exit(0);
    }
    NodeWord * np = head;
    np = head;
    for(int i = 0; i < nodecount; i++)//结点的指针组成的数组arr[]写好啦！
    {
        arr[i] = np;
        np = np->next;
    }
    qsort(arr, nodecount, sizeof(NodeWord *), nodecmp);//排序
    printAndfreenode(arr);
    head = NULL;
    nodecount = 0;
    fclose(fp);
    return 0;
}
void addword(char * word)//创建同时初始化词频为1
{
    NodeWord * np = (NodeWord *)malloc(sizeof(NodeWord));
    if(np == NULL)
    {
        printf("内存分配失败！\n");
        exit(0);
    }
    np->word = (char *)malloc(sizeof(char) * (strlen(word) + 1));
    if(np->word == NULL)
    {
        printf("内存分配失败！\n");
        free(np);
        exit(0);
    }
    np->word_frequency = 1;
    strcpy(np->word, word);
    np->next = head;
    head = np;//头插入
}
NodeWord * findword(char * word)
{
    NodeWord * np = head;
    while(np != NULL && strcmp(np->word, word))
    {
        np = np->next;
    }
    return np;
}
int nodecmp(const void * a, const void * b)
{
    NodeWord * ia = *(NodeWord **)a;
    NodeWord * ib = *(NodeWord **)b;
    int result;
    if((result = (ib->word_frequency - ia->word_frequency)) == 0) result = strcmp(ia->word, ib->word);
    return result;
}
void printAndfreenode(NodeWord * arr[])
{
    printf("****************************\n");
    printf("%-20s |%8s", "单词", "词频/个\n");
    for(int i = 0; i < nodecount; i++)//打印
    {
        printf("%-3d. %-15s|%5d\n", (i + 1), arr[i]->word, arr[i]->word_frequency);
        free(arr[i]->word);
        free(arr[i]);
    }
    printf("****************************\n");
    free(arr);
}
