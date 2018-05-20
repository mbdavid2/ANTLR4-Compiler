//////////////////////////////////////////////////////////////////////
//
//    CodeGenListener - Walk the parser tree to do
//                             the generation of code
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

#include "CodeGenListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

using namespace std;


// Constructor
CodeGenListener::CodeGenListener(TypesMgr       & Types,
				 SymTable       & Symbols,
				 TreeDecoration & Decorations,
				 code           & Code) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Code{Code} {
}

void CodeGenListener::enterProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
}
void CodeGenListener::exitProgram(AslParser::ProgramContext *ctx) {
  Symbols.popScope();
  DEBUG_EXIT();
}

void CodeGenListener::enterFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();
  subroutine subr(ctx->ID()->getText());
  Code.add_subroutine(subr);
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  codeCounters.reset();
}
void CodeGenListener::exitFunction(AslParser::FunctionContext *ctx) {
  subroutine & subrRef = Code.get_last_subroutine();
  instructionList code = getCodeDecor(ctx->statements());
  if (ctx->type() != NULL) subrRef.add_param("_result");
  if (ctx->parameters() != NULL) {
    for(auto eCtx : ctx->parameters()->ID()) {
        subrRef.add_param(eCtx->getText());
    } 
  }
  if (ctx->type() != NULL) {
	std::string ret = getAddrDecor(ctx->expr());
  	instructionList codeExp = getCodeDecor(ctx->expr());
  	code = code || codeExp || instruction::ILOAD("_result", ret);
  	putAddrDecor(ctx, ret);
  }
  /*if (ctx->expr() != NULL) {
    std::string addr1 = getAddrDecor(ctx->expr());
    std::string temp = "%"+codeCounters.newTEMP();
    code = code || instruction::ILOAD(temp, addr1);
  }*/
  code = code || instruction::RETURN();
  subrRef.set_instructions(code);
  Symbols.popScope();
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterExprFuncCall(AslParser::ExprFuncCallContext *ctx) {
    DEBUG_ENTER();
}
    
void CodeGenListener::exitExprFuncCall(AslParser::ExprFuncCallContext *ctx) {
    std:string nameFunc = ctx->ident()->getText();
    instructionList code;
    instructionList pushes;
    std::string temp = "%ret"+codeCounters.newTEMP();;
    code = code || instruction::ILOAD(temp, "3"); //esto es simplemente para "declarar" el temp este
    //donde se guardara el resultado
    pushes = instruction::PUSH("");
    for(auto eCtx : ctx -> expr()) {
        std::string addr1 = getAddrDecor(eCtx);
        pushes = pushes || instruction::PUSH(addr1);        
    }    
    code = code || pushes || instruction::CALL(nameFunc);
    instructionList pops;
    for(auto eCtx : ctx -> expr()) {
        std::string addr1; // = getAddrDecor(eCtx);
        pops = pops || instruction::POP(addr1);        
    }
    //temp = "ret"+codeCounters.newTEMP();
    code = code || pops || instruction::POP(temp);
    putAddrDecor(ctx, temp);
  	putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitProcCall(AslParser::ProcCallContext *ctx) {
    std:string nameFunc = ctx->funcCall()->ident()->getText();
    instructionList code;
    instructionList pushes;

    std::string addr;
    instructionList codeExp;
    for(auto eCtx : ctx->funcCall()->expr()) {
        addr = getAddrDecor(eCtx);
        codeExp = getCodeDecor(eCtx);
        code = code || codeExp;
    }    

    for(auto eCtx : ctx ->funcCall()-> expr()) {
        std::string addr1 = getAddrDecor(eCtx);
        pushes = pushes || instruction::PUSH(addr1);        
    }    
    code = code || pushes || instruction::CALL(nameFunc);
    instructionList pops;
    for(auto eCtx : ctx->funcCall()-> expr()) {
        std::string addr1; // = getAddrDecor(eCtx);
        pops = pops || instruction::POP(addr1);        
    }
    //temp = "ret"+codeCounters.newTEMP();
    code = code || pops;
    //putAddrDecor(ctx, temp);
  	putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterFuncCall(AslParser::FuncCallContext * ctx) {
	DEBUG_ENTER();
}

void CodeGenListener::exitFuncCall(AslParser::FuncCallContext * ctx) {
	/*std::string addr;
  	instructionList code, codeExp;
	for(auto eCtx : ctx-> expr()) {
		addr = getAddrDecor(eCtx);
        cout << "dsada: " << addr << endl;
        codeExp = getCodeDecor(eCtx);
        std::string temp = "%"+codeCounters.newTEMP();
        code = code || codeExp || instruction::ILOAD(temp, addr);
        putAddrDecor(eCtx, temp);
  		putOffsetDecor(eCtx, "");  
    }    */
	/**std::string ret = getAddrDecor(ctx->expr());
  	instructionList code = getCodeDecor(ctx->expr());
  	code = code || instruction::ILOAD("_result", ret);
	putAddrDecor(ctx, temp);
  	putOffsetDecor(ctx, "");*/
   // putCodeDecor(ctx, code);
	DEBUG_EXIT();
}

void CodeGenListener::enterReturnExpr(AslParser::ReturnExprContext *ctx) {
	DEBUG_ENTER();
}

void CodeGenListener::exitReturnExpr(AslParser::ReturnExprContext *ctx) {
	std::string ret = getAddrDecor(ctx->expr());
  	instructionList code = getCodeDecor(ctx->expr());
  	code = code || instruction::ILOAD("_result", ret);
	putAddrDecor(ctx, ret);
  	putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
	DEBUG_EXIT();
}

void CodeGenListener::enterDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitDeclarations(AslParser::DeclarationsContext *ctx) {
  DEBUG_EXIT();
}

void CodeGenListener::enterVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitVariable_decl(AslParser::Variable_declContext *ctx) {
  subroutine       & subrRef = Code.get_last_subroutine();
  TypesMgr::TypeId        t1 = getTypeDecor(ctx->type());
  std::size_t           size = Types.getSizeOfType(t1);
  for (auto eCtx : ctx->ID()){
    subrRef.add_var(eCtx->getText(), size);
  }
  DEBUG_EXIT();
}

void CodeGenListener::enterType(AslParser::TypeContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitType(AslParser::TypeContext *ctx) {
    
  DEBUG_EXIT();
}

void CodeGenListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitStatements(AslParser::StatementsContext *ctx) {
  instructionList code;
  for (auto stCtx : ctx->statement()) {
    code = code || getCodeDecor(stCtx);
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
  instructionList  code;
  std::string     addr1 = getAddrDecor(ctx->left_expr());
  // std::string     offs1 = getOffsetDecor(ctx->left_expr());
  instructionList code1 = getCodeDecor(ctx->left_expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  std::string     addr2 = getAddrDecor(ctx->expr());
  // std::string     offs2 = getOffsetDecor(ctx->expr());
  instructionList code2 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());
  if (Types.isFloatTy(tid1) || Types.isFloatTy(tid2)) {
    code = code1 || code2 || instruction::FLOAD(addr1, addr2);
  }
  else if (Types.isIntegerTy(tid1)) {
    code = code1 || code2 || instruction::ILOAD(addr1, addr2);
  }
  else if (Types.isCharacterTy(tid1)) {
    code = code1 || code2 || instruction::CHLOAD(addr1, addr2);
  }
  else if (Types.isBooleanTy(tid1)) { //TODO: bools con int??
    code = code1 || code2 || instruction::ILOAD(addr1, addr2);
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements(0));
  std::string      label = codeCounters.newLabelIF();
  std::string labelEndIf = "endif"+label;
  code = code1 || instruction::FJUMP(addr1, labelEndIf) ||
         code2 || instruction::LABEL(labelEndIf);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
}

void CodeGenListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
  instructionList   code;
  std::string      addr1 = getAddrDecor(ctx->expr());
  instructionList  code1 = getCodeDecor(ctx->expr());
  instructionList  code2 = getCodeDecor(ctx->statements());
  
  std::string label = codeCounters.newLabelWHILE();
  
  std::string labelEndWhile = "endwhile"+label;
  std::string labelStartWhile = "startwhile"+label;
  
  
  code = instruction::LABEL(labelStartWhile) || code1 || instruction::FJUMP(addr1, labelEndWhile) ||
         code2 || instruction::UJUMP(labelStartWhile) || instruction::LABEL(labelEndWhile);
         
         
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
  instructionList  code;
  std::string     addr1 = getAddrDecor(ctx->left_expr());
  // std::string     offs1 = getOffsetDecor(ctx->left_expr());
  instructionList code1 = getCodeDecor(ctx->left_expr());
  // TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());
  code = code1 || instruction::READI(addr1);
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
  instructionList code;
  std::string     addr1 = getAddrDecor(ctx->expr());
  // std::string     offs1 = getOffsetDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId tid1 = getTypeDecor(ctx->expr());
  if (Types.isBooleanTy(tid1)) {
  	code = code1 || instruction::WRITEI(addr1); //TODO: NPI
  }
  else if (Types.isIntegerTy(tid1)) {
  	code = code1 || instruction::WRITEI(addr1);
  }
  else if (Types.isFloatTy(tid1)) {
  	code = code1 || instruction::WRITEF(addr1);
  }
  else if (Types.isCharacterTy(tid1)) {
  	code = code1 || instruction::WRITEC(addr1);
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterWriteString(AslParser::WriteStringContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitWriteString(AslParser::WriteStringContext *ctx) {
  instructionList code;
  std::string s = ctx->STRING()->getText();
  std::string temp = "%"+codeCounters.newTEMP();
  int i = 1;
  while (i < int(s.size())-1) {
    if (s[i] != '\\') {
      code = code ||
	     instruction::CHLOAD(temp, s.substr(i,1)) ||
	     instruction::WRITEC(temp);
      i += 1;
    }
    else {
      assert(i < int(s.size())-2);
      if (s[i+1] == 'n') {
        code = code || instruction::WRITELN();
        i += 2;
      }
      else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,2)) ||
	       instruction::WRITEC(temp);
        i += 2;
      }
      else {
        code = code ||
               instruction::CHLOAD(temp, s.substr(i,1)) ||
	       instruction::WRITEC(temp);
        i += 1;
      }
    }
  }
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  DEBUG_ENTER();
}

void CodeGenListener::enterArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  //TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  //cout << "salu2" << "   1: " << addr1 << "   2: " << addr2 << endl;
  if (Types.isFloatTy(t1) || Types.isFloatTy(t2)) {
    //Operaciones con floats
    std::string temp1 = "%"+codeCounters.newTEMP();
    std::string temp2 = "%"+codeCounters.newTEMP();
    if(Types.isFloatTy(t1) && !Types.isFloatTy(t2)){
        if (ctx->MUL())
        code = code ||instruction::FLOAT(temp2,addr2) ||instruction::FMUL(temp, addr1, temp2);
        else if (ctx->DIV())
        code = code ||instruction::FLOAT(temp2,addr2) || instruction::FDIV(temp, addr1, temp2);
        else if (ctx->MINUS())
        code = code ||instruction::FLOAT(temp2,addr2) || instruction::FSUB(temp, addr1, temp2);
        else if (ctx->PLUS())
        code = code ||instruction::FLOAT(temp2,addr2) || instruction::FADD(temp, addr1, temp2);
        else if (ctx->MOD())
        code = code ||instruction::FLOAT(temp2,addr2) || instruction::FDIV(temp, addr1, temp2); //TODO: mod!!
    }
    else if(!Types.isFloatTy(t1) && Types.isFloatTy(t2)){
        if (ctx->MUL())
        code = code ||instruction::FLOAT(temp1,addr1) ||instruction::FMUL(temp, temp1, addr2);
        else if (ctx->DIV())
        code = code ||instruction::FLOAT(temp1,addr1) || instruction::FDIV(temp, temp1, addr2);
        else if (ctx->MINUS())
        code = code ||instruction::FLOAT(temp1,addr1) || instruction::FSUB(temp, temp1, addr2);
        else if (ctx->PLUS())
        code = code ||instruction::FLOAT(temp1,addr1) || instruction::FADD(temp, temp1, addr2);
        else if (ctx->MOD())
        code = code ||instruction::FLOAT(temp1,addr1) || instruction::FDIV(temp, temp1, addr2); //TODO: mod!!
    }
    else{
        if (ctx->MUL())
        code = code ||instruction::FMUL(temp, addr1, addr2);
        else if (ctx->DIV())
        code = code ||instruction::FDIV(temp, addr1, addr2);
        else if (ctx->MINUS())
        code = code ||instruction::FSUB(temp, addr1, addr2);
        else if (ctx->PLUS())
        code = code ||instruction::FADD(temp, addr1, addr2);
        else if (ctx->MOD())
        code = code ||instruction::FDIV(temp, addr1, addr2); //TODO: mod!!
        
    }
  }
  else {
    if (ctx->MUL())
      code = code || instruction::MUL(temp, addr1, addr2);
    else if (ctx->DIV())
      code = code || instruction::DIV(temp, addr1, addr2);
    else if (ctx->MINUS())
      code = code || instruction::SUB(temp, addr1, addr2);
    else if (ctx->PLUS())
      code = code || instruction::ADD(temp, addr1, addr2);
    else if (ctx->MOD())
      code = code || instruction::DIV(temp, addr1, addr2); //TODO: mod!!
  }
  //cout << "salu2" << "   1: " << addr1 << "   2: " << addr2 << "result temp: " << temp << endl;
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterBinaryop(AslParser::BinaryopContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitBinaryop(AslParser::BinaryopContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->AND())
    code = code || instruction::AND(temp, addr1, addr2);
  else if (ctx->OR())
    code = code || instruction::OR(temp, addr1, addr2);
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterParenthesis(AslParser::ParenthesisContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitParenthesis(AslParser::ParenthesisContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  instructionList code  = code1;
  putAddrDecor(ctx, addr1);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterUnary(AslParser::UnaryContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitUnary(AslParser::UnaryContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr());
  instructionList code1 = getCodeDecor(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  instructionList code  = code1;
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->NOT())
    code = code || instruction::NOT(temp, addr1);
  else if (ctx->MINUS()) {
    if (Types.isFloatTy(t1)) code = code || instruction::FNEG(temp, addr1);
    else code = code || instruction::NEG(temp, addr1);
  }
  
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitRelational(AslParser::RelationalContext *ctx) {
  std::string     addr1 = getAddrDecor(ctx->expr(0));
  instructionList code1 = getCodeDecor(ctx->expr(0));
  std::string     addr2 = getAddrDecor(ctx->expr(1));
  instructionList code2 = getCodeDecor(ctx->expr(1));
  instructionList code  = code1 || code2;
  // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
  // TypesMgr::TypeId t  = getTypeDecor(ctx);
  std::string temp = "%"+codeCounters.newTEMP();
  
  //op=EQUAL|op=NOTEQUAL|op=LESS|op=LESSEQ|op=BIGGER|op=BIGGEREQ
  
  if (ctx->EQUAL())
    code = code || instruction::EQ(temp, addr1, addr2);
  else if (ctx->NOTEQUAL())
    code = code || instruction::EQ(temp, addr1, addr2) || instruction::NOT(temp, temp);
  else if (ctx->LESS())
    code = code || instruction::LT(temp, addr1, addr2);
  else if (ctx->LESSEQ()) {
    std::string tempAux = "%"+codeCounters.newTEMP();
    code = code || instruction::EQ(tempAux, addr1, addr2)||instruction::LT(temp, addr1, addr2) || instruction::OR(temp, temp, tempAux) ;
  }
  else if (ctx->BIGGER()){
    std::string tempAux = "%"+codeCounters.newTEMP();
    code = code || instruction::EQ(tempAux, addr1, addr2)||instruction::LT(temp, addr1, addr2) || instruction::OR(temp, temp, tempAux) || instruction::NOT(temp, temp)  ;
  }
  else if (ctx->BIGGEREQ())
    code = code || instruction::LT(temp, addr1, addr2) || instruction::NOT(temp, temp);
  
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitValue(AslParser::ValueContext *ctx) {
  instructionList code;
  std::string temp = "%"+codeCounters.newTEMP();
  if (ctx->BOOLEAN()) {
    if(ctx->getText() == "true")
        code = instruction::ILOAD(temp, "1");
  	else
        code = instruction::ILOAD(temp, "0");
  }
  else if (ctx->INTVAL()) {
  	code = instruction::ILOAD(temp, ctx->getText());
  }
  else if (ctx->FLOATVAL()) {
  	code = instruction::FLOAD(temp, ctx->getText());
  }
  else if (ctx->CHARVAL()) {
  	code = instruction::CHLOAD(temp, ctx->getText());
  }
  putAddrDecor(ctx, temp);
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, code);
  DEBUG_EXIT();
}

void CodeGenListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
  putAddrDecor(ctx, getAddrDecor(ctx->ident()));
  putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
  putCodeDecor(ctx, getCodeDecor(ctx->ident()));
  DEBUG_EXIT();
}

void CodeGenListener::enterIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIdent(AslParser::IdentContext *ctx) {
  putAddrDecor(ctx, ctx->ID()->getText());
  putOffsetDecor(ctx, "");
  putCodeDecor(ctx, instructionList());
  DEBUG_EXIT();
}

// void CodeGenListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void CodeGenListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void CodeGenListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG(">>> visit " << node->getSymbol()->getLine() << ":" << node->getSymbol()->getCharPositionInLine() << " CodeGen TerminalNode");
// }
// void CodeGenListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type, Addr, Offset and Code
SymTable::ScopeId CodeGenListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
std::string CodeGenListener::getAddrDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getAddr(ctx);
}
std::string  CodeGenListener::getOffsetDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getOffset(ctx);
}
instructionList CodeGenListener::getCodeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getCode(ctx);
}

// Setters for the necessary tree node attributes:
//   Addr, Offset and Code
void CodeGenListener::putAddrDecor(antlr4::ParserRuleContext *ctx, const std::string & a) {
  Decorations.putAddr(ctx, a);
}
void CodeGenListener::putOffsetDecor(antlr4::ParserRuleContext *ctx, const std::string & o) {
  Decorations.putOffset(ctx, o);
}
void CodeGenListener::putCodeDecor(antlr4::ParserRuleContext *ctx, const instructionList & c) {
  Decorations.putCode(ctx, c);
}
