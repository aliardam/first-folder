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
    void iota(int val){
                for (int i = 0 ; i < len ; i++) {
                    mem[i]=i+val;
    }
    }
    void squares (){
        for (int i = 0 ; i < len ; i++){
            mem[i]=i*i;
        }
        
    }

    ~IntArray() {
        delete [] mem;
    }

    IntArray& operator=(const IntArray &) = delete;
};
class doubleArray {
    int len;
    double *mem;
public:
    doubleArray(int n):
        len(n),
        mem(new double[len])
    {
    }
    doubleArray(int n , int fi): len(n),mem(new double[len]){
        fill(fi);
    }

    void store(int i, double val) {
        mem[i] = val;
    }

    void print (){
        for (int i=0 ; i < len ; i++ )
        cout<<"element num "<<i+1<<" is "<<mem[i]<<endl;
    }
    void swap(double &a,double &b){
        double c;
        c=a;
        a=b;
        b=c;
    }
    void resize(int newlen){
        double *newmem = new double[newlen];
        for (int i = 0 ; i < len ; i++) {
            newmem[i]=mem[i];
    }
    mem=newmem;
    len=newlen;
    delete[] newmem;
    }

    double get(int i) {
        return mem[i];
    }

    double length() {
        return len;
    }

    doubleArray(const doubleArray &other):
        len(other.len),
        mem(new double[len])
    {
        for (int i = 0 ; i < len ; i++) {
            mem[i] = other.mem[i];
        }
    }
    void fill(double val){
        for (int i = 0 ; i < len ; i++) {
            mem[i]=val;
    }
    }
    void iota(double val){
                for (int i = 0 ; i < len ; i++) {
                    mem[i]=i+val;
    }
    }
    void squares (){
        for (int i = 0 ; i < len ; i++){
            mem[i]=i*i;
        }
        
    }

    ~doubleArray() {
        delete [] mem;
    }

    IntArray& operator=(const IntArray &) = delete;
};
int main ()
{
    int n; 
    cout<<" n = ";
    cin>>n;
    doubleArray arr(n);
    arr.squares();
    arr.print();
    cout<<"hi";

    return 0;
}