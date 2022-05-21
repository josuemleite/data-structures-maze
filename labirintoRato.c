#include <stdio.h>
#include "pilhaEncadeada.h"
#include <stdlib.h>
#include <locale.h>
#define MAX 15

void cria(char l[MAX][MAX]) {
	
    int i, j, x, y;
    
    srand(time(NULL));
    
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if ((rand() % 5) == 1) {
            	l[i][j] = '*';
			} else {
            	l[i][j] = '.';
            }
        }
    }
    
	for (i = 0; i < MAX; i++) {
    	l[0][i] = '*';
    	l[MAX-1][i] = '*';
    	l[i][0] = '*';
    	l[i][MAX-1] = '*';
    }
    
	x = rand() % MAX;
	y = rand() % MAX;
    l[x][y] = 'Q';
}
     
void mostraLabirinto(char mat[MAX][MAX], int linha, int coluna) {
	
    int i, j;
    
	for ( i = 0; i < linha; i++) {
    	printf("\n");
        for ( j = 0; j < coluna; j++) {
        	printf (" %c ", mat[i][j]);
		}
    }
}
     
int funcaoSuperMouse(char lab[MAX][MAX], int i, int j) {

	tpilha linha, coluna;
	
	inicializa(&linha);
	inicializa(&coluna);
	
	while (lab[i][j] != 'Q') {
		
		lab[i][j] = 'V';
		
		if (lab[i][j+1] == '.' || lab[i][j+1] == 'Q') {
			push(&linha, i);
			push(&coluna, j);
			j++;
		} else if (lab[i+1][j] == '.' || lab[i+1][j] == 'Q') {
			push(&linha, i);
			push(&coluna, j);
			i++;
		} else if (lab[i][j-1] == '.' || lab[i][j-1] == 'Q') {
			push(&linha, i);
			push(&coluna, j);
			j--;
		} else if (lab[i-1][j] == '.' || lab[i-1][j] == 'Q') {
			push(&linha, i);
			push(&coluna, j);
			i--;
		} else {
			if (!isEmpty(linha) && !isEmpty(coluna)) {
				lab[i][j] = 'X';
				i = pop(&linha);
				j = pop(&coluna);
			} else {
				printf("\nQueijo não encontrado!\n");
				return;
			}
		}
		
		Sleep(150);
		system("cls");
		mostraLabirinto(lab, MAX, MAX);
	}
	
	printf("\nO queijo foi encontrado pelo rato na posição: (%d, %d)\n", i, j);
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
    char labirinto[MAX][MAX];
    int x, y;
    
    cria(labirinto);
    
    mostraLabirinto(labirinto, MAX, MAX);
    
    printf("\nSolte o rato em uma posição (x, y): ");
    scanf("%d%d", &x, &y);
    
    funcaoSuperMouse(labirinto, x, y);
    
    getch();
    return 0;
}
