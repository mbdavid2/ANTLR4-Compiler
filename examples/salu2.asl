func f(a:int, f:float): bool
  var x:int
  var b:bool
  var z:array[10] of int
  write "funcion f, Valores recibidos: ";
  write a;
  write "   ";
  write f;
  write "\n";
  return true;
endfunc

func fz(r:int, u:float) : float
  write "funcion fz, Valores recibidos: ";
  write r;
  write "   ";
  write u;
  write "\n";
  r = 0;
  u = 2;
  f(55555, 1.0/4);
  write "funcion fz despues de llamada, Valores recibidos: ";
  write r;
  write "   ";
  write u;
  write "\n";
  u = (r+3)*u;
  write "Resultado operacion u (lo que retorna): ";
  write u;
  write "\n";
  return (r+3)*u;
endfunc

func main()
  var a:int
  var q :float
  q = 0;
  write "Primer return de q: ";
  write q;
  write "\n";
  q = fz(3+4, fz(4444, q + 2));
  write "\n";
  write "\n";
  write "\n";
  write "\n";
  write "Valor final q: ";
  write q;
  write "\n";
  write "\n";
  write "\n";
  write "\n";
  write q+3.7+4;
  write "\n";
endfunc
