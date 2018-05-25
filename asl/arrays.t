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
   %ret3 = 0
   pushparam 
   pushparam max
   call fact
   popparam 
   popparam %ret3
   writei %ret3
   writeln
   return
endfunction


