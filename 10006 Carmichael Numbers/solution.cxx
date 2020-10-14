/* Lyndon Renaud
 * 2020-10-13
 *
 * Solution:
 * For a number n to be Carmichael, it must not be prime
 * and it must satisfy the equation a^n = a (mod n) for
 * all integers a in the interval [2, n-1].
 * This equation can be computationally expensive, so we
 * compute it using fast modular exponentiation. 
 *
 * In fast modular exponentiation works because for any
 * even exponent m, a^(2m) = a^m * a^m (mod x)
 * For any odd exponent m, we have m = 2k+1
 * Then a^m = a^(m-1) * a
 *
 * We then build a list of all Carmichael numbers. This
 * is done using our list of primes and fast modular
 * exponentiation.
 *
 * Now that we have a list of Carmichael numbers, we can check
 * if a number in [0, 65000] is Carmichael in constant time.
 */

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define DEBUG 1

/* Implementation of fast modular exponentiation
 *
 */
ll fastModExp(ll base, ll exp, ll mod){
        ll res = 1;     //initialize result
        base = base % mod; //get smallest positive base in congruence class of base % mod
        
        if(base == 0) return 0; // if base % mod = 0, then base^a = 0^a = 0 % mod

        while(exp > 0){
                // we want exp to be even for fast exponentiation
                // if exp=2m+1 then res = base^(2m) * base
                if(exp & 1) res = (res*base) % mod;

                // then exp is even
                // divide exp by 2. we do this because 2^(2exp) = 2^exp * 2^exp (% mod)
                exp = exp >> 1;
                base = (base*base) % mod;
        }
        return res;
}

/* Implementation of Sieve of Eratosthenes
 * We find all primes less than 65000
 */
void erat(vector<bool>& primes){
        vector<bool> composites(65002, false);
        // initialize first prime
        int count = 0;
        int p = 2;
        primes[p] = true;

        while(count < 64997){
                // mark multiples of p as composite
                for(int i = 2; i < 65000; ++i){
                        int ip = i*p;
                        if(ip >= 65000) break;
                        if(!composites[ip]){
                                composites[ip] = true;
                                ++count;
                        }
                }

                // set p to be next non-composite number
                for(int i = p+1; i < 65000; ++i){
                        if(!composites[i]){
                                p = i;
                                primes[p]=true;
                                ++count;
                                break;
                        }
                }
        }
}

//a carmichael number is a composite number n which satisfies a^n = a (mod n) for all a in [2,n-1]
bool isCarmichael(int num){
        for(int i = 2; i < num; ++i) if(fastModExp(i, num, num) != i) return false;
        return true;
}

int main(){
        vector<bool> primes(65002, false);
        erat(primes);
        vector<bool> carmichaels(65002, false);
        
        //cout << "5^19 = " << fastModExp(5ll, 19ll, 22) << " (mod 22)";

        for(int i = 2; i <= 65000; ++i){
                if(primes[i]) continue;
                carmichaels[i] = isCarmichael(i);
        }

        // process input
        int num;
        while(cin >> num && num != 0){
               if(carmichaels[num]) cout << "The number " << num << " is a Carmichael number.\n";
               else cout << num << " is normal.\n";
        }
        
        return 0;
}
