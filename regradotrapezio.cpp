//Vamos escrever um programa para calcular uma integral definida usando a regra do trapézio

/*Vamos usar o arquivo mestre <cmath> ou <math.h> que inclui as funções transcendentais mais simples que aparecem em um curso de cálculo como a o funções potência, função exponencial, logarítmica, funções trigonométricas e funções hiperbólicas que podem ser invocadas diretamente. A função setpercision(#) e o arquivo mestre <iomanip> ajustam a precisão do resultados exibidos para averiáveis de precisão dupla*/

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

//Função a ser integrada. Esta função pode ser alterada se necessário.

double f(double x){
//Definição da variável resultado
double r;
//Definição da função
r=(pow(x, 3)*cos(x/2)+0.5)*sqrt(4-pow(x,2));
return(r);
}
//Agora começa a função pricipal do programa

int main(){
//Definindo as variáveis
double a, b, integral, passo, soma;
int n, i;
//Procedimentos para cálculo da integral
//Entrada manual de dados
cout<< "Digite o limite inferior do intervalo de integração:";
cin>>a;
cout<< "Digite o limite superior do intervalo de integração:";
cin>>b;
cout<< "Digite quantos subintervalos você deseja usar na integração numérica:";
cin>>n;
//Cálculo do passo de integração
passo=(b-a)/n;
//Cálculo da integral
soma=f(a)+f(b);
cout << "x                      f(x)";
cout<< "\n"<< setprecision(12)<<a << " "<< setprecision(12)<<f(a);
for (i=1; i<=n-1; i++)
 {soma = soma+2.0*f(a+i*passo);
cout<< "\n" << setprecision(12)<<a+i*passo << " "<< setprecision(12)<<f(a+i*passo);};
cout<< "\n"<< setprecision(12) <<b << " "<< setprecision(12) <<f(b);
integral = ((passo/2.0)*soma);
cout<< "\nO valor da integral definida é "<< setprecision(12)<<integral;
return 0;
}
