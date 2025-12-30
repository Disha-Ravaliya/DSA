#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int arr[5]={0,1,2,3,4};
    int start=0;
    int end=4;
    int temp;
    
    while(start<end){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;

        start++;
        end--;

        
        
    }
    
    cout<<"print arra is :\n";
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    return 0;
}