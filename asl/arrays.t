function search
  params
    _result
    needle
    stack
  endparams

  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label startfor1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endfor1
     %6 = stack
     %7 = %6[i]
     %8 = %7 == needle
     ifFalse %8 goto endif1
     _result = i
     return
  label endif1 :
     %4 = 1
     %5 = i + %4
     i = %5
     goto startfor1
  label endfor1 :
     %9 = 1
     %10 = - %9
     _result = %10
     return
endfunction

function main
  vars
    arr 10
    i 1
    find 1
  endvars

     %1 = 0
     i = %1
  label startfor1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endfor1
     readi %6
     arr[i] = %6
     %4 = 1
     %5 = i + %4
     i = %5
     goto startfor1
  label endfor1 :
     readi %7
     find = %7
     %ret8 = 0
     %10 = &arr
     pushparam 
     pushparam find
     pushparam %10
     call search
     popparam 
     popparam 
     popparam %ret8
     i = %ret8
     %11 = 'I'
     writec %11
     %11 = 'n'
     writec %11
     %11 = 'd'
     writec %11
     %11 = 'e'
     writec %11
     %11 = 'x'
     writec %11
     %11 = ':'
     writec %11
     %11 = ' '
     writec %11
     writei i
     writeln
     return
endfunction


