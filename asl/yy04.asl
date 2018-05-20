function f1
  params
    a
    b
  endparams

  vars
    c 1
    d 1
    found 1
  endvars

     %1 = 0
     found = %1
     %2 = 0.7
     %4 = float a
     %3 = %4 +. %2
     c = %3
     %6 = 0
     d = %6
     %7 = a + d
     %9 = %7 == c
     %8 = %7 < c
     %8 = %8 or %9
     %8 = not %8
     %10 = not found
     %11 = %8 or %10
     ifFalse %11 goto endif1
  label startwhile1 :
     %12 = 0
     %14 = b == %12
     %13 = b < %12
     %13 = %13 or %14
     %13 = not %13
     ifFalse %13 goto endwhile1
     %15 = 1
     %16 = b - %15
     b = %16
     %17 = 1
     found = %17
     goto startwhile1
  label endwhile1 :
  label endif1 :
     %18 = 11
     %20 = b == %18
     %19 = b < %18
     %19 = %19 or %20
     ifFalse %19 goto endif2
     %21 = 2
     %23 = float %21
     %22 = %23 *. c
     %25 = 1
     %28 = float %25
     %26 = %22 +. %28
     c = %26
  label endif2 :
     writef c
     writeln
     return
endfunction

function main
  vars
    a 1
    b 1
  endvars

   %1 = 4
   a = %1
   %2 = 2
   %3 = %2 * a
   %4 = 1
   %5 = %3 + %4
   b = %5
   %6 = 3
   %7 = %6 + b
   pushparam b
   pushparam %7
   call f1
   popparam 
   popparam 
   return
endfunction


