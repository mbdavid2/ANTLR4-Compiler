// Brainfuck interpreter (kind of)
// ASL doesn't allow to aithmetically operate with characters
// so it prints numbers instead of characters :(.
// It also needs a # to mark the end of the program ^^'
// Author: David Campos R.

func init(vec: array[1000] of int)
  var i: int

  i=0;
  while i<1000 do
    vec[i] = 0;
    i = i+1;
  endwhile
endfunc

func load_program(pr: array[2000] of int): bool
  var c: char
  var valid: bool
  var i,stack_i: int
  var stack: array[1000] of int

  i=0;
  stack_i=-1;
  read c;
  while c != '#' and i < 2000 do
    valid = false;
    if c == '>' then pr[i]=-1; valid = true; endif
    if c == '<' then pr[i]=-2; valid = true; endif
    if c == '+' then pr[i]=-3; valid = true; endif
    if c == '-' then pr[i]=-4; valid = true; endif
    if c == '.' then pr[i]=-5; valid = true; endif
    if c == ',' then pr[i]=-6; valid = true; endif
    if c == '[' then
      stack_i = stack_i + 1; // increment stack
      stack[stack_i] = i; // pile in stack the current "while"
      valid = true;
    endif
    if c == ']' then
      pr[i]=stack[stack_i]; // this jumps to the start of the "while"
      pr[stack[stack_i]] = i; // the start jumps here
      stack_i = stack_i - 1; // unpile stack
      valid = true;
    endif
    if valid then
      i = i+1;
    endif
    read c;
  endwhile
  pr[i] = -7; // -7 to end
  if stack_i != -1 then
    return false;
  endif
  return true;
endfunc

func execute(program: array[2000] of int)
  var pc,ptr,inst: int
  var vec: array[1000] of int
  var jump: bool
  init(vec);
  
  pc = 0;
  ptr = 0;
  while true do
    inst = program[pc];
    jump = true;
    
    //write "\npc="; write pc;
    //write "; ptr="; write ptr;
    //write "; vec[ptr]="; write vec[ptr];
    //write " => "; write inst;
    //write " => ";

    if inst == -1 then ptr = ptr + 1; jump = false; endif
    if inst == -2 then ptr = ptr - 1; jump = false; endif
    if inst == -3 then vec[ptr] = vec[ptr] + 1; jump = false; endif
    if inst == -4 then vec[ptr] = vec[ptr] - 1; jump = false; endif
    if inst == -5 then write vec[ptr]; write " "; jump = false; endif
    if inst == -6 then read vec[ptr]; jump = false; endif
    if inst == -7 then return; endif // end of program
    
    if jump then
      if (inst > pc  and vec[ptr] == 0) or
	 (inst < pc  and vec[ptr] != 0) then // forward if = 0, backwards if != 0
        pc = inst; // jump
      endif
    endif

    pc = pc + 1; // increment pc

    //write "pc="; write pc;
    //write "; ptr="; write ptr;
    //write "; vec[ptr]="; write vec[ptr];
    //write "\n";
  endwhile
endfunc

func main()
  var program: array[2000] of int
  if not load_program(program) then
    write "Error en el programa, los corchetes no coinciden.";
  else
    write "Executing...\n";
    execute(program);
  endif
  write "\n";
endfunc
