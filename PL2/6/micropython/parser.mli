
(* The type of tokens. *)

type token = 
  | WHILE
  | STRING of (string)
  | RPAREN
  | PRINT
  | PLUS
  | NOTEQUAL
  | NEWLINE
  | MUL
  | MINUS
  | LPAREN
  | INT of (int)
  | INDENT
  | IF
  | IDENT of (string)
  | EQUAL
  | EOF
  | ELSE
  | DIV
  | DEDENT
  | COLON
  | ASSIGN

(* This exception is raised by the monolithic API functions. *)

exception Error

(* The monolithic API. *)

val prog: (Lexing.lexbuf -> token) -> Lexing.lexbuf -> (Syntax.pyprog)
