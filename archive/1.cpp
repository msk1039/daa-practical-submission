#include<iostream>
#include<vector>
using namespace std;

void myMerge(vector<int>& nums, int left,int mid, int right){
    int l = left;
    int r = mid+1;
    vector<int> temp(right-left,0);
    int i=0;
    while(l<=mid && r<=right){
        if(nums[l]<nums[r]){


            temp[i] = nums[l];
            l++;
        }else{
            temp[i] = nums[r];
            r++;
        }
        i++;
    }

    while(l<=mid){
          temp[i++] = nums[l++];

    }
    while(r<=right){
          temp[i++] = nums[r++];

    }

    for(int j=left;j<=right;j++){
           nums[j] = temp[j-left];
    }
}

void myMergeSort(vector<int>& nums,int left, int right){
    if(left>=right){
        return;
    }
    int mid = (left+right)/2;

    myMergeSort(nums, left, mid);
    myMergeSort(nums, mid+1, right);

    myMerge(nums, left,mid, right );


}


int main(){
    vector<int> nums = {4,5,2,9,1};

    cout<<"before sorting\n";
    for(auto& i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
    myMergeSort(nums, 0 , nums.size()-1);
    cout<<"after sorting\n";
    for(auto& i:nums){
        cout<<i<<" ";
    }
    cout<<endl;
}
