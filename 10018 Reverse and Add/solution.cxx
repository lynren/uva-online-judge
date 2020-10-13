#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
#define DEBUG 0

ll reverse(ll num){
        ll rev = 0, remainder;
        while(num > 0){
                remainder = num%10;
                rev = rev*10 + remainder;
                num /= 10;
        }
        return rev;
}

int main(){
        int N;
        cin >> N;
        ll P, rev;
        while(cin >> P){
                // do initial sum
                rev = reverse(P);
                P += rev;
                // sum counter starts at 1, since we always do intial sum
                int counter = 1;
                // if the reverse of P is not a palindrome, add P+rev(P) and do again
                while(P != reverse(P)){
                        rev = reverse(P);
                        P = P+rev;
                        ++counter;
                }
                // P is a palindrome, print amount of sums performed and the palindrome P
                cout << counter << ' ' << P << '\n';
        }

        return 0;
}
