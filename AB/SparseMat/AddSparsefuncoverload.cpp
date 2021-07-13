#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
private:
    int m, n;
    int num;
    Element *ele; //created so that we can create the array IN THE HEAP depending upon the requirement size

public:
    Sparse(int m, int n, int num)
    {
        this->n = n;
        this->m = m;
        this->num = num;
        ele = new Element[this->num];
    }
    friend ostream &operator<<(ostream &out, Sparse &c);
    friend istream &operator>>(istream &in, Sparse &s);
    Sparse operator+(Sparse &s);
    ~Sparse()
    {
        delete[] ele;
    }
};
Sparse Sparse::operator+(Sparse &s)
{
    Sparse *sum;
    int i, j, k;
    i = j = k = 0;
    if (m != s.m || n != s.n)
    {
        printf("unequal dimensions");
        return {0, 0, 0};
    }
    sum = new Sparse(m, n, num + s.num); //******POINT TO BE NOTED************
    while (i < num && j < s.num)
    {
        if (ele[i].i < s.ele[i].i)
            sum->ele[k++] = ele[i++];
        else if (ele[i].i > s.ele[i].i)
            sum->ele[k++] = s.ele[i++];
        else
        {
            if (ele[i].j < s.ele[i].j)
                sum->ele[k++] = ele[j++];
            else if (ele[i].j > s.ele[i].j)
                sum->ele[k++] = s.ele[j++];

            else
            {
                sum->ele[k] = ele[i];

                sum->ele[k++].x = ele[i++].x + s.ele[i++].x;
            }
        }
    }
    for (; i < num; i++)
        sum->ele[k++] = ele[i];
    for (; j < s.num; j++)
        sum->ele[k++] = s.ele[j];
    return *sum;
}

istream &operator>>(istream &in, Sparse &s)
{
    cout << "enter the non zero elements";
    for (int i = 0; i < s.num; i++)
    {
        cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }
    return in;
}

ostream &operator<<(ostream &out, Sparse &c)
{
    int k = 0;

    for (int i = 0; i < c.m; i++)
    {
        for (int j = 0; j < c.n; j++)
        {
            if (c.ele[k].i == i && c.ele[k].j == j)
                cout << c.ele[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return out;
}

int main()
{
    Sparse s1(5, 5, 5);
    cin >> s1;
    Sparse s2(5, 5, 3);
    cin >> s2;
    Sparse sum = s1 + s2;
    cout << "entered matrices\n"
         << s1 << "\n"
         << s2;
    cout << " added matrices\n"
         << sum;

    return 0;
}