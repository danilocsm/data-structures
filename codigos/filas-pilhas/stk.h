#ifndef STK_H_INCLUDED
#define STK_H_INCLUDED

	typedef struct _Stack{
		int tam;
		int top;
		void **vet;
	}Stack;

	Stack *stkCreate(int max);
	int stkDestroy(Stack *s);
	int stkPush(Stack *s,void *key);
	void *stkPop(Stack *s);
	int isEmpty(Stack *s);

#endif