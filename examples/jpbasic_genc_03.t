function f
  vars
    a 1
    b 1
  endvars

     readi a
     %1 = 10
     %2 = a == %1
     ifFalse %2 goto endif1
     %3 = 3
     a = %3
  label endif1 :
     %4 = 67
     %5 = a + %4
     b = %5
     %6 = b + a
     %7 = 1
     %8 = %6 + %7
     writei %8
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


