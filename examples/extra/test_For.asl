func search(needle: int, stack: array[10] of int): int
  var i: int
  for (i = 0; i < 10; i = i+1):
    if stack[i] == needle then
      return i;
    endif
  endfor
  return -1;
endfunc

func main()
  var arr: array[10] of int
  var i, find: int
  for (i = 0; i < 10; i = i+1):
    read arr[i];
  endfor
  read find;
  i=search(find,arr);
  write "Index: ";
  write i;
  write "\n";
endfunc