function main
  vars
    a 1
    b 1
    end 1
    pi 1
  endvars

   %1 = 36.0
   %2 = 6
   %3 = %1 /. %2
   a = %3
   writef a
   writeln
   %5 = 4
   %6 = 5
   %7 = %5 / %6
   a = %7
   writef a
   writeln
   writeln
   %10 = 5
   %11 = a *. %10
   %12 = 1
   %13 = a +. %12
   %14 = a *. %13
   %15 = %11 +. %14
   b = %15
   %16 = b < a
   %16 = not %16
   %17 = 0
   %18 = a == %17
   %19 = not %18
   %20 = %16 and %19
   end = %20
   %21 = 3.3
   %22 = 1
   %23 = %22 /. a
   %24 = %21 +. %23
   %25 = 2.0
   %26 = -. %25
   %27 = %26 /. a
   %28 = %24 -. %27
   pi = %28
   %29 = a == b
   %30 = %29 or end
   writei %30
   writeln
   return
endfunction


