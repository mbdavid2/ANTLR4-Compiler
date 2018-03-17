
;;; This program reads an integer and computes
;;; its factorial using a recursive function 

function main
  vars
   x 1            ;;; int x, y
   y 1
  endvars

  readi x         ;;; read x
  pushparam       ;;; make space for function result
  pushparam x     ;;; pass parameter x
  call fact       ;;; y = fact(x)
  popparam        ;;; remove passed parameter x
  popparam y      ;;; pop result and store in y
  writei y        ;;; print y
  writeln
  return
endfunction

function fact
  params
    _result      ;;; _result is an internal variable used to 
                 ;;; access the result position in the stack
    n            ;;; received parameter
  endparams

  vars
    f 1          ;;; local variable
  endvars

  %1 = 0
  %1 = n == %1             ;;; compute %1 = (n==0)
  ifFalse %1 goto else1    
  f = 1                    ;;; n==0, so f=1
  goto endif1

  label else1 :             ;;; n!=0, prepare recursive call
  pushparam                ;;; space for function result
  %2 = 1                   ;;; %2 = n-1
  %2 = n - %2           
  pushparam %2             ;;; pass n-1 as parameter
  call fact                ;;; f = fact(n-1)
  popparam                 ;;; remove passed parameter n-1
  popparam f               ;;; pop result and store it in f
  f = n * f                ;;; f = n * f
  label endif1 :            
  _result = f              ;;; store f in space reserved for result
  return
endfunction

