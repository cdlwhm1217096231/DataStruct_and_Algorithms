#include "iostream"

using namespace std;




int main(){
    int num1, num2;
    cout << "������������������: "; 
    cin >> num1 >> num2;
    while(num1 != num2){
        if(num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    cout << "���Լ����: " << num1 << endl;
    int num3, num4;
    cout << "������������������: ";
    cin >> num3 >> num4;
    int max = (num3 > num4)? num3:num4;
    do{
        if(max % num3 == 0 && max % num4 == 0){
            cout << "��С��������: " << max << endl;
            break;
        }   
        else
            max++;
    }while(true);
    return 0;
}