#include <iostream>
#include <vector>
using namespace std;

class ipv4address {
    vector <unsigned char> address;
    public:
    ipv4address() : address(4) {}

    unsigned char getad(int i) const {
        if (i<1 || i>4){ cout<<"address does not exist"<<endl; return 0; }
        return address[i];
    }
    void setad(int i,unsigned char n ) {
        address[i]=n;
    }
};
