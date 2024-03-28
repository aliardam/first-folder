#include <iostream>
using namespace std;
class IntArray {
    int len;
    int *mem;
public:
    IntArray(int n):
        len(n),
        mem(new int[len])
    {
    }
    IntArray(int n , int fi): len(n),mem(new int[len]){
        fill(fi);
    }

    void store(int i, int val) {
        mem[i] = val;
    }

    void print (){
        for (int i=0 ; i < len ; i++ )
        cout<<"element num "<<i+1<<" is "<<mem[i]<<endl;
    }

    int get(int i) {
        return mem[i];
    }

    int length() {
        return len;
    }

    IntArray(const IntArray &other):
        len(other.len),
        mem(new int[len])
    {
        for (int i = 0 ; i < len ; i++) {
            mem[i] = other.mem[i];
        }
    }
    void fill(int val){
        for (int i = 0 ; i < len ; i++) {
            mem[i]=val;
    }
    }
    void iota(){
                for (int i = 0 ; i < len ; i++) {
                    mem[i]=i;
    }
    }

    ~IntArray() {
        delete [] mem;
    }

    IntArray& operator=(const IntArray &) = delete;
};

int main ()
{
    int n; 
    cout<<" n = ";
    cin>>n;
    IntArray arr(n);
    arr.iota();
    arr.print();
    cout<<"balls";


    return 0;
}