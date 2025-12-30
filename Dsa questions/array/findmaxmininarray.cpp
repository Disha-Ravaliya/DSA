#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    

    int arr[6]={2,5,-6,7,3,8};
    int max=0;
    int min=0;

    for(int i=0;i<6;i++){
        if(arr[i]>max){
            max=arr[i];

        }
        if(arr[i]<min){
            min=arr[i];
            
        }

        
    }
    cout<<"max:"<<max;
    cout<<"\n min :"<<min;
    return 0;
}