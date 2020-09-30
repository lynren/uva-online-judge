#include <iostream>
#include <vector>

using namespace std;

int main(){

        int field_count = 1;            // current field

        while(true){
                int n = 0;
                int m = 0;

                cin >> n >> m;
                // if n == m == 0, we are done
                if(!n && !m){
                        break;
                }
                if(field_count > 1){
                        cout << '\n';
                }
                cout << "Field #" << field_count << ':' << '\n';
                ++field_count;

                // fill 2d vector of size n x m with zeros
                // we add 2 extra rows and columns to avoid boundary
                // checking when updating neighbors
                vector<vector<int>> board(n+2, vector<int>(m+2, 0));

                // populate game board
                for(int i = 1; i < n+1; ++i){
                        for(int j = 1; j < m+1; ++j){
                                char current;
                                cin >> current;

                                // if mine found
                                if(current == '*'){
                                        // mark current cell as mine (-20 == mine)
                                        // max number in minesweeper is 8, so by setting a mine to -20,
                                        // mine cells will always be negative
                                        board[i][j] = -20;
                                        // increment neighbor values
                                        ++board[i+1][j-1];      // top left
                                        ++board[i+1][j];        // top
                                        ++board[i+1][j+1];      // top right
                                        ++board[i][j-1];        // left
                                        ++board[i][j+1];        // right
                                        ++board[i-1][j-1];      // bottom left
                                        ++board[i-1][j];        // bottom
                                        ++board[i-1][j+1];      // bottom right
                                }
                        }
                }

                // print game board
                for(int i = 1; i < n+1; ++i){
                        for(int j = 1; j < m+1; ++j){
                                if (board[i][j] >= 0){
                                        cout << board[i][j];
                                }
                                else{
                                        cout << '*';
                                }
                        }
                        cout << '\n';
                }

        }

        return 0;
}
