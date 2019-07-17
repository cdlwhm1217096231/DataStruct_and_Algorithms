#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
// �����򣺣����ѣ������������ӶѶ��ѶѶ�Ԫ�ص������������������ٻָ��ѡ�


// ��ӡԪ��
void PrintV(vector<int>& v){
    for(auto &e: v){
        cout << e << ' ';
    }
    cout << endl;
}

// ��������Ĵ���
void HeapSortCore(vector<int>& v, int start, int end){
    // �������ڵ���ӽڵ�ָ��
    int parent = start;
    int son = parent * 2 + 1;
    while(son <= end){  // �ӽڵ��ڷ�Χ�ڲ����Ƚ�
        if(son + 1 <= end && v[son] < v[son+1]){  // �ȱȽ������ӽڵ��С��ѡ������
            son++;
        }

        if(v[parent] > v[son]){  // ������ڵ�����ӽڵ㣬����ѵ�����ϣ�����ѭ��
            return;
        }
        else{  // ���򣬽������ӽڵ�����ݣ��ټ����ӽڵ����ڵ�Ƚ�
            swap(v[parent], v[son]);
            parent = son;
            son = parent * 2 + 1;
        }
    }
}


// ������----�ⲿ���ýӿ�
void HeapSort(vector<int>& v){
    // ��ʼ����i�����һ�����ڵ�������Ͽ�ʼ����
    int n = v.size();
    for(int i = n/2 - 1; i>=0; --i){
        HeapSortCore(v, i, n-1);
    }
    // �Ƚ���һ��Ԫ�غ��Ѿ��ź����Ԫ��ǰһλ�������������µ�����
    for(int i=n-1; i > 0; --i){
        swap(v[0], v[i]);
        HeapSortCore(v, 0, i-1);
    }
}


int main(){
    vector<int> v{7, 30, 16, 4, 1, 2, 9};
    cout << "������ǰ: ";
    PrintV(v);
    HeapSort(v);
    cout << "�������: ";
    PrintV(v);
    return 0;
}