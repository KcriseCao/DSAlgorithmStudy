/***********************************************************                                          *
* Time: 2021/3/14                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_STATICARRAY_H
#define DSALSTUDY_STATICARRAY_H
#include "Public.h"

typedef struct _STATICARRAY
{
    //数组容量
    int size;
    //数组长度
    int len;
    //数组存放地址
    void **pData;
} StaticArray;

typedef StaticArray ARRAY;

//初始化固定长度数组
ARRAY * initStaticArray(const int size);

//数组是否已满
bool isFull(ARRAY * pArray);

//指定位置插入数据
RET insertStaticArrayByPos(ARRAY *pArray, const int pos, void *data);

//指定位置删除数据
RET deleteStaticArrayByPos(ARRAY *pArray, const int pos);

//销毁数据
RET destroyStaticArray(ARRAY *pArray, void (*FREE)(void *data));

//获取数据的长度
int getStaticArrayLen(ARRAY *pArray);

//获取数据的容量
int getStaticArraySize(ARRAY *pArray);

//遍历数组
void foreachStaticArray(ARRAY *pArray, void (*PRINT)(void *data));

#endif //DSALSTUDY_STATICARRAY_H
