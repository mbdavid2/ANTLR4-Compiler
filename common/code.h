/////////////////////////////////////////////////////////////////
//
//    TVM - t-Code Virtual Machine
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: Lluis Padro (padro@cs.upc.es)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.320 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
////////////////////////////////////////////////////////////////

#pragma once

#include <map>
#include <list>
#include <vector>

/// predeclaration
class instructionList;

////////////////////////////////////////////////////////////////////
/// Class instruction stores a VM instruction code with its operands

class instruction {

 public:
  /// instruction codes
  typedef enum {_LABEL, _UJUMP, _FJUMP, _PUSH, _POP, _CALL, _RETURN,
                _ADD, _SUB, _MUL, _DIV, _EQ, _LT, _LE, _NEG, _NOT, _AND, _OR, _FLOAT,
                _FADD, _FSUB, _FMUL, _FDIV, _FEQ, _FLT, _FLE, _FNEG,
                _LOAD, _ILOAD, _CHLOAD, _FLOAD, _XLOAD, _LOADX, _ALOAD, _LOADC, _CLOAD,
                _READI, _READF, _READC, _WRITEI, _WRITEF, _WRITEC, _WRITELN, _NOOP, _INVALID} Operation;
  
  /// instruction code
  Operation oper;
  /// arguments
  std::string arg1, arg2, arg3;
  
  /// constructor
  instruction(Operation op,
              const std::string &a1="", const std::string &a2="", const std::string &a3="");

  /// destructor
  ~instruction();

  // concatenation of instruction+list (or instruction+instruction, via automatic coertion)
  instructionList operator||(const instructionList &lst) const;

  /// ------ specific constructors for each instruction -------

  // create new instruction "a1 :"
  static instruction LABEL(const std::string &a1);
  // create new instruction "goto a1"
  static instruction UJUMP(const std::string &a1);
  // create new instruction "ifFalse a1 goto a2"
  static instruction FJUMP(const std::string &a1, const std::string &a2);
  // create new instruction "pushparam a1"
  static instruction PUSH(const std::string &a1="");
  // create new instruction "popparam a1"
  static instruction POP(const std::string &a1="");
  // create new instruction "call a1"
  static instruction CALL(const std::string &a1);
  // create new instruction "return"
  static instruction RETURN();
  // create new instruction "a1 = a2 + a3"
  static instruction ADD(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 - a3"
  static instruction SUB(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 * a3"
  static instruction MUL(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 / a3"
  static instruction DIV(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 == a3"
  static instruction EQ(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 < a3"
  static instruction LT(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 <= a3"
  static instruction LE(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 and a3"
  static instruction AND(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 or a3"
  static instruction OR(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 +. a3"
  static instruction FADD(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 -. a3"
  static instruction FSUB(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 *. a3"
  static instruction FMUL(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 /. a3"
  static instruction FDIV(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 ==. a3"
  static instruction FEQ(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 <. a3"
  static instruction FLT(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2 <=. a3"
  static instruction FLE(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = not a2"
  static instruction NOT(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = - a2"
  static instruction NEG(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = -. a2"
  static instruction FNEG(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = float a2"
  static instruction FLOAT(const std::string &a1, const std::string &a2);  
  // create new instruction "a1 = a2"
  static instruction LOAD(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = a2" (where a2 is an integer constant)
  static instruction ILOAD(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = a2" (where a2 is a character constant)
  static instruction CHLOAD(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = a2" (where a2 is a float constant)
  static instruction FLOAD(const std::string &a1, const std::string &a2);
  // create new instruction "a1[a2] = a3" 
  static instruction XLOAD(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = a2[a3]" 
  static instruction LOADX(const std::string &a1, const std::string &a2, const std::string &a3);
  // create new instruction "a1 = &a2" 
  static instruction ALOAD(const std::string &a1, const std::string &a2);
  // create new instruction "a1 = *a2" 
  static instruction LOADC(const std::string &a1, const std::string &a2);
  // create new instruction "*a1 = a2" 
  static instruction CLOAD(const std::string &a1, const std::string &a2);
  // create new instruction "readi a1" 
  static instruction READI(const std::string &a1);
  // create new instruction "readf a1" 
  static instruction READF(const std::string &a1);
  // create new instruction "readc a1" 
  static instruction READC(const std::string &a1);
  // create new instruction "writei a1" 
  static instruction WRITEI(const std::string &a1); 
  // create new instruction "writef a1" 
  static instruction WRITEF(const std::string &a1);
  // create new instruction "writec a1" 
  static instruction WRITEC(const std::string &a1);
  // create new instruction "writeln" 
  static instruction WRITELN();
  // create new instruction "noop" (not really needed) 
  static instruction NOOP();
  
  // print instruction
  std::string dump() const;   
};

////////////////////////////////////////////////////////////////////
/// Class instructionList stores a list of instructions

class instructionList : public std::vector<instruction> {
 public:
   // constructor
   instructionList();
   // constructor from a single instruction
   instructionList(const instruction &);
   // destructor
   ~instructionList();

   // concatenation of lists (or list+instruction, via automatic coertion)
   instructionList operator||(const instructionList &lst) const;

   // print instructionList
   std::string dump() const;   
};



////////////////////////////////////////////////////////////////////
/// Class var stores a variable name and size

class var {
 public:
  std::string name;
  size_t size;

  var(const std::string &n, size_t s);
  ~var();

  // print var
  std::string dump() const; 
};

////////////////////////////////////////////////////////////////////
/// Class subroutine stores information about a subroutine (local
/// vars, parametres, instructions, declared/used labels...)

class subroutine {
 private:
  /// name of the subroutine
  std::string name;
  /// instructions
  instructionList instructions;
  /// map label name -> position in instructions
  std::map<std::string, size_t> labels;

 public:
  /// list of local variables
  std::list<var> vars;
  /// list of params
  std::list<var> params;  

  /// constructor and destructor
  subroutine(const std::string &sname);
  ~subroutine();

  /// get subroutine name
  std::string get_name() const;
  /// add a local var to subroutine
  void add_var(const std::string &name, size_t sz);
  /// add a parameter (size is always 1)
  void add_param(const std::string &name);
  /// add an instruction
  void add_instruction(const instruction &inst);
  /// add instruction list to current instructions
  void add_instructions(const instructionList &lins);
  /// set instruction list (overwritting current instructions)
  void set_instructions(const instructionList &lins);
  
  /// get instruction at given program counter in subroutine
  instruction get_instruction_at(size_t pc) const;
  /// get program counter in subroutine for given label
  size_t get_label_pc(std::string &lab) const;

  // print subroutine (params, vars, and instructions)
  std::string dump() const;
};

////////////////////////////////////////////////////////////////////
/// Class code stores a whole program (main plus subroutines)

class code {
 private:
  /// subroutines (including main progam)
  std::vector<subroutine> subs;
  /// index to access subroutines by name
  std::map<std::string, size_t> names;
  
 public:
  /// constructor and destructor
  code();
  ~code();

  /// get most recently added subroutine (i.e. the one currently being processed)
  subroutine& get_last_subroutine();
  /// get subroutine by name
  const subroutine& get_subroutine(const std::string &name) const;
  /// add new subroutine
  void add_subroutine(const subroutine &s);

  // print code (all info for all subroutines)
  std::string dump() const;
};


////////////////////////////////////////////////////////////////////
/// Class counters manages temporal and labels counters

class counters {
 private:
   static int countIF;
   static int countWHILE;
   static int countTEMP;
  
 public:
   // return id for new label or temp (id is a number, but returned as string
   // to ease concatenation with other literals (e.g. "labelIF" + "4" -> "LabelIF4")
   static std::string newLabelIF();
   static std::string newLabelWHILE();
   static std::string newTEMP();

   // reset individual counters 
   static void resetLabelIF();
   static void resetLabelWHILE();
   static void resetTEMP();

   // reset label counters (IF and WHILE)
   static void resetLabels();
   // reset all counters (IF, WHILE, and TEMP)
   static void reset();
};

