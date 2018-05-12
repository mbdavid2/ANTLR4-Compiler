func f1()
    var x1: int
    var y1: int
    write "err!!\n";
    if x1 == y1*2 then
        x1 = y1+3;
        y1 = x1 + y1*x1;
    endif
endfunc

func main()
    var x1: int
    x1 = 0;
    if x1 == 1 then
        f1();
    endif
    x1 = 4*5+6;
    write x1;
    write "\n";
endfunc
