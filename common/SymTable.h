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

#pragma once

#include "TypesMgr.h"

#include <string>
#include <map>
#include <vector>

#include <cstddef>    // std::size_t
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

// using namespace std;


////////////////////////////////////////////////////////////////
// Class SymTable: stores the symbols declared in the program
// along with the information associated with each one:
//   - its class (the symbol can be a function, a parameter or
//     a local variable)
//   - its type (the TypeId returned by the TypesMgr)
// The symbols are grouped in scopes. In the current version
// of Asl there are two level of scopes: the global and the
// local. The former for the symbols of function names, and
// the latter for symbols declared inside a function:
// parameters and local variables.
// The SymTable uses a 'stack' to keep the current available
// scopes that determines which symbols are visible and
// which are not. Entering in a function will push a new
// scope to the stack and exiting will pop the stack.

class SymTable {

public:

  // The ScopeId is an index in a vector
  typedef std::size_t ScopeId;

  // Constructor
  SymTable(TypesMgr & Types);
  // Destructor
  ~SymTable() = default;

  // Manage the stack of scopes
  //   - create a new empty scope and push its ScopeId in the stack
  ScopeId pushNewScope  (const std::string & name);
  //   - pop the stack of scopes
  void    popScope      ();
  //   - push a previously created scope sc and set it as current scope
  void    pushThisScope (ScopeId sc);
  //   - returns the current scope
  ScopeId topScope      ()                          const;

  // Methods to find an ident
  //   - in the current scope (top of the stack)
  bool    findInCurrentScope (const std::string & ident)             const;
  //   - in the whole stack. Returns the number of scopes skipped to
                          // find the symbol, or -1 if it is not found
  int     findInStack        (const std::string & ident)             const;

  // Adds a new symbol in the current scope
  void addLocalVar  (const std::string & ident, TypesMgr::TypeId type);
  void addParameter (const std::string & ident, TypesMgr::TypeId type);
  void addFunction  (const std::string & ident, TypesMgr::TypeId type);

  // Accessors to check the class of the symbol. If not found return false
  bool isLocalVarClass  (const std::string & ident) const;
  bool isParameterClass (const std::string & ident) const;
  bool isFunctionClass  (const std::string & ident) const;

  // Accessor to get the TypeId of a symbol. If not found return type 'error'
  TypesMgr::TypeId getType (const std::string & ident) const;

  // Print the symbols of a scope on the standard output
  //   - the symbols of the current scope (top of the stack)
  void printCurrentScope () const;
  //   - the symbols of the whole stack
  void print             () const;

  // Returns the type (TypeId) of the function whose scope is
  // on top of the stack
  TypesMgr::TypeId getCurrentFunctionTy () const;
  bool noMainProperlyDeclared() const;


private:
  // Forward declaration of class ScopeInfo
  class ScopeInfo;

  // Attributes:
  TypesMgr               & Types;
  std::vector<ScopeInfo>   ScopesVec;
  std::vector<ScopeId>     ScopeIdsStack;

  //////////////////////////////////////////////////////////////////
  // Class ScopeInfo: is declared inside SymTable and is private,
  // so only the SymTable can operate with Scope objects.
  // It keeps the information of the symbols declared is one scope.

  class ScopeInfo {
  public:
    // Constructor
    ScopeInfo () = delete;
    ScopeInfo (const std::string & name);

    // Accessor to get the name of the scope
    std::string getName () const;

    // Mutators to add symbols to the scope
    void addLocalVar  (const std::string & ident, TypesMgr::TypeId type);
    void addParameter (const std::string & ident, TypesMgr::TypeId type);
    void addFunction  (const std::string & ident, TypesMgr::TypeId type);

    // Accessor to check the existence of a symbol
    bool findSymbol (const std::string & ident) const;

    // Accessors to check the class of the symbol. If not found return false
    bool isLocalVarClass  (const std::string & ident) const;
    bool isParameterClass (const std::string & ident) const;
    bool isFunctionClass  (const std::string & ident) const;

    // Accessor to get the TypeId of a symbol. The symbol MUST exist
    TypesMgr::TypeId getType (const std::string & ident) const;

    // Writes the contents of the scope to the standard output
    void print (TypesMgr & Types) const;

  private:

    // Formard decration of class SymbolInfo
    class SymbolInfo;

    // For the name of the scope
    std::string name;
    // The information associated to each identifier declared in this scope.
    std::map<std::string, SymbolInfo> SymbolsMap;
    // For remember the order in which the Ids where introduced.
    std::vector<std::string> IdentsList;


    //////////////////////////////////////////////////////////////////
    // Class SymbolInfo: is declared inside ScopeInfo and is private,
    // so only the ScopeInfo can operate with SymbolInfo objects.
    // It keeps the information of one symbol: its symbol class
    // (function, parameter or local variable) and its type (TypeId)

    class SymbolInfo {
    public:
      enum SymClassId {
	FirstSymClassId = -2,
	ErrorClassId    = -1,      // "error" symbol class
	// Normal symbol classes:
	LocalVarId      =  0,      // local variables
	ParameterId     ,          // parameters
	FunctionId      ,          // functions
	LastSymClassId  ,
      };

      // Constructors
      SymbolInfo ();
      SymbolInfo (SymClassId c, TypesMgr::TypeId tid);

      // Accessors for working with the symbol attributes: class and type
      bool             isLocalVarClass  () const;
      bool             isParameterClass () const;
      bool             isFunctionClass  () const;
      bool             isErrorClass     () const;
      TypesMgr::TypeId getType          () const;

      // Method to convert a symbol class to its string representation
      std::string class2string () const;

      // Static methods to create SymbolInfo objects
      static SymbolInfo createLocalVar  (TypesMgr::TypeId type);
      static SymbolInfo createParameter (TypesMgr::TypeId type);
      static SymbolInfo createFunction  (TypesMgr::TypeId type);

    private:
      SymClassId       classId;
      TypesMgr::TypeId type;

    };  // class SymbolInfo

  };  // class ScopeInfo

};  // class SymTable
