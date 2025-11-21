#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class MinMaxHeap {

    vector<int> h;

public:

    MinMaxHeap(){ h.push_back(0); }

    bool isMinLevel(int i){
        int lvl = (int)floor(log2(i));
        return lvl%2==0;
    }

    void swapIt(int &a,int &b){
        int t=a; a=b; b=t;
    }

    void bubbleUpMin(int i){
        if(i/4>=1 && h[i] < h[i/4]){
            swapIt(h[i],h[i/4]);
            bubbleUpMin(i/4);
        }
    }

    void bubbleUpMax(int i){
        if(i/4>=1 && h[i] > h[i/4]){
            swapIt(h[i],h[i/4]);
            bubbleUpMax(i/4);
        }
    }

    void bubbleUp(int i){
        if(i==1) return;
        int p=i/2;

        if(isMinLevel(i)){
            if(p>=1 && h[i] > h[p]){
                swapIt(h[i],h[p]);
                bubbleUpMax(p);
            } else bubbleUpMin(i);
        } else {
            if(p>=1 && h[i] < h[p]){
                swapIt(h[i],h[p]);
                bubbleUpMin(p);
            } else bubbleUpMax(i);
        }
    }

    void insertVal(int x){
        h.push_back(x);
        bubbleUp(h.size()-1);
    }

    int smallestChild(int i){
        int l=2*i , r=l+1;
        if(r < h.size()) return h[l]<h[r]?l:r;
        else if(l < h.size()) return l;
        return -1;
    }

    int largestChild(int i){
        int l=2*i , r=l+1;
        if(r < h.size()) return h[l]>h[r]?l:r;
        else if(l < h.size()) return l;
        return -1;
    }

    void bubbleDown(int i){
        if(isMinLevel(i)){
            int m=smallestChild(i);
            if(m!=-1 && h[m] < h[i]){
                swapIt(h[m],h[i]);
                bubbleDown(m);
            }
        } else {
            int m=largestChild(i);
            if(m!=-1 && h[m] > h[i]){
                swapIt(h[m],h[i]);
                bubbleDown(m);
            }
        }
    }

    void update_key(int idx,int newV){
        if(idx<=0 || idx>=h.size()) return;
        int old=h[idx];
        h[idx]=newV;
        if(newV>old) bubbleDown(idx);
        else bubbleUp(idx);
    }

    void delete_index(int i){
        if(i<=0 || i>=h.size()) return;
        h[i]=h.back();
        h.pop_back();
        if(i<h.size()){
            bubbleUp(i);
            bubbleDown(i);
        }
    }

    void printHeap(){
        for(int i=1;i<h.size();i++) cout<<h[i]<<" ";
        cout<<endl;
    }
};


int main(){

    MinMaxHeap m;

    m.insertVal(8);
    m.insertVal(7);
    m.insertVal(6);
    m.insertVal(5);
    m.insertVal(4);

    m.printHeap();

    m.update_key(3, 100);
    m.printHeap();

    m.delete_index(2);
    m.printHeap();

    return 0;
}
