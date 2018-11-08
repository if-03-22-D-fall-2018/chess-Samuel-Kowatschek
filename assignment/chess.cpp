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
  if(cp.color == color && cp.type == type){
    return true;
  }
  return false;
}

void init_chess_board(ChessBoard chess_board){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      chess_board[i][j].is_occupied = false;
    }
  }
}

struct ChessSquare* get_square(ChessBoard chess_board, File file, Rank rank){
  if((file > 'h' || file < 'a') && (rank > 8 || rank < 1)){
    return 0;
  }
  return &chess_board[rank][(int)file];
}

bool add_piece(ChessBoard chess_board, char file, int rank, struct ChessPiece chess_piece){
  if(chess_board[rank][(int)file].is_occupied){
    return false;
  }
  chess_board[rank][(int)file].piece=chess_piece;
  return true;
}

struct ChessPiece get_piece(ChessBoard chess_board, char file, int rank){
  struct ChessPiece temp_piece;
  if(file>'h'||rank>7||rank<0||file<'a'||chess_board[rank][(int)file].piece.type==NoPiece){
    temp_piece.type=NoPiece;
    return temp_piece;
  }
  temp_piece.type=chess_board[rank][(int)file].piece.type;
  temp_piece.color=chess_board[rank][(int)file].piece.color;
  return temp_piece;
}

bool is_square_occupied(ChessBoard chess_board, char file, int rank){
  return chess_board[rank][file-'a'].piece.type!=NoPiece;
}

bool remove_piece(ChessBoard chess_board, File file, Rank rank){
struct ChessPiece temp_piece;
  if(file>'h'||rank>7||rank<0||file<'a'||chess_board[rank][(int)file].piece.type==NoPiece){
    return false;
  }
    temp_piece.type=NoPiece;
  chess_board[rank][file-'a'].piece=temp_piece;
  chess_board[rank][file-'a'].is_occupied=false;
  return true;
}

void setup_chess_board(ChessBoard chess_board){

  for (size_t x = 0; x < 8; x++)
  {
    add_piece(chess_board, x, 0, {White, Pawn});
    add_piece(chess_board, x, 7, {Black, Pawn});
  }
  add_piece(chess_board, 'a', 0, {White, Rook});
  add_piece(chess_board, 'h', 0, {White, Rook});
  add_piece(chess_board, 'b', 0, {White, Knight});
  add_piece(chess_board, 'g', 0, {White, Knight});
  add_piece(chess_board, 'c', 0, {White, Bishop});
 	add_piece(chess_board, 'f', 0, {White, Bishop});
 	add_piece(chess_board, 'd', 0, {White, Queen});
 	add_piece(chess_board, 'e', 0, {White, King});
 	add_piece(chess_board, 'a', 7, {Black, Rook});
 	add_piece(chess_board, 'h', 7, {Black, Rook});
 	add_piece(chess_board, 'b', 7, {Black, Knight});
  add_piece(chess_board, 'g', 7, {Black, Knight});
  add_piece(chess_board, 'c', 7, {Black, Bishop});
 	add_piece(chess_board, 'f', 7, {Black, Bishop});
 	add_piece(chess_board, 'd', 7, {Black, Queen});
 	add_piece(chess_board, 'e', 7, {Black, King});

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
