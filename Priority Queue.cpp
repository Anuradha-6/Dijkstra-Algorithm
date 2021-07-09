//Priority Queue using min heap.
#include<iostream>
#define size 30 //Total capacity
using namespace std;
int n=0;
int arr[size];
    void heapAdjust(int* arr,int i,int n){
        int key=arr[i];
        int j=2*i; //Leftchild
        while(j<=n){
            if(arr[j]>arr[j+1] && j+1<=n)
                j=j+1;
            if(arr[j]>=key)
                break;
            arr[j/2]=arr[j];
            j=j*2;
        }
        arr[j/2]=key;
    }
    int getMinimum(){
        //Returns minimum element.
        return arr[1];
    }
    int extractMinimum(){
    //Removes minimum element from heap.
        if(n<=0)
            return -9999;
        if(n==1){
            n-=1;
            return arr[1];
        }
        int min=arr[1];
        arr[1]=arr[n];
        n=n-1;
        heapAdjust(arr,1,n);
        return min;
    }
    void decreaseKey(int in,int newVal){
        int i=in;
        arr[i]=newVal;
        while(i>=1 && arr[i/2]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[i/2];
            arr[i/2]=temp;
            i/=2;
        }
    }
    void insertKey(int k){
        if(n>size){
            cout<<"Overflow. Could not insert key"<<endl;
            return;
        }
        n=n+1;
        arr[n]=k;
        int i=n;
        while(i>1 && arr[i/2]>arr[i]){
            int temp=arr[i];
            arr[i]=arr[i/2];
            arr[i/2]=temp;
            i/=2;
        }
    }
    void deleteKey(int i){
        if(i>n){
            cout<<"Delete not possible"<<endl;
            return;
        }
        decreaseKey(i,-9999);
        extractMinimum();
    }
    void print(){
        for(int i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    bool isEmpty(){
        if(n==0)
            return true;
        return false;
    }

/*int main(){
    arr[0]=-9999;
    int ch;
    int i,val,item,x;
    while(true){
        cout<<"1. Get Minimum\n2. Extract Minimum\n3. Decrease Key\n4. Insert Key\n5. Delete Key\n6. Print\n7. Exit\n";
        cout<<"*********************"<<endl;
        cin>>ch;
        switch(ch){
        case 1:
            x=getMinimum();
            cout<<x<<endl;
            break;
        case 2:
            x=extractMinimum();
            cout<<x<<endl;
            break;
        case 3:
            cout<<"Enter the key to be decreased\n";
            cin>>i;
            cout<<"Enter the new value\n";
            cin>>val;
            decreaseKey(i,val);
            break;
        case 4:
            cout<<"Enter the key to be inserted\n";
            cin>>item;
            insertKey(item);
            break;
        case 5:
            cout<<"Enter the position of key to be deleted\n";
            cin>>i;
            deleteKey(i);
            break;
        case 6:
            print();
            break;
        case 7:
            exit(0);

        }
    }
}*/
