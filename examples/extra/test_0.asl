// Array search test
// Author: David Campos R.

func search(needle: int, stack: array[10] of int): int
  var i: int
  i = 0;
  while i<10 do
    if stack[i] == needle then
      return i;
    endif
    i = i+1;
  endwhile
  return -1;
endfunc

func main()
  var arr: array[10] of int
  var i, find: int
  i = 0;
  while i<10 do
    read arr[i];
    i = i+1;
  endwhile
  read find;
  i=search(find,arr);
  write "Index: ";
  write i;
  write "\n";
endfunc
