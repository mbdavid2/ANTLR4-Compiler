function mul
  params
    a
    b
  endparams

  vars
    x 1
    y 1
  endvars

   writei a
   %1 = 'H'
   writec %1
   %1 = 'o'
   writec %1
   %1 = 'l'
   writec %1
   %1 = 'a'
   writec %1
   return
endfunction

function main
  vars
    x 1
    y 1
  endvars

   readi x
   readi y
   %1 = 'x'
   writec %1
   %1 = '*'
   writec %1
   %1 = 'y'
   writec %1
   %1 = '*'
   writec %1
   %1 = '2'
   writec %1
   %1 = '='
   writec %1
   pushparam 
   pushparam x
   pushparam y
   call mul
   popparam 
   %2 = 2
   %3 =  * %2
   writei %3
   %4 = '.'
   writec %4
   writeln
   return
endfunction


