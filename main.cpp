//
//  main.cpp
//  FibonacciNumbers
//
//  Created by Евгений Киримов on 16.08.2018.
//  Copyright © 2018 Евгений Киримов. All rights reserved.
//

#include <iostream>
int ** multiplyMatrices(int ** matr1, int ** matr2);
int ** power(int ** matr1, int pow);
int fib(int n);
int main(int argc, const char * argv[]) {
    int n;
    std::cout << "Чтобы получить n-е число Фибоначчи, введите n: " << std::endl;
    std::cin >> n;
    std::cout << n << "-е число Фибоначчи: " << fib(n) << std::endl;
    
    return 0;
}

int ** multiplyMatrices(int ** matr1, int ** matr2){
    int ** mat3 = new int* [2];
    for(int i = 0; i < 2; i++){
        mat3[i] = new int[2];
    }
    
    mat3[0][0] = matr1[0][0]*matr2[0][0] + matr1[0][1] * matr2[1][0];
    mat3[0][1] = matr1[0][0]*matr2[0][1] + matr1[0][1] * matr2[1][1];
    mat3[1][0] = matr1[1][0]*matr2[0][0] + matr1[1][1] * matr2[1][0];
    mat3[1][1] = matr1[1][0]*matr2[0][1] + matr1[1][1] * matr2[1][1];
    
    return mat3;
}

int ** power(int ** matr1, int pow){
    if(pow==0){
        int ** mat3 = new int* [2];
        for(int i = 0; i < 2; i++){
            mat3[i] = new int[2];
        }
        for(int i=0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                if(i==j)
                    mat3[i][j] = 1;
            }
        }
        return mat3;
    }
    else if(pow == 1){
        return matr1;
    }
    
    if(pow % 2){
        return multiplyMatrices(matr1, power(multiplyMatrices(matr1, matr1), pow/2));
    }else{
        return power(multiplyMatrices(matr1, matr1), pow/2);
    }
}

int fib(int n){
    int ** matr = new int* [2];
    for(int i = 0; i < 2; i++){
        matr[i] = new int[2];
    }
    matr[0][0] = 1;
    matr[0][1] = 1;
    matr[1][0] = 1;
    matr[1][1] = 0;
    
    return power(matr, n-1)[0][0];
}
