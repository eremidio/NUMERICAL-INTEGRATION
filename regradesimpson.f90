program regradesimpson

implicit none

real(kind=kind(1.0d0))::x, a, b, passo, f, s, simp
integer::i, n, h, k

interface

function k(i)
integer::fatork
integer, intent(in)::i
endfunction k

function f(y) 
real(kind=kind(1.0d0))::fun
real(kind=kind(1.0d0)), intent(in)::y
endfunction f
endinterface

Write(*,*) "Qual o limite superior da integral definida?"
read(*,*)b
Write(*,*) "Qual o limite inferior da integral definida?"
read(*,*)a
Write(*,*) "Quantos passos você deseja utilizar? (Explicite o valor de n)"
read(*,*)n

!Parâmetros de cálculo da integral
h=2*n
passo=(b-a)/h
s=f(a)+f(b)

write(*,*)a, f(a)

do i=1,h-1
x=a+passo*i

write(*,*)x, f(x)

s=s+k(i)*f(x)

simp=(s*passo)/3
enddo

write(*,*)b, f(b)

write(*,*) "A integral definida é", simp
end program regradesimpson

function k(i) result(fatork)
!Esta função deve permanecer inalterada
!Resultado da função
integer::fatork
!Variáveis
integer, intent(in)::i

!Definição
if(mod(i,2)==1) then
fatork=4
elseif(mod(i,2)==0) then
fatork=2
endif

endfunction k


function f(y) result(fun)
!Este programa pode ser reutilizado fazendo-se modificação da função f(y) a ser integrada
!Se a função for descontínua podemos usar o comando if para específicá-la

!Resultado da função
real(kind=kind(1.0d0))::fun
!Variaveis
real(kind=kind(1.0d0)), intent(in)::y
!DEfinição
fun=(y**3*cos(y/2) + 0.5)*sqrt(4-y**2)
endfunction f
