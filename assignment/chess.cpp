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
  return chess_board[rank][(int)file].piece.type!=NoPiece;
}

bool remove_piece(ChessBoard chess_board, File file, Rank rank){
struct ChessPiece temp_piece;
  if(file>'h'||rank>7||rank<0||file<'a'||chess_board[rank][(int)file].piece.type==NoPiece){
    return false;
  }
    temp_piece.type=NoPiece;
  chess_board[rank][(int)file].piece=temp_piece;
  return true;
}
