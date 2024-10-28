// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int Binom(int n, int k)
{
    // Calculate binomial coefficent
    // After method in https://de.wikipedia.org/wiki/Binomialkoeffizient#Algorithmus_zur_effizienten_Berechnung

    // if (2 * k > n)
    //     k = n - k;

    int result = 1;

    for (int i = 1; i < k + 1; i++)
    {
        // result = result * (n + 1 - i) / i;
        result = result * (k + i) / i;
    }
    return result;
}
vector<double> f(int n)
{
    vector<double> result = {1};
    int place = 0;
    while (place < n - 1)
    {
        result.push_back(result[place] / 4);
        result[place + 1] *= ((2 * place + 2) * (2 * place + 1));
        result[place + 1] /= ((place + 1) * (place + 1));
        place += 1;
    }
    return result;
}
int main()
{
    // Write C++ code here
    vector<double> result = f(10);
    for (int i = 0; i < result.size(); i++)
    {
        // result = result * (n + 1 - i) / i;
        std::cout << result[i] << " BINOM " << Binom(2 * i, i) << endl;
    }

    return 0;
}
