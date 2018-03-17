func f(a: int) : int
  a = b+1;
  c = a+1;
  b[3] = 5;
  a = c[9];
  a = g(2);
  h(34);
  g(3);
  return 45;
endfunc

func g(z: int) :int
  a = z;
  z = f(z) + g(z);
  return 54;
endfunc

func main()
endfunc
