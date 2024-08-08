#include <iostream>
#include <vector>
std::vector<double> C={2,9,0,3,4,3,6};//系数
double getpower(double x,int power,double ans=1){
        for(int i=0;i<power;i++){
            ans*=x;
        }
        return ans;
}//求幂函数
double function(double x){
    double fx=0;
    int n=C.size()-1;
    for(auto c:C){
        fx+=c*getpower(x,n);
        n--;
    }
    return fx;
}
double gradient(double x){
    double gx=0;
    int n=C.size();
    // C.pop_back();
    for(auto c:C){
        gx+=n*c*getpower(x,n-1);
        n--;
    }
    return gx;
}
double gradient_descent(double start,double learning_rate){
    while(1){double grad=gradient(start);
    double x=start;
    x=x-grad*learning_rate;
    if((start-x)*(start-x)<5.0E-20){break;}
    start=x;
    std::cout<<start<<'\n';
    }
    return start;
}
int main(){
    C.pop_back();
    double minute=gradient_descent(20,0.0000009);
    std::cout<<minute;
    printf("\n%.15f",minute);
}