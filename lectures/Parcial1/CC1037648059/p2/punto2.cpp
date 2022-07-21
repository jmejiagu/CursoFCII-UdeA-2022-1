#include<iostream>
#include<iomanip>
using namespace std;
int check(int n)
{
int sum=1;
    for(int i=2;i<n;i++)
    {
        if (n%i==0){
            sum+=i;
            };
    };
    if(sum==n){
        return 0;
    }
    else{return 1;};
}
int perfecto(int n){
    int sum=1;
    for(int i=2;i<n;i++)
    {
        if (n%i==0){
            sum+=i;
            cout<<i<<"+";
            };
    };
    if(sum==n){
        cout<<"1"<<"="<<n<<" El numero "<<n<<" es perfecto"<<endl;
    }
    else{cout<<"El numero "<<n<<" no es perfecto"<<endl;};
    return 0;
}

int main(){
for(int jj=2;jj<10000;jj++){
    if(check(jj)==0){perfecto(jj);}
    //else{cout<<"El numero "<<jj<<" no es perfecto"<<endl;};
    //cout<<jj<<endl;
};
return 0;}