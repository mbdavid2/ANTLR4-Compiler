// Float array reverse
// Author: David Campos R.

func reverse(a: array[10] of float)
  var aux: float
  var i: int
  i = 0;
  while i<5 do
    aux = a[i];
    a[i] = a[9-i];
    a[9-i] = aux;
    i = i+1;
  endwhile
endfunc

func main()
  var arr: array[10] of float
  var i: int
  i = 0;
  while i<10 do
    read arr[i];
    i = i+1;
  endwhile
  reverse(arr);
  write "Reversed: ";
  i = 0;
  while i<10 do
    write arr[i];
    write " ";
    i = i+1;
  endwhile
  write "\n";
endfunc
