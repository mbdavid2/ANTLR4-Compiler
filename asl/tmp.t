function fact
  params
    _result
    n
  endparams

  vars
    f 1
  endvars

     %1 = 1
     f = %1
  label startwhile1 :
     %2 = 1
     %4 = n == %2
     %3 = n < %2
     %3 = %3 or %4
     %3 = not %3
     ifFalse %3 goto endwhile1
     %5 = f * n
     f = %5
     %6 = 1
     %7 = n - %6
     n = %7
     goto startwhile1
  label endwhile1 :
     _result = f
     return
endfunction

function main
  vars
    max 1
    i 1
    f 1
    end 1
  endvars

     %1 = 1
     end = %1
     readi %2
     max = %2
     %4 = i == max
     %3 = i < max
     %3 = %3 or %4
     ifFalse %3 goto endif1
     %5 = 0
     end = %5
  label endif1 :
  label startwhile1 :
     %7 = not end
     ifFalse %7 goto endwhile1
     writei i
     %8 = '!'
     writec %8
     %8 = '='
     writec %8
     %ret9 = 0
     pushparam 
     pushparam i
     call fact
     popparam 
     popparam %ret9
     writei %ret9
     writeln
     %12 = i == max
     ifFalse %12 goto endif2
     %13 = 1
     end = %13
  label endif2 :
     goto startwhile1
  label endwhile1 :
     return
endfunction


