#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<vector<int> > possibleCombs(9);
    set<int> numberGroup;

    possibleCombs[1].push_back(N);
    numberGroup.insert(N);

    if(number == N) {
        return 1;
    }

    possibleCombs[2].push_back(N+N);
    numberGroup.insert(N+N);
    if(number == N+N) return 2;
    possibleCombs[2].push_back(0);
    numberGroup.insert(0);
    if(number == 0) return 2;
    possibleCombs[2].push_back(N*N);
    numberGroup.insert(N*N);
    if(number == N*N) return 2;
    possibleCombs[2].push_back(1);
    numberGroup.insert(1);
    if(number == 1) return 2;
    
    int newNumber = N*10 + N;
    numberGroup.insert(newNumber);
    if(newNumber == number) return 2;
    possibleCombs[2].push_back(newNumber);

    for(int i = 3; i <= 8; i++) {
        for(int j = 1; j < i; j++) {
            for(auto num1 : possibleCombs[j]) {
                for(auto num2 : possibleCombs[i-j]) {
                    int plus = num1 + num2;
                    if(plus == number) {
                        answer = i;
                        break;
                    }

                    if(numberGroup.count(plus) <= 0) {
                        numberGroup.insert(plus);
                        possibleCombs[i].push_back(num1 + num2);
                    }

                    int minus = num1 - num2;

                    if(minus == number) {
                        answer = i;
                        break;
                    }

                    if(numberGroup.count(minus) <= 0) {
                        numberGroup.insert(minus);
                        possibleCombs[i].push_back(num1 - num2);
                    }

                    int multiply = num1 * num2;

                    if(multiply == number) {
                        answer = i;
                        break;
                    }

                    
                    if(numberGroup.count(multiply) <= 0) {
                        numberGroup.insert(multiply);
                        possibleCombs[i].push_back(num1 * num2);
                    }

                    if(num2 == 0) continue;

                    int div = num1 / num2;
                    if(div == number) {
                        answer = i;
                        break;
                    }
                    
                    if(numberGroup.count(div) <= 0) {
                        numberGroup.insert(div);
                        possibleCombs[i].push_back(num1 / num2);
                    }
                }

                if(answer > 0) break;
            }

            if(answer > 0) break;
        }
        
        if(answer > 0) break;
        
        int newNum = 0;
        for(int digit = 0; digit < i; digit++) {
            newNum += pow(10, digit) * N;
        }

        possibleCombs[i].push_back(newNum);           
    }

    return answer;
}