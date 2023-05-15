#Vamos escrever um programa para calcular uma integral numericamente
import math
import functools

n1=input("Digite quantos passos você deseja utilizar no cálculo da integral definida.")
n=int(n1)
#Defina aqui a função que você deseja integrar
def f(x):
 '''Função a ser integrada numericamente. Esta função pode ser alterada.'''
 return ((x**3)*math.cos(x/2)+(1/2))*math.sqrt(4.0-(x**2))

#Vamos definir aqui as funções coeficientes

def coeficiente(i):
 '''Coeficientes de integração numérica.Esta função não deve ser alterada'''
 if i==1:
  return 1
 elif i==n:
  return 1
 else:
  return 2

def add(x, y):
 '''Função para somar dois números. Esta função não deve ser alterada'''
 return x+y

def g(x):
 '''Esta função multiplica um número pelo resultado da função coeficiente. Esta função não deve ser alterada'''
 for i in range(n+1):
  return x*coeficiente(i)

#Definição da integral definida
n2=input('Digite aqui o limite inferior do intervalo de integração')
a=float(n2)
n3=input('Digite aqui o limite superior do intervalo de integração')
b=float(n3)

#Calculo do passo de integração
passo=(b-a)/n


#Definição da integral definda

x1=[a+i*passo for i in range(n+1)]
#print("Argumentos da função", x1)

y=[f(x) for x in x1]
#print("Valores da função", list(y))

integral=[g(x) for x in y]
#print("As parcelas da soma da integral", integral)

print("O valor da integral definida é", (passo/2)*functools.reduce(add, integral, 0.0))
