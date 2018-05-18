function main
  vars
    a 1
    b 1
    end 1
    pi 1
  endvars

     %1 = 1
     end = %1
     %2 = 0
     %3 = %2 and end
     ifFalse %3 goto endif1
     %4 = 'a'
     writec %4
  label endif1 :
     return
endfunction


