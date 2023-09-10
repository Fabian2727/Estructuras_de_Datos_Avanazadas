#ifndef SKIP_PRIORITY_H
#define SKIP_PRIORITY_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <time.h>
#define MAX_LEVEL 6
const float P = 0.5;
using namespace std;

struct node
{
    int value;
    node** next;
    node(int level, int& value)
    {
        next = new node * [level + 1];
        memset(next, 0, sizeof(node*) * (level + 1));
        this->value = value;
    }
    ~node()
    {
        delete[] next;
    }
};

struct skiplist
{
    node* header;
    int value;
    int level;
    skiplist()
    {
        header = new node(MAX_LEVEL, value);
        level = 0;
    }
    ~skiplist()
    {
        delete header;
    }
    void display();
    bool contains(int&);
    void insert_element(int&);
    void delete_element(int&);
    void pop_element();
    int top_element();
};

float frand()
{
    return (float)rand() / RAND_MAX;
}

int random_level()
{
    static bool first = true;
    if (first)
    {
        srand((unsigned)time(NULL));
        first = false;
    }
    int lvl = (int)(log(frand()) / log(1. - P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}

void skiplist::insert_element(int& value)
{
    node* x = header;
    node* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(node*) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--)
    {
        while (x->next[i] != NULL && x->next[i]->value < value)
        {
            x = x->next[i];
        }
        update[i] = x;
    }
    x = x->next[0];
    if (x == NULL || x->value != value)
    {
        int lvl = random_level();
        if (lvl > level)
        {
            for (int i = level + 1; i <= lvl; i++)
            {
                update[i] = header;
            }
            level = lvl;
        }
        x = new node(lvl, value);
        for (int i = 0; i <= lvl; i++)
        {
            x->next[i] = update[i]->next[i];
            update[i]->next[i] = x;
        }
    }
}

void skiplist::delete_element(int& value)
{
    node* x = header;
    node* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(node*) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--)
    {
        while (x->next[i] != NULL && x->next[i]->value < value)
        {
            x = x->next[i];
        }
        update[i] = x;
    }
    x = x->next[0];
    if (x->value == value)
    {
        for (int i = 0; i <= level; i++)
        {
            if (update[i]->next[i] != x)
                break;
            update[i]->next[i] = x->next[i];
        }
        delete x;
        while (level > 0 && header->next[level] == NULL)
        {
            level--;
        }
    }
}

void skiplist::pop_element() {
    node* x = header;
    x = x->next[0];
    delete_element(x->value);
}

int skiplist::top_element() {
    node* x = header;
    x = x->next[0];
    return x->value;
}

void skiplist::display()
{
    const node* x = header->next[0];
    while (x != NULL)
    {
        cout << x->value;
        x = x->next[0];
        if (x != NULL)
            cout << "\t-\t";
    }
    cout << endl;
}

bool skiplist::contains(int& s_value)
{
    node* x = header;
    for (int i = level; i >= 0; i--)
    {
        while (x->next[i] != NULL && x->next[i]->value < s_value)
        {
            x = x->next[i];
        }
    }
    x = x->next[0];
    return x != NULL && x->value == s_value;
}


#endif
