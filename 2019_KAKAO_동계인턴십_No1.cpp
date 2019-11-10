#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> basket;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;

    vector<vector<int>> dollMap;

    int bSize = board.size();
    dollMap.resize(bSize);

    for (int i = 0; i < bSize; i++)
    {
        for (int j = bSize-1; j >= 0; j--)
        {
            if (board[j][i] > 0)
                dollMap[i].push_back(board[j][i]);
        }
    }

    // for(int i = 0 ; i < bSize; i++) {
    //     for(int j = 0; j < dollMap[i].size(); j++) {
    //         cout << dollMap[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int numOfMoves = moves.size();
    for (int i = 0; i < numOfMoves; i++)
    {
        if (dollMap[moves[i] - 1].size() > 0)
        {
            if (!basket.empty())
            {
                if (basket.top() == dollMap[moves[i] - 1].back())
                {
                    answer += 2;
                    basket.pop();
                }
                else
                {
                    basket.push(dollMap[moves[i] - 1].back());
                }
            }
            else
                basket.push(dollMap[moves[i] - 1].back());

            dollMap[moves[i] - 1].pop_back();
        }

    }

    return answer;
}