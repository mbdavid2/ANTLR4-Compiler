func fz(r:int, arr:array[10] of char, ch:char, lit:char)
  write arr[3];
  write "\n";
  write ch;
  write "\n";
  write "CHLOAD SON LOS PADRES";
  write "\n";
  arr[3] = 'y';
  return;
endfunc

func main()
	var x:array[10] of char
	var peta:array[10] of bool
    var a: int
    var b: float
    var f: int
    var c: char
    peta[4] = true;
    peta[5] = true;
    read x[3];
    peta[6] = x[3] == 'z';
    f = 2312;
    if (peta[5] and peta[4] or peta[6]) then
    	fz(0, x, x[3], 'e');
        write x[3];
        write "\n";
    else write 'u' ;
    endif
    write "\n";
endfunc
