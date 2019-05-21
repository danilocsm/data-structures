#ifndef LINKSTK_C_INCLUDED
#define LINKSTK_C_INCLUDED

	typedef struct slnode_{
		void *data;
		struct slnode_ *next;
	}SLNode;
	typedef struct _linkedstack{
		SLNode *top;
	}LStack;

	LStack *lsCreate();
	int lsDestroy(LStack *ls);
	int lsPush(LStack *ls,void *elm);
	void *lsPop(LStack *ls);
	
#endif // LINKSTK_C_INCLUDED