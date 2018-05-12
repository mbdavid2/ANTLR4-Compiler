func f(a:array[10] of float)
  a[5] = a[5]*10;
endfunc

func main()
  var b,c: array[10] of float
  read b[5];
  c[7] = b[5];
  write b[5]; write "\n";
  write c[7]; write "\n";
  f(b);
  write b[5]; write "\n";
  write c[7]; write "\n";
endfunc
