#include <iostream>
#include <vector>
 
int main()
{
    // 创建含有整数的 vector
    std::vector<int> v = {7, 5, 16, 8};
    std::cout << v.size() << std::endl;
    
    std::vector<std::vector<int> > v2 = {{1, 2, 3, 4},{5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::cout << v2.size() << std::endl;
    std::cout << v2[0].size() << std::endl;
    // 添加二个整数到 vector
    v.push_back(25);
    v.push_back(13);
 
    // 迭代并打印 vector 的值
    for(int n : v) {
        std::cout << n << '\n';
    }
    return 0;
}