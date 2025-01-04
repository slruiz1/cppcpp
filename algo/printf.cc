#include <bits/stdc++.h>
using namespace std;

int main()
{
        int a[5] = {10,12,3,4,15};
        int* const exp1 = &a[0];
        int const* exp2 = &a[0];
        for ( int i=0; i<5; i++) {
                printf("exp1, Value %d\n", *exp1);
                printf("exp2, Value %d\n", *exp2++);
        } // what will be the output?
        printf("\n");
        return 0;
}
