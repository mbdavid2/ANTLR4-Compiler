/////////////////////////////////////////////////////////////////
//
//    SymTable - Symbol table for the Asl programming language
//
//    Copyright (C) 2018  Universitat Politecnica de Catalunya
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
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
////////////////////////////////////////////////////////////////


#include "TypesMgr.h"
#include "SymTable.h"

#include <string>
#include <iostream>

#include <cstddef>    // std::size_t
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// using namespace std;


// Constructor
SymTable::SymTable(TypesMgr & Types) :
  Types{Types} {
}

// Creates a new scope, push its ScopeId in the stack
// and returns this ScopeId.
SymTable::ScopeId SymTable::pushNewScope(const std::string & name) {
  ScopeId currScope = ScopesVec.size();
  ScopesVec.push_back(ScopeInfo(name));
  ScopeIdsStack.push_back(currScope);
  return currScope;
}

// Pop the stack of scopes
void SymTable::popScope() {
  assert(not ScopeIdsStack.empty());
  ScopeIdsStack.pop_back();
}

// Push a previously created scope sc and set it as current scope
void SymTable::pushThisScope(ScopeId scope) {
  assert(scope < ScopesVec.size());
  ScopeIdsStack.push_back(scope);
}

// Returns the current scope.
SymTable::ScopeId SymTable::topScope() const {
  assert(not ScopeIdsStack.empty());
  return ScopeIdsStack.back();
}

// Returns true if ident occurs in the current scope (top of the stack)
bool SymTable::findInCurrentScope(const std::string & ident) const {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  assert(currScope < ScopesVec.size());
  return (ScopesVec[currScope].findSymbol(ident));
}

// Returns an iteger >= 0 if ident occurs in some of the scopes
// of the stack. If it it occurs at the top (current scope) returns 0.
// If it occurs in the scope below the top returns 1, and so on.
// Returns -1 if te symbol is not found.
int SymTable::findInStack(const std::string & ident) const {
  assert(not ScopeIdsStack.empty());
  int d = 0;
  for (int i = ScopeIdsStack.size() - 1; i >= 0; --i) {
    ScopeId sc = ScopeIdsStack[i];
    assert(sc < ScopesVec.size());
    if (ScopesVec[sc].findSymbol(ident))
      return d;
    ++d;
  }
  return -1;
}

// Adds a new symbol in the current scope.
void SymTable::addLocalVar(const std::string & ident, TypesMgr::TypeId type) {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  assert(currScope < ScopesVec.size());
  ScopesVec[currScope].addLocalVar(ident, type);
}
void SymTable::addParameter(const std::string & ident, TypesMgr::TypeId type) {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  assert(currScope < ScopesVec.size());
  ScopesVec[currScope].addParameter(ident, type);
}

void SymTable::addFunction(const std::string & ident, TypesMgr::TypeId type) {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  assert(currScope < ScopesVec.size());
  ScopesVec[currScope].addFunction(ident, type);
}

// Check the class of a symbol. If not found return false
bool SymTable::isLocalVarClass(const std::string & ident) const {
  assert(not ScopeIdsStack.empty());
  for (int i = ScopeIdsStack.size() - 1; i >= 0; --i) {
    ScopeId sc = ScopeIdsStack[i];
    assert(sc < ScopesVec.size());
    if (ScopesVec[sc].findSymbol(ident))
      return ScopesVec[sc].isLocalVarClass(ident);
  }
  return false;
}

bool SymTable::isParameterClass(const std::string & ident) const {
  assert(not ScopeIdsStack.empty());
  for (int i = ScopeIdsStack.size() - 1; i >= 0; --i) {
    ScopeId sc = ScopeIdsStack[i];
    assert(sc < ScopesVec.size());
    if (ScopesVec[sc].findSymbol(ident))
      return ScopesVec[sc].isParameterClass(ident);
  }
  return false;
}

bool SymTable::isFunctionClass(const std::string & ident) const {
  assert(not ScopeIdsStack.empty());
  for (int i = ScopeIdsStack.size() - 1; i >= 0; --i) {
    ScopeId sc = ScopeIdsStack[i];
    assert(sc < ScopesVec.size());
    if (ScopesVec[sc].findSymbol(ident))
      return ScopesVec[sc].isFunctionClass(ident);
  }
  return false;
}

// Get the TypeId of a symbol. If not found return type 'error'
TypesMgr::TypeId SymTable::getType(const std::string & ident) const {
  assert(not ScopeIdsStack.empty());
  for (int i = ScopeIdsStack.size() - 1; i >= 0; --i) {
    ScopeId sc = ScopeIdsStack[i];
    assert(sc < ScopesVec.size());
    if (ScopesVec[sc].findSymbol(ident))
      return ScopesVec[sc].getType(ident);
  }
  return Types.createErrorTy();
}

// Writes the contents of the current scope (top of the stack)
// on the standard output.
void SymTable::printCurrentScope() const {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  assert(currScope < ScopesVec.size());
  ScopesVec[currScope].print(Types);
}

// Write the contents of the symbol table on the standard output
void SymTable::print() const {
  std::cout << "Contents of symbol table:" << std::endl;
  for (int i = ScopeIdsStack.size() - 1; i >= 0; --i) {
    ScopeId sc = ScopeIdsStack[i];
    assert(sc < ScopesVec.size());
    ScopesVec[sc].print(Types);
  }
  std::cout << "----------------" << std::endl;
}

// Returns the type (TypeId) of the function whose scope is
// on top of the stack
TypesMgr::TypeId SymTable::getCurrentFunctionTy() const {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  std::string name = ScopesVec[currScope].getName();
  return ScopesVec[0].getType(name);
}

bool SymTable::noMainProperlyDeclared() const {
  assert(not ScopeIdsStack.empty());
  ScopeId currScope = ScopeIdsStack.back();
  assert(currScope < ScopesVec.size());
  if ((not ScopesVec[currScope].findSymbol("main")) or
      (not ScopesVec[currScope].isFunctionClass("main")))
    return true;
  TypesMgr::TypeId tid = ScopesVec[currScope].getType("main");
  if (Types.isFunctionTy(tid) and
      (Types.getNumOfParameters(tid) == 0) and
      Types.isVoidFunction(tid))
    return false;
  return true;
}


// class SymTable::ScopeInfo ==============================================================

// Constructor
SymTable::ScopeInfo::ScopeInfo(const std::string & name)
  : name{name} { }

// Accessors to work with the attributes: name, SymbolsMap, IdentsList
std::string SymTable::ScopeInfo::getName() const {
  return name;
}

// Mutators to add symbols to the scope
void SymTable::ScopeInfo::addLocalVar(const std::string & ident, TypesMgr::TypeId type) {
  assert(SymbolsMap.find(ident) == SymbolsMap.end());
  SymbolsMap[ident] = SymbolInfo::createLocalVar(type);
  IdentsList.push_back(ident);
}
void SymTable::ScopeInfo::addParameter(const std::string & ident, TypesMgr::TypeId type) {
  assert(SymbolsMap.find(ident) == SymbolsMap.end());
  SymbolsMap[ident] = SymbolInfo::createParameter(type);
  IdentsList.push_back(ident);
}
void SymTable::ScopeInfo::addFunction(const std::string & ident, TypesMgr::TypeId type) {
  assert(SymbolsMap.find(ident) == SymbolsMap.end());
  SymbolsMap[ident] = SymbolInfo::createFunction(type);
  IdentsList.push_back(ident);
}

// Accessor to check the existence of a symbol
bool SymTable::ScopeInfo::findSymbol(const std::string & ident) const {
  return (SymbolsMap.find(ident) != SymbolsMap.end());
}

// Accessors to check the class of the symbol. If not found return false
bool SymTable::ScopeInfo::isLocalVarClass(const std::string & ident) const {
  auto const & it = SymbolsMap.find(ident);
  if (it == SymbolsMap.end())
    return false;
  return it->second.isLocalVarClass();
}
bool SymTable::ScopeInfo::isParameterClass(const std::string & ident) const {
  auto const & it = SymbolsMap.find(ident);
  if (it == SymbolsMap.end())
    return false;
  return it->second.isParameterClass();
}
bool SymTable::ScopeInfo::isFunctionClass(const std::string & ident) const {
  auto const & it = SymbolsMap.find(ident);
  if (it == SymbolsMap.end())
    return false;
  return it->second.isFunctionClass();
}

// Accessor to get the TypeId of a symbol. The symbol MUST exist.
TypesMgr::TypeId SymTable::ScopeInfo::getType(const std::string & ident) const {
  assert(SymbolsMap.find(ident) != SymbolsMap.end());
  auto const & it = SymbolsMap.find(ident);
  return it->second.getType();
}

// Writes the contents of the scope to the standard output.
void SymTable::ScopeInfo::print(TypesMgr & Types) const {
  std::cout << "---------------- scope name: " << name << std::endl;
  for (auto & id : IdentsList) {
    auto const & it = SymbolsMap.find(id);
    std::cout << id << ":" << it->second.class2string();
    if (not it->second.isErrorClass()) {
      std::cout << "," << Types.to_string(it->second.getType());
    }
    std::cout << std::endl;
  }
}


// class SymTable::ScopeInfo::SymbolInfo ==========================================================

// Constructors
SymTable::ScopeInfo::SymbolInfo::SymbolInfo()
  : classId{ErrorClassId} {
}
SymTable::ScopeInfo::SymbolInfo::SymbolInfo(SymClassId c, TypesMgr::TypeId tid)
  : classId{c}, type{tid} {
    assert(FirstSymClassId < c and c < LastSymClassId);
}

// Accessors for working with the attributes: class and type
bool SymTable::ScopeInfo::SymbolInfo::isLocalVarClass() const {
  return classId == LocalVarId;
}
bool SymTable::ScopeInfo::SymbolInfo::isParameterClass() const {
  return classId == ParameterId;
}
bool SymTable::ScopeInfo::SymbolInfo::isFunctionClass() const {
  return classId == FunctionId;
}
bool SymTable::ScopeInfo::SymbolInfo::isErrorClass() const {
  return classId == ErrorClassId;
}
TypesMgr::TypeId SymTable::ScopeInfo::SymbolInfo::getType() const {
  return type;
}

// Convert the symbol class to string
std::string SymTable::ScopeInfo::SymbolInfo::class2string() const {
  switch (classId) {
  case LocalVarId:
    return "localVar";
  case ParameterId:
    return "parameter";
  case FunctionId:
    return "function";
  default:
    return "errorClass";
  }
}

// Static methods to create SymbolInfo objects
SymTable::ScopeInfo::SymbolInfo SymTable::ScopeInfo::SymbolInfo::createLocalVar(TypesMgr::TypeId type) {
  return SymbolInfo(SymClassId::LocalVarId, type);
}
SymTable::ScopeInfo::SymbolInfo SymTable::ScopeInfo::SymbolInfo::createParameter(TypesMgr::TypeId type) {
  return SymbolInfo(SymClassId::ParameterId, type);
}
SymTable::ScopeInfo::SymbolInfo SymTable::ScopeInfo::SymbolInfo::createFunction(TypesMgr::TypeId type) {
  return SymbolInfo(SymClassId::FunctionId, type);
}
