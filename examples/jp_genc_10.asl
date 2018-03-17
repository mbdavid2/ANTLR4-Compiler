func prod_escalar(a1: array[10] of int,
                  a2: array[10] of int): int
    var i: int
    var s: int
    s = 0;
    while i < 10 do
        s = s + a1[i]*a2[i];
	i = i+1;
    endwhile
    return s;
endfunc

func main()
    var i:int
    var v1, v2: array[10] of int
    i = 0;
    while i<10 do
        v1[i] = -i;
	v2[i] = i*i;
	i = i+1;
    endwhile
    write prod_escalar(v1, v2);
    write "\n";
endfunc
