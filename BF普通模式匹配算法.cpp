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
    if(j == strlen(t)){   // �ɹ�ƥ��
        return i - strlen(t) + 1;   // �����Ӵ�T������S�е�λ�ã���6��λ�ÿ�ʼƥ���ϵ�
    }else
        return -1;  // δƥ��ɹ���
}



int main(){
    int result;
    result = bf("ababcabcacbab", "abcac");
    cout << "�Ӵ�T������S�е�λ��: " << result << endl;
    return 0;
}