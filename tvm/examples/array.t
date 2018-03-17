
;;;  This program reads a number x, fills an array of 10
;;;  elements with values x to x+9, reverses the array,
;;;  and finally prints the array elements

function main
  vars
   x 1            ;;; int x, i, n
   i 1
   n 1
   a 10           ;;; int a[10] 
  endvars

  readi x
  n = 10                  ;;; n=10

  ;;; fill array with numbers from x to x+9
  i = 0                   ;;; i=0
  label for1 :             ;;; while (i<n)
  %1 = i < n
  ifFalse %1 goto endfor1

  %2 = x + i              ;;; a[i] = x+i 
  a[i] = %2

  %2 = 1                  ;;; i = i + 1
  i = i + %2              
  goto for1               ;;; endwhile 
  label endfor1 :

  ;;; reverse array, swapping x[i] with x[n-i-1] for all i<n/2
  i = 0                   ;;; i=0
  label for2 :             ;;; while (i<n/2)
  %1 = 2
  %2 = n / %1
  %3 = i < %2
  ifFalse %3 goto endfor2
  x = a[i]                ;;; x = a[i]
  %1 = 1                  ;;; a[i] = a[n-1-i]
  %1 = n - %1
  %1 = %1 - i
  %2 = a[%1]
  a[i] = %2 

  a[%1] = x               ;;; a[n-1-i] = x

  %2 = 1                  ;;; i = i + 1
  i = i + %2              
  goto for2               ;;; endwhile 
  label endfor2 :

  ;;; print array elements
  i = 0                   ;;; i=0
  label for3 :             ;;; while (i<n)
  %1 = i < n
  ifFalse %1 goto endfor3
  
  %2 = a[i]               ;;; write a[i]
  writei %2
  %2 = ' '                ;;; write ' ' 
  writec %2

  %2 = 1                  ;;; i = i + 1
  i = i + %2              
  goto for3               ;;; endwhile 
  label endfor3 :

  writeln

  return
endfunction
