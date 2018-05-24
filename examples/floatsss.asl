func f(a:int, f:float): bool
  var x:int
  var b:bool
  var z:array[10] of int
  write "funcion f, Valores recibidos: ";
  write a;
  write "   ";
  write f;
  write "\n";
  a = 0;
  f = (a+3)*f;
  write "funcion f, Valores cambiados: ";
  write a;
  write "   ";
  write f;
  write "\n";
  return true;
endfunc

func main()
  var a, c, d:int
  var q :float
  q = 2;
  write q;
  write "\n";
  write "\n";
  c = 0;
  q = (c+3)*q;
  write q;
  write "\n";
  write "\n";

  f(55555, 2);
endfunc