#include <iostream>

using namespace std;

int getNext(int n){
        // if n is odd
        if ((n & 1) == 1){
                return 3*n + 1;
        }

        else
                return n >> 1;
}

int main(){
        int i, j;
        while(cin >> i >> j){
                int start = i <= j ? i : j;
                int end = j > i ? j : i;
                int max = 0;
                for(int curr = start; curr <= end; ++curr){
                        int temp = curr, cycle_len = 1;
                        while(temp != 1){
                                temp = getNext(temp);
                                ++cycle_len;
                        }
                        max = cycle_len > max ? cycle_len : max;
                }

                cout << i << ' ' << j << ' ' << max << '\n';
        }

        return 0;
}
