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
//��̬����
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



//leetcode����ƥ������
bool isValid(char* s)
{
    //Init
    ST ps;
    STInit(&ps);
    char ret = 0;
    //���ŵ�����ƥ��
    while (*s)
    {
        if (*s == '{' || *s == '[' || *s == '(')//������ѹջ
            STPush(&ps, *s);
        else//���������ţ��������ŵ�ջ��ƥ�䡣
        {
            if (STEmpty(&ps))//������������ŵ�ʱ��ջ��û�������ţ�˵������������ƥ��
            {
                STDestory(&ps);
                return false;
            }
            ret = STTop(&ps);
            STPop(&ps);//ջ����
            if ((*s == '}' && ret != '{') || (*s == ']' && ret != '[') || (*s == ')' && ret != '('))
            {
                STDestory(&ps);
                return false;
            }
        }
        s++;//�ַ�������
    }
    //�����ŵ�����ƥ�䣨���ջ���Ƿ���������ʣ�ࣩ
    bool bret = STEmpty(&ps);
    STDestory(&ps);
    return bret;
}