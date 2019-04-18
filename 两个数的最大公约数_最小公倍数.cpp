#include "iostream"

using namespace std;




int main(){
    int num1, num2;
    cout << "请依次输入两个整数: "; 
    cin >> num1 >> num2;
    while(num1 != num2){
        if(num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    cout << "最大公约数是: " << num1 << endl;
    int num3, num4;
    cout << "请依次输入两个整数: ";
    cin >> num3 >> num4;
    int max = (num3 > num4)? num3:num4;
    do{
        if(max % num3 == 0 && max % num4 == 0){
            cout << "最小公倍数是: " << max << endl;
            break;
        }   
        else
            max++;
    }while(true);
    return 0;
}