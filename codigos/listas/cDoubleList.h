#ifndef CDOUBLELIST_H_INCLUDED
	#define CDOUBLELIST_H_INCLUDED
	#define TRUE 1
	#define FALSE 0
	
	#ifdef cDoubleList_c
		typedef struct _dlnode_{
			void *data;
			struct _dlnode_ *next,*prev;
		}DLNode;

		typedef struct _dllist_{
			DLNode *first;
			DLNode *curr;
		}DLList;

		DLList *cdllCreate();
		int cdllDestroy(DLList *l);
		int cdllInsertFirst(DLList *l,void *elm);
		int cdllInsertLast(DLList *l,void *elm);
		int cdllInsertKesimo(DLList *l,void *elm,int k);
		int cdllInsertAfterSpec(DLList *l,void *elm,void *key,int(*cmp)(void*,void*));
		int cdllInsertBeforeSpec(DLList *l,void *elm,void *key,int(*cmp)(void*,void*));
		void *cdllRemoveFirst(DLList *l);
		void *cdllRemoveLast(DLList *l);
		void *cdllRemoveKesimo(DLList *l,int k);
		void *cdllRemoveSpec(DLList *l,void *key,int(*cmp)(void*,void*));
		int cdllSearch(DLList *l,void *key,int(*cmp)(void*,void*));
		void *cdllGetFirst(DLList *l);
		void *cdllGetNext(DLList *l);
		int cdllBind(DLList *l1,DLList *l2);
		int cdllRemoveCloser(DLList *l,void *key,int(*cmp)(void*,void*));
		int cdllReverse(DLList *l);
	#else
		typedef struct _dlnode_ DLNode;
		typedef struct _dllist_ DLList;
		extern DLList *cdllCreate();
		extern int cdllDestroy(DLList *l);
		extern int cdllInsertFirst(DLList *l,void *elm);
		extern int cdllInsertLast(DLList *l,void *elm);
		extern int cdllInsertKesimo(DLList *l,void *elm,int k);
		extern int cdllInsertAfterSpec(DLList *l,void *elm,void *key,int(*cmp)(void*,void*));
		extern int cdllInsertBeforeSpec(DLList *l,void *elm,void *key,int(*cmp)(void*,void*));
		extern void *cdllRemoveFirst(DLList *l);
		extern void *cdllRemoveLast(DLList *l);
		extern void *cdllRemoveKesimo(DLList *l,int k);
		extern void *cdllRemoveSpec(DLList *l,void *key,int(*cmp)(void*,void*));
		extern int cdllSearch(DLList *l,void *key,int(*cmp)(void*,void*));
		extern void *cdllGetFirst(DLList *l);
		extern void *cdllGetNext(DLList *l);
		extern int cdllBind(DLList *l1,DLList *l2);
		extern int cdllRemoveCloser(DLList *l,void *key,int(*cmp)(void*,void*));
		extern int cdllReverse(DLList *l);
	#endif
	
#endif // DOUBLELIST_H_INCLUDED