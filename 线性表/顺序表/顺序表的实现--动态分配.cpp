//动态申请和释放空间——malloc、free
// L.data = (ElemType *) malloc (sizeof(ElemType)* InitSize); malloc 函数返回一个指针，需要强制转型为你定义的数据元素类型指针

#include <stdlib.h>
#define InitSize 10 //默认的最大长度
typedef struct
{
    int *data;   //指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length;  //顺序表的当前长度
} SeqList;

void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int)); //用malloc函数申请一片连续的存储空间
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];           //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len;    //顺序表最大长度增加len
    free(p);                        //释放原来的内存空间
}