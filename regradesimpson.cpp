//Vamos escrever um programa para calcular uma integral definida usando a regra de simpson

/*Vamos usar o arquivo mestre <cmath> ou <math.h> que inclui as funções transcendentais mais simples que aparecem em um curso de cálculo como a o funções potência, função exponencial, logarítmica, funções trigonométricas e funções hiperbólicas que podem ser invocadas diretamente.A função setpercision(#) e o arquivo mestre <iomanip> ajustam a precisão do resultados exibidos para averiáveis de precisão dupla*/

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
/*Função coeficiente. Esta função nos dá o coeficiente de uma parcela na soma da integral. Esta função não deve ser alterada*/
double coeficiente(int i){
//Definição de variáveis
double fatork;
switch(i%2){
case 1:
{fatork=4.0; break;}
case 0:
{fatork=2.0; break;};
};
return(fatork);
}

//Função a ser integrada. Esta função pode ser alterada se necessário.

double f(double x){
//Definição da variável resultado
double r;
//Definição da função. Se necessário modifique a definição da função
r=(pow(x, 3)*cos(x/2)+0.5)*sqrt(4-pow(x,2));
return(r);
}
//Agora começa a função pricipal do programa

int main(){
//Definindo as variáveis
double a, b, integral, passo, soma;
int n, h, i;
//Procedimentos para cálculo da integral
//Entrada manual de dados
cout<< "Digite o limite inferior do intervalo de integração:";
cin>>a;
cout<< "Digite o limite superior do intervalo de integração:";
cin>>b;
cout<< "Digite quantos subintervalos você deseja usar na integração numérica:";
cin>>n;
//Cálculo do passo de integração
h=2*n;
passo=(b-a)/h;
//Cálculo da integral
soma=f(a)+f(b);
cout << "x                      f(x)";
cout<< "\n"<< setprecision(12)<<a << " "<< setprecision(12)<<f(a);
for (i=1; i<=h-1; i++)
 {soma = soma+coeficiente(i)*f(a+i*passo);
cout<< "\n" << setprecision(12)<<a+i*passo << " "<< setprecision(12)<<f(a+i*passo);};
cout<< "\n"<< setprecision(12)<< b << " "<< setprecision(12)<<f(b);
integral = ((passo/3.0)*soma);
cout<< "\nO valor da integral definida é "<< setprecision(12)<<integral;
return 0;
}
