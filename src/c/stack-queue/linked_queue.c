#include "linkqueue.h"
#include <stdio.h>
#include <stdlib.h>

void main(void) {
  int i, *px;
  LQueue *lq;
  lq = lqCreate();
  if (lq != NULL) {
    printf("DEU CERTO\n");
    for (i = 1; i < 11; i++) {
      px = (int *)malloc(sizeof(int));
      *px = i;
      if (lqEnqueue(lq, (void *)px))
        printf("UHUL\n");
    }
    while (lq->first != NULL) {
      px = (int *)lqDequeue(lq);
      printf("<----%d---->\n", *px);
    }

  } else
    printf("JOAO OTAVIO É GAY\n");
}
