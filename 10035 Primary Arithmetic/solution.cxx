/* Lyndon Renaud
 * 2020-10-04
 *
 * Solution:
 * Initially, we have 0 total carries and carry value set to 0
 * Starting from the right most numbers i1, j1, we check
 * if i1 + j1 + carry > 9. If this is true, we carry, so we set carry to 1
 * and increment our carry counter. Else we set carry to 0.
 * We keep moving through the numbers from right to left, checking
 * if i + j + carry > 9 and incrementing the carry counter accordingly
 */

#include <iostream>

using namespace std;

int main(){
        int n1, n2;
        while(cin >> n1 >> n2){
                if(n1 == 0 && n2 == 0){
                        break;
                }

                int carry = 0;
                int total_carries = 0;
                while(n1 > 0 || n2 > 0){
                        int k1 = n1 % 10;
                        int k2 = n2 % 10;
                        n1 /= 10;
                        n2 /= 10;
                        if(k1 + k2 + carry > 9){
                                carry = 1;
                        }
                        else
                                carry = 0;
                        total_carries += carry;
                }

                if (total_carries > 1){
                        cout << total_carries << " carry operations.\n";
                }
                else if (total_carries == 1){
                        cout << "1 carry operation.\n";
                }
                else{
                        cout << "No carry operation.\n";
                }
        }

        return 0;
}
