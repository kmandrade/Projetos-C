#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 80
char lista[MAX][LEN];



void ordena(){
    int x,y,r;
    char aux[LEN];
    for (x=0; x<MAX; x++){
            for(y=x+1; y<MAX;y++){
                r=strcmp(lista[x],lista[y]);
            }
            if(r>0){
                strcpy(aux,lista[x]);
                strcpy(lista[x],lista[y]);
                strcpy(lista[y],aux);
            }
    }

}



int main(){

    int quant,valor;


    do{
        printf("DIGITE A QUANTIDADE DE PESSOAS\n");
        fflush(stdin);
        scanf("%d", &quant);
        putchar('\n');

            int i,j,t;
            for(i=0;i<quant;i++){
                printf("DIGITE O NOME DO AMIGO\n");
                fflush(stdin);
                gets(lista[i]);
            }
            ordena();
            for(j=0; j<i; j++){

                puts(lista[j]);

            }

      printf("DESEJA ADICIONAR MAIS PESSOAS?\n");
      fflush(stdin);
      scanf("%d", &quant);
    }while(quant!=0);








}
