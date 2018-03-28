function f2
  vars
    x2 1
    y2 1
  endvars

     %1 = 0
     x2 = %1
     y2 = x2
     %2 = 3
     %3 = y2 * %2
     %4 = x2 == %3
     ifFalse %4 goto endif3
     %5 = 5
     %6 = y2 * %5
     %7 = 3
     %8 = %6 + %7
     x2 = %8
     %9 = 1
     %10 = %9 + y2
     %11 = 1
     %12 = %10 + %11
     y2 = %12
     %13 = 1
     %14 = x2 + %13
     %15 = 2
     %16 = y2 * %15
     %17 = %14 == %16
     ifFalse %17 goto endif1
     %18 = 'o'
     writec %18
     %18 = 'k'
     writec %18
  label endif1 :
     %19 = 1
     %20 = 1
     %21 = %19 + %20
     %22 = y2 == %21
     ifFalse %22 goto endif2
     %23 = 6
     %24 = x2 * %23
     writei %24
  label endif2 :
  label endif3 :
     return
endfunction

function main
     %1 = 7
     %2 = 7
     %3 = %1 == %2
     ifFalse %3 goto endif1
     call f2
  label endif1 :
     %4 = 'b'
     writec %4
     %4 = 'y'
     writec %4
     %4 = 'e'
     writec %4
     writeln
     return
endfunction


