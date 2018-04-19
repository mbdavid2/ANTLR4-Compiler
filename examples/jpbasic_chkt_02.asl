func f2()
    var x2 : int
    var y2 : int
    var z2 : int
    x2 = z2;
    x2 = 2 * z2;
    x2 = y2 + 22 * z2; 
endfunc

func g2()
    var z2 : int
    g2 = 9 * z2;
    z2 = g2;
    read g2;
endfunc

func main()
    var x2 : int
    var t2 : int
    x2 = x2 == t2 == x2; 
    f2();
    if f2 then
        write f2;
    endif
    x2 = t2+x2 == x2*t2;
endfunc
