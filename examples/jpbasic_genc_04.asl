func f()
  var a: int
  var b: int
  read a;
  if a == 10 then
    a = 4*0+3;
    f();
  endif
  b = a+9;
  write b+a*2;
  write "\n";
endfunc

func main()
  var a: int
  read a;
  if a == 3 then
    f();
  endif
  write ".\n";
endfunc