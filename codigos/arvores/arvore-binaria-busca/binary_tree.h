#ifndef BINARYTREE_H_INCLUDED

	#define BINARYTREE_H_INCLUDED

	//#ifdef BinaryTree_c
		typedef struct _tnode_{
			void *data;
			struct _tnode_ *left,*right;
		}TNode;
		//TNode *btCreateEmpty();
		//TNode *bstInsert(TNode *t,void *elm,int(*cmp)(void*,void*));
		TNode *bstInsert(TNode *t,void *elm,int(*cmp)(void*,void*),void*(*helpFunction)(void*),int *distincts);
		TNode *bstRemove(TNode *t,void *elm,int(*cmp)(void*,void*));
		void* bstSearch(TNode *t,void *key,int(*cmp)(void*,void*));
		/*void btPreordem(TNode *t,void(*visit)(void*));
		void btPosordem(TNode *t,void(*visit)(void*));*/
		void btSimetrica(TNode *t,void(*visit)(void*));
		TNode* bstDeleteTree(TNode *root,int(*cmp)(void*,void*));
		TNode* bstGetMin(TNode *root);
		TNode* bstGetMax(TNode *root);
		/*int btContaNodes(TNode *t);
		int btAltura(TNode *t);
		int btContaNodesAlturaHrec(TNode *t,int h,int l);
		int btContaNodesAtLeastOne(TNode *t);
		int btContaNodesOnlyOne(TNode *t);
		int btContaNodesOnlyLeft(TNode *t);
		int btContaNodesOnlyTwo(TNode *t);
		void *bstBigger(TNode *t);
		void btBigger(TNode *t,int(*getValue)(void*),int *bigger);
		void btSmaller(TNode *t,int(*getValue)(void*),int *menor);
		int btIsComplete(TNode *t);
		int btIsBinarySearchTree(TNode *t,int(*cmp)(void*,void*));
		int btQntBigger(TNode *t,void *elm,int(*cmp)(void*,void*));
		int bstAlturaNode(TNode *t,void *key,int(*cmp)(void*,void*));
		int bstAlturaNodeRec(TNode *t,void *key,int(*cmp)(void*,void*),int l);
		int btIsEqual(TNode *t1,TNode *t2,int(*cmp)(void*,void*));
		int btIsEqualH(TNode *t1,TNode *t2,int(*cmp)(void*,void*),int h,int l);
		void bstPrintLeafDec(TNode *t,void(*visit)(void*));
		int btSoma(TNode *t,int(*getValue)(void*));;
		void *getRoot(TNode *t);
		int btContaNodesAlturaH(TNode *t,int h,int l);
		int btContaNodesTillH(TNode *t,int h,int l);
		void btSearch(TNode *t,void* key,int(*cmp)(void*,void*),int *stat);*/
	/*#else
		typedef struct _tnode_ TNode;
		//extern TNode *btCreateEmpty();
		extern TNode *bstInsert(TNode *t,void *elm,int(*cmp)(void*,void*));
		extern TNode *btInsert(TNode *t,void *elm,int(*getValue)(void*),int(*cmp)(void*,void*),void(*helpFunction)(void**));
		extern int bstSearch(TNode *t,void *key,int(*cmp)(void*,void*));*/
		/*extern void btPreordem(TNode *t,void(*visit)(void*));
		extern void btPosordem(TNode *t,void(*visit)(void*));*/
		//extern void btSimetrica(TNode *t,void(*visit)(void*));
		/*extern int btContaNodes(TNode *t);
		extern int btAltura(TNode *t);
		extern int btContaNodesAlturaHrec(TNode *t,int h,int l);
		extern int btContaNodesAtLeastOne(TNode *t);
		extern int btContaNodesOnlyOne(TNode *t);
		extern int btContaNodesOnlyLeft(TNode *t);
		extern int btContaNodesOnlyTwo(TNode *t);
		extern void *bstBigger(TNode *t);
		extern void btBigger(TNode *t,int(*getValue)(void*),int *maior);
		extern void btSmaller(TNode *t,int(*getValue)(void*),int *menor);
		extern TNode *bstRemove(TNode *t,void *elm,int(*cmp)(void*,void*));
		extern int btIsComplete(TNode *t);
		extern int btIsBinarySearchTree(TNode *t,int(*cmp)(void*,void*));
		extern int btQntBigger(TNode *t,void *elm,int(*cmp)(void*,void*));
		extern int bstAlturaNode(TNode *t,void *key,int(*cmp)(void*,void*));
		extern int bstAlturaNodeRec(TNode *t,void *key,int(*cmp)(void*,void*),int l);
		extern int btIsEqual(TNode *t1,TNode *t2,int(*cmp)(void*,void*));
		extern int btIsEqualH(TNode *t1,TNode *t2,int(*cmp)(void*,void*),int h,int l);
		extern void bstPrintLeafDec(TNode *t,void(*visit)(void*));
		extern int btSoma(TNode *t,int(*getValue)(void*));
		extern void *getRoot(TNode *t);
		extern int btContaNodesAlturaH(TNode *t,int h,int l);
		extern int btContaNodesTillH(TNode *t,int h,int l);
		extern void btSearch(TNode *t,void* key,int(*cmp)(void*,void*),int *stat);*/
	//#endif

#endif
