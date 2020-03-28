#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 65;

int newKey[MAX][MAX];
int newLock[MAX][MAX];
int kSize;

void setDefaultLock(const vector<vector<int>> &lock)
{
    int lSize = lock.size();

    for(int i = 0; i < lSize*3; i++) {
        for(int j = 0; j < lSize*3; j++) {
            newLock[i][j] = 0;
        }
    }

    for (int i = lSize; i < lSize * 2; i++)
    {
        for (int j = lSize; j < lSize * 2; j++)
        {
            newLock[i][j] = lock[i - lSize][j - lSize];
        }
    }
}

bool isOpen(const vector<vector<int>> &lock)
{
    bool flag = false;
    int lSize = lock.size();

    for (int x = 0; x <= lSize * 2; x++)
    {
        for (int y = 0; y <= lSize * 2; y++)
        {
            setDefaultLock(lock);

            // key 반영
            for (int i = 0; i < kSize; i++)
            {
                for (int j = 0; j < kSize; j++)
                {
                    newLock[i + x][j + y] = newKey[i][j];
                }
            }


        cout << "---------------------------" << endl;
        for(int ci = 0; ci < lSize*3; ci++) {
            for(int cj = 0; cj < lSize*3; cj++) {
                cout << newLock[ci][cj] << " ";
            }
            cout << endl;
        }
        
            bool tmp = true;
            // lock 검사
            for (int i = lSize; i < lSize * 2; i++)
            {
                for (int j = lSize; j < lSize * 2; j++)
                {
                    if(!newLock[i][j]) {
                        tmp = false;
                        break;
                    }
                }
            }
            
            tmp = flag;
            if(flag) break;
        }

        if(flag) break;
    }

    return flag;
}

void rotateKey()
{

    int tempKey[kSize][kSize];

    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            tempKey[j][kSize - i - 1] = newKey[i][j];
        }
    }

    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            newKey[i][j] = tempKey[i][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;

    kSize = key.size();

    for (int i = 0; i < kSize; i++)
    {
        for (int j = 0; j < kSize; j++)
        {
            newKey[i][j] = key[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        rotateKey();
        if (isOpen(lock))
        {
            answer = true;
            break;
        }
    }

    return answer;
}