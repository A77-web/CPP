#include <iostream>
using namespace std;

inline int call( ){
    static int ctr =1;
    return ctr++;    
}

int main(){
    for(int i=0; i<500; i++)
        cout<<call()<<" "<<endl;
}
