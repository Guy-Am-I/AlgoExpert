#include <vector>
using namespace std;


int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  // Index represents amound, value represents coins needed for that amount
  vector<int> coinsNeededLUT(n + 1, INT_MAX);
  coinsNeededLUT[0] = 0;
  for_each(denoms.begin(), denoms.end(), [&](const auto& currCoin) {
    int toCompare = 0;
    for (int amount = 0; amount <= n; ++amount) {
      if (currCoin <= amount) {
        auto coinsNeededForDiff = coinsNeededLUT[amount - currCoin];
        if (coinsNeededForDiff == INT_MAX)  { //invalid - can't create amount
          toCompare = coinsNeededForDiff; //we know its INT_MAX so won't apply
        }
        else {
          toCompare = coinsNeededForDiff + 1; //currCoin + however many coins for diff
        }
        coinsNeededLUT[amount] = min(coinsNeededLUT[amount], toCompare);
      }
    }
  });
  return coinsNeededLUT[n] != INT_MAX ? coinsNeededLUT[n] : -1;
}

int main() {
    auto res = minNumberOfCoinsForChange(7, {1,5,10});
    return 0;
}