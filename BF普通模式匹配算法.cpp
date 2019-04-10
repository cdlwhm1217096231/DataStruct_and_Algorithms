#include "iostream"
#include "cstring"

using namespace std;


int bf(char *s, char *t){
    int i=0, j=0;
    while(i < strlen(s) && j < strlen(t)){
        if(s[i] == t[j]){
            i++;
            j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == strlen(t)){   // 成功匹配
        return i - strlen(t) + 1;   // 返回子串T在主串S中的位置，第6个位置开始匹配上的
    }else
        return -1;  // 未匹配成功！
}



int main(){
    int result;
    result = bf("ababcabcacbab", "abcac");
    cout << "子串T在主串S中的位置: " << result << endl;
    return 0;
}