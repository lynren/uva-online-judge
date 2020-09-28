// 10082 - WERTYU

#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main(){

        // keyboard left shift mapping
        unordered_map<char, char> shift_map = {
                {'1', '`'}, {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'}, {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'},
                {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'}, {'O', 'I'}, {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'},
                {'S', 'A'}, {'D', 'S'}, {'F', 'D'}, {'G', 'F'}, {'H', 'G'}, {'J', 'H'}, {'K', 'J'}, {'L', 'K'}, {';', 'L'}, {'\'', ';'},
                {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'V'}, {'N', 'B'}, {'M', 'N'}, {',', 'M'}, {'.', ','}, {'/', '.'},
                {' ', ' '}, {'\n','\n'}
        };
        
        // for char in input, output shifted char value
        for(char x; scanf("%c", &x) != EOF;){
                cout << shift_map[x];
        }

        return 0;
}

