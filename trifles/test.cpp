
#include <iostream>

#include <cstring>

using namespace std;

class node{

public:

    string word;

    unsigned long x;

    node *next;

};

 

class sequence{

private:

    node *head;

    node *temp;

    int count;

public:

    sequence():head(NULL),temp(NULL),count(0){}

    node *create_sequence();

    node *do_sequence();

    void get_word();

    ~sequence();

};

node *sequence::create_sequence()

{

    head = temp = new node;

    head->next = temp->next = NULL;

    node *p = NULL;

    string s = "aa";

    cout<<"请输入你想要排序的英文单词，输入#结束："<<endl;

    while(s != "#")

    {

        cin>>s;

        p = new node;

        p->next = NULL;

        p->word = s;

        p->x = strlen(s.c_str());

        temp->next = p;

        temp = temp->next;

        count++;

    }

    return head;

}

 

node *sequence::do_sequence()

{

    temp = head->next;

    for(int i=0;i<count-2;i++)

    {

        for(int j=0;j<count-2;j++)

        {

            if(temp->x > temp->next->x)

            {

                unsigned long n;

                string s;

                s = temp->next->word;

                n = temp->next->x;

                temp->next->word = temp->word;

                temp->next->x = temp->x;

                temp->x = n;

                temp->word = s;

                temp = temp->next;

            }

            else

            {

                temp = temp->next;

            }

        }

        temp = head->next;

    }

    return head;

}

 

void sequence::get_word()

{

    cout<<"排序后得到的结果是："<<endl;

    node *p = head->next;

    while(p->word != "#")

    {

        cout<<p->word<<" ";

        p = p->next;

    }

    cout<<endl;

}

sequence::~sequence()

{

    node *p = new node;

    while(head != NULL)

    {

        p = head;

        head = head->next;

        delete p;

    }

}

 

int main()

{

    sequence l1;

    l1.create_sequence();

    l1.do_sequence();

    l1.get_word();

    return 0;

}
