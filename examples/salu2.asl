func main()
  var a, b: float
  var end : bool
  var pi : float
  a = 36.0 / 6.0;
  write a;
  write "\n";
  a = 4/5;
  write a;
  write "\n";
  write "\n";

  b = a*5 + a*(a+1);
  end = b >= a and not (a == 0);
  pi = 3.3 + 1/a - -2.0/a;
  write a==b or end;
  write "\n";
endfunc
