/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
#include "chess.h"
#include <stdio.h>
#include <stdbool.h>
#include "general.h"

bool is_piece(struct ChessPiece cp, enum Color color, enum PieceType type){
  return cp.color == color && cp.type == type;
}

bool is_square_ok (File file, Rank rank) {
  return file - 'a' < 8 && file - 'a' >= 0 && rank < 8 && rank >= 0;
}

void init_chess_board(ChessBoard chess_board){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      chess_board[i][j].is_occupied = false;
    }
  }
}

struct ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank){
  if(file > 'h' || (file < 'a' && rank > 8) || rank < 1) {
    return 0;
  }
  return &chess_board[rank - 1][file - 'a'];
}

bool add_piece(ChessBoard chess_board, char file, int rank, struct ChessPiece chess_piece){
  if(!is_square_occupied(chess_board, file, rank) && is_square_ok(file, rank - 1)){
    chess_board[rank-1][file-'a'].is_occupied=true;
    chess_board[rank-1][file-'a'].piece=chess_piece;
  }
  chess_board[rank-1][file-'a'].piece=chess_piece;
  return true;
}

struct ChessPiece get_piece(ChessBoard chess_board, char file, int rank){
  if (is_square_ok(file, rank - 1) && is_square_occupied(chess_board, file, rank)) {
  return chess_board[rank - 1][file - 'a'].piece;
}
  struct ChessPiece temp;
  temp.type = NoPiece;
  return temp;
}

bool is_square_occupied(ChessBoard chess_board, char file, int rank){
  return chess_board[rank-1][file-'a'].is_occupied;
}

bool remove_piece(ChessBoard chess_board, File file, Rank rank){
struct ChessPiece temp_piece;
  return file>'h'||rank>7||rank<0||file<'a'||chess_board[rank-1][file-'a'].piece.type==NoPiece;
    temp_piece.type=NoPiece;
  chess_board[rank-1][file-'a'].piece=temp_piece;
  chess_board[rank-1][file-'a'].is_occupied=false;
  return true;
}

void setup_chess_board(ChessBoard chess_board){

  for (size_t x = 1; x < 9; x++)
  {
    add_piece(chess_board, x, 2, {White, Pawn});
    add_piece(chess_board, x, 7, {Black, Pawn});
  }
  add_piece(chess_board, 'a', 1, {White, Rook});
  add_piece(chess_board, 'h', 1, {White, Rook});
  add_piece(chess_board, 'b', 1, {White, Knight});
  add_piece(chess_board, 'g', 1, {White, Knight});
  add_piece(chess_board, 'c', 1, {White, Bishop});
 	add_piece(chess_board, 'f', 1, {White, Bishop});
 	add_piece(chess_board, 'd', 1, {White, Queen});
 	add_piece(chess_board, 'e', 1, {White, King});
 	add_piece(chess_board, 'a', 8, {Black, Rook});
 	add_piece(chess_board, 'h', 8, {Black, Rook});
 	add_piece(chess_board, 'b', 8, {Black, Knight});
  add_piece(chess_board, 'g', 8, {Black, Knight});
  add_piece(chess_board, 'c', 8, {Black, Bishop});
 	add_piece(chess_board, 'f', 8, {Black, Bishop});
 	add_piece(chess_board, 'd', 8, {Black, Queen});
 	add_piece(chess_board, 'e', 8, {Black, King});

}

bool squares_share_diagonal(File file1,Rank rank1,File file2, Rank rank2){
  return (unsigned int) file1-file2-'a'*2==(unsigned int)rank1-rank2;

}

bool squares_share_file(File file1,Rank rank1,File file2, Rank rank2){
  return rank1==rank2;
}

bool squares_share_rank(File file1,Rank rank1,File file2, Rank rank2){
  return file1==file2;
}

bool squares_share_kings_move(File file1,Rank rank1,File file2, Rank rank2){
  return file1-'a'+1==file2||file1-'a'-1==file2||rank1-1==rank2||rank1+1==rank2||file1-'a'-1==rank2||file1-'a'+1==rank2;
}

bool squares_share_queens_move(File file1 ,Rank rank1,File file2, Rank rank2){
  return squares_share_file(file1, file2, rank1, rank2)||squares_share_rank(file1, file2, rank1, rank2)||squares_share_diagonal(file1, file2, rank1, rank2);
}

bool squares_share_knights_move(File file1, Rank rank1, File file2, Rank rank2){
  return (file1+2==file2&&rank1+1==rank2)||(file1-2==file2&&rank1+1==rank2)||(file1+2==file2&&rank1-1==rank2)
  ||(file1-2==file2&&rank1-1==rank2)||(file1+1==file2&&rank1+2==rank2)||(file1-1==file2&&rank1+2==rank2)
  ||(file1+1==file2&&rank1-2==rank2)||(file1-1==file2&&rank1-2==rank2);
}

bool squares_share_pawns_move(enum Color color, enum Move move, File file1, Rank rank1, File file2, Rank rank2){
  if(move==NormalMove){
    return rank1+1==rank2||rank1-1==rank2;
  }
  if(move==CaptureMove){
    return (rank1+1==rank2&&file1-'a'+1==file2)||(rank1-1==rank2&&file1-'a'-1==file2);
  }
  return false;
}
