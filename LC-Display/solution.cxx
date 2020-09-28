#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
        while(true){
                int s;
                string number;
                cin >> s >> number;

                // if end of input
                if(s == 0){
                        break;
                }
                
                int rows = 2*s + 3, col_space = s + 2;
                int origin = ((2*s+3) / 2); // origin row is the middle row
                int vert_grow_space = (rows - 1) / 2;
                int col = 0;   // LC-Display cursors

                int cols = (col_space+1) * number.size() + 1;

                vector<vector<char>> display(rows, vector<char>(cols, ' ')); // LC-Display
                

                // while stack isn't empty, write the top digit to LC-Display
                for(auto c = number.begin(); c != number.end(); ++c){
                        // retrieve top element from stack
                        int curr = static_cast<int>(*c) - 48;

                        switch(curr){
                                case 1:
                                        // grow 1 from row origin and column col
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin-i][col + col_space - 1] = '|';
                                                display[origin+i][col + col_space - 1] = '|';
                                        }
                                        col += col_space + 1;
                                        break;
                                case 2:
                                        // grow 2 from row origin and column col
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col + i] = '-';
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col] = '|';
                                                display[origin - i][col + (col_space-1)] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 3:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col + i] = '-';
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col + (col_space - 1)] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 4:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col+i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin - i][col] = '|';
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col + (col_space - 1)] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 5:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col + i] = '-';
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 6:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col + i] = '-';
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin - i][col] = '|';
                                                display[origin + i][col] = '|';
                                                display[origin + i][col + (col_space-1)] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 7:
                                        // write '-'s
                                        for(int i = 1; i < col_space - 1; ++i){
                                                display[0][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col + (col_space - 1)] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 8:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col + i] = '-';
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col + (col_space - 1)] = '|';
                                                display[origin - i][col] = '|';
                                                display[origin + i][col] = '|';
                                        }
                                        col += col_space + 1;
                                        break;
                                case 9:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[origin][col + i] = '-';
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        // write '|'s
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col + (col_space - 1)] = '|';
                                                display[origin - i][col] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                case 0:
                                        // write '-'s
                                        for(int i = 1; i < col_space-1; ++i){
                                                display[0][col + i] = '-';
                                                display[rows-1][col + i] = '-';
                                        }
                                        for(int i = 1; i < vert_grow_space; ++i){
                                                display[origin + i][col + (col_space - 1)] = '|';
                                                display[origin - i][col + (col_space - 1)] = '|';
                                                display[origin - i][col] = '|';
                                                display[origin + i][col] = '|';
                                        }
                                        col += col_space + 1;
                                        break;

                                default:
                                        continue;
                                        break;


                        }
                }

                for(int i = 0; i < rows; ++i){
                        for(int j = 0; j < col - 1; ++j){
                                cout << display[i][j];
                        }
                        cout << '\n';
                }

                cout << '\n';
        }

        return 0;
}
