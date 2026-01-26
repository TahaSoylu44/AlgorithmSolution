#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int size = temperatures.size();
    stack<pair<int, int>> s;
    vector<int> answer;
    vector<int> result;

    for (int i = size - 1; i >=0; i--)
    {
        if (s.empty())
        {
            answer.push_back(0);
            s.push({temperatures[i], i});
        }
        else
        {
            while(!s.empty())
            {
                if (temperatures[i] < s.top().first)
                {
                    answer.push_back(s.top().second - i);
                    s.push({temperatures[i], i});
                    break;
                }

                s.pop();

                if (s.empty())
                {
                    answer.push_back(0);
                    s.push({temperatures[i], i});
                    break;
                }
            }
        }
    }

    for (int i = size - 1; i>=0; i--) result.push_back(answer[i]);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}