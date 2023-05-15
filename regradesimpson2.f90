!Vamos escrever um programa que calcula uma integral definida usando coarrays para aumentar a velocidade de execução

program regradesimpson2
implicit none

!Definindo variáveis
real(kind=kind(1.0d0)), codimension[*]::x, f_x, soma !Poderia usar no lugar o comando: real(kind=kind(1.0d0))::x[*]
real(kind=kind(1.0d0))::a, b, k, f, passo, simp
integer::i, n


!Interface com procedimentos externos
interface

function f(y) 
real(kind=kind(1.0d0))::fun
real(kind=kind(1.0d0)), intent(in)::y
endfunction f

function k(i)
real(kind=kind(1.0d0))::fatork
integer, intent(in)::i
endfunction k

end interface



!Entrada de dados
Write(*,*) "Qual o limite superior da integral definida?"
read(*,*)b
Write(*,*) "Qual o limite inferior da integral definida?"
read(*,*)a
Write(*,*) "Quantos passos você deseja utilizar? (Explicite o valor de n)"
read(*,*)n

!Definição de parâmetros usados no cálculo
passo=(b-a)/real(2*n)
soma=f(a)+f(b)

write(*,*)a, f(a)

!Calculando a soma parcial da integral

do i=1,2*n-1,1
 x[this_image()]=a+passo*i
 f_x[this_image()]=f(x)
 write(*,*)x[this_image()], f_x[this_image()]
 soma[this_image()]=soma+k(i)*f(x)
end do
write(*,*)b, f(b)

!Calculando a integral
simp=(soma*passo)/3
write(*,*) "A integral definida é", simp




end program regradesimpson2



function f(y) result(fun)
!Este programa pode ser reutilizado fazendo-se modificação da função f(y) a ser integrada
!Se a função for descontínua podemos usar o comando if para específicá-la

!Definindo variáveis
real(kind=kind(1.0d0))::fun
real(kind=kind(1.0d0)), intent(in)::y
!Definição da função
fun=(y**3*cos(y/2) + 0.5)*sqrt(4-y**2)
endfunction f

function k(i) result(fatork)
!Esta função deve permanecer inalterada
!Resultado da função
real(kind=kind(1.0d0))::fatork
!Variáveis
integer, intent(in)::i

!Definição
if(mod(i,2)==1) then
fatork=4.0d0
elseif(mod(i,2)==0) then
fatork=2.0d0
endif

endfunction k
