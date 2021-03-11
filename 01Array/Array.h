//
// Created by tracy on 2021/3/11.
//

#ifndef DSALSTUDY_ARRAY_H
#define DSALSTUDY_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    RET_OK = 0,
    RET_FAIL = 1
};

typedef struct _ARRAY
{
    //数组容量
    int size;
    //数组长度
    int len;
    //数组首地址
    void **data;
} Array;

//初始化数组
Array * initArray(int size);

//指定位置插入数据
int insertArrayByPos(Array *arr, int pos, void *data);

//指定位置删除数据
int deleteArrayByPos(Array *pArr, int pos);

//获取数组长度
int getArrayLength(Array *pArr);

//获取数组容量
int getArraySize(Array *pArr);

//销毁数组
void destoryArray(Array *pArr, void (*Free)(void *data) = NULL);

//遍历数组
void foreachArray(Array *pArr, void(*print)(void *));


#endif //DSALSTUDY_ARRAY_H
