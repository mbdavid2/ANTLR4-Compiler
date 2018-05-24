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
   %2 = 0
   %2 = float %2
   q = %2
   %ret14 = 0
   %3 = 3
   %4 = 4
   %5 = %3 + %4
   %ret11 = 0
   %6 = 4444
   %7 = 2
   %10 = float %7
   %8 = q +. %10
   pushparam 
   pushparam %6
   pushparam %8
   call fz
   popparam 
   popparam 
   popparam %ret11
   pushparam 
   pushparam %5
   pushparam %ret11
   call fz
   popparam 
   popparam 
   popparam %ret14
   q = %ret14
   %17 = 3.7
   %18 = q +. %17
   %21 = 4
   %24 = float %21
   %22 = %18 +. %24
   writef %22
   writeln
   return
endfunction


