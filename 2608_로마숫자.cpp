#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;
const int MAX = 1005;

map<string, int> nList;
string nums[] = {"IV", "IX", "XL", "XC", "CD", "CM"};
int digits[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
map<int, string> switcher;
int cntOfAvailable[MAX];

int main() {

    cin.tie(NULL), cout.tie(NULL);
    string num1, num2;
    cin >> num1 >> num2;

    int digitNum1 = 0, digitNum2 = 0;
    int digitAns = 0;
    string numAns = "";

    memset(cntOfAvailable, 0, sizeof(cntOfAvailable));

    nList.insert(make_pair("I", 1));
    nList.insert(make_pair("V", 5));
    nList.insert(make_pair("X", 10));
    nList.insert(make_pair("L", 50));
    nList.insert(make_pair("C", 100));
    nList.insert(make_pair("D", 500));
    nList.insert(make_pair("M", 1000));
    nList.insert(make_pair("IV", 4));
    nList.insert(make_pair("IX", 9));
    nList.insert(make_pair("XL", 40));
    nList.insert(make_pair("XC", 90));
    nList.insert(make_pair("CD", 400));
    nList.insert(make_pair("CM", 900));

    switcher.insert(make_pair(1, "I"));
    switcher.insert(make_pair(5, "V"));
    switcher.insert(make_pair(10, "X"));
    switcher.insert(make_pair(50, "L"));
    switcher.insert(make_pair(100, "C"));
    switcher.insert(make_pair(500, "D"));
    switcher.insert(make_pair(1000, "M"));
    switcher.insert(make_pair(4, "IV"));
    switcher.insert(make_pair(9, "IX"));
    switcher.insert(make_pair(40, "XL"));
    switcher.insert(make_pair(90, "XC"));
    switcher.insert(make_pair(400, "CD"));
    switcher.insert(make_pair(900, "CM"));

    cntOfAvailable[1] = 3;
    cntOfAvailable[4] = 1;
    cntOfAvailable[5] = 1;
    cntOfAvailable[9] = 1;
    cntOfAvailable[10] = 3;
    cntOfAvailable[40] = 1;
    cntOfAvailable[50] = 1;
    cntOfAvailable[90] = 1;
    cntOfAvailable[100] = 3;
    cntOfAvailable[400] = 1;
    cntOfAvailable[500] = 1;
    cntOfAvailable[900] = 1;
    cntOfAvailable[1000] = 3;

    // num1 검사
    for(int i = 0; i < 6; i++) {
        int n = num1.find(nums[i]);
        if(n >= 0) {
            num1.replace(n, 2, "");
            digitNum1 += nList[nums[i]];
        }
    }

    // num2 검사
    for(int i = 0; i < 6; i++) {
        int n = num2.find(nums[i]);
        if(n >= 0) {
            num2.replace(n, 2, "");
            digitNum2 += nList[nums[i]];
        }
    }
    
    int len1 = num1.length();
    int len2 = num2.length();

    for(int i = 0; i < len1; i++) {
        string tmp = "";
        tmp += num1.at(i);
        digitNum1 += nList[tmp];
    }

    for(int i = 0; i < len2; i++) {
        string tmp = "";
        tmp += num2.at(i);
        digitNum2 += nList[tmp];
    }
    
    digitAns = digitNum1 + digitNum2;
    printf("%d\n", digitAns);

    int idx = 0;
    while (digitAns > 0)
    {
        if(digitAns >= digits[idx]) {
            if(cntOfAvailable[digits[idx]] > 0) {

                cntOfAvailable[digits[idx]]--;
                switch (digits[idx])
                {
                case 900:
                    cntOfAvailable[400]--;
                    break;
                case 400:
                    cntOfAvailable[900]--;
                    break;
                case 90:
                    cntOfAvailable[40]--;
                    break;
                case 40:
                    cntOfAvailable[90]--;
                    break;
                case 9:
                    cntOfAvailable[4]--;
                    break;
                case 4:
                    cntOfAvailable[9]--;
                    break;
                }

                numAns += switcher[digits[idx]];
                digitAns -= digits[idx];
            } else idx++;
        } else idx++;
    }

    cout << numAns << endl;

    return 0;
}