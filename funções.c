#include <stdio.h>
/*
int par(int num){
    while(num%2!=0){
        printf("invalido");
        scanf("%d", &num);
    }
    return num;
}
int main(){
    int numero;
    scanf("%d", &numero);
    printf("%d", par(numero));

*/
/*
float area(float base, float altura){
    float resultado;
    resultado=base*altura/2;
    return resultado;
}
int main(){
 float num1,num2,result;

 scanf("%f %f", &num1, &num2);

  printf("%f", area(num1, num2));
*/
/*
void elevad(){
   int x,z,i,soma=0;
   scanf("%d %d", &x, &z);
   for (i=1; i<z; i++){
    soma+=x*x;
   }
   printf("%d", soma);

}
int main(){
    elevad();

}
*/
/*
void sei(){
    int n, i,soma=1;
    printf("Digite o expoente da base 2\n");
    scanf("%d", &n);
    while (n==0){
        printf("digite novamente");
        scanf("%d", &n);
    }
   for ( ; n; n--){
    soma*=2;
   }

    printf("%d", soma);


}
int main() {

    sei();

return 0;
}
*/
/*
int fib (int n){
int prox,ant, i, aux;
if (n == 1){
    return 0;
}
else if (n==2){
    return 1;
}
else {
    for (i=3; i<=n; i++){
        aux=prox;
        prox=ant+prox;
        ant=aux;
    }
    return prox;
}
}
int main (){
    int num;
    printf("digite a posicao que quer");
    scanf("%d", &num);
    printf("o termo e %d", fib(num));

}
*/
/*
void soma_vetor(int vet[3]){
    int i,soma=0;
    for (i=0; i<3; i++){
        scanf("%d", &vet[i]);
    }
    for (i=0; i<3; i++){
        soma=soma+vet[i];
    }
    printf("%d", soma);
}
int main(){
    int vetor[3];
    soma_vetor(vetor);
}
*/

/*
int volume(int a){
    int fun=a*a*a;
    return fun;
    }
int main(){
    int num;
    printf("escreva valor das arestas");
    scanf("%d", &num);
    printf("%d",volume(num) );
return 0;
}
*/
/*
int vetor(int vet[10]){
    int soma=0, i;
    for (i=0; i<10; i++){
        soma=soma+vet[i];
    }
    return soma;
}
int main (){
    int vet[10];
    scanf("%d", vetor(vet[10]));
    printf("%d", vetor(vet[10]));

}
*/
/*
int maior(int num1, int num2, int num3){
    if (num1>num2 && num1>num3){
        return num1;
    }
    else if(num2>num1 && num2>num3){
        return num2;
    }
    else if (num3>num2 && num3>num1){
        return num3;
    }
    return num3;
}
int main(){
int numero1,numero2,numero3;
scanf("%d %d %d\n", &numero1, &numero2, &numero3);
printf("%d %d %d", maior(numero1), maior(numero2), maior(numero3));

}
*/
/*
int triangulo(int a, int b, int c){
    int alado, clado,blado,aguais,biguais,ciguais;
    while(a>c+b && c>a+b && b>a+b){
        printf("invalido digite novamente");
        scanf("%d %d %d", &a, &b, &c);
        // so ta verificando uma vez
    }
    if (a+b+c!=180){
        printf("invalido");
        scanf("%d %d %d", &a, &b, &c);
    }

    if (a<b+c){
        alado=a;
    }
    else if(b<a+c){
        blado=b;
    }
    else if (c<a+b){
        clado=c;
    }
   if (alado == blado && alado == clado && blado==clado ){
    printf("triangulo equilatero");
   }
   if (alado != blado && alado != clado && blado!=clado ){
    printf("triangulo isoceles");
   }

return alado,blado,clado;
}

int main(){
    int ladoa,ladob,ladoc;
    scanf("%d %d %d", &ladoa, &ladob, &ladoc);
    triangulo(ladoa, ladob, ladoc);

}
*/
/*
void primos(){

    int k=0, p;
    scanf("%d", &p);
    int div=1;
    while (div<=p){
        if (p%div==0){
            div++;
            }
      k++;
    }
    if (k==2 || p==1){
        printf("e primo");
    }
    else{
        printf("nao e primo");
    }

}

int main(){
    primos();


}
*/
/*
void soma(){
int a,b,i,soma=0;
    scanf("%d %d", &a, &b);
    for (i=a+1; i<b; i++){
        soma=soma+i;
    }
    printf("%d", soma);
}

int main(){

    soma();

}
*/



