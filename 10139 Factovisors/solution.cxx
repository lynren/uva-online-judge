/* Lyndon Renaud
 * 2020-10-14
 *
 * Solution: use prime factorizations
 */

#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
using ll = long long;
#define DEBUG 1

int main(){
        ll n, m;
        while(cin >> n >> m){
                // some weird cases
                if(m == 1){cout << m << " divides " << n << "!\n"; continue;}
                if(m == 0){cout << "0 does not divide " << n << "!\n"; continue;}
                if(n == m || n == 0){cout << m << " divides " << n << "!\n"; continue;}
                unordered_map<ll, ll> prime_factor_powers;
                ll temp = m;

                //if a | b, then b = ak, for some positive lleger k
                //let P be the prime factorization of a
                //then b = ak = Pk, hence a divides b iff P is in prime
                //factorization of b

                // we first compute the prime factorization of a
                // Special case for 2, since it's the only even prime
                if(m % 2 == 0){
                        prime_factor_powers[2] = 0;
                        while(m % 2 == 0){
                                ++prime_factor_powers[2];
                                m /= 2;
                        }
                }

                // we check if i divides m
                // each i which divides m is prime
                // this is similar to the sieve or eratosthenes
                for(ll i = 3; i <= sqrt(m); i+=2){
                        if(m % i == 0){
                                prime_factor_powers[i] = 0;
                                while(m % i == 0){
                                        ++prime_factor_powers[i];
                                        m /= i;
                                }
                        }
                }

                // check if m is prime
                if(m > 2){
                        //only primes less than n can appear in the prime
                        //factorization of n!
                        if(m > n){
                                cout << temp << " does not divide " << n << "!\n";
                                continue;
                        }
                        prime_factor_powers[m] = 1;
                }
                // we now check if the prime factorization of m is in n!
                // Proposition: 
                //      If p is prime and p < n, then the exponent of p in
                //      the factorization of n! is
                //      floor(n/p) + floor(n/p^2) + floor(n/p^3) + ... while p^k <= n
                //
                //for each prime x in the prime factorization of m:
                //      check if the exponent of x in the prime factorization of m
                //      is <= the exponent of x in the prime factorization of n!
                //How do we find the prime factorization of x in n! ?
                //      x is in n! if x <= n
                //      for i from 1 to 
                //      finish these comments
                bool divides = true;    // assume at first m divides n!
                

                //for(ll i = 0; i < prime_factors.size(); ++i){
                for(auto& i : prime_factor_powers){
                        ll res = 0, factor = i.first, exp=i.second;
                        for(ll power = factor; power <= n; power *= factor) res += n/power;
                        if(res < exp){
                                divides = false;
                                break;
                        }
                }

                if(divides) cout << temp << " divides " << n << "!\n";
                else cout << temp << " does not divide " << n << "!\n";

        }

        return 0;
}
