
;;; This program computes number "e" with a precision "eps"
;;; using the formula e = sum 1/(i!)  for all i>0
  
function main
  vars
   e 1            ;;; float e, eant, eps, f
   eant 1
   eps 1
   f 1
   i 1            ;;; int i
  endvars

  eant = 0.0
  e = 1.0
  eps = 0.00001
  f = 1.0
  i = 1

  label while1 :      ;;; while (eps < e-eant)
  %1 = e -. eant
  %1 = eps <. %1
  ifFalse %1 goto endwhile1
  eant = e
  
  %2 = 1.0           ;;; e = e + 1.0/f
  %2 = %2 /. f       ;;; (e and f are float, note float 
  e = e +. %2        ;;; operations "+." and "/.")

  %2 = 1             ;;; i = i + 1
  i = i + %2         ;;; (i is int -> integer addition "+")

  %3 = float i       ;;; f = f * i
  f = f *. %3        ;;; (i is converted to float before
                     ;;; performing a float product "*.")

  goto while1
  label endwhile1 :   ;;; endwhile

  writef e
  writeln
  
  return
endfunction
