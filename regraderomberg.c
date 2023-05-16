//VAMOS ESCRVER UM PROGRAM EM C QUE CALCULA INTEGRAIS DEFINIDAS USANDO A REGRA DE INTEGRAÇÃO DE ROMBERG
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o regraderomberg regraderomberg.c -lm
/*
A REGRA DO TRAPÉZIO PARA INTEGRAÇÃO DEFINIDA, CONSISTE EM USAR TRAPÉZIOS NO LUGAR DE RETÂNGULOS PARA APROXIMAR UMA SOMA DE
RIEMANN, NA PRÁTICA DIVIDE-SE O INTERVALO DE INTEGRAÇÃO EM n SUBINTERVALOS E UMA MÉDIA PONDERADA DO VALOR DA FUNÇÃO EM CADA SUBINTERVALO MULTIPLICADA PELO TAMANHO DESTE SUBINTERVALO É SOMADA E USADA PARA APROXIMAR A INTEGRAL. TAL MÉTODO NÓS DÁ UM
ERRO DADO POR E=(-1/12)F²(c)(b-a)Δx², ONDE a E b SÃO OS EXTREMOS DO INTERVALO DE INTEGRAÇÃO E Δx É O COMPRIMENTO DE CADA SUBINTERVALO, c É UMA CONSTANTE  NO INTERVALO [a, b], F² DENOTA A DERIVADA SEGUNDA. A GROSSO MODO REESCREVEMOS O ERRO COMO 
E=KΔx², COM K CONSTANTE. SEJA ESTE UMA EXPRESSÃO DO NÚMERO DE SUBINTERVALOS E(N)=KΔx², PORTANTO E(2N)=KΔx²/4, CHAMANDO DE I(N)
E I(2N) AS PROXIMAÇÕES COM N E 2N SUBINTERVALOS TEMOS QUE I(N)+E(N)=I(2N)+E(2N) E REARRANJANDO ESTA EQUAÇÃO TEMOS QUE
I(2N)-I(N)= (3/4)K(Δx²) OU KΔx²/4 =(1/3)(I(2N)-I(N)), PORTANO USAMOS COMO UMA MELHOR APROXIMAÇÃO PARA O VALOR EXATO DA
INTEGRAL O VALOR I(2N)+(1/3)(I(2N)-I(N))=(4/3)I(2N)-(1/3)I(N). ESTA APROXIMAÇÃO TEM ERRO DE ΔX⁴, COMPARÁVEL A MÉTODOS MAIS COMPLEXOS COMO A REGRA
DE SIMPSON.

*/


//Cabeçalho
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Função a ser integrada. (Esta função pode ser livremente modoficada pelo usuário)

double integrated_function(double x){ 
return (pow(x, 3)*cos(x/2)+0.5)*sqrt(4.0-pow(x, 2)); 
                                    };


//Função que calcula a integral definida via regra do trapézio. Não modificar esta função.
double trapezoidal_rule(int n, double a, double b){
//Variáveis locais
double values_array[n];
double integral_array[n];
double step, integral_sum;
int i, j;

//Procedimentos
//Calculando o passo de integração
step=((b-a)/n);

//Cálculo do array de integral
for(i=0; i<n; ++i){

//Calculando o array de valores correspondendo aos argumentos da função
values_array[i]=a+i*step;

//Calculo de uma parcela da soma da integração
if(i==0 || i==(n-1))
integral_array[i]=integrated_function(values_array[i]);
else if(i!=0 && i!=(n-1))
integral_array[i]=integrated_function(values_array[i])*2.0;

                  };

//Calculando a integral definida
integral_sum=0.0;
for(i=0; i<n; ++i)
integral_sum+=integral_array[i];

integral_sum*=step;
integral_sum/=2.0;

printf("Regra do trapézio(%d subintervalos): %0.12lf\n", n, integral_sum);
return integral_sum;
                                                  };

//Função que calcula a integral definida via regra do Romberg. Não modificar esta função.
double romberg_rule(int n, double a, double b){
return (4.0/3.0)*trapezoidal_rule(2*n, a, b)-(1.0/3.0)*trapezoidal_rule(n, a, b);
                                              };


//Função principal
int main(){
//Variáveis locais
double a, b;
int n;

//Procedimento
//Recebendo input do usuário
printf("Limite inferior de integração:\n");
scanf("%lf", &a);
printf("Limite superior de integração:\n");
scanf("%lf", &b);
printf("Número de subintervalos usados na integração:\n");
scanf("%d", &n);

//Exibindo o resultado e encerrando a aplicação
printf("O resultado da integral usando a regra de Romberg é %0.12lf\n", romberg_rule(n, a ,b));
return 0;
          }


