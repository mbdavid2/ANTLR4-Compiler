//////////////////////////////////////////////////////////////////////
//
//    TreeDecoration - Tree node attributes for
//                     the Asl programming language
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
//////////////////////////////////////////////////////////////////////

#include "TreeDecoration.h"

#include "TypesMgr.h"
#include "SymTable.h"
#include "code.h"

#include "antlr4-runtime.h"
#include "antlr4-runtime.h"

#include <string>


// Getters:
SymTable::ScopeId TreeDecoration::getScope(antlr4::ParserRuleContext *ctx) {
  return ScopeDecor.get(ctx);
}

TypesMgr::TypeId TreeDecoration::getType(antlr4::ParserRuleContext *ctx) {
  return TypeDecor.get(ctx);
}

bool TreeDecoration::getIsLValue(antlr4::ParserRuleContext *ctx) {
  return IsLValueDecor.get(ctx);
}

std::string TreeDecoration::getAddr(antlr4::ParserRuleContext *ctx) {
  return AddrDecor.get(ctx);
}

std::string TreeDecoration::getOffset(antlr4::ParserRuleContext *ctx) {
  return OffsetDecor.get(ctx);
}

instructionList TreeDecoration::getCode(antlr4::ParserRuleContext *ctx) {
  return CodeDecor.get(ctx);
}

// Setters:
void TreeDecoration::putScope(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  ScopeDecor.put(ctx, s);
}

void TreeDecoration::putType(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  TypeDecor.put(ctx, t);
}

void TreeDecoration::putIsLValue(antlr4::ParserRuleContext *ctx, bool b) {
  IsLValueDecor.put(ctx, b);
}

void TreeDecoration::putAddr(antlr4::ParserRuleContext *ctx, const std::string & a) {
  AddrDecor.put(ctx, a);
}

void TreeDecoration::putOffset(antlr4::ParserRuleContext *ctx, const std::string & o) {
  OffsetDecor.put(ctx, o);
}

void TreeDecoration::putCode(antlr4::ParserRuleContext *ctx, const instructionList & c) {
  CodeDecor.put(ctx, c);
}
