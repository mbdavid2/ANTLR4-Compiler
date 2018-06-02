function main
  vars
    x 10
    peta 10
    a 1
    b 1
    f 1
  endvars

     %1 = 4
     %2 = 1
     peta[%1] = %2
     %3 = 5
     %4 = 0
     peta[%3] = %4
     %5 = 2312
     %5 = float %5
     f = %5
     %6 = 5
     %7 = peta[%6]
     %8 = 4
     %9 = peta[%8]
     %10 = %7 or %9
     ifFalse %10 goto endif1
     writef f
  label endif1 :
     writeln
     return
endfunction


