#include <iostream>
#include <string>


using namespace std;

int main(){
    string str;
    char c;
    getline(cin, str);
    c = getchar();
    int count = 0;
    int len = str.length() - 1;
    for(int i=0; i <= len; i++){
        if(str[i] == c || str[i] == c - 32 || str[i] == c + 32){
            count++;
        }
        else{
            continue;
        }
    }
    cout << count << endl;
    return 0;
}