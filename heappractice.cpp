#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size =0;
    void insert(int d){
        size = size+1;
        int index = size;
        arr[index] = d;
        while(index>1){
            int parent =index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index = parent; 
            }
            else return;

        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<< " ";
        }
    }
    void deleteheap(){
        if(size==0){
            cout<<"Heap is Empty"<<endl;
        }
        arr[1]=arr[size];
        size--;
        int index = 1;
        while(index<=size){
            int left = 2*index;
            int right = 2*index +1;
            if(arr[index]<arr[left] && left<=size){
                swap(arr[index],arr[left]);
                index = left;
            }
            else if(arr[index]<arr[right] && right <= size){
                swap(arr[index],arr[right]);
                index = right;
            }
            else return;
        }

    }

};
void heapify(int arr[], int index,int n){
    int largest = index;
    int left = 2*index;
    int right = 2*index +1;
    if(arr[largest]<arr[left] &&  left <= n){
        largest = index;

    }
    else if(arr[largest]<arr[right] && right <=n){
        largest = right;


    }
    if(largest != index){
        swap(arr[largest] , arr[index]);
        heapify(arr,largest,n);
    }

}
int main(){
    Heap h;
    int arr[]= {34,5,43,7,87,44,67,46,7,45,65};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = n/2; i>0;i--){
        heapify(arr,i,n);
    }
}