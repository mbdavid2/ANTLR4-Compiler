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

     %1 = 'F'
     writec %1
     %1 = 'u'
     writec %1
     %1 = 'n'
     writec %1
     %1 = 'c'
     writec %1
     %1 = 'i'
     writec %1
     %1 = 'o'
     writec %1
     %1 = 'n'
     writec %1
     %1 = ','
     writec %1
     %1 = ' '
     writec %1
     %1 = 'e'
     writec %1
     %1 = 's'
     writec %1
     %1 = 't'
     writec %1
     %1 = 'a'
     writec %1
     %1 = 'd'
     writec %1
     %1 = 'o'
     writec %1
     %1 = ' '
     writec %1
     %1 = 'a'
     writec %1
     %1 = 'r'
     writec %1
     %1 = 'r'
     writec %1
     %1 = 'a'
     writec %1
     %1 = 'y'
     writec %1
     %1 = 's'
     writec %1
     %1 = ':'
     writec %1
     %1 = ' '
     writec %1
     writeln
     %3 = 0
     i = %3
  label startwhile1 :
     %4 = 10
     %5 = i < %4
     ifFalse %5 goto endwhile1
     %6 = a1
     %7 = %6[i]
     writei %7
     %8 = ' '
     writec %8
     %8 = ' '
     writec %8
     %9 = 1
     %10 = i + %9
     i = %10
     goto startwhile1
  label endwhile1 :
     writeln
     %12 = 0
     i = %12
  label startwhile2 :
     %13 = 10
     %14 = i < %13
     ifFalse %14 goto endwhile2
     %15 = a2
     %16 = %15[i]
     writei %16
     %17 = ' '
     writec %17
     %17 = ' '
     writec %17
     %18 = 1
     %19 = i + %18
     i = %19
     goto startwhile2
  label endwhile2 :
     %20 = 0
     s = %20
  label startwhile3 :
     %21 = 10
     %22 = i < %21
     ifFalse %22 goto endwhile3
     %23 = a1
     %24 = %23[i]
     %25 = a2
     %26 = %25[i]
     %27 = %24 * %26
     %28 = s + %27
     s = %28
     %29 = 1
     %30 = i + %29
     i = %30
     goto startwhile3
  label endwhile3 :
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
     %8 = 0
     i = %8
  label startwhile2 :
     %9 = 10
     %10 = i < %9
     ifFalse %10 goto endwhile2
     %11 = v1[i]
     writei %11
     %12 = ' '
     writec %12
     %12 = ' '
     writec %12
     %13 = 1
     %14 = i + %13
     i = %14
     goto startwhile2
  label endwhile2 :
     writeln
     %16 = 0
     i = %16
  label startwhile3 :
     %17 = 10
     %18 = i < %17
     ifFalse %18 goto endwhile3
     %19 = v2[i]
     writei %19
     %20 = ' '
     writec %20
     %20 = ' '
     writec %20
     %21 = 1
     %22 = i + %21
     i = %22
     goto startwhile3
  label endwhile3 :
     writeln
     writeln
     %ret25 = 0
     %26 = &v1
     %27 = &v2
     pushparam 
     pushparam %26
     pushparam %27
     call prod_escalar
     popparam 
     popparam 
     popparam %ret25
     writei %ret25
     writeln
     return
endfunction


