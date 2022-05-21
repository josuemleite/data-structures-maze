#include <stdio.h>
#include <stdlib.h>

typedef int tdado;

typedef struct no {
	tdado dado;
	struct no *abaixo;
}tno;

typedef struct {
	tno *topo;
}tpilha;

void inicializa(tpilha *p) {
	p->topo = NULL;
}

int push(tpilha *p, tdado x) {
	tno *novo = malloc(sizeof(tno));
	if (novo == NULL)
		return 0;
	novo->dado = x;
	novo->abaixo = p->topo;
	p->topo = novo;
	return 1;
}

tdado pop(tpilha *p) {
	tno *aux = p->topo;
	tdado retorno = p->topo->dado;
	p->topo = p->topo->abaixo;
	free(aux);
	return retorno;
}

tdado top(tpilha p) {
	return p.topo->dado;
}

int isEmpty(tpilha p) {
	if(p.topo== NULL)
		return 1;
    else
		return 0;	  
}

void mostra(tpilha p) {
	while (p.topo != NULL) {
		printf("%d ", top(p));
		p.topo = p.topo->abaixo;
	}
	printf("\n");
}
