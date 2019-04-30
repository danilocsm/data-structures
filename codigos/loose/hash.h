#ifndef HASH_H_INCLUDED
  #define HASH_H_INCLUDED
  // #ifdef hash_c
    typedef struct slnode_{
			void *data;
			struct slnode_ *next;
		}SLNode;
		typedef struct sllist_{
			SLNode *first;
			SLNode *curr;
		}SLList;
		SLList *sllCreate();
    SLList **createHashTable(int size);
		int sllDestroy(SLList *l);
		int sllInsertFirst(SLList *l,void *elm);
    void *sllRemoveSpec(SLList *l,void *key,int(*cmp)(void*,void*));
    void* sllSearch(SLList *l,void *key,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int flag);
    int hashFunction(int size,void *elm,char*(*getValue)(void*));
    int hashInsert(SLList *list,void *elm,int(*cmp)(void*,void*),void*(helpFunction)(void*),int *distincts);
    void printHash(SLList *list,void (*visit)(void*));
  /* #else
    typedef struct slnode_ SLNode;
		typedef struct sllist_ SLList;
		extern SLList *sllCreate();
    extern SLList **createHashTable(int M)
		extern int sllDestroy(SLList *l);
		extern int sllInsertFirst(SLList *l,void *elm);
    extern void *sllRemoveSpec(SLList *l,void *key,int(*cmp)(void*,void*));
    extern int hashFunction(int size,void *elm,char*(*getValue)(void*));
    extern int hashInsert(SLList *list,void *elm);
   #endif*/
#endif
