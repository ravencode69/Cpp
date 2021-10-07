#include <string>
using namespace std;

template <typename V>
class Mapnode
{
public: //DOING THIS FOR OUR LINKED LIST IN BUCKET ARRAY
    string key;
    V value;
    Mapnode *next;

    Mapnode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~Mapnode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    Mapnode<V> **buckets; //creating the array of heads of the Linked lists
    int size;
    int numbuckets;

public:
    ourmap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new Mapnode<V> *[numbuckets];

        //Lets not keep garbage in array
        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
    }
    int size()
    {
        return count;
    }
    V getValue(string key)
    {
        int bucketindex = getbucketindex(key);
        Mapnode<V> *head = buckets[bucketindex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getbucketindex(string key)
    {
        int hashcode = 0;

        int currentcoff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentcoff; //taki out of bound na jaye
            hashcode = hashcode % numbuckets;
            currentcoff *= 37;
            currentcoff = currentcoff % numbuckets;
        }

        return hashcode % numbuckets;
    }

public:
    void insert(string key, V value)
    {
        int bucketindex = getbucketindex(key);
        Mapnode<v> *head = buckets[bucketindex];

        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next
        }
        Mapnode<v> *head = buckets[bucketindex];
        Mapnode<v> *node = new Mapnode<V>(key, value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
    }

    V remove(string key)
    {
        int bucketindex = getbucketindex(key);
        Mapnode<V> *head = buckets[bucketindex];
        Mapnode<V> *prev = NULL;

        while (head != NULL)
        {
            if (prev == NULL)
            {
                buckets[bucketindex] = head->next;
            }
            if (head->key == key)
            {
                prev->next = head->next;
            }
            V value = head->value;
            head->next = NULL;
            delete head;
            count--;
            return value;
        }
        return 0;
    }
};
