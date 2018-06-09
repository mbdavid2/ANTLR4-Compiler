// 5x5 Matrix multiplication
// Author: David Campos R.

func read_matrix(m: array[25] of float)
  var i,j: int
  var aux: int
  i = 0;
  while i<5 do
    j = 0;
    while j<5 do
      write "(";
      write i;
      write ", ";
      write j;
      write "): ";
      aux = i*5+j;
      read m[aux];
      j = 1+j;
    endwhile
    i = i+1;
  endwhile
endfunc

func print_matrix(m: array[25] of float)
  var i,j: int
  i = 0;
  while i<5 do
    j = 0;
    while j<5 do
      write m[i*5+j];
      write " ";
      j = 1+j;
    endwhile
    write "\n";
    i = i+1;
  endwhile
endfunc

func mult_matrix(m1: array[25] of float, m2: array[25] of float, res: array[25] of float)
  var i,j,k: int
  var sum: float
  i = 0;
  while i<5 do
    j = 0;
    while j<5 do
      sum = 0;
      k = 0;
      while k<5 do
        sum = sum + (m1[5*i+k] * m2[5*k+j]);
        k = k+1;
      endwhile
      res[5*i+j] = sum;
      j = 1+j;
    endwhile
    i = i+1;
  endwhile
endfunc

func main()
  var m1, m2, mul: array[25] of float
  read_matrix(m1);
  read_matrix(m2);
  write "m1:\n";
  print_matrix(m1);
  write "m2:\n";
  print_matrix(m2);
  mult_matrix(m1, m2, mul);
  write "m1 x m2:\n";
  print_matrix(mul);
endfunc
