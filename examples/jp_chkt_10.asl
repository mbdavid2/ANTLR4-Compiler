func f(a: int, b: array[10] of bool) : int
  var c : bool
  var d : float
  var e : array[10] of bool
  a = f(3, e);
  c = 4;
  c = a > 1;
  d = c;
  d = d*2;
  d = f(3,e);
  a = d;
  a = c or true;
  b = e;
  f = 4;
  return 99;
endfunc

func g() : bool
  return true;
endfunc

func main()
endfunc
