function f1
  vars
    x1 1
    y1 1
  endvars

     %1 = 'e'
     writec %1
     %1 = 'r'
     writec %1
     %1 = 'r'
     writec %1
     %1 = '!'
     writec %1
     %1 = '!'
     writec %1
     writeln
     %2 = 2
     %3 = y1 * %2
     %4 = x1 == %3
     ifFalse %4 goto endif1
     %5 = 3
     %6 = y1 + %5
     x1 = %6
     %7 = y1 * x1
     %8 = x1 + %7
     y1 = %8
  label endif1 :
     return
endfunction

function main
  vars
    x1 1
  endvars

     %1 = 0
     x1 = %1
     %2 = 1
     %3 = x1 == %2
     ifFalse %3 goto endif1
     call f1
  label endif1 :
     %4 = 4
     %5 = 5
     %6 = %4 * %5
     %7 = 6
     %8 = %6 + %7
     x1 = %8
     writei x1
     writeln
     return
endfunction


