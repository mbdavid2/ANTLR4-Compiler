function f
  params
    _result
    a
    f
  endparams

  vars
    x 1
    b 1
    z 10
  endvars

     %1 = 5
     readi %2
     z[%1] = %2
     %3 = 5
     %4 = z[%3]
     %5 = 88
     %6 = %4 + %5
     writei %6
     readi %7
     b = %7
     readf %8
     f = %8
     ifFalse b goto endif1
     %9 = 'h'
     writec %9
     writeln
     %9 = '\t'
     writec %9
     %9 = 'l'
     writec %9
     %9 = '\\'
     writec %9
     %9 = 'a'
     writec %9
     %10 = -. f
     %11 = -. %10
     %12 = -. %11
     writef %12
     writeln
  label endif1 :
     %14 = 1
     _result = %14
     return
endfunction

function fz
  params
    _result
    r
    u
  endparams

  label startwhile1 :
     %1 = 0
     %3 = r == %1
     %2 = r < %1
     %2 = %2 or %3
     %2 = not %2
     ifFalse %2 goto endwhile1
     %4 = 1
     %5 = r - %4
     r = %5
     goto startwhile1
  label endwhile1 :
     %6 = 0
     %7 = r == %6
     ifFalse %7 goto endif1
     %8 = 55555
     %9 = 1
     %10 = 4
     %11 = %9 / %10
     %13 = float %11
     pushparam %8
     pushparam %13
     call f
     popparam 
     popparam 
  label endif1 :
     %14 = 3
     %15 = r + %14
     %17 = float %15
     %16 = %17 *. u
     _result = %16
     return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 0
   %1 = float %1
   q = %1
   %ret13 = 0
   %2 = 3
   %3 = 4
   %4 = %2 + %3
   %ret10 = 0
   %5 = 4444
   %6 = 2
   %9 = float %6
   %7 = q +. %9
   pushparam 
   pushparam %5
   pushparam %7
   call fz
   popparam 
   popparam 
   popparam %ret10
   pushparam 
   pushparam %4
   pushparam %ret10
   call fz
   popparam 
   popparam 
   popparam %ret13
   q = %ret13
   %16 = 3.7
   %17 = q +. %16
   %20 = 4
   %23 = float %20
   %21 = %17 +. %23
   writef %21
   writeln
   return
endfunction


