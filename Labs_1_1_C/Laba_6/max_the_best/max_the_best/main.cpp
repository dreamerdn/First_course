//
//  main.cpp
//  max_the_best
//
//  Created by Dasha Neyzhmak on 10/19/20.
//  Copyright © 2020 Dasha Neyzhmak. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
void hui()
{
    cout<<"hui";
}
int kvadrat(int x)
{
    return x*x;
}
int main(int argc, const char * argv[]) {
    int i;
    i = pow (3,2);
    cout<<i;
    hui();
    hui();
    //i=kvadrat(5)*3;
    cout<<kvadrat(5)*3;
    return 0;
}
