func main()
    var n, f, aux : int
    var end : bool
    read n;
    aux = n;
    if n < 0 then
       write "n >= 0!\n";
       end = true;
    endif
    f = 1;
    while not end and n > 1 do
        f = f * n;
        n = n - 1;
    endwhile
    if end == false then
        write aux;
        write "!=";
        write f;
        write "\n";
    endif
endfunc