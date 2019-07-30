#include <iostream>
#include <string>

using namespace std;


int main(){
    string s;
    getline(cin, s);
    int count = s.rfind(' ');
    if(count < 0){
        count  = s.length();
    }
    else{
        count = s.length() - count - 1;
    }
    cout << count << endl;
    return 0;
}