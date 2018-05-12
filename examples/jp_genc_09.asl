func fact(n: int): int
    var f: int
    f = 1;
    while n>1 do
        f = f*n;
	n = n-1;
    endwhile
    return f;
endfunc

func main()
    var max, i, f : int
    var end : bool
    end = true;    
    read max;
    if i <= max then
        end = false;
    else
        i = 0;
    endif
    while not end do
	write i;
	write "!=";
	write fact(i);
	write "\n";
	if i == max then
	    end = true;
	else
   	    i = i+1;
	endif
    endwhile
endfunc
