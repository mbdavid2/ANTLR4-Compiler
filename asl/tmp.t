function prod_escalar
  params
    _result
    a1
    a2
  endparams

  vars
    i 1
    s 1
  endvars

     %1 = 0
     s = %1
  label startwhile1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endwhile1
     %4 = a1
     %5 = %4[i]
     %6 = a2
     %7 = %6[i]
     %8 = %5 * %7
     %9 = s + %8
     s = %9
     %10 = 1
     %11 = i + %10
     i = %11
     goto startwhile1
  label endwhile1 :
     _result = s
     return
endfunction

function main
  vars
    i 1
    v1 10
    v2 10
  endvars

     %1 = 0
     i = %1
  label startwhile1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endwhile1
     %4 = - i
     v1[i] = %4
     %5 = i * i
     v2[i] = %5
     %6 = 1
     %7 = i + %6
     i = %7
     goto startwhile1
  label endwhile1 :
     %ret8 = 0
     pushparam 
     pushparam v1
     pushparam v2
     call prod_escalar
     popparam 
     popparam 
     popparam %ret8
     writei %ret8
     writeln
     return
endfunction


