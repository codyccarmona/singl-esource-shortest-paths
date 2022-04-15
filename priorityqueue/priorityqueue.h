#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

struct Arr{
    Arr() {}
    int& operator[](int i){
        return values[i - 1];
    }
    
    vector<int> values;
    int heap_size;
};

struct PriorityQueue{
    PriorityQueue(){}

    void build_max_heap(Arr& A){
        A.heap_size = 1;
        for(auto i = 2; i <= A.values.size(); )
            insert(A, A[i]);
    }


    void insert(Arr& A, int key){
        A.heap_size++;
        A[A.heap_size] = INT_MIN;
        increase_key(A, A.heap_size, key);
    }

    int maximum(Arr& A){
        return A.values[1];
    }

    int extract_max(Arr& A){
        if(A.heap_size < 1)
            __throw_underflow_error("heap underflow");
        auto max = A.values[1];
        A[1] = A[A.heap_size];
        A.heap_size = A.heap_size - 1;
        max_heapify(A, 1);
        return max;
    }

    void increase_key(Arr& A, int i, int key){
        if(key < A[i])
            __throw_invalid_argument("new key is smaller than current key");
        A[i] = key;
        while(i > 1 && A[parent(i)] < A[i]){
            auto currValue = A[i];
            A[i] = A[parent(i)];
            A[parent(i)] = currValue;
            i = parent(i);
        }
    }

private:
    int parent(int i){
        return ceil(i / 2);
    }

    int left(int i){
        return 2 * i;
    }

    int right(int i){
        return (2 * i) + 1;
    }

    void max_heapify(Arr& A, int i){
        int largest;
        auto l = left(i);
        auto r = right(i);

        if(l <= A.heap_size && A[l] > A[i])
            largest = l;
        else    
            largest = i;

        if(r <= A.heap_size && A[r] > A[i])
            largest = r;

        if(largest != i){
            auto currValue = A[i];
            A[i] = A[largest];
            A[largest] = currValue;
            max_heapify(A, largest);
        }
    }
};