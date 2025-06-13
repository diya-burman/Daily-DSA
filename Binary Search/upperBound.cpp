#include<iostream>
using namespace std;

int upperBound(int arr[], int n, int x) {
    int s=0;
    int e=n-1;
    int ans=n;
    while(s<=e) {
        int mid=(s+e)/2;
        if(arr[mid]<=x) {
            ans=mid;
            s=mid+1;
        } else {
            e=mid-1;
        }
    }
    return ans;
}

int main() {
    int even[10] = {1,2,3,3,7,8,9,9,9,11};
    cout<<"Upper bound is "<<upperBound(even,10,9)<<endl;

    return 0;
}