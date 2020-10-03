/* Lyndon Renaud
 * 2020-10-03
 *
 * Solution:
 * We have a sequence S of integers of length n
 * Let diff(x, y) = difference between x and y
 *
 * A sequence is jolly if diff(x, y) for x, y adjacent
 * in the sequence take on all values between 1 and n-1
 * Thus if a sequence is jolly, diff(x, y) for x, y adjacent
 * in the sequence forms a set of size n-1
 *
 * Let D = {diff(x, y) | x, y are adjacent in S}
 * if S is jolly, then the max element in D is n-1
 *
 * This gives us two constraints to check if a sequence is jolly:
 *      - D must be of size n-1
 *      - max element of D must be n-1
 * If these conditions are not met, the seqeunce is not jolly
 */

#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>      //abs()
using namespace std;

#define DEBUG 0

int main(){
        string line;
        // for each line in stdin
        while(getline(cin, line)){
                stringstream line_stream(line);

                set<int> differences;   //holds the differences between successive elements in the sequence
                int n1, n2, n;
                int max_diff = 0;    // current max difference between numbers in sequence (max elem of differences)
                line_stream >> n;
                line_stream >> n1;
                while(line_stream >> n2){
                        int diff = abs(n1 - n2);
                        max_diff = diff > max_diff ? diff : max_diff;
                        if(DEBUG){cout << "diff between " << n1 << ", " << n2 << " = " << diff << '\n';}
                        differences.insert(diff);
                        n1 = n2;

                }

                //check if jolly or not
                if(DEBUG){cout << "differences.size == " << differences.size() << ", max == " << max_diff << ", len == " << n << '\n';}
                if((static_cast<int>(differences.size()) == n-1 && max_diff == n-1) || n == 1){
                        cout << "Jolly\n";
                }
                else
                        cout << "Not jolly\n";
        }
        return 0;
}
