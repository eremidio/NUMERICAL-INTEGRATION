{-
VAMOS ESCREVER UM PROGRAMA EM HASKELL QUE CALCULA INTEGRAIS DEFINIDAS USANDO A REGRA DO TRAPÉZIO
PARA FUNÇÕES DE UMA VARIÁVEL.

-}

--FUNÇÕES 
--Função a ser integrada. Esta função pode ser livremente alterada pelo usuário.
f::Double-> Double
f x = ((x**3)*cos(x/2)+(1/2))*sqrt(4.0-(x**2))

--Função que calcula uma lista de fatores multiplicativos para a soma da integral. Não alterar esta função.
factor::Integer->Integer->Double
factor i j
    | i==0 = 1.0
    | i/=j = 2.0
    | i==j = 1.0
   

factor_array::Integer->[Double]
factor_array n  = map (\i-> factor i n)[0..n]

                   
--Função que calcula os valores dos argumentos da função a ser integrada. Não alterar esta função.
value_array::Integer->Double->Double->[Double]
value_array n x a = map (\i -> a+fromInteger(i)*x)[0..n] -- n é o index do termo na lista, x é o tamanho do subintervalo e a o limite inferior do intervalo

--Função que calcula os valores das funções a serem integrada. Não alterar esta função.
function_value_array::(Double->Double)->[Double]->[Double]
function_value_array f [] = [] 
function_value_array f (x:xs) = f x : function_value_array f xs

--Função que calcula os valores das parcelas da soma da integral definida. Não alterar esta função.
integral_value_array::[Double]->[Double]->[Double]
integral_value_array _ [] = []
integral_value_array [] _ = []
integral_value_array (x:xs)(y:ys) = x*y: integral_value_array xs ys


--FUNÇÃO PRINCIPAL
main::IO()
main = do
 --Recebendo input do usuário
 putStrLn("Digite o limite inferior do intervalo de integração:")
 n1<-getLine
 let a = read n1::Double
 putStrLn("Digite o limite superior do intervalo de integração:")
 n2<-getLine
 let b = read n2::Double
 putStrLn("Digite quantos passos você deseja usar na integração:")
 n3<-getLine
 let n = read n3::Integer

 --Definindo as variáveis usadas no calculo
 --Passo de integração
 let step = (b-a)/(fromInteger(n))

 --Array de coeficientes multiplicativos
 let array1 = value_array n step a
 let array2 = function_value_array f array1
 let array3 = factor_array n
 let array4 = integral_value_array array2 array3

 --Exibindo o resultado
 --TESTE USE UM {- -} APÓS O MESMO
{- print(step)
 print(array1)
 print(array2)
 print(array3)
 print(array4)-}

 --Exibindo o resultado
 putStrLn("O valor da integral definida é "++show((foldr(+) 0 array4)*step/2)++".")

