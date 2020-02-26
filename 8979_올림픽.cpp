#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Medal {
    int cntGold;
    int cntSilver;
    int cntBronze;
};

vector<pair<Medal, int> > countriesRank;

bool comp(pair<Medal, int> &p1, pair<Medal, int> &p2) {
    if(p1.first.cntGold != p2.first.cntGold) return p1.first.cntGold > p2.first.cntGold;
    else if(p1.first.cntGold == p2.first.cntGold && p1.first.cntSilver != p2.first.cntSilver) return p1.first.cntSilver > p2.first.cntSilver;
    else if(p1.first.cntSilver == p2.first.cntSilver && p1.first.cntBronze != p2.first.cntBronze) return p1.first.cntBronze > p2.first.cntBronze;
    else return p1.first.cntGold > p2.first.cntGold;
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int team, gold, silver, bronze;
    int tmpCntGold, tmpCntSilver, tmpCntBronze;
    Medal m;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &team, &gold, &silver, &bronze);
        m.cntGold = gold;
        m.cntSilver = silver;
        m.cntBronze = bronze;
        if(k == team) {
            tmpCntGold = gold;
            tmpCntSilver = silver;
            tmpCntBronze = bronze;
        }
        countriesRank.push_back(make_pair(m, team));
    }

    sort(countriesRank.begin(), countriesRank.end(), comp);

    int ansRank = -1;
    
    for(int i = 0; i < n; i++) {
        if(k == countriesRank[i].second) {
            ansRank = i+1;
            break;
        }
    }

    // 중복검사
    for(int i = 0; i < n; i++) {
        if(tmpCntGold == countriesRank[i].first.cntGold && tmpCntSilver == countriesRank[i].first.cntSilver && tmpCntBronze == countriesRank[i].first.cntBronze) {
            ansRank = i+1;
            break;
        }
    }

    printf("%d\n", ansRank);

    return 0;
}