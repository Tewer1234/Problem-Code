#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <math.h>
using namespace std;
int main(int argc, char** argv) {
    int a,b,c,total=0,remain;
    scanf("%d",&a);
    scanf("%d",&b);
    for (int i=1;i<=b;i++){
        scanf("%d",&c);
        remain=a-c;
        total+=remain;
    }
    printf("%d",total+a);
    return 0;
}
