
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AslListener.h"


/**
 * This class provides an empty implementation of AslListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AslBaseListener : public AslListener {
public:

  virtual void enterProgram(AslParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(AslParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunction(AslParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(AslParser::FunctionContext * /*ctx*/) override { }

  virtual void enterDeclarations(AslParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(AslParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterVariable_decl(AslParser::Variable_declContext * /*ctx*/) override { }
  virtual void exitVariable_decl(AslParser::Variable_declContext * /*ctx*/) override { }

  virtual void enterType(AslParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(AslParser::TypeContext * /*ctx*/) override { }

  virtual void enterStatements(AslParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(AslParser::StatementsContext * /*ctx*/) override { }

  virtual void enterAssignStmt(AslParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(AslParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(AslParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(AslParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(AslParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(AslParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterProcCall(AslParser::ProcCallContext * /*ctx*/) override { }
  virtual void exitProcCall(AslParser::ProcCallContext * /*ctx*/) override { }

  virtual void enterReadStmt(AslParser::ReadStmtContext * /*ctx*/) override { }
  virtual void exitReadStmt(AslParser::ReadStmtContext * /*ctx*/) override { }

  virtual void enterWriteExpr(AslParser::WriteExprContext * /*ctx*/) override { }
  virtual void exitWriteExpr(AslParser::WriteExprContext * /*ctx*/) override { }

  virtual void enterWriteString(AslParser::WriteStringContext * /*ctx*/) override { }
  virtual void exitWriteString(AslParser::WriteStringContext * /*ctx*/) override { }

  virtual void enterLeft_expr(AslParser::Left_exprContext * /*ctx*/) override { }
  virtual void exitLeft_expr(AslParser::Left_exprContext * /*ctx*/) override { }

  virtual void enterBinaryop(AslParser::BinaryopContext * /*ctx*/) override { }
  virtual void exitBinaryop(AslParser::BinaryopContext * /*ctx*/) override { }

  virtual void enterBoolean(AslParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(AslParser::BooleanContext * /*ctx*/) override { }

  virtual void enterExprIdent(AslParser::ExprIdentContext * /*ctx*/) override { }
  virtual void exitExprIdent(AslParser::ExprIdentContext * /*ctx*/) override { }

  virtual void enterArithmetic(AslParser::ArithmeticContext * /*ctx*/) override { }
  virtual void exitArithmetic(AslParser::ArithmeticContext * /*ctx*/) override { }

  virtual void enterRelational(AslParser::RelationalContext * /*ctx*/) override { }
  virtual void exitRelational(AslParser::RelationalContext * /*ctx*/) override { }

  virtual void enterValue(AslParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(AslParser::ValueContext * /*ctx*/) override { }

  virtual void enterIdent(AslParser::IdentContext * /*ctx*/) override { }
  virtual void exitIdent(AslParser::IdentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

