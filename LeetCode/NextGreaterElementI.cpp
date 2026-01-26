#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    stack<int> s;
    unordered_map<int, int> mymap;
    vector<int> v;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        int number = nums2[i];

        if (s.empty())
        {
            mymap.insert({number, -1});
            s.push(number);
            continue;
        }

        while (!s.empty())
        {
            if (s.top() > number)
            {
                mymap.insert({number, s.top()});
                s.push(number);
                break;
            }
            else
            {
                s.pop();

                if (s.empty())
                {
                    mymap.insert({number, -1});
                    s.push(number);
                    break;
                }
            }   
        }
    }

    for (int i = 0; i < nums1.size(); i++) v.push_back(mymap[nums1[i]]);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}