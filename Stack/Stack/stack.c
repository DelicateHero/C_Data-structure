#define _CRT_SECURE_NO_WARNINGS 1
#include"stcak.h"

typedef char STDataType;
typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void STInit(ST* ps)
{
    assert(ps);

    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

void STDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;

    ps->top = ps->capacity = 0;

}
//动态扩容
void STPush(ST* ps, STDataType x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
        if (tmp == NULL)
        {
            perror("realloc fail");
            exit(-1);
        }
        ps->a = tmp;
        tmp = NULL;
        ps->capacity = newcapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
void STPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}
STDataType  STTop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top - 1];
}
int STSize(ST* ps)
{
    assert(ps);
    return ps->top;
}
bool STEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}



//leetcode括号匹配问题
bool isValid(char* s)
{
    //Init
    ST ps;
    STInit(&ps);
    char ret = 0;
    //括号的类型匹配
    while (*s)
    {
        if (*s == '{' || *s == '[' || *s == '(')//左括号压栈
            STPush(&ps, *s);
        else//遇见右括号，让左括号弹栈，匹配。
        {
            if (STEmpty(&ps))//如果遇见右括号的时候栈里没有左括号，说明左右数量不匹配
            {
                STDestory(&ps);
                return false;
            }
            ret = STTop(&ps);
            STPop(&ps);//栈迭代
            if ((*s == '}' && ret != '{') || (*s == ']' && ret != '[') || (*s == ')' && ret != '('))
            {
                STDestory(&ps);
                return false;
            }
        }
        s++;//字符串迭代
    }
    //左括号的数量匹配（检查栈中是否还有左括号剩余）
    bool bret = STEmpty(&ps);
    STDestory(&ps);
    return bret;
}