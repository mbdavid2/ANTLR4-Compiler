//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
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
//    contact: José Miguel Rivero (rivero@cs.upc.es)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' (parameters)? ')' declarations statements ENDFUNC
        | FUNC ID '(' (parameters)? ')' ':' type declarations statements RETURN expr ENDFUNC
        ;     

parameters
		: ID ':' type (',' ID ':' type)*
		;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR ID (',' ID )* ':' type
        ;

type    : ARRAY '[' INTVAL ']' OF type
        | INT
        | FLOAT
        | BOOL
        | CHAR
        
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           # assignStmt
          // while statement endwhile
        | WHILE expr DO statements ENDWHILE   #whileStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)?  ENDIF       # ifStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ident '(' ')' ';'                   # procCall
          // Read a variable
        | READ left_expr ';'                  # readStmt
          // Write an expression
        | WRITE expr ';'                      # writeExpr
          // Write a string
        | WRITE STRING ';'                    # writeString
        ;
// Grammar for left expressions (l-values in C++)
left_expr
        : ident
        | ident '[' expr ']'
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    : expr (op=MUL|op=DIV | op=MOD) expr  # arithmetic
        | expr (op=PLUS|op=MINUS) expr        # arithmetic
        | expr (op=EQUAL|op=NOTEQUAL|op=LESS|op=LESSEQ|op=BIGGER|op=BIGGEREQ) expr                  # relational
        | expr (op=AND|op=OR) expr            # binaryop
        | BOOLEAN                             # boolean
        | op=INTVAL                           # value
        | op=FLOATVAL                         # value
        | op=CHARVAL						  # value 
        | ident                               # exprIdent
        | ident '[' expr ']'				  # arrayAccess
        
        ;

ident   : ID
        ;
        
        

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '=' ;
EQUAL     : '==' ;
NOTEQUAL  : '!=' ;
LESS      : '<';
LESSEQ    : '<=';
BIGGER    : '>';
BIGGEREQ  : '>=';
PLUS      : '+' ;
MINUS     : '-';
MUL       : '*';
DIV       : '/';
MOD       : '%';
VAR       : 'var';
INT       : 'int';
FLOAT     : 'float';
BOOL      : 'bool';
CHAR      : 'char';
AND       : 'and';
OR        : 'or';
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE     : 'while';
ENDWHILE  : 'endwhile';
DO        : 'do';
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
READ      : 'read' ;
WRITE     : 'write' ;
ARRAY     : 'array';
OF        : 'of';
RETURN    : 'return';
TRUE      : 'true';
FALSE     : 'false';
BOOLEAN   : TRUE | FALSE;
ID        : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;
FLOATVAL  : (INTVAL '.' INTVAL);
CHARVAL	  : ('a'..'z'|'A'..'Z');



// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
