#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 55;

bool isTrueKnow[MAX];
vector<vector<int> > participants(MAX);
vector<int> trueKnownPeople;
queue<int> q;
vector<vector<int> > numOfParty(MAX);
bool isCheckedParty[MAX];

void findTrueKnowPerson(int person) {

    q.push(person);

    while (!q.empty())
    {
        person = q.front();
        q.pop();

        for(int i = 0; i < numOfParty[person].size(); i++) {
            if(!isCheckedParty[numOfParty[person][i]]) {
                isCheckedParty[numOfParty[person][i]] = true;
                int party = numOfParty[person][i];
                for(int j = 0; j < participants[party].size(); j++) {
                    if(!isTrueKnow[participants[party][j]]) {
                        isTrueKnow[participants[party][j]] = true;
                        q.push(participants[party][j]);
                    }
                }
            }
        }
    }

    return ;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;

    memset(isTrueKnow, false, sizeof(isTrueKnow));
    memset(isCheckedParty, false, sizeof(isCheckedParty));

    int numOfTrue;
    scanf("%d", &numOfTrue);

    for(int i = 0; i < numOfTrue; i++) {
        int person;
        scanf("%d", &person);
        isTrueKnow[person] = true;
        trueKnownPeople.push_back(person);
    }

    for(int i = 0; i < m; i++) {
        int numOfParticipants;
        scanf("%d", &numOfParticipants);
        for(int j = 0; j < numOfParticipants; j++) {
            int person;
            scanf("%d", &person);
            participants[i].push_back(person);
            numOfParty[person].push_back(i);
        }
    }

    // 진실을 아는 자 체크
    for(auto person : trueKnownPeople) {
        findTrueKnowPerson(person);    
    }

    // ans count
    for(int i = 0; i < m; i++) {
        bool flag = true;
        for(int j = 0; j < participants[i].size(); j++) {
            if(isTrueKnow[participants[i][j]]) {
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }

    printf("%d\n", ans);

    return 0;
}