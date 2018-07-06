# ANTLR4-Compiler

Compiler from a simple language to the assembly language of a virtual machine.

## Setting up

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

```
ANTLR4
```

```
Java(?)
```

### Installing

A step by step series of examples that tell you how to get a development env running

First install ...

```
ANTLR
```

.....

## Running the tests

You can write your own program or use any of the tests in the "examples" folder. 

Example: a program that finds a given value inside an array

```
func search(value: int, list: array[10] of int): int
  var i: int
  for (i = 0; i < 10; i = i+1):
    if list[i] == value then
      return i;
    endif
  endfor
  return -1;
endfunc

func main()
  var list: array[10] of int
  var i, value: int
  for (i = 0; i < 10; i = i+1):
    read list[i];
  endfor
  read value;
  i = search(value, list);
  write "Index: ";
  write i;
  write "\n";
endfunc
```

The check-examples.sh bash script tests all the examples.

## Built With

* [ANTLR4](https://github.com/antlr/antlr4) - The parser generator used

## Authors

* [Dartemiss](https://github.com/Dartemiss)
* [mbdavid2](https://github.com/mbdavid2)
