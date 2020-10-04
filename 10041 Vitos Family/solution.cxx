/* Lyndon Renaud
 * 2020-10-03
 *
 * Solution:
 * We wish to find the address which minimizes the total travel cost
 * to all other addresses.
 * This can be done using the 1D geometric median 
 * Let A be the set of all addresses
 * After sorting A, the geometric median of A is the middle element of A
 * This middle element minimizes the total travel cost to all other addresses in A
 * This method also works when |A| is even:
 *      Given two medians x, y with y > x, suppose we pick x as the median:
 *      If we were to pick y as the median, then we increase the distance from
 *      addresses < y by x - y, and decrease the distance from addresses > y
 *      by x - y
 * Once we get the geometric median x of A, we sum the distance from x to 
 * all addresses in A
 */

#include <vector>
#include <iostream>
#include <algorithm>    // sort()
#include <cstdlib>      // abs()

using namespace std;

#define DEBUG 0

int main(){
        int total_cases;
        cin >> total_cases;

        while(total_cases--){
                int r;
                cin >> r;
                vector<int> addresses(r);
                for(int i = 0; i < r; ++i){
                        cin >> addresses[i];
                }
                sort(addresses.begin(), addresses.end());
                int median = addresses[addresses.size() / 2];
                int total_travel_cost = 0;
                for(int address : addresses){
                        // note travel cost from x to x is 0
                        total_travel_cost += abs(median - address);
                }

                cout << total_travel_cost << '\n';
        }

        return 0;
}
