func g()
  var n : int
  if n + 1 then
    n = n+1;
  endif
  while n*n do
     n = n > 3;
  endwhile
  if n > 1 then
     n = 4;
     while n != 4 do
        n = n + 1;
     endwhile
  endif
  return;
endfunc

func main()
endfunc
