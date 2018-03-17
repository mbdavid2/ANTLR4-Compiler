
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, EQUAL = 9, NOTEQUAL = 10, LESS = 11, LESSEQ = 12, BIGGER = 13, 
    BIGGEREQ = 14, PLUS = 15, MINUS = 16, MUL = 17, DIV = 18, MOD = 19, 
    VAR = 20, INT = 21, FLOAT = 22, BOOL = 23, CHAR = 24, AND = 25, OR = 26, 
    IF = 27, THEN = 28, ELSE = 29, ENDIF = 30, WHILE = 31, ENDWHILE = 32, 
    DO = 33, FUNC = 34, ENDFUNC = 35, READ = 36, WRITE = 37, ARRAY = 38, 
    OF = 39, RETURN = 40, TRUE = 41, FALSE = 42, BOOLEAN = 43, ID = 44, 
    INTVAL = 45, FLOATVAL = 46, STRING = 47, COMMENT = 48, WS = 49
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

