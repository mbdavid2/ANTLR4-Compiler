func f2()
    var x2: int
    var y2: int
    x2 = 0;
    y2 = x2;
    if x2 == y2*3 then
        x2 = y2*5 + 3;
        y2 = 1 + y2 + 1;
        if x2+1 == y2*2 then
	    write "ok";
	endif
	if y2 == 1+1 then
	    write x2*6;
	endif
    endif
endfunc

func main()
   if 7 == 7 then
       f2();
   endif
   write "bye\n";
endfunc
