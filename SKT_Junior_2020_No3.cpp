#include <string>
#include <iostream>

using namespace std;

int solution(string & S) {

    int ans = 0;

    int sLen = S.length();

    int numOfA = 0;
    for(int i = 0; i < sLen; i++) {
        if(S[i] == 'a') numOfA++;
    }

    if(numOfA%3) {
        return ans;
    }

    if(numOfA) {
        int cntOfB = 0;
        int idxOfA = 0;
        int numOfSameA = 0;
        int tmpAns = 1;
        for(int i = 0; i < sLen; i++) {
            if(S[i] == 'b') {
                cntOfB++;
            } else {
                numOfSameA++;
                if(numOfSameA == numOfA/3) {
                    switch (idxOfA)
                    {
                    case 0:
                    tmpAns *= 1;
                        break;
                    
                    case 1:
                    if(cntOfB) tmpAns *= cntOfB*2;
                        break;

                    case 2:
                    if(cntOfB) tmpAns *= cntOfB*2;
                        break;

                    case 3:
                    tmpAns *= 1;
                        break;
                    }
                    numOfSameA = 0;
                    cntOfB = 0;
                    idxOfA++;
                }
            }
        }

        ans = tmpAns;

    } else {
        int start = sLen-2;
        while (start)
        {
            ans += start;
            start--;
        }
    }

    return ans;

}

int main() {

    string s = "bababa";

    printf("%d\n", solution(s));

    return 0;
}