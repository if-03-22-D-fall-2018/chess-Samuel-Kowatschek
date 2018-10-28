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
    enum PieceType type;

};

struct ChessSquare{
  struct ChessPiece piece;
  bool is_occupied;
};

typedef ChessSquare ChessBoard[8][8] ;
typedef char File;
typedef int Rank;

void init_chess_board(ChessBoard chess_board);
void setup_chess_board(ChessBoard chess_board);

struct ChessSquare* get_square(ChessBoard chess_board,  char file, int rank);
struct ChessPiece get_piece(ChessBoard chess_board, char file, int rank);

bool is_piece(struct ChessPiece piece, enum Color color, enum PieceType type);
bool is_square_occupied(ChessBoard chess_board, char file, int rank);
bool add_piece(ChessBoard chess_board, char file, int rank, struct ChessPiece chess_piece);
bool remove_piece(ChessBoard chess_board, File file, Rank rank);

bool squares_share_file(File file1,Rank rank1,File file2, Rank rank2);
bool squares_share_rank(File file1,Rank rank1,File file2, Rank rank2);
bool squares_share_diagonal(File file1,Rank rank1,File file2, Rank rank2);
bool squares_share_knights_move(File file1,Rank rank1,File file2, Rank rank2);
bool squares_share_pawns_move(File file1,Rank rank1,File file2, Rank rank2);
bool squares_share_queens_move(File file1,Rank rank1,File file2, Rank rank2);
bool squares_share_kings_move(File file1,Rank rank1,File file2, Rank rank2);
