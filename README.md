# ANTLR4-Compiler

Compiler from a simple language to the assembly language of a virtual machine.

### Prerequisites

```
ANTLR4
```

```
Java
```

### Installation of ANTLR4

This installation guide was put together by [david-campos](https://github.com/david-campos)

* First of all, you should have java installed.

* ANTLR4 Quick Start (taken from http://www.antlr.org/)

  (You should have sudo privileges)

  ```
  $ cd /usr/local/lib
  $ sudo curl -O https://www.antlr.org/download/antlr-4.7.1-complete.jar
  $ export CLASSPATH=".:/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH"
  $ alias antlr4='java -jar /usr/local/lib/antlr-4.7.1-complete.jar'
  $ alias grun='java org.antlr.v4.gui.TestRig'
  ```
  To permanently have these alias you can add them to ~/.bash_profile and then source it (source ~/.bash_profile) so you don't have to restart the terminal.
  
* Download the C++ target (Linux version) from http://www.antlr.org/download.html and extract it, from now on this folder will be called "antlr4-dir".

* To compile the previous library, cmake and uuid are needed, you can install them using:

  ```
  $ sudo apt-get install cmake
  $ sudo apt-get install uuid-dev
  ```

* Compiling the library:

  ```
  $ cd antlr4-dir
  $ mkdir build && mkdir run && cd build
  $ cmake .. -DANTLR_JAR_LOCATION=f/usr/local/lib/YOUR_ANTLR_JAR.jar -DWITH_DEMO=True
  $ make
  $ DESTDIR=../run make install
  ```

  Assuming you were still in the build directory you can use ../ as in the last instruction, which is basically:
  ```
  $ DESTDIR=antlr4-dir/run make install
  ```

  The necessary files will be inside the run directory, now copy them to /usr with:

  ```
  $ cd <antlr4-dir>/run
  $ cp -r usr /
  ```

  You can check if this worked with something like:

  ```
  $ ls /usr/local/include/antlr4-runtime
  ```

* Finally, for the Makefile to work, you need to create a file called "antlr4" at /usr/local/bin/ with this content:

  ```
  java -jar /usr/local/lib/YOUR_ANTLR_JAR.jar “$@”
  ```

  And give it execution permissions

  ```
  $ chmod 777 /usr/local/bin/antlr4
  ```

  Be sure to update the dynamic libraries by using:

  ```
  $ sudo ldconfig
  ```

## Compiling

```
$ cd asl
$ make antlr
$ make
```

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

To write and test your own program do (if you're inside the "asl" folder):

```
./asl < inputProgram.asl > code.t
```

To generate the 3 adress code that will look like this:

```
[...]

function main
  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label startfor1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endfor1

[...]
```

Then execute the code with the virtual machine (you can add the input from a file if you want):

```
../tvm/tvm code.t [< input.in]
```

## Built With

* [ANTLR4](https://github.com/antlr/antlr4) - Parser generator

## Authors

* [Dartemiss](https://github.com/Dartemiss)
* [mbdavid2](https://github.com/mbdavid2)
