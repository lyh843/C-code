#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N (100000 + 50)
#define B 2000

int n, m, qn, insCnt;
char str[N], tmp[N];

struct node 
{
    char a[B + 1];
    int siz;
    struct node *nxt;
};

typedef struct node Node;

Node *head;

Node *newNode() 
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->siz = 0, node->nxt = NULL;
    return node;
}

Node *build(char *s)
{
    m = strlen(s + 1);
    Node *curHead = newNode();
    Node *cur = curHead;
    int p = 1;
    bool flag = false;
    while (1) 
    {
        for (int i = 1; i <= B; i++) 
        {
            cur->a[i] = s[p];
            cur->siz = i;
            if (p == m) 
            {
                flag = true;
                break;
            }
            ++p;
        }
        if (flag) break;
        cur->nxt = newNode();
        cur = cur->nxt;
    }
    return curHead;
}

bool split(Node *x, int pos) 
{
    if (pos == x->siz) return false;
    Node *y = newNode();
    y->siz = (x->siz) - pos;
    for (int i = 1, j = pos + 1; i <= (y->siz) && j <= (x->siz); i++, j++) 
    {
        y->a[i] = x->a[j];
    }
    x->siz -= y->siz;
    y->nxt = x->nxt;
    x->nxt = y;
    return true;
}

void merge(Node *x, Node *y) 
{
    for (int i = x->siz + 1, j = 1; j <= y->siz; i++, j++) 
    {
        x->a[i] = y->a[j];
    }
    x->siz += y->siz;
    x->nxt = y->nxt;
    free(y);
}

void maintain() 
{
    for (Node *p = head; p->nxt; p = p->nxt) 
    {
        while (p->nxt && p->siz + p->nxt->siz <= B) 
        {
            merge(p, p->nxt);
        }
        if (!(p->nxt)) break;
    }
}

int count(Node *cur) 
{
    int ret = 0;
    for (Node *p = head; p != cur; p = p->nxt) 
    {
        ret += p->siz;
    }
    return ret;
}

Node *get(int pos) 
{
    for (Node *p = head; p; p = p->nxt) 
    {
        if (pos > p->siz) 
        {
            pos -= p->siz;
        } 
        else 
        {
            return p;
        }
    }
}

void ins(int pos) 
{
    if (pos == 0) 
    {
        Node *x = build(tmp);
        Node *y = x;
        for (; y->nxt; y = y->nxt);
        y->nxt = head;
        head = x;
    } 
    else 
    {
        Node *x = get(pos);
        int splitPos = pos - count(x);
        split(x, splitPos);
        Node *y = build(tmp);
        Node *z = y;
        for (; z->nxt; z = z->nxt);
        z->nxt = x->nxt;
        x->nxt = y;
    }
    maintain();
    insCnt += strlen(tmp + 1);
    n += strlen(tmp + 1);
}

char query(int pos) 
{
    Node *p = get(pos);
    return p->a[pos - count(p)];
}

int main() 
{
    scanf("%d%d", &n, &qn);
    scanf("%s", str + 1);
    head = build(str);
    for (char op[3]; qn--;) 
    {
        scanf("%s", op);
        if (op[0] == 'I') 
        {
            int p;
            scanf("%d%s", &p, tmp + 1);
            ins(p);
        } 
        else
        {
            int p;
            scanf("%d", &p);
            printf("%c\n", query(p));
        }
    }
    return 0;
}