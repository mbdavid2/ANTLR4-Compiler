func x2(a:array[10] of int) : int
  var i: int
  var n: int
  n = 0;
  i = 0;
  while i < 10 do
    if a[i] == 0 then
      n = n+1;
    endif
    a[i] = a[i]*2;
    write a[i];
    write "\n";
    i = i+1;
  endwhile
  return n;
endfunc

func main()
  var x:array[10] of int
  var i,z: int
  i = 0;
  while i < 10 do
    x[i] = i;
    i = i+1;
  endwhile
  i = 0;
  while i < 10 do
    write x[i]; write "\n";
    i = i+1;
  endwhile
  z = x2(x);
  write "z:";
  write z;
  write "\n";
  i = 0;
  while i < 10 do
    write "x[";
    write i;
    write "]=";
    write x[i];
    write "\n";
    i = i+1;
  endwhile
  
endfunc
