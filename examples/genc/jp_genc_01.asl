func main()
  var a, b: int
  var end : bool
  var pi : float
  a = 12;
  b = a*5 + a*(a+1);
  end = b >= a and not (a == 0);
  pi = 3.3 + 1/a - -2.0/a;
  write a==b or end;
  write "\n";
  write a*b;
  write "\n";
  write 2*pi;
  write "\n";
endfunc
