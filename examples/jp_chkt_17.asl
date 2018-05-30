func f(a:array[10] of bool) : int
  var b : array[10] of bool
  var c : array[10] of bool
  b = f(a);
  b[3] = true;
  b[3] = c[5];
  b = f(f(b));
  return 67;
endfunc

func main()
endfunc
