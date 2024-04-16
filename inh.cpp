#include <iostream>
#include <vector>
using namespace std;

class ipv4address {
    vector <unsigned char> address;
    public:
    ipv4address() : address(4) {}
    ipv4address(unsigned char a, unsigned char b, unsigned char c, unsigned char d) : address({a, b, c, d}) {}

    unsigned char getad(int i) const {
        if (i<1 || i>4){ cout<<"address does not exist"<<endl; return 0; }
        return address[i-1];
    }
    void setad(int i,unsigned char n ) {
        address[i]=n;
    }
};

class request {
    ipv4address origin;
    public:
    request(ipv4address address) : origin(address) {}
    ipv4address getorigincon() const {
        return origin;
    }
    void log () {
        cout<<"Request of unknown type from"<<origin.getad(1)<<","<<origin.getad(2)<<","<<origin.getad(3)<<origin.getad(4);
    }
    protected:
    ipv4address getorigin(){
        return origin;
    }


};

class HttpRequest : public request {
    string url;
    public:
    HttpRequest(unsigned char a, unsigned char b, unsigned char c, unsigned char d, string _url) : request(ipv4address(a,b,c, d)) , url(_url) {}
    HttpRequest(ipv4address address , string _url) : request(address) , url(_url) {}
    void seturl(string _url){
        url = _url;
    }
    string geturl() const {
        return url;
    }
    void log () {
        cout<<"Request of unknown type from"<<getorigin().getad(1)<<","<<getorigin().getad(2)<<","<<getorigin().getad(3)<<getorigin().getad(4)<<"to url"<<geturl()<<endl;
    }

};
class GetRequest : public HttpRequest {
    public:
    GetRequest(unsigned char a, unsigned char b, unsigned char c, unsigned char d, string _url) : HttpRequest(ipv4address(a,b,c, d),_url) {}
    GetRequest(ipv4address address , string _url) : HttpRequest(address,_url) {}
    void log () {
        cout<<"Request of unknown type from"<<getorigin().getad(1)<<","<<getorigin().getad(2)<<","<<getorigin().getad(3)<<getorigin().getad(4)<<"to url"<<geturl()<<endl;
    }
};
class PostRequest : public HttpRequest 
{
    string payload;

    public:
    PostRequest(unsigned char a, unsigned char b, unsigned char c, unsigned char d, string _url,string _pay) : HttpRequest(ipv4address(a,b,c, d),_url) , payload(_pay) {}
    PostRequest(ipv4address address , string _url, string _pay) : HttpRequest(address,_url) , payload(_pay) {}
    PostRequest(HttpRequest _req, string _pay) : HttpRequest(_req) , payload(_pay) {}
    void log () {
        cout<<"Http POST Request of from"<<getorigin().getad(1)<<","<<getorigin().getad(2)<<","<<getorigin().getad(3)<<getorigin().getad(4)<<"to url "<<geturl()<<"with payroll "<<endl;
    }
int main () {
    GetRequest gr(127, 0, 0, 1, "http://example.com/api");
gr.log();
PostRequest pr(127, 0, 0, 1, "http://example.com/api", "{\"password\": \"secret\"}");
pr.log();
return 0;
}






};