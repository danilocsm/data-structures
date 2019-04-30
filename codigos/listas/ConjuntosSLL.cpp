#include "SimpleList.h"
#ifndef CONJUNTOS_H_INCLUDED
	#define CONJUNTOS_H_INCLUDED
	
	#ifdef ConjSllAux_c
		int slluniaoConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		int sllinterConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		int slldiferConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		int sllcompleConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		int sllisContido(SLList *A,SLList *B,int(*cmp)(void*,void*));
		int sllInsereElms(int n,SLList *l,int(*cmp)(void*,void*));
		void sllListaConj(SLList *l);
		int sllLimpaConj(SLList *l);
		int compara(void* a,void* b);
	#else
		extern int slluniaoConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		extern int sllinterConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		extern int slldiferConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		extern int sllcompleConjuntos(SLList *A,SLList *B,SLList *C,int(*cmp)(void*,void*));
		extern int sllisContido(SLList *A,SLList *B,int(*cmp)(void*,void*));
		extern int sllInsereElms(int n,SLList *l,int(*cmp)(void*,void*));
		extern void sllListaConj(SLList *l);
		extern int sllLimpaConj(SLList *l);
		extern int compara(void* a,void* b);
	#endif
		
#endif