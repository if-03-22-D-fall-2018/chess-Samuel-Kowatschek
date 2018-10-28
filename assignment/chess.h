/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.h
 * Author:			P. Bauer
 * Due Date:		October 15, 2014
 * ----------------------------------------------------------
 * Description:
 * Basic chess functions.
 * ----------------------------------------------------------
 */
#include <stdbool.h>


enum PieceType{
    Pawn, Knight, Rook, Bishop, Queen, King
};


enum Color{White,Black};

struct ChessPiece{
    enum Color color;
    enum PieceType piece;

};

struct NoPiece{
  enum Color color;
  enum PieceType piece;
};

struct ChessSquare{
  bool is_set;
  struct ChessPiece piece;
  bool is_occupied;
};

typedef ChessSquare ChessBoard[8][8] ;
bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);
void init_chess_board(ChessBoard chess_board);
struct ChessSquare* get_square(ChessBoard chess_board,  char file, int rank);
bool is_square_occupied(ChessBoard chess_board, char file, int rank);
bool add_piece(ChessBoard chess_board, char file, int rank, struct ChessPiece chess_piece);
struct ChessPiece get_piece(ChessBoard chess_board, char file, int rank);
