#include <stdio.h>
#include <stdlib.h>

struct usedNode {
  int l;
  int r;
};

struct freeNode {
  int l;
  int r;
  struct freeNode *next;
};

typedef struct freeNode freeNode;
typedef struct usedNode usedNode;

freeNode *f;
usedNode *used[5005];

int fenPei(int size, int id) {
  freeNode *p = f;
  while (p->next != NULL) {
    if (p->next->r - p->next->l >= size) {
      break;
    }
    p = p->next;
  }
  int left = 0;
  if (p->next != NULL) {
    if (p->next->r - p->next->l == size) {
      left = p->next->l;
      freeNode *toFree = p->next;
      p->next = p->next->next;
      free(toFree);
    } else {
      left = p->next->l;
      p->next->l = p->next->l + size;
    }
    used[id] = malloc(sizeof(usedNode));
    used[id]->l = left;
    used[id]->r = left + size;
  } else {
    left = -1;
  }

  return left;
}

int huiShou(int id) {
  if (used[id] == NULL) {
    return 0;
  }
  freeNode *p = f;
  while (p->next != NULL) {
    if (p->next->l >= used[id]->r) {
      break;
    }
    p = p->next;
  }
  if (p->next == NULL) {
    p->next = malloc(sizeof(freeNode));
    p->next->l = used[id]->l;
    p->next->r = used[id]->r;
    p->next->next = NULL;
  } else {
    freeNode *newNode = malloc(sizeof(freeNode));
    newNode->l = used[id]->l;
    newNode->r = used[id]->r;
    newNode->next = p->next;
    p->next = newNode;
  }
  p = f;
  while (p->next != NULL && p->next->next != NULL) {
    if (p->next->r == p->next->next->l) {
      freeNode *toFree = p->next;
      p->next->next->l = p->next->l;
      p->next = p->next->next;
      free(toFree);
    } else {
      p = p->next;
    }
  }
  free(used[id]);
  used[id] = NULL;
  return 1;
}

int main() {
  int T, n;
  scanf("%d %d", &T, &n);

  f = malloc(sizeof(freeNode));
  f->l = 0;
  f->r = 0;
  f->next = malloc(sizeof(freeNode));
  f->next->l = 0;
  f->next->r = n;
  f->next->next = NULL;

  int fenPeiid = 1;
  for (int i = 1; i <= T; ++i) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int size;
      scanf("%d", &size);
      int left = fenPei(size, fenPeiid++);
      if (left < 0) {
        printf("malloc fail\n");
      } else {
        printf("%d\n", left);
      }
    } else if (op == 2) {
      int id;
      scanf("%d", &id);
      int ok = huiShou(id);
      if (ok) {
        printf("free success\n");
      } else {
        printf("free fail\n");
      }
    } else {
        freeNode *p = f;
      if (f->next == NULL) {
        printf("NULL\n");
      } else {
        while (p->next != NULL) {
          printf("[%d,%d)", p->next->l, p->next->r);
          if (p->next->next != NULL) {
            printf(" ");
          }
          p = p->next;
        }
        printf("\n");
      }
    }
  }

  return 0;
}