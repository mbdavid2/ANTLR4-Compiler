func f1(a: int, b:int)
    var c : float
    var d: int
    var found: bool
    found = false;
    c = a+0.7; d = 0;
    if a+d>c or not found then
        while b > 0 do
	   b = b-1;
	   found = true;
	endwhile
    endif
    if b <= 11 then
        c = 2*c + 1;
    endif
    write c;
    write "\n";
endfunc

func main()
    var a: int
    var b: int
    a = 4;
    b = 2*a + 1;
    f1(b, 3+b);
endfunc
