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

void setup_chess_board(ChessBoard chess_board){

  //White_Pawn
  for (size_t i = 0; i < 8; i++)
  {
    chess_board[1][i].piece.type=Pawn;
    chess_board[1][i].piece.color=White;
    chess_board[1][i].is_occupied=true;
  }
  //Black_Pawn
  for (size_t i = 0; i < 8; i++)
  {
    chess_board[6][i].piece.type=Pawn;
    chess_board[6][i].piece.color=Black;
    chess_board[6][i].is_occupied=true;
  }
  //White_Rook
  chess_board[0][0].piece.type=Rook;
  chess_board[0][0].piece.color=White;
  chess_board[0][0].is_occupied=true;
  chess_board[0][7].piece.type=Rook;
  chess_board[0][7].piece.color=White;
  chess_board[0][7].is_occupied=true;
  //Black_Rook
  chess_board[7][0].piece.type=Rook;
  chess_board[7][0].piece.color=Black;
  chess_board[7][0].is_occupied=true;
  chess_board[7][7].piece.type=Rook;
  chess_board[7][7].piece.color=Black;
  chess_board[7][7].is_occupied=true;
  //White_Knight
  chess_board[0][1].piece.type=Knight;
  chess_board[0][1].piece.color=White;
  chess_board[0][1].is_occupied=true;
  chess_board[0][6].piece.type=Knight;
  chess_board[0][6].piece.color=White;
  chess_board[0][6].is_occupied=true;
  //Black_Knight
  chess_board[7][1].piece.type=Knight;
  chess_board[7][1].piece.color=White;
  chess_board[7][1].is_occupied=true;
  chess_board[7][6].piece.type=Knight;
  chess_board[7][6].piece.color=White;
  chess_board[7][6].is_occupied=true;
  //White_Bishop
  chess_board[0][2].piece.type=Bishop;
  chess_board[0][2].piece.color=White;
  chess_board[0][2].is_occupied=true;
  chess_board[0][5].piece.type=Bishop;
  chess_board[0][5].piece.color=White;
  chess_board[0][5].is_occupied=true;
  //Black_Bishop
  chess_board[7][2].piece.type=Bishop;
  chess_board[7][2].piece.color=Black;
  chess_board[7][2].is_occupied=true;
  chess_board[7][5].piece.type=Bishop;
  chess_board[7][5].piece.color=Black;
  chess_board[7][5].is_occupied=true;
  //White King
  chess_board[0][3].piece.type=King;
  chess_board[0][3].piece.color=White;
  chess_board[0][3].is_occupied=true;
  //Black_King
  chess_board[7][3].piece.type=King;
  chess_board[7][3].piece.color=Black;
  chess_board[7][3].is_occupied=true;
  //White_Queen
  chess_board[0][4].piece.type=Queen;
  chess_board[0][4].piece.color=White;
  chess_board[0][4].is_occupied=true;
  //Black_Queen
  chess_board[7][4].piece.type=Queen;
  chess_board[7][4].piece.color=Black;
  chess_board[7][4].is_occupied=true;

}

bool squares_share_diagonal(File file1,Rank rank1,File file2, Rank rank2){
  int multiplicatorFile=1;
  int multiplicatorRank=1;
  if(file1-file2-'a'<0){
    multiplicatorFile=-1;
  }
  if(rank1-rank2<0){
    multiplicatorRank=-1;
  }
  return (file1-file2-'a'*2)*multiplicatorFile==(rank1-rank2)*multiplicatorRank;
}

bool squares_share_file(File file1,Rank rank1,File file2, Rank rank2){
  return file1==file2;
}

bool squares_share_rank(File file1,Rank rank1,File file2, Rank rank2){
  return rank1==rank2;
}

bool squares_share_kings_move(File file1,Rank rank1,File file2, Rank rank2){
  if(file1==file2||file1=file2/*||(file1-'a')+1==rank1||((int)file1)==rank2*/){
    return true;
  }
  return false;
}
