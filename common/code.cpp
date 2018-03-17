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

#include <iostream>
#include "code.h"

using namespace std;

////////////////////////////////////////////////////////////////////
/// Implementation for class 'instruction'

/// Constructor
instruction::instruction(Operation op,
                         const std::string &a1, const std::string &a2, const std::string &a3) {
  oper = op;
  arg1 = a1;
  arg2 = a2;
  arg3 = a3;
}

instruction instruction::LABEL(const std::string &a1) { return instruction(_LABEL, a1); }
instruction instruction::UJUMP(const std::string &a1) { return instruction(_UJUMP, a1); }
instruction instruction::FJUMP(const std::string &a1, const std::string &a2) { return instruction(_FJUMP, a1, a2); }
instruction instruction::PUSH(const std::string &a1) { return instruction(_PUSH, a1); }
instruction instruction::POP(const std::string &a1) { return instruction(_POP, a1); }
instruction instruction::CALL(const std::string &a1) { return instruction(_CALL, a1); }
instruction instruction::RETURN() { return instruction(_RETURN); }
instruction instruction::ADD(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_ADD, a1, a2, a3); }
instruction instruction::SUB(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_SUB, a1, a2, a3); }
instruction instruction::MUL(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_MUL, a1, a2, a3); }
instruction instruction::DIV(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_DIV, a1, a2, a3); }
instruction instruction::EQ(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_EQ, a1, a2, a3); }
instruction instruction::LT(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_LT, a1, a2, a3); }
instruction instruction::LE(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_LE, a1, a2, a3); }
instruction instruction::AND(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_AND, a1, a2, a3); }
instruction instruction::OR(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_OR, a1, a2, a3); }
instruction instruction::FADD(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FADD, a1, a2, a3); }
instruction instruction::FSUB(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FSUB, a1, a2, a3); }
instruction instruction::FMUL(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FMUL, a1, a2, a3); }
instruction instruction::FDIV(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FDIV, a1, a2, a3); }
instruction instruction::FEQ(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FEQ, a1, a2, a3); }
instruction instruction::FLT(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FLT, a1, a2, a3); }
instruction instruction::FLE(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_FLE, a1, a2, a3); }
instruction instruction::NOT(const std::string &a1, const std::string &a2) { return instruction(_NOT, a1, a2); }
instruction instruction::NEG(const std::string &a1, const std::string &a2) { return instruction(_NEG, a1, a2); }
instruction instruction::FNEG(const std::string &a1, const std::string &a2) { return instruction(_FNEG, a1, a2); }
instruction instruction::FLOAT(const std::string &a1, const std::string &a2) { return instruction(_FLOAT, a1, a2); }  
instruction instruction::LOAD(const std::string &a1, const std::string &a2) { return instruction(_LOAD, a1, a2); }
instruction instruction::ILOAD(const std::string &a1, const std::string &a2) { return instruction(_ILOAD, a1, a2); }
instruction instruction::CHLOAD(const std::string &a1, const std::string &a2) { return instruction(_CHLOAD, a1, a2); }
instruction instruction::FLOAD(const std::string &a1, const std::string &a2) { return instruction(_FLOAD, a1, a2); }
instruction instruction::XLOAD(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_XLOAD, a1, a2, a3); }
instruction instruction::LOADX(const std::string &a1, const std::string &a2, const std::string &a3) { return instruction(_LOADX, a1, a2, a3); }
instruction instruction::ALOAD(const std::string &a1, const std::string &a2) { return instruction(_ALOAD, a1, a2); }
instruction instruction::LOADC(const std::string &a1, const std::string &a2) { return instruction(_LOADC, a1, a2); }
instruction instruction::CLOAD(const std::string &a1, const std::string &a2) { return instruction(_CLOAD, a1, a2); }
instruction instruction::READI(const std::string &a1) { return instruction(_READI, a1); }
instruction instruction::READF(const std::string &a1) { return instruction(_READF, a1); }
instruction instruction::READC(const std::string &a1) { return instruction(_READC, a1); }
instruction instruction::WRITEI(const std::string &a1) { return instruction(_WRITEI, a1); }
instruction instruction::WRITEF(const std::string &a1) { return instruction(_WRITEF, a1); }
instruction instruction::WRITEC(const std::string &a1) { return instruction(_WRITEC, a1); }
instruction instruction::WRITELN() { return instruction(_WRITELN); }
instruction instruction::NOOP() { return instruction(_NOOP); }


/// Destructor
instruction::~instruction() {}

string instruction::dump() const {
  string s;
  string ind="   ";
  switch (oper) {
  case instruction::_LABEL : { s = "label " + arg1 + " :"; ind = ""; break; }
  case instruction::_UJUMP : { s = "goto " + arg1; break; }
  case instruction::_FJUMP : { s = "ifFalse " + arg1 + " goto " +arg2; break; }
  case instruction::_LOAD : 
  case instruction::_FLOAD : 
  case instruction::_ILOAD : { s = arg1 + " = " + arg2; break; } 
  case instruction::_CHLOAD : { s = arg1 + " = '" + arg2 +"'"; break; } 
  case instruction::_PUSH : { s = "pushparam " + (arg1.empty()? "" : arg1); break; }
  case instruction::_POP : { s = "popparam " + (arg1.empty()? "" : arg1); break; }
  case instruction::_CALL : { s = "call " + arg1; break; }
  case instruction::_RETURN : { s = "return"; break; }
  case instruction::_XLOAD : { s = arg1 + "[" + arg2 + "] = " + arg3; break; }
  case instruction::_LOADX : { s = arg1 + " = " + arg2 + "[" + arg3 + "]"; break; }
  case instruction::_ALOAD : { s = arg1 + " = &" + arg2; break; }
  case instruction::_LOADC : { s = arg1 + " = *" + arg2; break; }
  case instruction::_CLOAD : { s = "*" + arg1 + " = " + arg2; break; }
  case instruction::_READI : { s = "readi " + arg1; break; }
  case instruction::_READF : { s = "readf " + arg1; break; }
  case instruction::_READC : { s = "readc " + arg1; break; }
  case instruction::_WRITEI : { s = "writei " + arg1; break; }
  case instruction::_WRITEF : { s = "writef " + arg1; break; }
  case instruction::_WRITEC : { s = "writec " + arg1; break; }
  case instruction::_WRITELN : { s = "writeln"; break; }
  case instruction::_ADD : { s = arg1 + " = " + arg2 + " + " + arg3; break; }
  case instruction::_SUB : { s = arg1 + " = " + arg2 + " - " + arg3; break; }
  case instruction::_MUL : { s = arg1 + " = " + arg2 + " * " + arg3; break; }
  case instruction::_DIV : { s = arg1 + " = " + arg2 + " / " + arg3; break; }
  case instruction::_AND : { s = arg1 + " = " + arg2 + " and " + arg3; break; }
  case instruction::_OR : { s = arg1 + " = " + arg2 + " or " + arg3; break; }
  case instruction::_EQ : { s = arg1 + " = " + arg2 + " == " + arg3; break; }
  case instruction::_LT : { s = arg1 + " = " + arg2 + " < " + arg3; break; }
  case instruction::_LE : { s = arg1 + " = " + arg2 + " <= " + arg3; break; }
  case instruction::_NOT : { s = arg1 + " = not " + arg2; break; }
  case instruction::_NEG : { s = arg1 + " = - " + arg2; break; }
  case instruction::_FADD : { s = arg1 + " = " + arg2 + " +. " + arg3; break; }
  case instruction::_FSUB : { s = arg1 + " = " + arg2 + " -. " + arg3; break; }
  case instruction::_FMUL : { s = arg1 + " = " + arg2 + " *. " + arg3; break; }
  case instruction::_FDIV : { s = arg1 + " = " + arg2 + " /. " + arg3; break; }
  case instruction::_FEQ : { s = arg1 + " = " + arg2 + " ==. " + arg3; break; }
  case instruction::_FLT : { s = arg1 + " = " + arg2 + " <. " + arg3; break; }
  case instruction::_FLE : { s =  arg1 + " = " + arg2 + " <=. " + arg3; break; }
  case instruction::_FNEG : { s =  arg1 + " = -. " + arg2; break; }
  case instruction::_FLOAT : { s = arg1 + " = float " + arg2; break; }
  case instruction::_NOOP : { s = "noop"; break; }
  default : { s = "????"; break; }
  }

  return ind + s;
}

////////////////////////////////////////////////////////////////////
// concatenation of instruction+list (or instruction+instruction, via automatic coertion)

instructionList instruction::operator||(const instructionList &lst) const {
  return instructionList(*this) || lst;
}


////////////////////////////////////////////////////////////////////
/// Implementation for class 'instructionList'

// constructor
instructionList::instructionList() {}
// constructor from a single instruction
instructionList::instructionList(const instruction &inst) { this->push_back(inst); }
// destructor
instructionList::~instructionList() {}

// concatenation of lists (or list+instruction, via automatic coertion)
instructionList instructionList::operator||(const instructionList &lst) const {
  instructionList newlist = (*this);
  newlist.insert(newlist.end(), lst.begin(), lst.end());
  return newlist;
}

// print instructionList (for debugging)
string instructionList::dump() const {
  string s;  
  for (auto i : *this ) s += i.dump() + "\n";
  return s;
}


////////////////////////////////////////////////////////////////////
/// Implementation for class 'var'

/// constructor
var::var(const std::string &n, size_t s) {
  name = n;
  size = s;
}

/// destructor
var::~var() {}

/// print (for debugging)
string var::dump() const {
  if (size != 0)
    return name + " " + std::to_string(size);
  return name;
}

////////////////////////////////////////////////////////////////////
/// Implementation for class 'subroutine'

/// constructor
subroutine::subroutine(const string &sname) { name = sname; }
/// destructor
subroutine::~subroutine() {}
/// get subroutine name
string subroutine::get_name() const { return name; };
/// add new variable
void subroutine::add_var(const std::string &name, size_t sz) { vars.push_back(var(name,sz)); }
/// add new parameter
void subroutine::add_param(const std::string &name) { params.push_back(var(name,0)); }
/// add new instruction
void subroutine::add_instruction(const instruction &inst) {
  if (inst.oper == instruction::_LABEL) labels.insert(make_pair(inst.arg1,instructions.size()));
  instructions.push_back(inst);
}
/// add instruction list to current instructions
void subroutine::add_instructions(const instructionList &lins) {
  for (auto i : lins)
    this->add_instruction(i);
}
/// set instruction list (overwritting current instructions)
void subroutine::set_instructions(const instructionList &lins) {
  instructions.clear();
  this->add_instructions(lins);
}
/// get instruction at given program counter
instruction subroutine::get_instruction_at(size_t pc) const {
  if (pc>=instructions.size()) return instruction(instruction::_INVALID);
  return instructions[pc];
}
/// get program counter for given label
size_t subroutine::get_label_pc(std::string &lab) const { return labels.find(lab)->second; }
/// print (for debugging)
string subroutine::dump() const {
  string s;
  s = "function " + name + "\n";
  if (not params.empty()) {
    s += "  params\n" ;
    for (auto p : params) s += "    " + p.dump() + "\n";
    s += "  endparams\n\n";
  }
  if (not vars.empty()) {
    s += "  vars\n";
    for (auto v : vars) s += "    " + v.dump() + "\n";
    s += "  endvars\n\n";
  }

  string ind = "  ";
  if (labels.empty()) ind="";
  for (auto i : instructions) s += ind + i.dump() + "\n";  
  s += "endfunction\n\n";
  return s;
}

////////////////////////////////////////////////////////////////////
/// Implementation for class 'subroutine'

/// constructor
code::code() {};
/// destructor
code::~code() {};

/// get most recently added subroutine 
subroutine& code::get_last_subroutine() { return subs[subs.size()-1]; }
/// get subroutine by name
const subroutine& code::get_subroutine(const string &name) const {
  size_t p = names.find(name)->second;
  return subs[p];
}
/// add subroutine
void code::add_subroutine(const subroutine &s) {
  subs.push_back(s);
  names.insert(make_pair(s.get_name(), subs.size()-1));
}
/// print (for debugging)
string code::dump() const {
  string c;
  for (auto s : subs) c += s.dump();
  return c;
}


////////////////////////////////////////////////////////////////////
/// Static methods to manage counters
int counters::countIF = 0;
int counters::countWHILE = 0;
int counters::countTEMP = 0;

string counters::newLabelIF() { return std::to_string(++countIF); }
string counters::newLabelWHILE() { return std::to_string(++countWHILE); }
string counters::newTEMP() { return std::to_string(++countTEMP); }

void counters::resetLabelIF() { countIF = 0; }
void counters::resetLabelWHILE() { countWHILE = 0; }
void counters::resetTEMP() { countTEMP = 0; }

void counters::resetLabels() { resetLabelIF(); resetLabelWHILE(); }
void counters::reset() { resetLabels(); resetTEMP(); }
