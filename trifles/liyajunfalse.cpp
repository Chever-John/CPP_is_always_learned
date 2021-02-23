#include<iostream>
#include<string>
using namespace std;

class build {
    friend void badguy::text();
    public:
        build();
        string sittingroom;
    private:
        string bedroom;
};

build::build(){
    this->bedroom = "卧室";
    this->sittingroom = "客厅";
}

class badguy {
    public:
        void text();
};

void badguy::text() {
    build p;
    p.sittingroom;
    p.bedroom;
}