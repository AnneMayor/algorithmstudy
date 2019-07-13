#include <iostream>
#include <string>

using namespace std;

/* 풀이방식 */
// 주의!
// iterator대신 int idx와 char배열을 활용하고자할 경우엔, 매개변수로 해당 위치의 char값을 넘겨주어야 한다.
// 단순히, idx+1만 시켜서 내부에서 char 찾게 짤 경우, 위치가 0에서 더이상 진행하지 않고 재귀함수가 끝나버림.
// 아래와 같이 짜면 안됨.
// string quard(int idx) {
//     char c = str[idx];

//     if(head == 'b' || if(head == 'w') {
//         return string(1, head);
//     }

//     string one = quard(idx+1);
//     .. 이하 동문 ..
// }

string quard(string::iterator& it)
{
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w')
        return string(1, head); //x인 경우에는 또다시 4개로 분할이 이루어지기 때문에 재귀로 다시 불러오게 됩니다.
    string one = quard(it);
    string two = quard(it);
    string three = quard(it);
    string four = quard(it); //one은 왼쪽 위, two는 오른쪽 위, three는 왼쪽 아래, four는 오른쪽 아래를 나타냅니다.

    //return할때 상하의 위치를 바꿉니다.
    return string("x") + three + four + one + two;
}

int main()
{
    int T;
    string str;
    cin >> T;
    while (T--)
    {
        cin >> str;
        string::iterator it = str.begin();
        cout << quard(it) << endl;
    }
}