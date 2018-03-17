
;;;  This program reads a number x, fills an array of 10
;;;  elements with values x to x+9, passes it to a
;;;  function that reverses the array and computes the sum of
;;;  the elements,  and finally prints the array elements

function reverse_and_sum

  params
    _result
    b
  endparams

  vars
   i 1
   n 1
   x 1
   s 1
  endvars

  ;;; reverse array, swapping x[i] with x[n-i-1] for all i<n/2
  ;;; and add all elements in s
  n = 10                  ;;; n=10
  s = 0                   ;;; s=0
  i = 0                   ;;; i=0
  label for2 :            ;;; while (i<n/2)
  %1 = 2
  %2 = n / %1             
  %3 = i < %2
  ifFalse %3 goto endfor2
  %5 = b                  ;;; b is a pointer to a
  x = %5[i]               ;;; x = b[i]
  s = s + x               ;;; s = s + b[i]  
  %1 = 1                  ;;; b[i] = b[n-1-i]
  %1 = n - %1
  %1 = %1 - i
  %2 = %5[%1]
  %5[i] = %2 
  %5[%1] = x              ;;; b[n-1-i] = x

  s = s + %2               ;;; s = s + b[n-1-i]
  
  %2 = 1                  ;;; i = i + 1
  i = i + %2              
  goto for2               ;;; endwhile 
  label endfor2 :

  _result = s
  return
endfunction

function main
  vars
   x 1            ;;; int x, i, n, sum
   i 1
   n 1
   sum 1
   a 10           ;;; int a[10]
  endvars

  readi x
  n = 10                  ;;; n=10

  ;;; fill array with numbers from x to x+9
  i = 0                    ;;; i=0
  label for1 :             ;;; while (i<n)
  %1 = i < n
  ifFalse %1 goto endfor1

  %2 = x + i               ;;; a[i] = x+i 
  a[i] = %2

  %2 = 1                   ;;; i = i + 1
  i = i + %2              
  goto for1                ;;; endwhile 
  label endfor1 :

  ;;; call function    
  pushparam
  %1 = &a                  ;;; pass array address (reference parameter)
  pushparam %1
  call reverse_and_sum
  popparam
  popparam sum             ;;; sum = reverse_and_sum(a)
 
  writei sum  ;;; print sum
  writeln

  ;;; print array elements
  i = 0                    ;;; i=0
  label for3 :             ;;; while (i<n)
  %1 = i < n
  ifFalse %1 goto endfor3
  
  %2 = a[i]                ;;; write a[i]
  writei %2
  %2 = ' '                 ;;; write ' ' 
  writec %2

  %2 = 1                   ;;; i = i + 1
  i = i + %2              
  goto for3                ;;; endwhile 
  label endfor3 :

  writeln

  return
endfunction
