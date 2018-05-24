function f
  params
    _result
    a
    f
  endparams

  vars
    x 1
    b 1
    z 10
  endvars

   %1 = 'f'
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
   %1 = ' '
   writec %1
   %1 = 'f'
   writec %1
   %1 = ','
   writec %1
   %1 = ' '
   writec %1
   %1 = 'V'
   writec %1
   %1 = 'a'
   writec %1
   %1 = 'l'
   writec %1
   %1 = 'o'
   writec %1
   %1 = 'r'
   writec %1
   %1 = 'e'
   writec %1
   %1 = 's'
   writec %1
   %1 = ' '
   writec %1
   %1 = 'r'
   writec %1
   %1 = 'e'
   writec %1
   %1 = 'c'
   writec %1
   %1 = 'i'
   writec %1
   %1 = 'b'
   writec %1
   %1 = 'i'
   writec %1
   %1 = 'd'
   writec %1
   %1 = 'o'
   writec %1
   %1 = 's'
   writec %1
   %1 = ':'
   writec %1
   %1 = ' '
   writec %1
   writei a
   %2 = ' '
   writec %2
   %2 = ' '
   writec %2
   %2 = ' '
   writec %2
   writef f
   writeln
   %4 = 1
   _result = %4
   return
endfunction

function fz
  params
    _result
    r
    u
  endparams

   %1 = 'f'
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
   %1 = ' '
   writec %1
   %1 = 'f'
   writec %1
   %1 = 'z'
   writec %1
   %1 = ','
   writec %1
   %1 = ' '
   writec %1
   %1 = 'V'
   writec %1
   %1 = 'a'
   writec %1
   %1 = 'l'
   writec %1
   %1 = 'o'
   writec %1
   %1 = 'r'
   writec %1
   %1 = 'e'
   writec %1
   %1 = 's'
   writec %1
   %1 = ' '
   writec %1
   %1 = 'r'
   writec %1
   %1 = 'e'
   writec %1
   %1 = 'c'
   writec %1
   %1 = 'i'
   writec %1
   %1 = 'b'
   writec %1
   %1 = 'i'
   writec %1
   %1 = 'd'
   writec %1
   %1 = 'o'
   writec %1
   %1 = 's'
   writec %1
   %1 = ':'
   writec %1
   %1 = ' '
   writec %1
   writei r
   %2 = ' '
   writec %2
   %2 = ' '
   writec %2
   %2 = ' '
   writec %2
   writef u
   writeln
   %4 = 0
   r = %4
   %5 = 2
   %5 = float %5
   u = %5
   %6 = 55555
   %7 = 1.0
   %8 = 4
   %11 = float %8
   %9 = %7 /. %11
   pushparam %6
   pushparam %9
   call f
   popparam 
   popparam 
   %14 = 'f'
   writec %14
   %14 = 'u'
   writec %14
   %14 = 'n'
   writec %14
   %14 = 'c'
   writec %14
   %14 = 'i'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 'n'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'f'
   writec %14
   %14 = 'z'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'd'
   writec %14
   %14 = 'e'
   writec %14
   %14 = 's'
   writec %14
   %14 = 'p'
   writec %14
   %14 = 'u'
   writec %14
   %14 = 'e'
   writec %14
   %14 = 's'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'd'
   writec %14
   %14 = 'e'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'l'
   writec %14
   %14 = 'l'
   writec %14
   %14 = 'a'
   writec %14
   %14 = 'm'
   writec %14
   %14 = 'a'
   writec %14
   %14 = 'd'
   writec %14
   %14 = 'a'
   writec %14
   %14 = ','
   writec %14
   %14 = ' '
   writec %14
   %14 = 'V'
   writec %14
   %14 = 'a'
   writec %14
   %14 = 'l'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 'r'
   writec %14
   %14 = 'e'
   writec %14
   %14 = 's'
   writec %14
   %14 = ' '
   writec %14
   %14 = 'r'
   writec %14
   %14 = 'e'
   writec %14
   %14 = 'c'
   writec %14
   %14 = 'i'
   writec %14
   %14 = 'b'
   writec %14
   %14 = 'i'
   writec %14
   %14 = 'd'
   writec %14
   %14 = 'o'
   writec %14
   %14 = 's'
   writec %14
   %14 = ':'
   writec %14
   %14 = ' '
   writec %14
   writei r
   %15 = ' '
   writec %15
   %15 = ' '
   writec %15
   %15 = ' '
   writec %15
   writef u
   writeln
   %17 = 3
   %18 = r + %17
   %20 = float %18
   %19 = %20 *. u
   u = %19
   %22 = 'R'
   writec %22
   %22 = 'e'
   writec %22
   %22 = 's'
   writec %22
   %22 = 'u'
   writec %22
   %22 = 'l'
   writec %22
   %22 = 't'
   writec %22
   %22 = 'a'
   writec %22
   %22 = 'd'
   writec %22
   %22 = 'o'
   writec %22
   %22 = ' '
   writec %22
   %22 = 'o'
   writec %22
   %22 = 'p'
   writec %22
   %22 = 'e'
   writec %22
   %22 = 'r'
   writec %22
   %22 = 'a'
   writec %22
   %22 = 'c'
   writec %22
   %22 = 'i'
   writec %22
   %22 = 'o'
   writec %22
   %22 = 'n'
   writec %22
   %22 = ' '
   writec %22
   %22 = 'u'
   writec %22
   %22 = ' '
   writec %22
   %22 = '('
   writec %22
   %22 = 'l'
   writec %22
   %22 = 'o'
   writec %22
   %22 = ' '
   writec %22
   %22 = 'q'
   writec %22
   %22 = 'u'
   writec %22
   %22 = 'e'
   writec %22
   %22 = ' '
   writec %22
   %22 = 'r'
   writec %22
   %22 = 'e'
   writec %22
   %22 = 't'
   writec %22
   %22 = 'o'
   writec %22
   %22 = 'r'
   writec %22
   %22 = 'n'
   writec %22
   %22 = 'a'
   writec %22
   %22 = ')'
   writec %22
   %22 = ':'
   writec %22
   %22 = ' '
   writec %22
   writef u
   writeln
   %24 = 3
   %25 = r + %24
   %27 = float %25
   %26 = %27 *. u
   _result = %26
   return
endfunction

function main
  vars
    a 1
    q 1
  endvars

   %1 = 0
   %1 = float %1
   q = %1
   %2 = 'P'
   writec %2
   %2 = 'r'
   writec %2
   %2 = 'i'
   writec %2
   %2 = 'm'
   writec %2
   %2 = 'e'
   writec %2
   %2 = 'r'
   writec %2
   %2 = ' '
   writec %2
   %2 = 'r'
   writec %2
   %2 = 'e'
   writec %2
   %2 = 't'
   writec %2
   %2 = 'u'
   writec %2
   %2 = 'r'
   writec %2
   %2 = 'n'
   writec %2
   %2 = ' '
   writec %2
   %2 = 'd'
   writec %2
   %2 = 'e'
   writec %2
   %2 = ' '
   writec %2
   %2 = 'q'
   writec %2
   %2 = ':'
   writec %2
   %2 = ' '
   writec %2
   writef q
   writeln
   %ret15 = 0
   %4 = 3
   %5 = 4
   %6 = %4 + %5
   %ret12 = 0
   %7 = 4444
   %8 = 2
   %11 = float %8
   %9 = q +. %11
   pushparam 
   pushparam %7
   pushparam %9
   call fz
   popparam 
   popparam 
   popparam %ret12
   pushparam 
   pushparam %6
   pushparam %ret12
   call fz
   popparam 
   popparam 
   popparam %ret15
   q = %ret15
   writeln
   writeln
   writeln
   writeln
   %22 = 'V'
   writec %22
   %22 = 'a'
   writec %22
   %22 = 'l'
   writec %22
   %22 = 'o'
   writec %22
   %22 = 'r'
   writec %22
   %22 = ' '
   writec %22
   %22 = 'f'
   writec %22
   %22 = 'i'
   writec %22
   %22 = 'n'
   writec %22
   %22 = 'a'
   writec %22
   %22 = 'l'
   writec %22
   %22 = ' '
   writec %22
   %22 = 'q'
   writec %22
   %22 = ':'
   writec %22
   %22 = ' '
   writec %22
   writef q
   writeln
   writeln
   writeln
   writeln
   %27 = 3.7
   %28 = q +. %27
   %31 = 4
   %34 = float %31
   %32 = %28 +. %34
   writef %32
   writeln
   return
endfunction


