
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    ASSIGN = 8, EQUAL = 9, NOTEQUAL = 10, LESS = 11, LESSEQ = 12, BIGGER = 13, 
    BIGGEREQ = 14, PLUS = 15, MINUS = 16, MUL = 17, DIV = 18, POW = 19, 
    MOD = 20, VAR = 21, FLOAT = 22, INT = 23, BOOL = 24, CHAR = 25, NOT = 26, 
    AND = 27, OR = 28, IF = 29, THEN = 30, ELSE = 31, ENDIF = 32, WHILE = 33, 
    ENDWHILE = 34, DO = 35, FUNC = 36, ENDFUNC = 37, READ = 38, WRITE = 39, 
    ARRAY = 40, OF = 41, RETURN = 42, BOOLEAN = 43, TRUE = 44, FALSE = 45, 
    FLOATVAL = 46, INTVAL = 47, CHARVAL = 48, ID = 49, STRING = 50, COMMENT = 51, 
    WS = 52
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

