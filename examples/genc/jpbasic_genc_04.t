function f
  vars
    a 1
    b 1
  endvars

     readi a
     %1 = 10
     %2 = a == %1
     ifFalse %2 goto endif1
     %3 = 4
     %4 = 0
     %5 = %3 * %4
     %6 = 3
     %7 = %5 + %6
     a = %7
     call f
  label endif1 :
     %8 = 9
     %9 = a + %8
     b = %9
     %10 = 2
     %11 = a * %10
     %12 = b + %11
     writei %12
     writeln
     return
endfunction

function main
  vars
    a 1
  endvars

     readi a
     %1 = 3
     %2 = a == %1
     ifFalse %2 goto endif1
     call f
  label endif1 :
     %3 = '.'
     writec %3
     writeln
     return
endfunction


