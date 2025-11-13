#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int>& arr,int low,int high){
    int pivot = arr[low];
    int l = low+1;
    int r = high;

    while(true){
        while(l<=high &&  arr[l]<pivot)
            l++;
        while(r>=low &&  arr[r]>=pivot)
            r--;
        if(l<r){
            swap(arr[l],arr[r]);
        }else{
            break;
        }
    }
    swap(arr[low],arr[r]);
    return r;
}
void myQuickSort(vector<int>& arr,int low , int high){
    if(low<high){
        int p = partition(arr,low, high);
        myQuickSort(arr, low, p - 1);
        myQuickSort(arr, p + 1, high);
    }
}

int main(){
    vector<int> arr = {3,5,2,9,1};
    cout<<"before sorting\n";
    for(auto& i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    myQuickSort(arr,0,arr.size()-1);
    cout<<"after sorting\n";
    for(auto& i:arr){
        cout<<i<<" ";
    }

}
