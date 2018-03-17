func f(a: int, b: array[10] of bool) : int
  var x: int
  x = f(3, 4 or true);
  x = f();
  x = f(3, b, 6);
  g(34, x+1);
  g();
  return 33;
endfunc

func g()
  g(f(2));
endfunc

func h(a: array[10] of bool) : bool
  var b : array[10] of bool
  var x : bool
  x = h[b];
  h(b);
  return true;
endfunc

func p(a: array[10] of bool)
  var b : array[10] of bool
  p(h(b));
  p(3);
  p(b);
endfunc

func main()
endfunc
