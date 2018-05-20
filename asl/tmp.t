function f
  params
    _result
    a
    b
  endparams

  vars
    x 1
    y 1
    z 10
  endvars

     %4 = 34
     x = %4
     %11 =  == x
     %10 =  < x
     %10 = %10 or %11
     %10 = not %10
     ifFalse %10 goto endif1
     %12 = 78
     x = %12
     writef b
     writeln
  label endif1 :
     writei 
     writeln
     %17 = 1
     _result = %17
     return
endfunction

function fz
  params
    r
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
     return
endfunction

function main
  vars
    a 1
  endvars

     %ret3 = 3
     pushparam 
     pushparam %1
     pushparam %2
     call f
     popparam 
     popparam 
     popparam %ret3
     ifFalse %ret3 goto endif1
     %4 = 3.7
     %6 = float a
     %5 = %6 +. %4
     %8 = 4
     %11 = float %8
     %9 = %5 +. %11
     writef %9
     writeln
  label endif1 :
     return
endfunction


