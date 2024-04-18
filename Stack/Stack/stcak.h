#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void STInit(ST* ps);
void STDestory(ST* ps);
void STPush(ST* ps, STDataType x);
void STPop(ST* ps);
STDataType  STTop(ST* ps);
int STSize(ST* ps);
bool STEmpty(ST* ps);

