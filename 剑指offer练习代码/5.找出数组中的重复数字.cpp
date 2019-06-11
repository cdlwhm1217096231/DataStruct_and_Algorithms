#include <cstdio>

/*
��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
��ô��Ӧ��������ظ�������2����3��
*/
// ����˼·1���ȶ������������O(nlogn)��Ȼ��Ӵ�ͷ��β���������������ɨ��
// ����˼·2������������û���ظ�Ԫ�أ����ź����Ԫ��iӦ��������Ϊi��λ�ô�����Ϊʵ�����ظ�Ԫ�أ�������Щλ�ô��ڶ��Ԫ�أ���Щλ�ÿ���û��Ԫ��
// ���ȣ��Ƚ�����i����Ԫ��m�Ƿ����i����Ⱦ�˵�������������ʼ�ƶ�iָ�뵽��һ��λ�ã��������ȣ��Ƚ�Ԫ��m���m����������Ԫ��ֵ��
// ��ȾͲ�������˵��Ԫ��m�Ѿ��ظ��ˣ����򣬽���Ԫ���ټ����Ƚ�

bool duplicate(int nums[], int len, int *copy){
    /*
        nums:һ����������
        len:����ĳ���
        copy:�ظ���Ԫ��
        ���أ�true,������Ч�����������ظ���Ԫ��;false,������Ч�����������ظ���Ԫ��
    */
   if(nums==NULL || len <= 0)
        return false;
    for(int i = 0; i < len; ++i){
        if (nums[i] < 0 || nums[i] > len-1)
            return false; 
    }

    for(int i = 0; i < len; ++i){
        while(nums[i] != i){
            if(nums[i] == nums[nums[i]]){
                *copy = nums[i];
                return true;
            }
            // nums[i] ��= nums[nums[i]]�����н�������
            int temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;
        }
    }
    return false;  // ���������ظ���Ԫ��
}


// ====================���Դ���====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// �ظ�����������������С������
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �ظ�����������������������
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// �����д��ڶ���ظ�������
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// û���ظ�������
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// û���ظ�������
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// ��Ч������
void test6()
{
    int* numbers = NULL;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}