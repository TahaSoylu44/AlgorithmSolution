#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long

bool isAppropriate(vector<int>& array, int pointer, int M, int trial)
{
    int num_of_two = M / 2;
    int num_of_one = M - num_of_two;
    int need, need_of_two;

    for (int i = pointer; i < array.size(); i++)
    {
        need = trial - array[i];

        // std::cout << "trial: " << trial << " need : " << need << " i: " << i << '\n';

        if (need > 0)
        {
            if (num_of_two > 0 && need >= 2)
            {
                need_of_two = need / 2;

                if (need_of_two <= num_of_two)
                {
                    need -= (2 * need_of_two);
                    num_of_two -= need_of_two;
                }
                else
                {
                    need -= (2 * num_of_two);
                    num_of_two = 0;
                }
            }

            if (num_of_one > 0 && need > 0)
            {
                if (need > num_of_one) return false;
                num_of_one -= need;
                need = 0;
            }

            if (need > 0) return false;
        }
        else return true;
    }

    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M,K;
    cin >> N >> M >> K;

    vector<int> array(N);
    for (int i = 0; i < N; i++) cin >> array[i];
    sort(array.begin(), array.end());

    int pointer = K - 1;

    int num_of_two = M / 2;
    int num_of_one = M - num_of_two;

    int left = 0;
    int right = 1e18;

    int ans, mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (isAppropriate(array, pointer, M, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    std::cout << ans;

    return 0;
}