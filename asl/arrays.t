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
     %6 = 'V'
     writec %6
     %6 = 'a'
     writec %6
     %6 = 'l'
     writec %6
     %6 = 'o'
     writec %6
     %6 = 'r'
     writec %6
     %6 = ' '
     writec %6
     %6 = 'u'
     writec %6
     %6 = ':'
     writec %6
     %6 = ' '
     writec %6
     writef u
     writeln
     %8 = 0
     %9 = r == %8
     ifFalse %9 goto endif1
     %10 = 55555
     %11 = 1
     %12 = 4
     %13 = %11 / %12
     pushparam %10
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
   q = %1
   %2 = 'V'
   writec %2
   %2 = 'a'
   writec %2
   %2 = 'l'
   writec %2
   %2 = 'o'
   writec %2
   %2 = 'r'
   writec %2
   %2 = ' '
   writec %2
   %2 = 'q'
   writec %2
   %2 = ':'
   writec %2
   %2 = ' '
   writec %2
   writef q
   writeln
   %4 = 2
   %7 = float %4
   %5 = q +. %7
   q = %5
   %8 = 'V'
   writec %8
   %8 = 'a'
   writec %8
   %8 = 'l'
   writec %8
   %8 = 'o'
   writec %8
   %8 = 'r'
   writec %8
   %8 = ' '
   writec %8
   %8 = 'q'
   writec %8
   %8 = ':'
   writec %8
   %8 = ' '
   writec %8
   writef q
   writeln
   %ret15 = 0
   %10 = 3
   %11 = 4
   %12 = %10 + %11
   %ret14 = 0
   %13 = 4444
   pushparam 
   pushparam %13
   pushparam q
   call fz
   popparam 
   popparam 
   popparam %ret14
   pushparam 
   pushparam %12
   pushparam %ret14
   call fz
   popparam 
   popparam 
   popparam %ret15
   q = %ret15
   %16 = 3.7
   %17 = q +. %16
   %20 = 4
   %23 = float %20
   %21 = %17 +. %23
   writef %21
   writeln
   return
endfunction


