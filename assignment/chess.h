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

enum PieceType{
    Pawn, Knight, Rook, Bishop, Queen, King
};


enum Color{White,Black};

struct ChessPiece{
    enum Color color;
    enum PieceType piece;
};

struct ChessSquare{
  bool is_set;
  struct ChessPiece piece;
};

typedef ChessSquare ChessBoard[8][8] ;

bool is_piece(ChessBoard board,enum Color color,enum PieceType type);

void init_chess_board(ChessBoard chess_board);
