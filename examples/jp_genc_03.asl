func mul(a:int,b:int) : int
  return a*b;
endfunc

func main()
  var x,y:int
  read x;
  read y;
  write "x*y*2=";
  write mul(x,y)*2;
  write ".\n";
endfunc
