func f()
  var a: int
  var b: int
  read a;
  if a == 10 then
    a = 3;
  endif
  b = a+67;
  write b+a+1;
endfunc

func main()
  var a: int
  read a;
  if a == 3 then
    f();
  endif
  write ".\n";
endfunc