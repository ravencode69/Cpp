#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int *input, int n)
{
  int *output = new int[n]; // equal to the size of input array
  output[0] = 1;
  for (int i = 1; i < n; i++)
  {
    output[i] = 1;
    for (int j = i - 1; j >= 0; j--)
    {
      if (input[j] >= input[i])
      {
        continue;
      }
      int possibleans = output[j] + 1;
      if (possibleans > output[i])
        output[i] = possibleans;
    }
  }
  int best = 0;
  for (int i = 0; i < n; i++)
  {
    if (best < output[i])
      best = output[i];
  }
  delete[] output;
  return best;
}
