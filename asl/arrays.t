function main
  vars
    a 1
    b 1
    f 1
  endvars

     %1 = 1.0
     %2 = 2
     %5 = float %2
     %3 = %1 /. %5
     %6 = 3
     %7 = - %6
     %8 = %3
     %9 = %7
     %16 = 0
     %13 = %7 < %16
     ifFalse %13 goto salu21
     %9 = - %9
  label salu21 :
     %14 = 1
     %10 = 0
     %11 = 1.0
  label startwhile1 :
     %12 = %10 < %9
     ifFalse %12 goto endwhile1
     %11 = %11 *. %8
     %10 = %10 + %14
     goto startwhile1
  label endwhile1 :
     ifFalse %13 goto salu2_tokyo_drift2
     %15 = 1.0
     %11 = %15 /. %11
  label salu2_tokyo_drift2 :
     f = %11
     writef f
     writeln
     return
endfunction


