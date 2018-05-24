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

     f = float f
     %1 = 5
     readi %2
     z[%1] = %2
     %3 = 5
     %4 = z[%3]
     writei %4
     readi %5
     b = %5
     readf %6
     f = %6
     ifFalse b goto endif1
     %7 = 'h'
     writec %7
     writeln
     %7 = '\t'
     writec %7
     %7 = 'l'
     writec %7
     %7 = '\\'
     writec %7
     %7 = 'a'
     writec %7
     %8 = -. f
     %9 = -. %8
     %10 = -. %9
     writef %10
     writeln
  label endif1 :
     %12 = 1
     _result = %12
     return
endfunction

function fz
  params
    _result
    r
    u
  endparams

     u = float u
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
     pushparam %8
     pushparam %11
     call f
     popparam 
     popparam 
  label endif1 :
     %12 = 3
     %13 = r + %12
     %15 = float %13
     %14 = %15 *. u
     _result = %14
     return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 0
   q = %1
   %ret11 = 0
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
   popparam %ret11
   q = %ret11
   %12 = 3.7
   %13 = q +. %12
   %16 = 4
   %19 = float %16
   %17 = %13 +. %19
   writef %17
   writeln
   return
endfunction


