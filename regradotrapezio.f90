program regradotrapezio
 implicit none
real(kind=kind(1.0d0))::x,f, s, passo, a, b, trap
integer::i, n, k, j

interface
function f(y) 
real(kind=kind(1.0d0))::fun
real(kind=kind(1.0d0)), intent(in)::y
endfunction f
endinterface

write(*,*) "Quantos passos você deseja utilizar?"
read(*,*)n
write(*,*) "Qual o limite inferior de integração?"
read(*,*)a
write(*,*) "Qual o limite superior de integração?"
read(*,*)b

passo=(b-a)/n

s=f(a)+f(b)
write(*,*)a, f(a)
do i=1,n-1
x=a+passo*i


write(*,*)x, f(x)

s=s+2*f(x)
trap=s*passo/2
end do
write(*,*)b, f(b)

write(*,*) "A integral definida é", trap


end program regradotrapezio

function f(y) result(fun)
!Este programa pode ser reutilizado fazendo-se modificação da função f(y) a ser integrada
!Se a função for descontínua podemos usar o comando if para específicá-la

!Resultado da função
real(kind=kind(1.0d0))::fun
!Variaveis
real(kind=kind(1.0d0)), intent(in)::y
!DEfinição
fun=y**2
endfunction f
