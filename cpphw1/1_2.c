#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024*1024
unsigned char image_table[256];
unsigned char buffer[BUFFER_SIZE];
void tranbyte(int);
int main()
{
    for(int i = 0; i < 256; i++)//建表
    {
        unsigned char t = 0, ib = i;
        for(int j = 0; j < 8; j++)
        {
            t |= (ib & 1);
            if(j < 7) t <<= 1;
            ib >>=1;
        }
        image_table[i] = t;
    }
    char fs[256];
    printf("请输入待处理文件名：");
    scanf("%s", fs);
    FILE * fin = fopen(fs, "rb");
    FILE * fout = fopen("1_2out", "wb");
    if(!fin)
    {
        printf("打开文件失败！\n");
        exit(0);
    }
    if(!fout)
    {
        printf("创建文件失败！\n");
        exit(0);
    }
    size_t byte_read;
    while((byte_read = fread(buffer, 1, BUFFER_SIZE, fin)) > 0)
    {
        tranbyte((int)(byte_read));
        fwrite(buffer, 1, byte_read, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
void tranbyte(int byte_read)
{
    for(int i = 0; i < byte_read; i++)
    {
        printf("%hhx", buffer[i]);
        buffer[i] = image_table[buffer[i]];
        printf("已转化：%hhx\n", buffer[i]);
    }
}