
#include<iostream>
#include<algorithm>
using namespace std;

int ternarySearch(int l, int r, int key, int arr[]){
    if(l<=r){
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        
        if(arr[mid1] == key){
            return mid1;
        }
        if(arr[mid2] == key){
            return mid2;
        }
        if(key < arr[mid1]){
            return ternarySearch(l, mid1-1, key, arr);
        }
        else if(key > arr[mid2]){
            return ternarySearch(mid2+1, r, key, arr);
        }
        else{
            return ternarySearch(mid1+1, mid2-1, key, arr);
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int key;
    cout<<"Enter the key element : ";
    cin>>key;
    
    sort(arr, arr+n);
    
    int result = ternarySearch(0, n-1, key, arr);
    
    if(result != -1){
        cout<<"Key element is found in the array... At the index position : "<<result<<endl;
    }
    else{
        cout<<"Key element not found!!"<<endl;
    }
    return 0;
}
