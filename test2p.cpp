#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool login() {
    string username, password;
    string storedUsername = "chess";
    string storedPassword = "checkmate";

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == storedUsername && password == storedPassword) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid username or password. Try again." << endl;
        return false;
    }
}

enum PieceType { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN, NONE };
enum Color { WHITE, BLACK, NO_COLOR };

struct Piece {
    PieceType type;
    Color color;

    Piece(PieceType t = NONE, Color c = NO_COLOR) : type(t), color(c) {}

    char getSymbol() const {
        if (color == WHITE) {
            switch (type) {
                case KING: 
                return 'K';
                case QUEEN: 
                return 'Q';
                case ROOK: 
                return 'R';
                case BISHOP: 
                return 'B';
                case KNIGHT: 
                return 'N';
                case PAWN: 
                return 'P';
                case NONE: 
                return '.';
            }
        } else {
            switch (type) {
                case KING: 
                return 'k';
                case QUEEN: 
                return 'q';
                case ROOK: 
                return 'r';
                case BISHOP: 
                return 'b';
                case KNIGHT:
                 return 'n';
                case PAWN: 
                return 'p';
                case NONE: 
                return '.';
            }
        }
        return '.';
    }
};

class ChessBoard {
private:
    vector<vector<Piece>> board;

public:
    ChessBoard() {
        board.resize(8, vector<Piece>(8, Piece()));
        setupBoard();
    }

    void setupBoard() {
        // Setup pawns
        for (int i = 0; i < 8; ++i) {
            board[1][i] = Piece(PAWN, WHITE);
            board[6][i] = Piece(PAWN, BLACK);
        }

        // Setup other pieces
        vector<PieceType> pieces = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
        for (int i = 0; i < 8; ++i) {
            board[0][i] = Piece(pieces[i], WHITE);
            board[7][i] = Piece(pieces[i], BLACK);
        }
    }

    void printBoard() {
        for (int row = 7; row >= 0; --row) {
            cout << row + 1 << " ";
            for (int col = 0; col < 8; ++col) {
                cout << board[row][col].getSymbol() << ' ';
            }
            cout << row + 1 << endl;
        }
    }
};

int main() {

    if (!login()) {
        return 0;
    }

    ChessBoard board;
    board.printBoard();
    return 0;
}
