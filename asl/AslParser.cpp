
// Generated from Asl.g4 by ANTLR 4.7.1


#include "AslListener.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

void AslParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AslParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(28);
      function();
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(33);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::ParametersContext* AslParser::FunctionContext::parameters() {
  return getRuleContext<AslParser::ParametersContext>(0);
}

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::FunctionContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

void AslParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AslParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(62);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(35);
      match(AslParser::FUNC);
      setState(36);
      match(AslParser::ID);
      setState(37);
      match(AslParser::T__0);
      setState(39);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ID) {
        setState(38);
        parameters();
      }
      setState(41);
      match(AslParser::T__1);
      setState(42);
      declarations();
      setState(43);
      statements();
      setState(44);
      match(AslParser::ENDFUNC);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(46);
      match(AslParser::FUNC);
      setState(47);
      match(AslParser::ID);
      setState(48);
      match(AslParser::T__0);
      setState(50);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ID) {
        setState(49);
        parameters();
      }
      setState(52);
      match(AslParser::T__1);
      setState(53);
      match(AslParser::T__2);
      setState(54);
      type();
      setState(55);
      declarations();
      setState(56);
      statements();
      setState(57);
      match(AslParser::RETURN);
      setState(58);
      expr(0);
      setState(59);
      match(AslParser::T__3);
      setState(60);
      match(AslParser::ENDFUNC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

AslParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::ParametersContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::ParametersContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

std::vector<AslParser::TypeContext *> AslParser::ParametersContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::ParametersContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}


size_t AslParser::ParametersContext::getRuleIndex() const {
  return AslParser::RuleParameters;
}

void AslParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void AslParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

AslParser::ParametersContext* AslParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(AslParser::ID);
    setState(65);
    match(AslParser::T__2);
    setState(66);
    type();
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__4) {
      setState(67);
      match(AslParser::T__4);
      setState(68);
      match(AslParser::ID);
      setState(69);
      match(AslParser::T__2);
      setState(70);
      type();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

void AslParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void AslParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(76);
      variable_decl();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

void AslParser::Variable_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_decl(this);
}

void AslParser::Variable_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_decl(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    match(AslParser::VAR);
    setState(83);
    match(AslParser::ID);
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__4) {
      setState(84);
      match(AslParser::T__4);
      setState(85);
      match(AslParser::ID);
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    match(AslParser::T__2);
    setState(92);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::Type_basicContext* AslParser::TypeContext::type_basic() {
  return getRuleContext<AslParser::Type_basicContext>(0);
}

tree::TerminalNode* AslParser::TypeContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::TypeContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::TypeContext::OF() {
  return getToken(AslParser::OF, 0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

void AslParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AslParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::INT:
      case AslParser::FLOAT:
      case AslParser::BOOL:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        type_basic();
        break;
      }

      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(95);
        match(AslParser::ARRAY);
        setState(96);
        match(AslParser::T__5);
        setState(97);
        match(AslParser::INTVAL);
        setState(98);
        match(AslParser::T__6);
        setState(99);
        match(AslParser::OF);
        setState(100);
        type_basic();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_basicContext ------------------------------------------------------------------

AslParser::Type_basicContext::Type_basicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Type_basicContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::Type_basicContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::Type_basicContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::Type_basicContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::Type_basicContext::getRuleIndex() const {
  return AslParser::RuleType_basic;
}

void AslParser::Type_basicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_basic(this);
}

void AslParser::Type_basicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_basic(this);
}

AslParser::Type_basicContext* AslParser::type_basic() {
  Type_basicContext *_localctx = _tracker.createInstance<Type_basicContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleType_basic);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

void AslParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void AslParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleStatements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(108);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(105);
        statement(); 
      }
      setState(110);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ProcCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcCall(this);
}
void AslParser::ProcCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcCall(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteExpr(this);
}
void AslParser::WriteExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteExpr(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void AslParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void AslParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReadStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadStmt(this);
}
void AslParser::ReadStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void AslParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- ReturnExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnExprContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnExprContext::ReturnExprContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReturnExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnExpr(this);
}
void AslParser::ReturnExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnExpr(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteString(this);
}
void AslParser::WriteStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteString(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(111);
      left_expr();
      setState(112);
      match(AslParser::ASSIGN);
      setState(113);
      expr(0);
      setState(114);
      match(AslParser::T__3);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(116);
      match(AslParser::WHILE);
      setState(117);
      expr(0);
      setState(118);
      match(AslParser::DO);
      setState(119);
      statements();
      setState(120);
      match(AslParser::ENDWHILE);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(122);
      match(AslParser::IF);
      setState(123);
      expr(0);
      setState(124);
      match(AslParser::THEN);
      setState(125);
      statements();
      setState(128);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(126);
        match(AslParser::ELSE);
        setState(127);
        statements();
      }
      setState(130);
      match(AslParser::ENDIF);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(132);
      ident();
      setState(133);
      match(AslParser::T__0);
      setState(142);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLEAN)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(134);
        expr(0);
        setState(139);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__4) {
          setState(135);
          match(AslParser::T__4);
          setState(136);
          expr(0);
          setState(141);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(144);
      match(AslParser::T__1);
      setState(145);
      match(AslParser::T__3);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(147);
      match(AslParser::READ);
      setState(148);
      left_expr();
      setState(149);
      match(AslParser::T__3);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(151);
      match(AslParser::WRITE);
      setState(152);
      expr(0);
      setState(153);
      match(AslParser::T__3);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(155);
      match(AslParser::WRITE);
      setState(156);
      match(AslParser::STRING);
      setState(157);
      match(AslParser::T__3);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnExprContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(158);
      match(AslParser::RETURN);
      setState(160);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLEAN)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(159);
        expr(0);
      }
      setState(162);
      match(AslParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::Array_accessContext* AslParser::Left_exprContext::array_access() {
  return getRuleContext<AslParser::Array_accessContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft_expr(this);
}

void AslParser::Left_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft_expr(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(167);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(165);
      ident();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(166);
      array_access();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BinaryopContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BinaryopContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BinaryopContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BinaryopContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BinaryopContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BinaryopContext::BinaryopContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::BinaryopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryop(this);
}
void AslParser::BinaryopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryop(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIdent(this);
}
void AslParser::ExprIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIdent(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic(this);
}
void AslParser::ArithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NOTEQUAL() {
  return getToken(AslParser::NOTEQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LESS() {
  return getToken(AslParser::LESS, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LESSEQ() {
  return getToken(AslParser::LESSEQ, 0);
}

tree::TerminalNode* AslParser::RelationalContext::BIGGER() {
  return getToken(AslParser::BIGGER, 0);
}

tree::TerminalNode* AslParser::RelationalContext::BIGGEREQ() {
  return getToken(AslParser::BIGGEREQ, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::RelationalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational(this);
}
void AslParser::RelationalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::UnaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::UnaryContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::UnaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary(this);
}
void AslParser::UnaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParenthesisContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ParenthesisContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenthesis(this);
}
void AslParser::ParenthesisContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenthesis(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::BOOLEAN() {
  return getToken(AslParser::BOOLEAN, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}
void AslParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}
//----------------- ExprArrayAccessContext ------------------------------------------------------------------

AslParser::Array_accessContext* AslParser::ExprArrayAccessContext::array_access() {
  return getRuleContext<AslParser::Array_accessContext>(0);
}

AslParser::ExprArrayAccessContext::ExprArrayAccessContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprArrayAccess(this);
}
void AslParser::ExprArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprArrayAccess(this);
}
//----------------- ExprFuncCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprFuncCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

std::vector<AslParser::ExprContext *> AslParser::ExprFuncCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ExprFuncCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ExprFuncCallContext::ExprFuncCallContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprFuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprFuncCall(this);
}
void AslParser::ExprFuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprFuncCall(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(200);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(173);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case AslParser::NOT: {
          setState(170);
          dynamic_cast<UnaryContext *>(_localctx)->op = match(AslParser::NOT);
          break;
        }

        case AslParser::PLUS: {
          setState(171);
          dynamic_cast<UnaryContext *>(_localctx)->op = match(AslParser::PLUS);
          break;
        }

        case AslParser::MINUS: {
          setState(172);
          dynamic_cast<UnaryContext *>(_localctx)->op = match(AslParser::MINUS);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(175);
      expr(13);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(176);
      match(AslParser::T__0);
      setState(177);
      expr(0);
      setState(178);
      match(AslParser::T__1);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(180);
      dynamic_cast<ValueContext *>(_localctx)->op = match(AslParser::BOOLEAN);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      dynamic_cast<ValueContext *>(_localctx)->op = match(AslParser::CHARVAL);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(182);
      dynamic_cast<ValueContext *>(_localctx)->op = match(AslParser::INTVAL);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      dynamic_cast<ValueContext *>(_localctx)->op = match(AslParser::FLOATVAL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(184);
      dynamic_cast<ExprIdentContext *>(_localctx)->op = ident();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ExprArrayAccessContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(185);
      dynamic_cast<ExprArrayAccessContext *>(_localctx)->op = array_access();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<ExprFuncCallContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      ident();
      setState(187);
      match(AslParser::T__0);
      setState(196);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::T__0)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::BOOLEAN)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(188);
        expr(0);
        setState(193);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__4) {
          setState(189);
          match(AslParser::T__4);
          setState(190);
          expr(0);
          setState(195);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(198);
      match(AslParser::T__1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(233);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(231);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(206);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::MUL: {
              setState(203);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::MUL);
              break;
            }

            case AslParser::DIV: {
              setState(204);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::DIV);
              break;
            }

            case AslParser::MOD: {
              setState(205);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::MOD);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(208);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(209);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(212);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::PLUS: {
              setState(210);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::PLUS);
              break;
            }

            case AslParser::MINUS: {
              setState(211);
              dynamic_cast<ArithmeticContext *>(_localctx)->op = match(AslParser::MINUS);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(214);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(215);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(222);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::EQUAL: {
              setState(216);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::EQUAL);
              break;
            }

            case AslParser::NOTEQUAL: {
              setState(217);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::NOTEQUAL);
              break;
            }

            case AslParser::LESS: {
              setState(218);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::LESS);
              break;
            }

            case AslParser::LESSEQ: {
              setState(219);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::LESSEQ);
              break;
            }

            case AslParser::BIGGER: {
              setState(220);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::BIGGER);
              break;
            }

            case AslParser::BIGGEREQ: {
              setState(221);
              dynamic_cast<RelationalContext *>(_localctx)->op = match(AslParser::BIGGEREQ);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(224);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryopContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(228);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case AslParser::AND: {
              setState(226);
              dynamic_cast<BinaryopContext *>(_localctx)->op = match(AslParser::AND);
              break;
            }

            case AslParser::OR: {
              setState(227);
              dynamic_cast<BinaryopContext *>(_localctx)->op = match(AslParser::OR);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(230);
          expr(9);
          break;
        }

        } 
      }
      setState(235);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- FuncCallContext ------------------------------------------------------------------

AslParser::FuncCallContext::FuncCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FuncCallContext::ID() {
  return getToken(AslParser::ID, 0);
}

std::vector<AslParser::ExprContext *> AslParser::FuncCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::FuncCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}


size_t AslParser::FuncCallContext::getRuleIndex() const {
  return AslParser::RuleFuncCall;
}

void AslParser::FuncCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncCall(this);
}

void AslParser::FuncCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncCall(this);
}

AslParser::FuncCallContext* AslParser::funcCall() {
  FuncCallContext *_localctx = _tracker.createInstance<FuncCallContext>(_ctx, getState());
  enterRule(_localctx, 22, AslParser::RuleFuncCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::EOF: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case AslParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(237);
        match(AslParser::ID);
        setState(238);
        match(AslParser::T__0);
        setState(247);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AslParser::T__0)
          | (1ULL << AslParser::PLUS)
          | (1ULL << AslParser::MINUS)
          | (1ULL << AslParser::NOT)
          | (1ULL << AslParser::BOOLEAN)
          | (1ULL << AslParser::CHARVAL)
          | (1ULL << AslParser::INTVAL)
          | (1ULL << AslParser::FLOATVAL)
          | (1ULL << AslParser::ID))) != 0)) {
          setState(239);
          expr(0);
          setState(244);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == AslParser::T__4) {
            setState(240);
            match(AslParser::T__4);
            setState(241);
            expr(0);
            setState(246);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(249);
        match(AslParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

void AslParser::IdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdent(this);
}

void AslParser::IdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdent(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_accessContext ------------------------------------------------------------------

AslParser::Array_accessContext::Array_accessContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::Array_accessContext::getRuleIndex() const {
  return AslParser::RuleArray_access;
}

void AslParser::Array_accessContext::copyFrom(Array_accessContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayAccessContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ArrayAccessContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::ArrayAccessContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ArrayAccessContext::ArrayAccessContext(Array_accessContext *ctx) { copyFrom(ctx); }

void AslParser::ArrayAccessContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayAccess(this);
}
void AslParser::ArrayAccessContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayAccess(this);
}
AslParser::Array_accessContext* AslParser::array_access() {
  Array_accessContext *_localctx = _tracker.createInstance<Array_accessContext>(_ctx, getState());
  enterRule(_localctx, 26, AslParser::RuleArray_access);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Array_accessContext *>(_tracker.createInstance<AslParser::ArrayAccessContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(254);
    ident();
    setState(255);
    match(AslParser::T__5);
    setState(256);
    expr(0);
    setState(257);
    match(AslParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 10: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "parameters", "declarations", "variable_decl", 
  "type", "type_basic", "statements", "statement", "left_expr", "expr", 
  "funcCall", "ident", "array_access"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'('", "')'", "':'", "';'", "','", "'['", "']'", "'='", "'=='", "'!='", 
  "'<'", "'<='", "'>'", "'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'var'", 
  "'int'", "'float'", "'bool'", "'char'", "'not'", "'and'", "'or'", "'if'", 
  "'then'", "'else'", "'endif'", "'while'", "'endwhile'", "'do'", "'func'", 
  "'endfunc'", "'read'", "'write'", "'array'", "'of'", "'return'", "", "'true'", 
  "'false'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "ASSIGN", "EQUAL", "NOTEQUAL", "LESS", 
  "LESSEQ", "BIGGER", "BIGGEREQ", "PLUS", "MINUS", "MUL", "DIV", "MOD", 
  "VAR", "INT", "FLOAT", "BOOL", "CHAR", "NOT", "AND", "OR", "IF", "THEN", 
  "ELSE", "ENDIF", "WHILE", "ENDWHILE", "DO", "FUNC", "ENDFUNC", "READ", 
  "WRITE", "ARRAY", "OF", "RETURN", "BOOLEAN", "TRUE", "FALSE", "CHARVAL", 
  "INTVAL", "FLOATVAL", "ID", "STRING", "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x35, 0x106, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x3, 0x2, 0x6, 0x2, 0x20, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0x21, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x2a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x35, 0xa, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x41, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4a, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x4d, 0xb, 0x4, 0x3, 0x5, 0x7, 0x5, 0x50, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x53, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x59, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5c, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x68, 0xa, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x7, 0x9, 0x6d, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x70, 
    0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x83, 0xa, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 
    0xa, 0x8c, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x8f, 0xb, 0xa, 0x5, 0xa, 0x91, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xa3, 0xa, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0xa6, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xaa, 0xa, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb0, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x7, 0xc, 0xc2, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc5, 0xb, 0xc, 
    0x5, 0xc, 0xc7, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xcb, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd1, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd7, 0xa, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0xe1, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0xe7, 0xa, 0xc, 0x3, 0xc, 0x7, 0xc, 0xea, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0xed, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x7, 0xd, 0xf5, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xf8, 0xb, 0xd, 
    0x5, 0xd, 0xfa, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0xfd, 0xa, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x2, 0x3, 0x16, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 
    0x14, 0x16, 0x18, 0x1a, 0x1c, 0x2, 0x3, 0x3, 0x2, 0x17, 0x1a, 0x2, 0x128, 
    0x2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x40, 0x3, 0x2, 0x2, 0x2, 0x6, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x51, 0x3, 0x2, 0x2, 0x2, 0xa, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xa9, 0x3, 0x2, 0x2, 0x2, 0x16, 0xca, 0x3, 0x2, 0x2, 0x2, 0x18, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x100, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x20, 0x5, 0x4, 0x3, 0x2, 0x1f, 0x1e, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0x23, 0x24, 0x7, 0x2, 0x2, 0x3, 0x24, 0x3, 0x3, 0x2, 0x2, 0x2, 0x25, 
    0x26, 0x7, 0x25, 0x2, 0x2, 0x26, 0x27, 0x7, 0x32, 0x2, 0x2, 0x27, 0x29, 
    0x7, 0x3, 0x2, 0x2, 0x28, 0x2a, 0x5, 0x6, 0x4, 0x2, 0x29, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x2b, 0x2c, 0x7, 0x4, 0x2, 0x2, 0x2c, 0x2d, 0x5, 0x8, 0x5, 
    0x2, 0x2d, 0x2e, 0x5, 0x10, 0x9, 0x2, 0x2e, 0x2f, 0x7, 0x26, 0x2, 0x2, 
    0x2f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x25, 0x2, 0x2, 0x31, 
    0x32, 0x7, 0x32, 0x2, 0x2, 0x32, 0x34, 0x7, 0x3, 0x2, 0x2, 0x33, 0x35, 
    0x5, 0x6, 0x4, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x7, 0x4, 
    0x2, 0x2, 0x37, 0x38, 0x7, 0x5, 0x2, 0x2, 0x38, 0x39, 0x5, 0xc, 0x7, 
    0x2, 0x39, 0x3a, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x3b, 0x5, 0x10, 0x9, 0x2, 
    0x3b, 0x3c, 0x7, 0x2b, 0x2, 0x2, 0x3c, 0x3d, 0x5, 0x16, 0xc, 0x2, 0x3d, 
    0x3e, 0x7, 0x6, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x26, 0x2, 0x2, 0x3f, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x40, 0x25, 0x3, 0x2, 0x2, 0x2, 0x40, 0x30, 0x3, 
    0x2, 0x2, 0x2, 0x41, 0x5, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x7, 0x32, 
    0x2, 0x2, 0x43, 0x44, 0x7, 0x5, 0x2, 0x2, 0x44, 0x4b, 0x5, 0xc, 0x7, 
    0x2, 0x45, 0x46, 0x7, 0x7, 0x2, 0x2, 0x46, 0x47, 0x7, 0x32, 0x2, 0x2, 
    0x47, 0x48, 0x7, 0x5, 0x2, 0x2, 0x48, 0x4a, 0x5, 0xc, 0x7, 0x2, 0x49, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x5, 0xa, 
    0x6, 0x2, 0x4f, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x9, 0x3, 0x2, 0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0x16, 0x2, 0x2, 0x55, 0x5a, 0x7, 0x32, 0x2, 0x2, 0x56, 0x57, 
    0x7, 0x7, 0x2, 0x2, 0x57, 0x59, 0x7, 0x32, 0x2, 0x2, 0x58, 0x56, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x5, 0x2, 0x2, 
    0x5e, 0x5f, 0x5, 0xc, 0x7, 0x2, 0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x68, 0x5, 0xe, 0x8, 0x2, 0x61, 0x62, 0x7, 0x29, 0x2, 0x2, 0x62, 0x63, 
    0x7, 0x8, 0x2, 0x2, 0x63, 0x64, 0x7, 0x30, 0x2, 0x2, 0x64, 0x65, 0x7, 
    0x9, 0x2, 0x2, 0x65, 0x66, 0x7, 0x2a, 0x2, 0x2, 0x66, 0x68, 0x5, 0xe, 
    0x8, 0x2, 0x67, 0x60, 0x3, 0x2, 0x2, 0x2, 0x67, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0xd, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x9, 0x2, 0x2, 0x2, 
    0x6a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6d, 0x5, 0x12, 0xa, 0x2, 0x6c, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x5, 0x14, 
    0xb, 0x2, 0x72, 0x73, 0x7, 0xa, 0x2, 0x2, 0x73, 0x74, 0x5, 0x16, 0xc, 
    0x2, 0x74, 0x75, 0x7, 0x6, 0x2, 0x2, 0x75, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x77, 0x7, 0x22, 0x2, 0x2, 0x77, 0x78, 0x5, 0x16, 0xc, 0x2, 0x78, 
    0x79, 0x7, 0x24, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x10, 0x9, 0x2, 0x7a, 0x7b, 
    0x7, 0x23, 0x2, 0x2, 0x7b, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 
    0x1e, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x16, 0xc, 0x2, 0x7e, 0x7f, 0x7, 0x1f, 
    0x2, 0x2, 0x7f, 0x82, 0x5, 0x10, 0x9, 0x2, 0x80, 0x81, 0x7, 0x20, 0x2, 
    0x2, 0x81, 0x83, 0x5, 0x10, 0x9, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x85, 0x7, 0x21, 0x2, 0x2, 0x85, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 
    0x5, 0x1a, 0xe, 0x2, 0x87, 0x90, 0x7, 0x3, 0x2, 0x2, 0x88, 0x8d, 0x5, 
    0x16, 0xc, 0x2, 0x89, 0x8a, 0x7, 0x7, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x16, 
    0xc, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x91, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x4, 0x2, 0x2, 0x93, 0x94, 0x7, 
    0x6, 0x2, 0x2, 0x94, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x27, 
    0x2, 0x2, 0x96, 0x97, 0x5, 0x14, 0xb, 0x2, 0x97, 0x98, 0x7, 0x6, 0x2, 
    0x2, 0x98, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x7, 0x28, 0x2, 0x2, 
    0x9a, 0x9b, 0x5, 0x16, 0xc, 0x2, 0x9b, 0x9c, 0x7, 0x6, 0x2, 0x2, 0x9c, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x28, 0x2, 0x2, 0x9e, 0x9f, 
    0x7, 0x33, 0x2, 0x2, 0x9f, 0xa6, 0x7, 0x6, 0x2, 0x2, 0xa0, 0xa2, 0x7, 
    0x2b, 0x2, 0x2, 0xa1, 0xa3, 0x5, 0x16, 0xc, 0x2, 0xa2, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa6, 0x7, 0x6, 0x2, 0x2, 0xa5, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0x76, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0x86, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x95, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x99, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0x9d, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x5, 0x1a, 
    0xe, 0x2, 0xa8, 0xaa, 0x5, 0x1c, 0xf, 0x2, 0xa9, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xaf, 0x8, 0xc, 0x1, 0x2, 0xac, 0xb0, 0x7, 0x1b, 0x2, 0x2, 0xad, 
    0xb0, 0x7, 0x11, 0x2, 0x2, 0xae, 0xb0, 0x7, 0x12, 0x2, 0x2, 0xaf, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xcb, 0x5, 0x16, 
    0xc, 0xf, 0xb2, 0xb3, 0x7, 0x3, 0x2, 0x2, 0xb3, 0xb4, 0x5, 0x16, 0xc, 
    0x2, 0xb4, 0xb5, 0x7, 0x4, 0x2, 0x2, 0xb5, 0xcb, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xcb, 0x7, 0x2c, 0x2, 0x2, 0xb7, 0xcb, 0x7, 0x2f, 0x2, 0x2, 0xb8, 
    0xcb, 0x7, 0x30, 0x2, 0x2, 0xb9, 0xcb, 0x7, 0x31, 0x2, 0x2, 0xba, 0xcb, 
    0x5, 0x1a, 0xe, 0x2, 0xbb, 0xcb, 0x5, 0x1c, 0xf, 0x2, 0xbc, 0xbd, 0x5, 
    0x1a, 0xe, 0x2, 0xbd, 0xc6, 0x7, 0x3, 0x2, 0x2, 0xbe, 0xc3, 0x5, 0x16, 
    0xc, 0x2, 0xbf, 0xc0, 0x7, 0x7, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x16, 0xc, 
    0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 
    0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x4, 0x2, 0x2, 0xc9, 0xcb, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xab, 0x3, 0x2, 0x2, 0x2, 0xca, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xca, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xca, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xca, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xca, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xd0, 0xc, 
    0xd, 0x2, 0x2, 0xcd, 0xd1, 0x7, 0x13, 0x2, 0x2, 0xce, 0xd1, 0x7, 0x14, 
    0x2, 0x2, 0xcf, 0xd1, 0x7, 0x15, 0x2, 0x2, 0xd0, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xea, 0x5, 0x16, 0xc, 0xe, 0xd3, 
    0xd6, 0xc, 0xc, 0x2, 0x2, 0xd4, 0xd7, 0x7, 0x11, 0x2, 0x2, 0xd5, 0xd7, 
    0x7, 0x12, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xea, 0x5, 0x16, 
    0xc, 0xd, 0xd9, 0xe0, 0xc, 0xb, 0x2, 0x2, 0xda, 0xe1, 0x7, 0xb, 0x2, 
    0x2, 0xdb, 0xe1, 0x7, 0xc, 0x2, 0x2, 0xdc, 0xe1, 0x7, 0xd, 0x2, 0x2, 
    0xdd, 0xe1, 0x7, 0xe, 0x2, 0x2, 0xde, 0xe1, 0x7, 0xf, 0x2, 0x2, 0xdf, 
    0xe1, 0x7, 0x10, 0x2, 0x2, 0xe0, 0xda, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xe0, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdd, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0xe1, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xea, 0x5, 0x16, 0xc, 
    0xc, 0xe3, 0xe6, 0xc, 0xa, 0x2, 0x2, 0xe4, 0xe7, 0x7, 0x1c, 0x2, 0x2, 
    0xe5, 0xe7, 0x7, 0x1d, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 
    0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 
    0x5, 0x16, 0xc, 0xb, 0xe9, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 
    0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0x32, 0x2, 0x2, 0xf0, 0xf9, 0x7, 0x3, 0x2, 0x2, 0xf1, 0xf6, 
    0x5, 0x16, 0xc, 0x2, 0xf2, 0xf3, 0x7, 0x7, 0x2, 0x2, 0xf3, 0xf5, 0x5, 
    0x16, 0xc, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 0x7, 0x4, 0x2, 0x2, 0xfc, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xfc, 0xef, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x32, 0x2, 0x2, 0xff, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x100, 0x101, 0x5, 0x1a, 0xe, 0x2, 0x101, 0x102, 0x7, 0x8, 
    0x2, 0x2, 0x102, 0x103, 0x5, 0x16, 0xc, 0x2, 0x103, 0x104, 0x7, 0x9, 
    0x2, 0x2, 0x104, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x21, 0x29, 0x34, 0x40, 
    0x4b, 0x51, 0x5a, 0x67, 0x6e, 0x82, 0x8d, 0x90, 0xa2, 0xa5, 0xa9, 0xaf, 
    0xc3, 0xc6, 0xca, 0xd0, 0xd6, 0xe0, 0xe6, 0xe9, 0xeb, 0xf6, 0xf9, 0xfc, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
