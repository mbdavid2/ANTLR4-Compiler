function f
  params
    a
  endparams

   %1 = 5
   %2 = 5
   %3 = a[%2]
   %4 = 10
   %7 = float %4
   %5 = %3 *. %7
   a[%1] = %5
   return
endfunction

function main
  vars
    b 10
    c 10
  endvars

   %1 = 5
   readf %2
   b[%1] = %2
   %3 = 7
   %4 = 5
   %5 = b[%4]
   c[%3] = %5
   %6 = 5
   %7 = b[%6]
   writef %7
   writeln
   %9 = 7
   %10 = c[%9]
   writef %10
   writeln
   pushparam b
   call f
   popparam 
   %13 = 5
   %14 = b[%13]
   writef %14
   writeln
   %16 = 7
   %17 = c[%16]
   writef %17
   writeln
   return
endfunction


