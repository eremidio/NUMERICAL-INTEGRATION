//Vamos usar arrays para escrever um programde integração númerica num estilo similar a programação funcional
/*Cabeçalho com arquivos mestres e namespaces usados*/

#include<iostream>
#include<array>
#include<iomanip>
#include<cmath>

using namespace std;

//Definição da função a ser integrada. Esta função pode ser alterada conforme a necessidade do uso do programa.

double f(double x){
//Variavel de resultado
double r;
//Definição da função
r=(pow(x,3)*cos(x/2)+0.5)*sqrt(4-pow(x, 2));
return(r);
}

/*Função para calcular a soma da integral. Vamos criar uma array que irá alocar o valor da função a ser integrada em um conjunto específico de pontos e vamos operar diretamente com este array de valores. A variável tamanho contém o número de parcelas na soma da integral. Esta função não deve ser alterada*/
double somaparcial(double array[], int tamanho){
//Variáveis adicionais, i é a variável de iteração
double soma;
int i;
//Definição
soma=array[0]+array[tamanho-1];
for (i=1; i<=tamanho-2; i++)
 soma=soma+2.0*array[i];
return(soma);
}

//Aqui começa a função principal do programa

int main(){
//Definição de variáveis
double a, b, passo, integral;
int i, n;
//Procedimentos executáveis
//Entrada manual de dados
cout<<"Qual o limite inferior do seu intervalo de integração?";
cin>>a;
cout<<"\nQual o limite superior do seu intervalo de integração?";
cin>>b;
cout<<"\n Quantos passos você deseja usar na sua integração númerica?";
cin>>n;
//Cálculo do passo de integração
passo=(b-a)/n;
//Definição dos arrays que alocarão os limites do subintervalos de integração e o valor da função a ser integrada
double argumento[n];
double funcao[n];
//Definição recursiva do array com os argumentos da função
for(i=0; i<=n; i++)
{argumento[0]=a;
argumento[i]=argumento[i-1]+passo;
funcao[i]=f(argumento[i]);
}
//Exibindo a  função a ser computada
cout << "x"<< "     "<< "f(x)";
for(i=0; i<n; i++)
 cout<< "\n"<<setprecision(12)<< argumento[i]<< " "<<setprecision(12)<<funcao[i];
cout<< "\n"<<setprecision(12)<< b<< " "<<setprecision(12)<<f(b);
cout<< "\n O valor da integral definida é "<<setprecision(12)<< (passo/2.0)*(somaparcial(funcao, n)+f(b));
return 0;
}
