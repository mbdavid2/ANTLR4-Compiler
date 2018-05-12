
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, EQUAL = 9, NOTEQUAL = 10, LESS = 11, LESSEQ = 12, BIGGER = 13, 
    BIGGEREQ = 14, PLUS = 15, MINUS = 16, MUL = 17, DIV = 18, MOD = 19, 
    VAR = 20, FLOAT = 21, INT = 22, BOOL = 23, CHAR = 24, NOT = 25, AND = 26, 
    OR = 27, IF = 28, THEN = 29, ELSE = 30, ENDIF = 31, WHILE = 32, ENDWHILE = 33, 
    DO = 34, FUNC = 35, ENDFUNC = 36, READ = 37, WRITE = 38, ARRAY = 39, 
    OF = 40, RETURN = 41, BOOLEAN = 42, TRUE = 43, FALSE = 44, FLOATVAL = 45, 
    INTVAL = 46, CHARVAL = 47, ID = 48, STRING = 49, COMMENT = 50, WS = 51
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

