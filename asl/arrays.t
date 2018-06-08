function fz
  params
    r
    arr
    ch
    lit
  endparams

   %1 = 3
   %2 = arr
   %3 = %2[%1]
   writec %3
   writeln
   writec ch
   writeln
   %6 = 'C'
   writec %6
   %6 = 'H'
   writec %6
   %6 = 'L'
   writec %6
   %6 = 'O'
   writec %6
   %6 = 'A'
   writec %6
   %6 = 'D'
   writec %6
   %6 = ' '
   writec %6
   %6 = 'S'
   writec %6
   %6 = 'O'
   writec %6
   %6 = 'N'
   writec %6
   %6 = ' '
   writec %6
   %6 = 'L'
   writec %6
   %6 = 'O'
   writec %6
   %6 = 'S'
   writec %6
   %6 = ' '
   writec %6
   %6 = 'P'
   writec %6
   %6 = 'A'
   writec %6
   %6 = 'D'
   writec %6
   %6 = 'R'
   writec %6
   %6 = 'E'
   writec %6
   %6 = 'S'
   writec %6
   writeln
   %8 = 3
   %9 = arr
   %10 = 'y'
   %9[%8] = %10
   return
endfunction

function main
  vars
    x 10
    peta 10
    a 1
    b 1
    f 1
    c 1
  endvars

     %1 = 4
     %2 = 1
     peta[%1] = %2
     %3 = 5
     %4 = 1
     peta[%3] = %4
     %5 = 3
     readc %6
     x[%5] = %6
     %7 = 6
     %8 = 3
     %9 = x[%8]
     %10 = 'z'
     %11 = %9 == %10
     peta[%7] = %11
     %12 = 2312
     f = %12
     %13 = 5
     %14 = peta[%13]
     %15 = 4
     %16 = peta[%15]
     %17 = %14 and %16
     %18 = 6
     %19 = peta[%18]
     %20 = %17 or %19
     ifFalse %20 goto else2
     %21 = 0
     %22 = 3
     %23 = x[%22]
     %24 = 'e'
     pushparam 
     pushparam %21
     pushparam x
     pushparam %23
     pushparam %24
     call fz
     popparam 
     popparam 
     popparam 
     popparam 
     popparam 
     %29 = 3
     %30 = x[%29]
     writec %30
     writeln
     goto endif1
  label else2 :
     %32 = 'u'
     writec %32
  label endif1 :
     writeln
     return
endfunction


