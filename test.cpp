#include <iostream>
#include <vector>
using namespace std;

class BinHeap{

private:
    vector<int> heapvector;
    int currentSize;

public:
    BinHeap(vector<int> heapvector){
        this->heapvector = heapvector;
        this->currentSize = 0;
    }

    void print(){
        int i=0;
        for ( i=0 ; i < heapvector.size(); i++ )
            cout << heapvector[i] << " ";
        cout << endl;
    }
    void upHeap(int i){
        while ((i / 2) > 0){
            if (this->heapvector[i] < this->heapvector[i/2]){ // compare with its parent
                int tmp = this->heapvector[i/2];
                this->heapvector[i/2] = this->heapvector[i];
                this->heapvector[i] = tmp;
                i = i/2;
            } else
                break;
        }
    }

    void insert(int k){
        this->heapvector.push_back(k);
        this->currentSize = this->currentSize + 1;
        this->upHeap(this->currentSize);
    }

    void downHeap(int i){
        while ((i*2) <= this->currentSize){
            int mc = this->minChild(i);
            if (this->heapvector[i] > this->heapvector[mc]){
                int tmp = this->heapvector[i];
                this->heapvector[i] = this->heapvector[mc];
                this->heapvector[mc] = tmp;
            }
            i = mc;
        }
    }

    int minChild(int i){
        if (((i*2)+1) > this->currentSize){
            return i * 2;
        }
        else{
            if (this->heapvector[i*2] < this->heapvector[(i*2)+1]){
                return i * 2;
            }
            else{
                return (i * 2) + 1;
            }
        }
    }

    int delMin(){
        int retval = this->heapvector[1];
        this->heapvector[1] = this->heapvector[this->currentSize];
        this->currentSize = this->currentSize - 1;
        this->heapvector.pop_back();
        this->downHeap(1);
        return retval;
    }

    void buildheap(vector<int> avector){
        int i = avector.size() / 2;
        this->currentSize = avector.size();
        this->heapvector.insert(this->heapvector.end(), avector.begin(), avector.end());
        while (i > 0){
            this->downHeap(i);
            i = i - 1;
        }
    }

    bool isEmpty(){
        if (this->heapvector.size()>0){
            return false;
        }
        return true;
    }

    int findMin(){
        return this->heapvector[1];
    }
};


int main(){
    vector<int> vec;
    vec.push_back(0);

    BinHeap *bh = new BinHeap(vec);
    cout << "Begin: ";
    bh->print();

    bh->insert(5);
    bh->insert(7);
    bh->insert(3);
    bh->insert(11);
    cout << "After insertting...\n";
    bh->print();

    cout << bh->delMin() << " is deleted\n";
    cout << bh->delMin() << " is deleted\n";
    cout << bh->delMin() << " is deleted\n";
    cout << bh->delMin() << " is deleted\n";
    cout << "AFter deleting...\n";
    bh->print();
    return 0;
}

