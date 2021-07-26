#include <iostream>
#include <string.h>
using namespace std;
string options(int digit)
{
    if (digit == 2)
        return "abc";
    if (digit == 3)
        return "def";
    if (digit == 4)
        return "ghi";
    if (digit == 5)
        return "jkl";
    if (digit == 6)
        return "mno";
    if (digit == 7)
        return "pqrs";
    if (digit == 8)
        return "uvw";
    if (digit == 9)
        return "xyz";

    return "";
}

int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int lastdigit = num % 10;
    int smallernumber = num / 10;
    int sizeofSM = keypad(smallernumber, output); //faith step Assume that ki isme small number ke liye output fill ho gaya hai

    //ab aage dekte h last digit k options aur fir usko attach kar denge smallnumber k output k saath
    string optionsoflastdigit = options(lastdigit);

    for (int i = 0; i < optionsoflastdigit.length() - 1; i++)
    {

        for (int j = 0; j < sizeofSM; j++)
        {
            output[j + (i + 1) * sizeofSM] = output[j]; //creating copy of the output set accordingly
        }
    }

    int k = 0;
    for (int i = 0; i < optionsoflastdigit.length(); i++)
    {

        for (int j = 0; j < sizeofSM; j++)
        {
            output[k] = output[k] + optionsoflastdigit[i];
            k++;
        }
    }
    return sizeofSM * optionsoflastdigit.length();
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
