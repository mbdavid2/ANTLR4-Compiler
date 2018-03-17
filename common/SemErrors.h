/////////////////////////////////////////////////////////////////
//
//    SemErrors - Semantic errors for the Asl programming language
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

#include "antlr4-runtime.h"

#include <string>
#include <vector>

// using namespace std;


////////////////////////////////////////////////////////////////
// Class SemErrors: this class contains methods that emit
// semantic error messages with their localization.
// It is used by the semantic listeners:
//   - SymbolsListener
//   - TypeCheckListener
// Semantic errors emitted are kept in a vector and when the
// typecheck finishes they will be printed (sorted by line number)

class SemErrors {

public:

  // Constructor
  SemErrors() = default;

  // Write the semantic errors ordered by line number
  void print ();

  // Accessor to get the number of semantic errors
  std::size_t getNumberOfSemanticErrors () const;

  // Methods that emit the error messages
  void declaredIdent                (antlr4::tree::TerminalNode *node);
  void undeclaredIdent              (antlr4::tree::TerminalNode *node);
  void incompatibleAssignment       (antlr4::tree::TerminalNode *node);
  void nonReferenceableLeftExpr     (antlr4::ParserRuleContext *ctx);
  void incompatibleOperator         (antlr4::Token *node);
  void nonArrayInArrayAccess        (antlr4::ParserRuleContext *ctx);
  void nonIntegerIndexInArrayAccess (antlr4::ParserRuleContext *ctx);
  void booleanRequired              (antlr4::ParserRuleContext *ctx);
  void isNotCallable                (antlr4::ParserRuleContext *ctx);
  void isNotProcedure               (antlr4::ParserRuleContext *ctx);
  void isNotFunction                (antlr4::ParserRuleContext *ctx);
  void numberOfParameters           (antlr4::ParserRuleContext *ctx);
  void incompatibleParameter        (antlr4::ParserRuleContext *pCtx,
				     unsigned int n,
				     antlr4::ParserRuleContext *cCtx);
  void referenceableParameter       (antlr4::ParserRuleContext *pCtx,
				     unsigned int n,
				     antlr4::ParserRuleContext *cCtx);
  void incompatibleReturn           (antlr4::ParserRuleContext *ctx);
  void readWriteRequireBasic        (antlr4::ParserRuleContext *ctx);
  void nonReferenceableExpression   (antlr4::ParserRuleContext *ctx);
  void noMainProperlyDeclared       (antlr4::ParserRuleContext *ctx);


private:

  class ErrorInfo {
  public:
    ErrorInfo() = delete;
    ErrorInfo(std::size_t line, std::size_t coln, std::string message);
    std::size_t getLine() const;
    void print() const;
  private:
    std::size_t line, coln;
    std::string message;
  };

  // List of semantic errors
  std::vector<ErrorInfo> ErrorList;

  // Compare two errors to determine the order (needed in print)
  static bool less(const ErrorInfo & e1, const ErrorInfo & e2);

};  // class SemErrors
