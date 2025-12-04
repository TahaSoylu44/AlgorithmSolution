#include <iostream>
#include <vector>

/*
Açıkçası ilk kimin aklına gelmişşe helal olsun,
bilgisayarın geleceği görmesini sağlayan kolay gözüken
bir karmaşık kod.Memoization yapmak için bir array oluşturdum.
Ondan sonra belli bir noktada yapılması gereken en mantıklı davranışı 
kaydettim.Bilgisayarı geleceği göreceği zaman elinde 2 seçenek var.
Ya listenin başından kart seçecek ya da sonundan.Benim bunlardan ikisini 
karşılaştırmam lazımdı laikn greedy yaklaşamazdın.Her zaman en büyüğünü seçmek 
kazandırmıyor.O yüzden bir heşper fonksiyonu lazımdı çünkü yapacağım hamlenin sonuçlarını 
hesaplamalıydım.Yaptığım her hareket sonucu rakibin en mantıklı hareketini çıkardım.
Bu şekilde ilerleyerek kazanıp kazanmayacağımı buldum.
*/

// dp[i][j] = max( nums[i] - dp[i+1][j], nums[j] - dp[i][j-1] )

using namespace std;

int memo[21][21];

int helper(vector<int>& nums, int left, int right)
{
    if (left == right) return nums[left];

    if (memo[left][right] == -1e9)
    {
        int opt1 = nums[left] - helper(nums, left + 1, right);
        int opt2 = nums[right] - helper(nums, left, right - 1);
        memo[left][right] = (opt1 > opt2) ? opt1 : opt2;
    }
    return memo[left][right];  
}

bool predictTheWinner(vector<int>& nums) {
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            memo[i][j] = -1e9;
        }  
    }
    
    return helper(nums, 0, nums.size() - 1) >= 0;
}

int main() {
    
    vector<int> nums = {1};

    std::cout << predictTheWinner(nums) << std::endl;

    return 0;
}