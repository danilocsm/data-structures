#define cDoubleList_c
#include "circular_double_linked_list.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

DLList *cdllCreate() {
  DLList *l;
  l = (DLList *)malloc(sizeof(DLList));
  if (l != NULL) {
    l->first = NULL;
    l->curr = NULL;
    return l;
  }
  return NULL;
}

int cdllDestroy(DLList *l) {
  DLNode *destroy, *curr;
  if (l != NULL) {
    if (l->first == NULL) {
      free(l);
      return TRUE;
    }
  }
  return FALSE;
}

int cdllInsertFirst(DLList *l, void *elm) {
  DLNode *new;
  if (l != NULL) {
    new = (DLNode *)malloc(sizeof(DLNode));
    if (new != NULL) {
      new->data = elm;
      if (l->first == NULL) {
        l->first = new;
        new->next = new;
        new->prev = new;
      } else {
        new->next = l->first;
        new->prev = l->first->prev;
        l->first->prev->next = new;
        l->first->prev = new;
        l->first = new;
      }
      return TRUE;
    }
  }
  return FALSE;
}

int cdllInsertLast(DLList *l, void *elm) {
  DLNode *new, *curr;
  if (l != NULL) {
    new = (DLNode *)malloc(sizeof(DLNode));
    if (new != NULL) {
      new->data = elm;
      if (l->first == NULL) {
        l->first = new;
        new->next = new;
        new->prev = new;
      } else {
        curr = l->first;
        while (curr->next != l->first)
          curr = curr->next;
        new->next = l->first;
        new->prev = curr;
        curr->next = new;
        l->first->prev = new;
      }
      return TRUE;
    }
  }
  return FALSE;
}

int cdllInsertAfterSpec(DLList *l, void *elm, void *key,
                        int (*cmp)(void *, void *)) {
  DLNode *new, *spec;
  int stat;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(spec->data, key);
      while (stat != TRUE && spec->next != l->first) {
        spec = spec->next;
        stat = cmp(spec->data, key);
      }
      if (stat) {
        new = (DLNode *)malloc(sizeof(DLNode));
        if (new != NULL) {
          new->data = elm;
          new->next = spec->next;
          new->prev = spec;
          spec->next->prev = new;
          spec->next = new;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

int cdllInsertBeforeSpec(DLList *l, void *elm, void *key,
                         int (*cmp)(void *, void *)) {
  DLNode *new, *spec;
  int stat;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(spec->data, key);
      while (stat != TRUE && spec->next != l->first) {
        spec = spec->next;
        stat = cmp(spec->data, key);
      }
      if (stat) {
        new = (DLNode *)malloc(sizeof(DLNode));
        if (new != NULL) {
          new->data = elm;
          new->next = spec;
          new->prev = spec->prev;
          spec->prev->next = new;
          spec->prev = new;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

void *cdllRemoveFirst(DLList *l) {
  void *dados;
  DLNode *destroy;
  if (l != NULL) {
    if (l->first != NULL) {
      destroy = l->first;
      dados = destroy->data;
      if (destroy->next == destroy->prev) {
        l->first = NULL;
      } else {
        destroy->next->prev = destroy->prev;
        destroy->prev->next = destroy->next;
        l->first = destroy->next;
      }
      free(destroy);
      return dados;
    }
  }
  return NULL;
}

void *cdllRemoveLast(DLList *l) {
  DLNode *destroy;
  void *dados;
  if (l != NULL) {
    if (l->first != NULL) {
      destroy = l->first->prev;
      dados = destroy->data;
      if (l->first->next == l->first) {
        l->first = NULL;
      } else {
        l->first->prev = destroy->prev;
        destroy->prev->next = l->first;
      }
      free(destroy);
      return dados;
    }
  }
  return NULL;
}

void *cdllRemoveSpec(DLList *l, void *key, int (*cmp)(void *, void *)) {
  void *dados;
  int stat;
  DLNode *spec;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(spec->data, key);
      while (stat != TRUE && spec->next != l->first) {
        spec = spec->next;
        stat = cmp(spec->data, key);
      }
      if (stat) {
        dados = spec->data;
        if (spec->next == spec) {
          l->first = NULL;
        } else {
          spec->prev->next = spec->next;
          spec->next->prev = spec->prev;
          if (spec = l->first)
            l->first = spec->next;
        }
        free(spec);
        return dados;
      }
    }
  }
  return NULL;
}

int cdllSearch(DLList *l, void *key, int (*cmp)(void *, void *)) {
  DLNode *curr;
  int stat;
  if (l != NULL) {
    if (l->first != NULL) {
      curr = l->first;
      stat = cmp(curr->data, key);
      while (stat != TRUE && curr->next != l->first) {
        curr = curr->next;
        stat = cmp(curr->data, key);
      }
      if (stat) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

void *cdllGetFirst(DLList *l) {
  if (l != NULL) {
    if (l->first != NULL) {
      l->curr = l->first;
      return l->curr->data;
    }
  }
  return NULL;
}

void *cdllGetNext(DLList *l) {
  if (l != NULL) {
    if (l->first != NULL) {
      l->curr = l->curr->next;
      if (l->curr != l->first)
        return l->curr->data;
    }
  }
  return NULL;
}

int cdllBind(DLList *l1, DLList *l2) {
  DLNode *last;
  if (l1 != NULL && l2 != NULL) {
    if (l1->first != NULL && l2->first != NULL) {
      last = l1->first;
      while (last->next != l1->first)
        last = last->next;
      last->next = l2->first;
      l2->first->prev = last;
      while (last->next != l2->first)
        last = last->next;
      last->next = l1->first;
      return TRUE;
    }
  }
  return FALSE;
}

int cdllRemoveCloser(DLList *l, void *key, int (*cmp)(void *, void *)) {
  DLNode *previous, *spec, *nextnode;
  int stat;
  if (l != NULL) {
    if (l->first != NULL) {
      spec = l->first;
      stat = cmp(spec->data, key);
      while (stat != TRUE && spec->next != l->first) {
        spec = spec->next;
        stat = cmp(spec->data, key);
      }
      if (stat) {
        previous = spec->prev;
        nextnode = spec->next;
        if (nextnode != previous) {
          if (spec->next->next != spec->prev) {
            previous->prev->next = nextnode->next;
            nextnode->next->prev = previous->prev;
            if (spec == l->first || previous == l->first ||
                nextnode == l->first)
              l->first = nextnode->next;
          } else
            l->first = NULL;
        } else
          l->first = NULL;
        free(nextnode);
        free(previous);
        free(spec);
        return TRUE;
      }
    }
  }
  return FALSE;
}

int cdllReverse(DLList *l) {
  DLNode *curr, *last, *newfirst = NULL;
  if (l != NULL) {
    if (l->first != NULL) {
      if (l->first->next != NULL) {
        last = l->first;
        while (l->first->next != newfirst) {
          curr = l->first;
          while (curr->next != last) {
            curr = curr->next;
          }
          curr->next = curr->prev;
          curr->prev = last;
          if (last == l->first)
            newfirst = curr;
          last = curr;
        }
        l->first = newfirst;
        return TRUE;
      }
    }
  }
  return FALSE;
}
