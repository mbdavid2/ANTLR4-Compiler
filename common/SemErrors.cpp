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

#include "SemErrors.h"

#include "antlr4-runtime.h"

#include <iostream>
#include <string>
#include <algorithm>

// using namespace std;


void SemErrors::print() {
  std::sort(ErrorList.begin(), ErrorList.end(), less);  
  for (auto & error : ErrorList) error.print();
}

bool SemErrors::less(const ErrorInfo & e1, const ErrorInfo & e2) {
  return e1.getLine() < e2.getLine();
}

std::size_t SemErrors::getNumberOfSemanticErrors() const {
  return ErrorList.size();
}

void SemErrors::declaredIdent(antlr4::tree::TerminalNode *node) {
  ErrorInfo error(node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine(), "Identifier '" + node->getSymbol()->getText() + "' already declared.");
  ErrorList.push_back(error);
}

void SemErrors::undeclaredIdent(antlr4::tree::TerminalNode *node) {
  ErrorInfo error(node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine(), "Identifier '" + node->getSymbol()->getText() + "' is undeclared.");
  ErrorList.push_back(error);
}

void SemErrors::incompatibleAssignment(antlr4::tree::TerminalNode *node) {
  ErrorInfo error(node->getSymbol()->getLine(), node->getSymbol()->getCharPositionInLine(), "Assignment with incompatible types.");
  ErrorList.push_back(error);
}

void SemErrors::nonReferenceableLeftExpr(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Left expression of assignment is not referenceable.");
  ErrorList.push_back(error);
}

void SemErrors::incompatibleOperator(antlr4::Token* tok) {
  ErrorInfo error(tok->getLine(), tok->getCharPositionInLine(), "Operator '" + tok->getText() + "' with incompatible types.");
  ErrorList.push_back(error);
}

void SemErrors::nonArrayInArrayAccess(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Array access to a non array operand.");
  ErrorList.push_back(error);
}

void SemErrors::nonIntegerIndexInArrayAccess(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Array access witn non integer index.");
  ErrorList.push_back(error);
}

void SemErrors::booleanRequired(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Instruction '" + ctx->getStart()->getText() + "' requires a boolean condition.");
  ErrorList.push_back(error);
}

void SemErrors::isNotCallable(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Identifier '" + ctx->getStart()->getText() + "' is not a callable function.");
  ErrorList.push_back(error);
}

void SemErrors::isNotProcedure(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Identifier '" + ctx->getStart()->getText() + "' is not a procedure.");
  ErrorList.push_back(error);
}

void SemErrors::isNotFunction(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Identifier '" + ctx->getStart()->getText() + "' is a void returning function.");
  ErrorList.push_back(error);
}

void SemErrors::numberOfParameters(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "The number of parameters in the call to '" + ctx->getStart()->getText() + "' does not match.");
  ErrorList.push_back(error);
}

void SemErrors::incompatibleParameter(antlr4::ParserRuleContext *pCtx,
				      unsigned int n,
				      antlr4::ParserRuleContext *cCtx) {
  ErrorInfo error(pCtx->getStart()->getLine(), pCtx->getStart()->getCharPositionInLine(), "Parameter #" + std::to_string(n) + " with incompatible types in call to '" + cCtx->getStart()->getText() + "'.");
  ErrorList.push_back(error);
}

void SemErrors::referenceableParameter(antlr4::ParserRuleContext *pCtx,
				       unsigned int n,
				       antlr4::ParserRuleContext *cCtx) {
  ErrorInfo error(pCtx->getStart()->getLine(), pCtx->getStart()->getCharPositionInLine(), "Parameter #" + std::to_string(n) + " is expected to be referenceable in call to '" + cCtx->getStart()->getText() + "'.");
  ErrorList.push_back(error);
}

void SemErrors::incompatibleReturn(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Return with incompatible type.");
  ErrorList.push_back(error);
}

void SemErrors::readWriteRequireBasic(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Basic type required in '" + ctx->getStart()->getText() + "'.");
  ErrorList.push_back(error);
}

void SemErrors::nonReferenceableExpression(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStart()->getLine(), ctx->getStart()->getCharPositionInLine(), "Referenceable expression required in '" + ctx->getStart()->getText() + "'.");
  ErrorList.push_back(error);
}

void SemErrors::noMainProperlyDeclared(antlr4::ParserRuleContext *ctx) {
  ErrorInfo error(ctx->getStop()->getLine(), ctx->getStop()->getCharPositionInLine(), "There is no 'main' function properly declared.");
  ErrorList.push_back(error);
}

SemErrors::ErrorInfo::ErrorInfo(std::size_t line, std::size_t coln, std::string message)
  : line{line}, coln{coln}, message{message} {
}

void SemErrors::ErrorInfo::print() const {
  std::cout << "Line " << line << ":" << coln << " error: " << message << std::endl;
}

std::size_t SemErrors::ErrorInfo::getLine() const {
  return line;
}
