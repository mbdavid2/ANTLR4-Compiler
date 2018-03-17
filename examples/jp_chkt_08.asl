func f( a : int ) : bool
  var b : bool
  f(a + 3);
  b = f(a);
  b = f(a) > 3;
  return true;
endfunc


func p()
  var a : int
  a = p();
  a();
  a = a();
endfunc

func main()
endfunc
