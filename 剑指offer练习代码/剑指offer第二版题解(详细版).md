#### 1.滑动窗口的最大值（剑指offer原59题）
- 解题思路：**其实是一个队列的问题，用一个队列去维护当前窗口中的所有元素；首先将超出窗口中的队头元素先删掉，然后将新的元素插入当前窗口中，插入时要判断新插入的元素与队尾元素的大小，如果队尾元素较小，则先删除队尾元素再插入**。
    ```
    #include <iostream>
    #include <vector>
    #include <deque>


    using namespace std;


    class Solution{
    public:
        vector<int> maxInWindows(vector<int>& nums, int k)   // k是窗口的大小
        {
            vector<int> res;
            deque<int> q;
            for(int i = 0; i < nums.size(); i++)
            {
                while(q.size() && q.front() <= i - k) q.pop_front();  // 将已经划出窗口中的元素从队列中删除
                while(q.size() && nums[q.back()] <= nums[i])  nums.pop_back();   // 如果在队尾插入的元素大于等于当前队尾的元素值，就可以删除队尾的元素！
                q.push_back(i);
                if(i >= k - 1) res.push_back(nums[q.front()]);
            }
            return res;
        }
    };
    ```
#### 2.n个骰子的点数，这里求的是扔n次骰子，n次中骰子点数之和是s的，所有方案可能的数！(与剑指offer60题有点差别！)
- 解题思路：每次扔骰子，最小值是1，最大值是6；所以扔n个骰子在地上后的，最小值就是n，最大值就是6*n。dfs()算法的思路：
    ```
    #include <iostream>
    #include <vector>

    using namespace std;

    // dfs方法来解决：注意两点，第一是状态的表示是什么(从输出中来)？第二是按照什么顺序来计算第一步中的状态？

    class Solution{
    public:
        vector<int> numberOfDice(int n){
            vector<int> res;
            for(int i = n; i <= 6 * n; i++) res.push_back(dfs(n, i));  // dfs(n, s)表示的就是所要输出的结果；也就是每次求总和是s的情况下，一共投了n次骰子，一共有多少种方案
            return res;
        }

        int dfs(int n, int sum){
            if(sum < 0) return 0;
            if(n == 0) return !sum;

            for(int i = 1; i <= 6; i++)
            {
                res += dfs(n - 1, sum - i);  // 热狗法：最后一次骰子点数已经确定时，则只需要计算前面投了n-1次骰子，总和是s-i的情况下，一共有多少种方案。
            }
            return res;
        }
    };
    ```
- 动态规划算法dp的思路：
    ```
    #include <iostream>
    #include <vector>

    using namespace std;


    // dp方法来解决：注意三点，第一是状态的表示是什么(从输出中来)？第二是如何计算第一步中的状态？第三是边界问题

    class Solution{
    public:
        vector<int> numberOfDice(int n){
           vector<vector<int>> f(n + 1, vector<int>(n * 6 + 1));  // dp的状态表示
           f[0][0] = 1;  // 当所有的骰子都没有扔出时，总和s=0时，只有一种方案；总和s=1, 2, 3, 4, ....都是不合法的！
           for(int i = 1; i <= n; i++){  // 先循环扔出去的次数
               for(int j = 1; j <= i * 6; j++){      // 再循环总和s是多少
                    for(int k = 1; k <= min(j, 6); k++){  // 枚举最后一次的点数是多少
                        f[i][j] += f[i- 1][j - k];  // 状态f[i][j]表示前i次总和是j的方案数！
                    }
               }
           }

           vector<int> res;
           for(int i = n; i <= n * 6; i++) res.push_back(f[n][i]);
           return res;
        }
    };
    ```
#### 3.扑克牌的顺子(剑指offer原61题)
- 解题思路：模拟人的想法，先将**除去了大小王之外**的牌拿过来，如果有相同元素，则一定不是顺子！如果没有任何两个元素相同，看一下牌中最小值与最大值的差距是否在4以内。如果满足条件，则可以将缺失的部分用大小王来进行填补。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    // 从扑克牌中随机抽5张牌，判断是不是一个顺子。
    class Solution{
    public:
        bool isContinous(vector<int>& nums)
        {
            if(nums.empty()) return false;
            sort(nums.begin(), nums.end());
            int k = 0;
            while(!nums[k]) k++;   // 去掉行首的0
            for(int i = k + 1; i < nums.size(); i++){  // 去掉重复元素
                if(nums[i] == nums[i - 1]) return false;
            }

            return nums.back() - nums[k] <= 4;
        }
    };
    ```
#### 4.圆圈中最后剩下的数字(剑指offer原62题)----约瑟夫环问题
- 解题思路：f(n,m)表示总共n个数字，每次报到数字m时，就将此数字从环中删除,最后剩下的数字。f(n-1,m)表示从剩下的n-1个数字中，每次报到数字m时，就将此数字从环中删除，最后剩下的数字。观察f(n,m)与f(n-1,m)之间的关系，可知f(n,m) = (f(n-1,m) + m) % n,其中边界条件是f(n==1, m) = 0;
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        int lastRemaining(int n, int m){
            if(n == 1) return 0;
            return (lastRemaining(n - 1, m) + m) % n;
        }
    };
    ```
#### 5.股票的最大利润（剑指offer原63题）
- 解题思路：找出前i天的最小值，利用一个变量minValue来存储。第i天卖出的价格是nums[i]，最大利润res是等于第i天卖出价格与前i天中价格最低时买入的价格之差，此时获得的利润是最大的。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        int maxDiff(vector<int>& nums)
        {
            if(nums.empty()) return 0;
            int res = 0;   // 最大利润
            for(int i = 1, minValue = nums[0]; i < nums.size(); i++){
                res = max(res, nums[i] - minValue);  // minValue表示前i天的最小值，nums[i]表示第i天卖出的价格！
                minValue = min(minValue, nums[i]);
            }
            return res;
        }
    };
    ```
#### 6.求1+2+3+...+n，不能使用乘除法和各种循环、判断语句(剑指offer原64题)
- 解题思路：使用递归的思路来写，但是将当中的if语句，改成&&运算符。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        int getSum(int n){
            int res = n;
            n > 0 && (res += getSum(n - 1));   // 实际是对if(n > 0) res += getSum(n - 1);语句的改写
            return res;
        }
    };
    ```
#### 7.不用加减乘除做加法(剑指offer原65题)
- 解题思路：模拟计算机中的加法A + B，结果是CD。其中C是十位，D是个位。A和B对应位上的取值有四种(0 0、0 1、1 0、1 1)，C上的结果是(0 0 0 1),D上的结果是(0 1 1 0)。可以将C上的结果看出(A对应位上的取值 & B对应位上的取值)；将D上的结果看出(A对应位上的取值 ^ B对应位上的取值)。因此，可以将多位数相加A + B可以看出是A + B= A^B(无进位) + (A & B << 1)(A & B表示的就是进位)。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        int add(int num1, int num2){

            while(num2){
                int sum = num1 ^ num2;
                int carry = (num1 & num2) << 1;
                num1 = sum;
                num2 = carry;
            }
            return num1;
        }
    };
    ```
#### 8.构建乘积数组(剑指offer原66题)[不能用除法、只能开一个数组]
- 解题思路：B[i] = A[0] \* A[1] \* ... \* A[i-1] \* A[i+1] \* ... \* A[n-1]。可以先算i的左半边 A[0] \* A[1] \* ... \* A[i-1]，然后算i的右半边A[i+1] \* ... \* A[n-1]，最后两部分相乘。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        vector<int> multiply(const vector<int>& A){
            if(A.empty()) return vector<int>();

            int n = A.size();
            vector<int> B(n);

            // 先算A[0]到A[i-1]的乘积
            for(int i = 0, p = 1; i < n; i++){
                B[i] = p;
                p *= A[i];
            }
            // 再算A[i+1]到A[n-1]的乘积
            for(int i = n - 1, p = 1; ~i; i--){
                B[i] *= p;
                p *= A[i];
            }
            return B;
        }
    };
    ```
#### 9.把字符串转换成整数(剑指offer原67题)
- 解题思路：处理好各种边界问题！
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>

    using namespace std;


    class Solution{
    public:
        int strToInt(string str)
        {
            int k = 0;
            while(k < str.size() && str[k] == ' ') k++;  // 忽略所有的行首空格！
            long long number = 0;
            bool is_minus = false;
            // 忽略完行首的空格后，可能有-/+的符号
            if(str[k] == '+') k++;
            else if(str[k] == '-') k++, is_minus = true;

            while(k < str.size() && str[k] >= '0' && str[k] <= '9'){
                number = number * 10 + str[k] - '0';   // 字符串表示的数字转换成真正的数字
                k++;
            }

            if(is_minus) number *= -1;  // 处理负数的情况
            if(number > INT_MAX) number = INT_MAX;
            if(number < INT_MIN) number = INT_MIN;
            return (int)number;
        }
    };
    ```
#### 10.树中两个结点的最低公共祖先(剑指offer原68题)
- 解题思路：给出的两个结点的位置可能有两种情况，一种是两个结点出现在一个结点的左右两个子树上；另一种是一个给定的结点出现最低公共祖先节点上，另一个给定的结点出现在左子树或右子树上！
具体的方法是：先遍历左子树，检查是否有给定的两个结点p、q；再遍历右子树，检查是否有给定的两个结点p、q。如果左右子树中同时出现了p、q，则当前结点就是需要返回的就是最低公共祖先结点；如果只在左子树或右子树中出现p、q，则返回值就是p、q的最低公共祖先。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>

    using namespace std;


    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
            if(!root) return nullptr;  // 空树

            if(root == p || root == q) return root;

            auto left = lowestCommonAncestor(root->left, p, q);   // 检查一下左边是否有p和q
            auto right = lowestCommonAncestor(root->right, p, q);  // 检查一下右边是否有p和q
            if(left && right) return root;

            if(left) return left;

            return right;
        }
    };
    ```
#### 11.数字在排序数组中出现的次数(剑指offer原53题--题目一）
- 解题思路：**二分法解决！**就是此数字第一次出现的位置与此数字最后一次出现的位置，两者之间的数的个数就是该数字出现的次数！
    ```
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;


    class Solution{
    public:
        int getNumberOfK(vector<int>& nums, int k){
            if(nums.empty()) return 0;
            int l = 0, r = nums.size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(nums[mid] < k) l = mid + 1;
                else r = mid;
            }

            if(nums[l] != k) return 0;

            int left = l;
            l = 0, r = nums.size() - 1;
            while(l < r){
                int mid = l + r + 1 >> 1;
                if(nums[mid] <= k) l = mid;
                else r = mid - 1;
            }
            return r - left + 1;
        }
    };
    ```
#### 12.0到n-1中缺失的数字(剑指offer原53题---题目二)
- 题目要求的是：长度为n的数组,将其中的一个数删掉，只剩下n-1个数了。将剩下的n-1个数作为程序的输入，找出被删除的那个数！
- 解题思路：先计算0到n-1中的n个数的和，再减去当前序列中的每个数，也就可以得到答案了。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>

    using namespace std;



    class Solution{
    public:
        int getMissingNumber(vector<int>& nums){  // nums是输入的n-1个数
            int n = nums.size() + 1;
            int res = (n - 1) * n / 2;
            for(auto x: nums) res -= x;
            return res;   // res就是0到n-1中缺失的那个数字
        }
    };
    ```
#### 13.数组中数值和下标相等的元素(剑指offer原53题---题目三)
- 解题思路：因为给定的数组nums具有单调递增的性质，可以使用二分查找，时间复杂度是O(logn)。考察数组nums[i]-i是否具有单调性。即（nums[i]-i >= nums[i-1] - (i-1)是否成立？）
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>

    using namespace std;


    class Solution{
    public:
        int getNumberSameAsIndex(vector<int>& nums){
            int l = 0, r = nums.size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(nums[mid] - mid >= 0) r = mid;
                else l = mid + 1;
            }
            if(nums[r] - r == 0) return r;  // 相等元素的下标
            return -1;
        }
    };
    ```
#### 14.二叉搜索树的第K个大的结点(剑指offer原54题)
- 解题思路：先对二叉搜索树进行中序遍历，每遍历到一个结点后，就对K进行减一操作。直到k减小到0后，就已经找到了第K个大的结点。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>

    using namespace std;

    // 二叉树的定义
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        TreeNode* ans;

        TreeNode* KthNode(TreeNode* root, int k){
            dfs(root, k);
            return ans;
        }

        void dfs(TreeNode* root, int& k){
            if(!root) return;
            dfs(root->left, k);  // 中序遍历
            k--;
            if(!k) ans = root;
            if(k > 0) dfs(root->right, k);
        }
    };
    ```
#### 15.二叉树的深度(剑指offer原55题)
- 解题思路：深度就是找出从根结点到叶子节点的路径最长长度！具体就是找出根节点的左右子树两者中更长者的深度+1，即二叉树的深度。左右子树的深度用递归的方法来求解，当递归到叶子节点时，递归停止！
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <string>

    using namespace std;

    // 二叉树的定义
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        int treeDepth(TreeNode* root){
            if(!root) return 0;  // 递归终止条件！
            return max(treeDepth(root->left), treeDepth(root->right)) + 1;
        }
    };
    ```
#### 16.平衡二叉树(剑指offer原55题--题目二)
- 解题思路：利用上一题的思路，求出左右子树的深度之差是否是大于1的，如果所有点的深度差都不大于1的话，则是平衡二叉树；如果任意一个结点的左右子树深度之差大于1，则一定是非平衡二叉树!
    ```
    #include <iostream>
    #include <cmath>

    using namespace std;

    // 二叉树的定义
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        bool ans = true;

        bool isBalanced(TreeNode* root){
            dfs(root);
            return ans;
        }

        int dfs(TreeNode* root){
            if(!root) return 0;
            int left = dfs(root->left), right = dfs(root->right);
            if(abs(left - right) > 1) ans = false;
            return max(left, right) + 1;  // 当前结点的深度 == 当前结点左右子树的深度的更大者 + 1
        }
    };
    ```
#### 17.数组中只出现一次的两个数字(剑指offer原56题)
- 原题是：一个数组中除了两个数字之外，其他数字都出现了2次。利用程序找出这两个只出现一次的数字！
- 解题思路：
    - **先考虑一种简单的情况**，数组中除了一个数字只出现一次外，其余数字都出现了2次，找出这个只出现一次的数字。**利用异或运算的特点，所有出现两次的数字异或时都被消成0，再将异或结果与只出现一次的数字进行异或，结果就是我们要找的数字**。
    - 本题中只出现一次的数字有两个，如何找出这两个只出现一次的数呢?***利用上面一样的操作，对所有的数字执行异或操作，得到的结果是两个只出现一次的数字的异或，由于两个数字都只出现一次。因此，最终的异或结果肯定不等于0**。因为两个只出现一次的数字的异或的结果不等于0，所以异或结果的二进制表示中肯定有一位是1。假设异或结果中的第3位是1，则两个只出现一次的数字二进制表示的第3位一定是不相同的。**此时，将原始数组中所有数字划分成两个集合，划分的依据就是看数组中每个数字的第3位是0还是1。因此，两个只出现一次的数字一定不在同一个集合中！所有出现两次的数字一定在同一个集合中！此时，两个集合中的数字就转化成最开始讨论的一种简单情况的例子**。
    ```
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    class Solution{
    public:
        vector<int> findNumsAppearance(vector<int>& nums){
            int sum = 0;
            for(auto x : nums) sum ^= x;   // 先求所有数字的异或和,也就是sum = x ^ y  x,y分别表示数组中只出现一次的数字
            int k = 0;
            while(!(sum >> k & 1)) k++;  // 然后从sum中找出其二进制表示中任意一位不为0的位，k存储的就是x ^ y结果中第k位是1的那一位
            int first = 0;
            for(auto x : nums){
                if(x >> k & 1)   // 将x的二进制表示中第k位是1的划分到第一个集合first中！
                    first ^= x;  // 第一个集合异或的结果first  第二个结果异或的结果first ^ sum
            }
            return vector<int>{first, sum ^ first};
        }
    };
    ```
#### 18.数组中唯一只出现一次的数字(剑指offer原56题--题目2)
- 原题目：一个数组中除了一个数字只出现一次外，其他数字都出现了三次，找出那个只出现一次的数字。
- 解题思路：**有限状态机原理，初始的状态是(ones=0,twos=0);输入的数字的二进制表示中某一位是1时，状态转移成(1,0),接着数字的二进制表示中某一位仍然是1时，状态转移成(0,1),接着数字的二进制表示中某一位继续是1时，状态转移成(0,0)。也就是每三个状态构成一个循环；当输入的数字的二进制表示中某一位是0时，从初始的状态是(ones=0,twos=0)转移至自身(0,0)；当所有的输入数字中某一位出现次数是%3余1时，状态就转移到(1,0)；当所有的输入数字中某一位出现次数是%3余0时，状态就转移到(0,0)状态**。ones就代表了上面两种情况的结果。数组中唯一只出现一次的数字。
    ```
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;


    class Solution{
    public:
        int findNumberAppearingOnce(vector<int>& nums){
            int ones = 0, twos = 0;
            for(auto x : nums){
                ones = (ones ^ x) & ~twos;
                twos = (twos ^ x) & ~ones;
            }
            return ones;
        }
    };
    ```
#### 19.和为s的数字(剑指offer原57题---题目一)
- 解题思路1：暴力解法，先依次遍历每个数字，遍历到某个数字时，固定这个数字。再依次判断数组中其余的n-1个数字与它的和是否等于target。
    ```
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    // 暴力解法O(n**2)
    class Solution{
    public:
        vector<int> findNumberWithSum(vector<int>& nums, int target){
            for(int i = 0; i < nums.size(); i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] + nums[j] == target) return vector<int>{nums[i], nums[j]};
                }
            }
        }
    };
    ```
- 解题思路2：对第二重循环进行优化，第二重循环的目的是判断对于j < i这个范围内，是否存在一个数字nums[j]使得target - nums[i] == nums[j]成立。因此，可以使用哈希表来统计数字nums[j]是否出现从而来优化，使得时间复杂度变成O(n)。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_set>

    using namespace std;


    class Solution{
    public:
        vector<int> findNumberWithSum(vector<int>& nums, int target){
            unordered_set<int> hash;
            for(int i = 0; i < nums.size(); i++){
                if(hash.count(target - nums[i])) return vector<int>{target - nums[i], nums[i]};  // hash.count(target - nums[i])就是判断nums[j]是否在j < i的范围内出现！
                hash.insert(nums[i]);
            }
            return vector<int>();
        }
    };
    ```
#### 20.和为s的连续正数序列(剑指offer原57题---题目二)
- 原题：**输入一个正数s,输出所有和为s的连续正数序列**，序列中至少含有两个数。
- 解题思路：暴力方法是给出区间的起点i,再给出区间的终点j。利用求和公式计算出区间[i,j]中数字的和是否为s，时间复杂度是O(n**2)。改进的方法是：假设区间[i,j]中数字的和是s，当区间左端点i向右移动到i1时，**区间的右端点j也会向右移动到j1，如果右端点j向左移动到j2，则区间[i1,j2]中的数字之和一定是小于s的**。总结起来就是使用双指针算法，时间复杂度变成O(n)。
    ```
    #include <iostream>
    #include <vector>
    #include <string>


    using namespace std;

    // 暴力方法：O(n**2)
    class Solution{
    public:
       vector<vector<int>> findContinuousSequence(int sum){
           vector<vector<int>> res;
           for(int i = 1, j = 1, s = 1; i <= sum; i++)  // s是当前序列的和
           {
               while(s < sum) s += ++j;
               if(s == sum && j - i + 1 > 1){  // [i,j]中包含的元素个数是: j - i + 1
                   vector<int> line;
                   for(int k = i; k <= j; k++) line.push_back(k);  // line是一个一维数组，数组中存放的是区间[i,j]中和为s的数字
                   res.push_back(line);
               }
               s -= i;
           }
           return res;
       }
    };
    ```
#### 21.翻转单词顺序(剑指offer原58题---题目一)
- 原题：输入一个句子，翻转句子中单词的顺序，但每个单词内的字母顺序不变。
- 解题思路：先用双指针i和j，将整个句子的每个单词以字母为单位进行翻转；然后对句子的每个单词进行翻转。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>


    using namespace std;

    class Solution{
    public:
        string reverseWords(string s){
            reverse(s.begin(), s.end());  // 等价于for(int i = 0, j = s.size() - 1; i < j; i++, j--) swap(s[i], s[j]); 第一步首先对整个句子进行翻转
            for(int i = 0; i < s.size(); i++){  // 对第一步中翻转后的每个单词进行翻转，下面是从一段字符串中提取出一个单词的操作！
                int j = i;
                while(j < s.size() && s[j] != ' ') j++;
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
            return s;
        }
    };
    ```
#### 22.左旋转字符串(剑指offer原58题---题目二)
- 原题是：将字符串中的前面的前n位移动到字符串的尾部。
- 解题思路：和上一题一样的思路，先对整个字符串进行翻转。然后将翻转后的结果分成两个部分：前str.size() - n个字符和倒数n个字符，然后分别对上面的两部分进行翻转即可。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>


    using namespace std;

    class Solution{
    public:
        string leftRotateString(string str, int n){
            reverse(str.begin(), str.end());
            reverse(str.begin(), str.begin() + str.size() - n);
            reverse(str.begin() + str.size() - n, str.end());
            return str;
        }
    };
    ```
#### 23.数字序列中某一位的数字(剑指offer原44题)
- 解题思路：
    - 1.确定是几位数（n - 10\*1 - 90\*2 - 900\*3 - ...）
    - 2.确定是几位数的第几个数
    - 3.确定那个数的第几位
- 详细过程：首先要确定第n位对应的数字在什么范围内，也就是确定第n位对应的数字是几位数。因为一位数有10个，占10位，两位数有90个，占180位，三位数有900个，占2700位。假设输入的是第1000位，则第1000位对应的应该是一个三位数（因为1000-10-180 = 720 < 2700）；然后确定第1000位对应的是哪个三位数上的某一位。因为经过上一步的分析可知，输入的第1000位出现在两位数之后的第720位，因为三位数每个数占3位，所以输入的第1000位对应的应该是第240个三位数中的某一位！由于三位数从100开始，所以第240个三位数是100 + 240 - 1 = 339；最后确定对应是339中的哪一位（因为720 / 3 = 240，所以应该对应339的最后一位9）
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>


    using namespace std;

    class Solution{
    public:
        int digitAtIndex(int n){
            long long i = 1, s = 9, base = 1;  // i是几位数  s是几位数的个数  base是几位数的开始第一个数字
            // 确定n对应是几位数
            while(n > i * s){
                n -= i * s;
                i++;
                s *= 10;
                base *= 10;
            }
            // 确定是几位数中的哪个数
            int number = base + (n + i - 1) / i - 1;
            // 确定那个数的第几位
            int r = n % i ? n % i : i;
            for(int j = 0; j < i - r; j++) number /= 10;
            return number % 10;
        }
    };
    ```
#### 24.把数组排成最小的数(剑指offer原45题)
- 解题思路：首先在数组中定义两个数字之间的小于<关系：即a < b等价于ab < ba。然后将原始的输入数组按照定义的小于关系重新排序，一次拼接派好序后的数组中的数字即可。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>


    using namespace std;

    class Solution{
    public:
        static bool cmp(int a, int b){
            auto as = to_string(a), bs = to_string(b);
            return as + bs < bs + as;
        }

        string printMinNumber(vector<int>& nums){
            sort(nums.begin(), nums.end(), cmp);
            string res;
            for(auto x : nums) res += to_string(x);
            return res;
        }
    };
    ```
#### 25.把数字翻译成字符串(剑指offer原46题)
- 解题思路：**大部分计数的问题，可以看成是动态规划的问题**。问题的关键是**a.状态表示 b.状态如何计算 c.边界怎么定义**。f(i)表示前i位数字一共有多少种翻译方式，f(i)
如何计算？如果将第i位数字单独翻译成一个字母，则f(i)可表示为前i-1位数字一共有多少种翻译方式；如果将第i位和第i-1位数字翻译成两个个字母，则f(i)可表示为前i-2为数字一共有多少种翻译方式。综合上述两种情况,f(i) = f(i-1) + f(i-2)。**注意第二种情况：f(i-2)是将第i和第i-1位数字联合起来翻译成字母，因此必须有约束,范围是[10,25]之间**。最后，考虑边界f(0) = 1。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>


    using namespace std;

    class Solution{
    public:
        int getTranslationCount(string s){
            int n = s.size();
            vector<int> f(n+1);
            f[0] = 1;
            for(int i = 1; i <= n; i++){
                f[i] = f[i - 1];   // 第一种情况
                int t = (s[i-2] - '0') * 10 + s[i-1] - '0';  // 第二种情况
                if(t >= 10 && t <= 25) f[i] += f[i-2];
            }
            return f[n];
        }
    };
    ```
#### 26.礼物的最大价值(剑指offer原47题)
- 解题思路：**经典的边界问题，还是要考虑三个问题，状态怎么表示；状态的计算问题；怎么定义边界**。f[i,j]表示从左上角出发，到达当格子获得的最大价值。状态计算[i, j] = max(f[i-1, j],f[i, j-1]) + gifts[i,j]；边界f[i,0] = f[0, j] = 0。所要求的答案是f[n,m]。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>


    using namespace std;

    class Solution{
    public:
        int getMaxValue(vector<vector<int>>& grid){
            int n = grid.size(), m = grid[0].size();
            vector<vector<int>> f(n + 1, vector<int>(m + 1));
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    f[i][j] = max(f[i -1][j], f[i][j-1]) + grid[i-1][j-1];
                }
            }
            return grid[n][m];
        }
    };
    ```
#### 27.最长不含重复字符的子字符串(剑指offer原48题)
- 解题思路：双指针i、j算法，当j指针每向后移动一位时，判断i到j中是否有重复字符，如果出现了重复字符，就将i指向的重复字符删除，同时i指针向后移动一次。当j移动到字符串末尾时，j-i+1的距离就是不含重复字符的子字符串。
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_map>


    using namespace std;

    class Solution{
    public:
        int lengthLongestSubString(string s){
            unordered_map<char, int> hash;
            int res = 0;
            for(int i = 0, j = 0; j < s.size(); j++){
                hash[s[j]]++;
                while(hash[s[j]] > 1) hash[s[i++]]--;
                res = max(res, j - i + 1);
            }
            return res;
        }
    };
    ```
#### 28.丑数(剑指offer原49题)------求第n个丑数的值
- 解题思路：丑数：一个数的质因子中只包含2 3 5的数！首先将1加入丑数集合中去，然后分别用三个i,j,k指针指向1.。其中i表示2，j表示3，k表示5；然后用1分别与i、j、k三个指针相乘，取相乘后所有结果中的最小值放在1的下一个位置。同时，将指针向后移动一个位置。**当有多个相等的最小值出现时，需要将多个指针分别向后移动一个位置**。依次循环下去，就可以找到整个丑数组成的集合了。（实际上是3路归并排序，将包含因子2的排好序丑数放入一个数组、包含因子3的排好序丑数放入一个数组、包含因子5的排好序丑数放入一个数组；**前面的三个数组中，是不包含因子1**。然后将三个数组分别除以数字2 数字3 数字5得到的结果仍然是一个丑数序列，将得到的3个丑数序列合并后进行判重处理，就得到了最终结果）
    ```
    #include <iostream>
    #include <vector>


    using namespace std;

    class Solution{
    public:
        int getUglyNumber(int n){
            vector<int> q(1, 1);
            int i = 0, j = 0, k = 0;
            while(--n){  // 循环n-1次    while(n--){}是循环n次
                int t = min(q[i] * 2, min(q[j] * 3, q[k] * 5));
                q.push_back(t);
                if(q[i] * 2 == t) i++;
                if(q[j] * 3 == t) j++;
                if(q[k] * 5 == t) k++;
            }
            return q.back();
        }
    };
    ```
#### 29.字符串中第一个只出现一次的字符(剑指offer原50题---题目一)
- 解题思路：先定义一个hash表，统计每个字符出现多少次，然后从前往后遍历hash表，扫描到第一个值是1对应的key，也就是最终的结果
    ```
    #include <iostream>
    #include <vector>
    #include <string>
    #include <unordered_map>


    using namespace std;

    class Solution{
    public:
        char firstNotRepeatingChar(string s){
            unordered_map<char, int> hash;
            for(auto c : s) hash[c]++;  // 统计字符串s中每个字符出现的次数
            char res = '#';  // 无解的情况
            for(auto c : s)
                if(hash[c] == 1){
                    res = c;
                    break;
                }
            return res;
        }
    };
    ```
#### 30.字符流中第一个只出现一次的字符(剑指offer原50题---题目二)
- 解题思路：每次输入字符时，将输入的字符流中出现次数大于1的字符删除。使用队列的数据结构来存储插入的字符！
    ```
    #include <iostream>
    #include <unordered_map>
    #include <queue>


    using namespace std;

    class Solution{
    public:
        unordered_map<char, int> hash;
        queue<char> q;

        // 插入字符到一个队列queue中
        // 利用hash表判断当前正在插入的字符是否出现在当前的队列中
        void insert(char ch){
            if(++hash[ch] > 1){  // 插入的字符已经出现在队列中
                while(q.size() && hash[q.front()] > 1) q.pop();
            }
            else q.push(ch); // 插入的字符没有出现在队列中
        }

        char firstAppearingOnce(){
            if(q.empty()) return '#';
            return q.front();
        }
    };
    ```
#### 31.数组中的逆序对(剑指offer原51题）
- 解题思路：暴力做法的时间复杂度是O(n**2)，考虑能否使用归并排序的方法来优化算法为O(nlogn)。首先分别对统计同时在左右两个子序列中一共有多少个逆序对（递归方法）；然后计算逆序对不在同一个子序列时，对第二个序列中的每一个数a[j]，计算第一个序列中一共有多少个数a[i]比a[j]要大。因此一共有r-i+1个数比a[j]]要大！最后的结果是上面三个部分的和。
    ```
    #include <iostream>
    #include <vector>
    #include <string>



    using namespace std;

    class Solution{
    public:
        int merge(vector<int>& nums, int l, int r){
            if(l >= r) return 0;
            int mid = l + r >> 1;
            int res = merge(nums, l, mid) + merge(nums, mid + 1, r);  // 第一和第二部分
            // 第三个部分
            int i = l, j = mid + 1;
            vector<int> temp;
            while(i <= mid && j <= r){
                if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
                else{
                    temp.push_back(nums[j++]);
                    res += mid - i + 1;
                }
                while(i <= mid) temp.push_back(nums[i++]);
                while(j <= r) temp.push_back(nums[j++]);
                i = l;
                for(auto x : temp) nums[i++] = x;
                return res;
            }
        }

        int inversePairs(vector<int>& nums){
            int res = 0;
            return merge(nums, 0, nums.size() - 1);
        }
    };
    ```
#### 32.两个链表的第一个公共结点(剑指offer原52题）
- 思路：使用两个指针p和q，p指针指向第一个链表的头结点，q指针指向第二个链表的头结点。当p指针遍历到第一个链表的末尾时，接着回到第二链表的头结点位置；当q指针遍历到第二个链表的末尾时，接着回到第一链表的头结点位置。**注意两个指针所走的总距离是相等的**！当进行了多次循环后，两个指针一定会在某个结点处相遇，即公共结点。
    ```
    #include <iostream>

    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };


    using namespace std;

    class Solution{
    public:
        ListNode* findFirstCommonNode(ListNode* headA, ListNode* headB){
            auto p = headA, q = headB;
            while(p != q){
                if(p) p = p->next;
                else p = headB;

                if(q) q = q->next;
                else q = headA;
            }
            return p;
        }
    };
    ```
#### 33.二叉搜索树的后序遍历序列(剑指offer原33题)
- 题目：给定一个数组，判断此数组是否是某二叉搜索树的后序遍历结果！
- 解题思路：先找出数组中的最后一个元素作为树根root，然后找到二叉搜索树的左子树的最后一个位置（左子树中的结点值均小于root，右子树的结点值均大于root）。接着找到二叉搜索树的右子树的最后一个位置。判断结点的值是否满足二叉搜索树的定义！
    ```
    #include <iostream>
    #include <vector>


    using namespace std;


    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        vector<int> seq;
        bool verifySequenceOFBST(vector<int> sequence){
            seq = sequence;
            return dfs(0, seq.size() - 1);
        }

        bool dfs(int l, int r){
            if(l >= r) return true;
            int root = seq[r];
            int k = l;
            while(k < r && seq[k] < root) k++;  // 二叉搜索树的左子树
            for(int i = k; i < r; i++){  // 判断二叉搜索树的右子树是否合法
                if(seq[i] < root) return false;
            }
            return dfs(l, k-1) && dfs(k+1, r);
        }
    };
    ```
#### 34.二叉树中和为某一值的路径(剑指offer原34题)
- 解题思路：直接遍历一遍二叉树，当遍历到叶节点时，判断从根节点到当前节点的路径上的节点值之和是否等于给定值。如果等于的话，就记录当前的路径。
    ```
    #include <iostream>
    #include <vector>


    using namespace std;


    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        vector<vector<int>> ans;
        vector<int> path;

        vector<vector<int>> findPath(TreeNode* root, int sum){
            dfs(root, sum);
            return ans;
        }

        void dfs(TreeNode* root, int sum){
            if(!root) return;  // 当前节点是空的，就不是叶子节点
            path.push_back(root->val);
            sum -= root->val;
            // 如果当前节点的左右子树都是空的，则当前节点是叶子节点
            if(!root->left && !root->right && !sum) ans.push_back(path);
            // 递归处理左右子树
            dfs(root->left, sum);
            dfs(root->right, sum);
            path.pop_back();
        }
    };
    ```
#### 35.复杂链表的复制(剑指offer原35题)
- 解题思路：第一步将每个节点复制出来，然后将当前节点的next指针指向复制出来的节点；第二步将原先节点p的random指针指向第3个节点；那么，被复制出来的p节点是p->next，其random指针即p->next->random指向p->random->next节点。最后将复制出来的节点全部连接起来！
    ```
    #include <iostream>
    #include <vector>


    using namespace std;


    struct ListNode{
        int val;
        ListNode* next, *random;
        ListNode(int x): val(x), next(nullptr), random(nullptr){}
    };

    class Solution{
    public:
        ListNode* copyRandomList(ListNode* head){
            // 第一步复制所有的节点，并将当前节点指向复制出来的节点
            for(auto p = head; p;)
            {
                auto np = new ListNode(p->val);  // 复制出来的新节点
                auto next = p->next;   // 备份一下p->next;
                p->next = np;   // 复制出来的点接在当前节点的后面
                np->next = next;
                p = next;
            }
            // 第二步复制random指针
            for(auto p = head; p; p = p->next->next){
                if(p->random)
                    p->next->random = p->random->next;
            }
            // 第三步将所有复制出来的节点连接起来
            auto dummy = new ListNode(-1);
            auto cur = dummy;   // 当前新链表的尾节点
            for(auto p = head; p; p = p->next){
                cur->next = p->next;
                cur = cur->next;
                p = p->next;
            }
            return dummy->next;

        }
    };
    ```
#### 36.二叉搜索树与双向链表(剑指offer原36题)
- 解题思路：首先获取根节点；然后分别递归左右子树，左右子树分别返回一个首尾节点(即当前子树中最左边的节点和当前子树中最右边的节点)；接着将三部分拼接起来；最后将左子树的最左侧和右子树的最右侧节点返回就是最后的答案。
    ```
    #include <iostream>
    #include <vector>


    using namespace std;


    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        TreeNode* convert(TreeNode* root){
            if(!root) return nullptr;

            auto sides = dfs(root);
            return sides.first;
        }

        pair<TreeNode*, TreeNode*> dfs(TreeNode* root){
            if(!root->left && !root->right) return {root, root};  // 当前节点是叶子节点

            if(root->left && root->right){
                auto lsides = dfs(root->left), rsides = dfs(root->right);
                lsides.second->right = root, root->left = lsides.second;
                root->right = rsides.first, rsides.first->left = root;
                return {lsides.first, rsides.second};
            }
            if(root->left){
                auto lsides = dfs(root->left);
                lsides.second->right = root, root->left = lsides.second;
                return {lsides.first, root};
            }
            if(root->right){
                auto rsides = dfs(root->right);
                root->right = rsides.first, rsides.first->left = root;
                return {root, rsides.second};
            }
        }
    };
    ```
#### 37.序列化二叉树(剑指offer原37题)
- 题目：确保二叉树可以序列化为字符串；并且可以将此字符串反序列化为原始树结构。
- 解题思路：利用二叉树的前序遍历实现从二叉树到字符串的序列化操作；反序列化实现的是从字符串到二叉树的转换，注意将字符串类型的数字转成整数的方法！
    ```
    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;


    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };

    class Solution{
    public:
        // 序列化
        string serialize(TreeNode* root){
            string res;
            dfs_s(root, res);
            return res;
        }

        // 前序遍历实现序列化
        void dfs_s(TreeNode* root, string& res){
            if(!root){
                res += "null ";
                return;
            }
            res += to_string(root->val) + ' ';
            dfs_s(root->left, res);
            dfs_s(root->right, res);
        }

        // 反序列化
        TreeNode* deserialize(string data){
            int u = 0;
            return dfs_d(data, u);
        }

        TreeNode* dfs_d(string data, int& u){
            if(u == data.size()) return nullptr;
            int k = u;
            while(data[k] != ' ') k++;
            if(data[u] == 'n'){ // 'n'是null的开始字符
                u = k + 1;
                return nullptr;
            }
            int val = 0;
            for(int i = u; i < k; i++) val = val * 10 + data[i] - '0';  // 将字符串整数"123"转换成整数123
            u = k + 1;
            auto root = new TreeNode(val);
            root->left = dfs_d(data, u);
            root->right = dfs_d(data, u);
            return root;
        }

    };
    ```
#### 38.数字排列---（与剑指offer38题不同）
- 题目：输入一组数字(可能包含重复数字)，输出其所有的全排列
- 解题思路：先对输入的数字进行排序，然后开辟与输入一组数字相同长度的数组，接着从输入数字中按顺序取一个数字放在数组的任意一个位置上。**接下来，取第二个数字放在数组中剩下空间的任意一个位置上，如果第二个数字与第一个数字值是相同的，则规定第二个数字只能放在第一个数字的后面的位置**，依次将输入的数字放入数组中，直到数组的各位都已经占满为止。
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        vector<vector<int>> ans;
        vector<int> path;

        vector<vector<int>> permutation(vector<int>& nums){
            path.resize(nums.size());   // 开辟的数组空间大小
            sort(nums.begin(), nums.end());
            dfs(nums, 0, 0, 0);   // 用一个二进制位来表示哪些位置是空的
            return ans;
        }

        void dfs(vector<int>& nums, int u, int start, int state){
            // u:当前枚举的位置   start: 当前这个数应该从哪个位置开始枚举？（即上一个数的后一个位置开始枚举）
            // state: 存储的是状态，表示哪些数被用过
            if(u == nums.size()){
                ans.push_back(path);
                return;
            }

            if(!u || nums[u] != nums[u-1]) start = 0;

            for(int i = start; i < nums.size(); i++){
                if(!(state >> i & 1)){   // state >> i & 1：看一下state的二进制表示中第i位是否表示为1
                    path[i] = nums[u];
                    dfs(nums, u + 1, i + 1, state + (1 << i));
                }
            }

        }
    };
    ```
#### 39.数组中出现次数超过一半的数字（寻找数组中的众数）(剑指offer原39题)
- 解题思路：初始化一个计数变量count = 0，然后遍历数组中的每个元素，当val等于第一个元素时，count加1。接着遍历第二个元素，如果第二个元素的值与第一个元素的值相同时，则count加1；如果第二个元素的值与第一个元素的值不同时，count减1；最后遍历完整个数组后，最终结果存储在val变量中。**摩尔投票法原理**
    ```
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    class Solution{
    public:
        int moreThanHalfNum(vector<int>& nums){
            int cnt = 0, val = -1;
            for(auto x : nums)
            {
                if(!cnt) val = x, cnt = 1;
                else
                {
                    if(x == val) cnt++;
                    else cnt--;
                }
            }
            return val;
        }
    };
    ```
#### 40.最小的k个数(剑指offer原40题)
- 解题思路：维护一个大顶堆，当最小的k个数存放在大顶堆中。遍历输入数组中的每个元素，然后将每个元素与大顶堆中的堆顶元素进行比较，如果比堆顶元素小，就更新堆顶元素。
    ```
    #include <iostream>
    #include <vector>
    #include <queue>
    #include <algorithm>

    using namespace std;

    class Solution{
    public:
        vector<int> getLeastNumbers(vector<int> input, int k){
            priority_queue<int> heap;
            for(auto x : input)
            {
                heap.push(x);
                if(heap.size() > k) heap.pop();
            }
            vector<int> res;
            while(heap.size()) res.push_back(heap.top()), heap.pop();  // heap存放的是从大到小的顺序
            reverse(res.rbegin(), res.rend());  // 翻转一下变成从小到大
            return res;
        }
    };
    ```
#### 41.数据流中的中位数(剑指offer原41题)
- 题目：如果从数据流中读出奇数个数值，则中位数就是所有数值排序后位于中间的数值；如果从数据流中读出偶数个数值，则中位数就是所有数值排序之后中间两个数的平均值。
- 解题思路：将当前所有的数维护成两个集合，第一个集合是一个小顶堆，存的是比较大的那一部分数；第二个集合是一个大顶堆，存的是比较小的那一部分数。**可以发现，大顶堆的堆顶元素和小顶堆的堆顶元素实际就是输入数据流中间的两个数**。规定，数据流中读出的是奇数个数值时，大顶堆比小顶堆中的元素多一个。如何维护这个结构？**每次插入一个新的元素到大顶堆中，如果下面大顶堆的堆顶元素比上面小顶堆的堆顶元素的大（即逆序了），则交换；如果下面大顶堆中的元素太多了，就要直接转移当中的一个元素到小顶堆中**。
    ```
    #include <iostream>
    #include <vector>
    #include <queue>

    using namespace std;


    class Solution{
    public:
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        void insert(int num){

            max_heap.push(num);

            if(min_heap.size() && max_heap.top() > min_heap.top())
            {
                auto maxv = max_heap.top(), minv = min_heap.top();
                max_heap.pop(), min_heap.pop();
                max_heap.push(minv), min_heap.push(maxv);
            }

            if(max_heap.size() > min_heap.size() + 1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }

        double getMedian(){
            if(max_heap.size() + min_heap.size() & 1) return max_heap.top();   // 数据流中是奇数个数值
            return (max_heap.top() + min_heap.top()) / 2.0;    // 数据流中是偶数个数值
        }
    };
    ```
#### 42.连续子数组的最大和(剑指offer原42题)
- 解题思路：s表示遍历到当前数x前一个位置为结尾的子数组的和最大值，s如何更新？当s > 0时，s = s + x；当s <= 0时，s = x；
    ```
    #include <iostream>
    #include <vector>


    using namespace std;


    class Solution{
    public:
        int maxSubArray(vector<int>& nums){
            int res = INT_MIN, s = 0;
            for(auto x : nums)
            {
                if(s < 0) s = 0;
                s += x;
                res = max(res, s);
            }
            return res;
        }
    };
    ```
#### 43.从1到n整数中1出现的次数(剑指offer原43题)
- 解题思路：假设输入13015，则万位上的1个数：10000-13015共3016个；千位上的1个数：1000-1999,11000-11999，一共有2000个；百位上的1个数：情况有很多种！十位上的1个数：情况有很多种！总结出的一般规律：输入的数字是abcedf，第一种情况：假设c位置上的数字是1，则ab位置上的取值范围是00到ab-1；def位置上的取值范围是000到999，则总方案数是ab\*1000。第二种情况：最高位恰好取到ab时，分两种情况讨论。1.c位等于0时，就只有0个1；2.c位等于1时，则def的取值范围是0到def，一共有def+1种方案；3.c大于1时，def位置上的取值范围是000到999，则总方案数是1000！
    ```
    #include <iostream>
    #include <vector>


    using namespace std;


    class Solution{
    public:
        int numberOfBetween1AndN(int n){
            if(!n) return 0;
            vector<int> number;
            // 取出n中的每位数字放入number中
            while(n)
            {
                number.push_back(n % 10);
                n /= 10;
            }

            int res = 0;
            for(int i = number.size() -  1; i >= 0; i--)
            {
                auto left = 0, right = 0, t = 1;

                for(int j = number.size() - 1; j > i; j--)
                {
                    left = left * 10 + number[j];
                }

                for(int j = i - 1; j >= 0; j--)
                {
                    right = right * 10 + number[j];
                    t *= 10;  // t表示右边一共有多少位数
                }

                res += left * t;
                if(number[i] == 1) res += right + 1;
                else if(number[i] > 1) res += t;
            }
            return res;
        }
    };
    ```
#### 44.反转链表(剑指offer原24题)
- 解题思路：因为反转的是一个单向链表，所以无法直接遍历当前节点的前驱结点，因此利用一个变量pre记录当前节点的前驱结点。然后从头开始遍历给定的单向链表，直到遍历到空结点为止。
    ```
    #include <iostream>
    #include <vector>


    using namespace std;

    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };


    class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            ListNode* pre = nullptr;   // 记录当前结点的前驱结点
            auto cur = head;
            while(cur)
            {
                auto next = cur->next;    // 用next变量缓存cur->next，用来使得cur向后移动一位
                cur->next = pre;                   // 每次遍历时，将当前结点的next指针指向其前驱结点
                pre = cur;        // 将pre指针向后移动一位，此时pre指向cur
                cur = next;
            }
            return pre;                 // pre就是反转后链表的头结点
        }
    };
    ```
#### 45.合并两个排序的链表(剑指offer原25题)
- 解题思路：**归并排序的方法来实现即可！**
    ```
    #include <iostream>
    #include <vector>


    using namespace std;

    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };


    class Solution{
    public:
        ListNode* merge(ListNode* l1, ListNode* l2){
            auto dummy = new ListNode(-1);
            auto cur = dummy;   // 因为往合并后的链表中添加元素时，是尾部插入的。因此，需要一个cur指针来记录当前链表的尾结点在哪。
            while(l1 && l2)
            {
                if(l1->val < l2->val){
                    cur->next = l1;
                    cur = l1;
                    l1 = l1->next;
                }
                else{
                    cur->next = l2;
                    cur = l2;
                    l2 = l2->next;
                }
            }
            // 将两个链表中更长者中剩余的部分链接到已合并链表的末尾
            if(l1) cur->next = l1;
            else cur->next = l2;
            return dummy->next;
        }
    };
    ```
#### 46.树的子结构---树的匹配(剑指offer原26题)
- 解题思路：类比字符串匹配的方法，从根结点root开始枚举，看一下树根root是否是子树的根节点；不是的话，判断树的左孩子结点是否是子树的树根结点；不是的话，判断树的右孩子结点是否是子树的树根结点。然后利用前序遍历树和子树即可。
    ```
    #include <iostream>
    #include <vector>


    using namespace std;

    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };


    class Solution{
    public:
        bool hasSubTree(TreeNode* pRoot1, TreeNode* pRoot2){
            if(!pRoot1 || !pRoot2) return false;
            // 前序遍历树pRoot1，然后与pRoot2结点进行对比
            if(isPart(pRoot1, pRoot2)) return true;
            return hasSubTree(pRoot1->left, pRoot2) || hasSubTree(pRoot1->right, pRoot2);
        }

        bool isPart(TreeNode* p1, TreeNode* p2){
            if(!p2) return true;
            if(!p1 || p1->val != p2->val) return false;
            return isPart(p1->left, p2->left) && isPart(p1->right, p2->right);
        }
    };
    ```
#### 47.二叉树的镜像(剑指offer原27题)
- 解题思路：所有结点的左右孩子结点都交换了一下，遍历树中的所有结点，每次遍历完后，将每个结点的左右孩子结点交换一下就可以了。
    ```
    #include <iostream>
    #include <vector>


    using namespace std;

    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };


    class Solution{
    public:
        void mirror(TreeNode* root){
            if(!root) return;
            mirror(root->left);
            mirror(root->right);
            swap(root->left, root->right);
        }
    };
    ```
#### 48.对称的二叉树(剑指offer原28题)
- 解题思路：除了根节点之外，其他的每个结点它的左边的结点和右边的结点是对应的！并且左边结点的左孩子和右边结点的右孩子是对称的，左边结点的右孩子和右边结点的左孩子是对称的！
    ```
    #include <iostream>
    #include <vector>


    using namespace std;

    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };


    class Solution{
    public:
        bool isSymmetric(TreeNode* root){
            if(!root) return true;
            return dfs(root->left, root->right);
        }

        bool dfs(TreeNode* p, TreeNode* q){
            if(!p || !q) return !p && !q;
            if(p->val != q->val) return false;
            return dfs(p->left, q->right) && dfs(p->right, q->left);
        }
    };
    ```
#### 49.顺时针打印矩阵(剑指offer原29题)
- 解题思路：顺时针定义四个方向：右 下 左 上；先按右的方向走，走到不能走为止；然后向下移动一个位置，按下的方向走，走到不能走为止；再向左移动一个位置，按左的方向走，走到不能走为止；最后向上移动一个位置，按上的方向走，走到不能走为止！直到总完n*m步就完成了！不能走的定义是：**要么走出了边界，要么你已经走过了这个格子了**。
    ```
    #include <iostream>
    #include <vector>

    using namespace std;

    class Solution{
    public:
        vector<int> printMatrix(vector<vector<int>> matrix){
            vector<int> res;
            int n = matrix.size(), m = matrix[0].size();
            if(!n) return res;

            vector<vector<bool>> st(n, vector<bool>(m, false));   // 二维数组记录每个格子是否被访问过
            int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};   // 上 右 下 左
            int x = 0, y = 0, d = 1;  // 起始方向是向右移动，故d = 1
            for(int i = 0; i < n * m; i++)
            {
                res.push_back(matrix[x][y]);
                st[x][y] = true;   // 当前点被标记成已经访问
                int a = x + dx[d], b = y + dy[d];  // 下一个点的坐标
                if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]){  // 当前点已经出界或者被访问过
                    d = (d + 1) % 4;   // d向下移动
                    a = x + dx[d], b = y + dy[d];
                }
            }
            return res;
        }
    };
    ```
#### 50.包含min函数的栈(剑指offer原30题)
- 题目：设计一个支持push pop top等操作并可以在O(1)的时间复杂度内检索出最小元素的堆栈。
- 解题思路：利用一个辅助栈(**单调栈**)来操作。单调栈：即栈中的元素是单调的！维护一个单调栈，单调栈中的元素大小是单独变化的，当插入一个新的元素到主栈中时，将其与单调栈中的栈顶元素进行比较，当插入的元素比单调栈中的栈顶元素大，则不会将新的元素插入到主栈中；**当插入的元素比单调栈中的栈顶元素小或者与单调栈中的栈顶元素相等时，则将新的元素插入到主栈中去**。
    ```
    #include <iostream>
    #include <vector>
    #include <stack>


    using namespace std;


    class MinStack{
    public:
        stack<int> stk, min_stk;   // stk是主栈  min_stk是单调栈

        MinStack(){

        }

        void push(int x){
            stk.push(x);
            if(min_stk.empty() || min_stk.top() >= x) min_stk.push(x);
        }

        void pop(){
            if(stk.top() == min_stk.top()) min_stk.pop();
            stk.pop();
        }

        int top(){
            return stk.top();
        }

        int getMin(){
            return min_stk.top();
        }
    };
    ```
#### 51.栈的压入与弹出序列(剑指offer原31题)
- 解题思路：模拟一遍整个过程，每次往栈里面加一个元素，加完后判断当前栈顶元素是否是当前弹出序列的元素。如果是，则将栈顶元素弹出。当栈里面已经是空时，弹出序列就是合法的，否则就是不合法的!
    ```
    #include <iostream>
    #include <vector>
    #include <stack>


    using namespace std;


    class Solution{
    public:
        bool isPopOrder(vector<int> pushV, vector<int> popV){
            if(popV.size() != pushV.size()) return false;

            stack<int> s;
            int index = 0;
            for(int i = 0; i < pushV.size(); i++){
                s.push(pushV[i]);
                while(!s.empty() && s.top() == popV[index]){
                    s.pop();
                    index++;
                }
            }

            if(s.empty()) return true;
            return false;
        }
    };
    ```
#### 52.不分行从上往下打印二叉树\[层序遍历\](剑指offer原32题---题目一)
- 解题思路：宽度优先搜索BFS，利用队列这个数据结构来实现
    ```
    #include <iostream>
    #include <vector>
    #include <queue>


    using namespace std;


    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };


    class Solution{
    public:
        vector<int> printFromTopToBottom(TreeNode* root){
            vector<int> res;
            if(!root) return res;

            queue<TreeNode*> q;
            q.push(root);
            while(q.size())
            {
                auto t = q.front();
                q.pop();
                res.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            return res;
        }
    };
    ```
#### 53.分行从上往下打印二叉树(剑指offer原32题---题目二)
- 解题思路：在队列中增加一个null标记，表示当前层的结点已经全部遍历结束。
    ```
    #include <iostream>
    #include <vector>
    #include <queue>


    using namespace std;


    struct TreeNode{
        int val;
        TreeNode *left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };


    class Solution{
    public:
        vector<vector<int>> printFromTopToBottom(TreeNode* root){
            vector<vector<int>> res;
            if(!root) return res;

            queue<TreeNode*> q;
            q.push(root);
            q.push(nullptr);

            vector<int> level;   // 辅助的数组表示每层中有多少个结点
            while(q.size()){
                auto t = q.front();  // 队首元素
                q.pop();
                if(!t)  // t为空时，表示已经遍历完一层
                {
                    if(level.empty()) break;  // level数组为空时，表示已经遍历完所有的结点，就直接返回
                    res.push_back(level);
                    level.clear();
                    q.push(nullptr);
                    continue;
                }
                level.push_back(t->val);  // t不为空时，将当前的点加入到level中，进行扩展
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            return res;
        }
    };
    ```
#### 54.之字形打印二叉树(剑指offer原32题---题目三)
- 解题思路：在上一题的基础上增加一个布尔类型的变量zigzag，当zigzag为true时，表示从右到左打印；zigzag为false时，表示从左到右打印！
    ```
    class Solution{
    public:
        vector<vector<int>> printFromTopToBottom(TreeNode* root){
            vector<vector<int>> res;
            if(!root) return res;

            queue<TreeNode*> q;
            q.push(root);
            q.push(nullptr);

            vector<int> level;   // 辅助的数组表示每层中有多少个结点
            bool zigzag = false;   // 表示从左到右打印
            while(q.size()){
                auto t = q.front();  // 队首元素
                q.pop();
                if(!t)  // t为空时，表示已经遍历完一层
                {
                    if(level.empty()) break;  // level数组为空时，表示已经遍历完所有的结点，就直接返回
                    if(zigzag) reverse(level.begin(), level.end());
                    res.push_back(level);
                    level.clear();
                    q.push(nullptr);
                    zigzag = !zigzag;
                    continue;
                }
                level.push_back(t->val);  // t不为空时，将当前的点加入到level中，进行扩展
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            return res;
        }
    };
    ```
#### 55.机器人的运动范围(剑指offer原13题)
- 解题思路：一般考虑使用宽度优先遍历BFS，不建议使用深度优先遍历DFS。因为深度优先遍历在数据范围比较大时，可能会出现栈溢出！从(0,0)点开始遍历，每次将**符合要求**的格子加入到队列中去。最后一共遍历完多少个合法的格子，就是我们最终的结果。
    ```
    class Solution
    {
    public:
        // 算出一个数字的各个位置上的数字之和
        int get_single_sum(int x){
            int s = 0;
            while(x)
            {
                s += x % 10;
                x /= 10;
            }
            return s;
        }
        // 算出一个格子中的各个位置上数字之和
        int get_sum(pair<int, int> p){
            return get_single_sum(p.first) + get_single_sum(p.second);    // p.first是x坐标   p.second是y坐标
        }

        int movingcount(int threshold, int rows, int cols){
            int res = 0;
            if(!rows || !cols) return 0;
            vector<vector<bool>> st(rows, vector<bool> (cols, false));   // 全部初始化成false，记录每个格子是否已经被访问
            queue<pair<int, int>> q;

            q.push({0, 0});  // 初始坐标初始化

            int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};    // 顺时针来记忆 上 右 下 左

            while(q.size()){
                auto t = q.front();
                q.pop();

                if(get_sum(t) > threshold || st[t.first][t.second]) continue;
                res++;
                st[t.first][t.second] = true;

                for(int i = 0; i < 4; i++)
                {
                    int x = t.first + dx[i], y = t.second + dy[i];
                    if(x >= 0 && x < rows && y >= 0 && y < cols){
                        q.push({x, y});
                    }
                }
            }
            return res;
        }
    };
    ```
#### 56.剪绳子(剑指offer原14题)
- 题目：给定一个正整数，将此整数划分成若干个更小的正整数的和
**使得划分出来的若干个正整数的乘积最大**
- 解题思路：目标：假设输入的正整数是N，拆分成尽可能多的3！。分下面几种情况：1.如果N % 3 == 0，则拆分成若干个3；2.如果N % 3 == 1，则先将N拆分成两个2，剩下的全部拆分成3；3.如果N % 3 == 2，则先将N拆分成一个2，剩下的全部拆分成3；
- 证明上面的三种情况：N > 0，N = n1 + n2 + n3 + ...+ nk 1.假设ni >= 5，3 \* (ni - 3) >= ni(即3\*ni-9 >= ni得到2ni >= 9)是否成立？2.ni = 4， 4 = 2 \* 2。**由前面的1和2得到拆分出来的数字一定不包含4和大于等于5的数字**；因此可知所有拆分出来的ni不是2就是3。接下来证明拆分出来的数字中，最多只有两个2（因为2\*2\*2 < 3\*3）。
    ```
    class Solution
    {
    public:
        int maxProductAfterCutting(int n){
            if(n <= 3) return 1 * (n-1);

            int res = 1;
            if(n % 3 == 1) res *= 4, n -= 4;  // 拆成出来两个2
            if(n % 3 == 2) res *= 2, n -= 2;  // 拆出来一个2
            while(n) res *= 3, n -= 3;    // 拆出来全部都是3
            return res;
        }
    };
    ```
#### 57.二进制中1的个数(剑指offer原15题)
- 解题思路：s += n & 1是先统计n中个位上是数字1的个数，n>>1则是统计完n中个位的结果后，移除n的个位上的数字来进行更新。
    ```
    class Solution
    {
    public:
        int numberOf1(int _n){
            unsigned int n = _n;  // 将有符号数转换成无符号数，为了下面的循环
            int s = 0;
            while(n)
            {
                s += n & 1;  // 每次将n的个位取出来，判断是否是1，是1的话就s++
                n >> 1;  // 然后将n的个位移除，即n右移一位
            }
            return s;
        }
    };
    ```
#### 58.数值的整数次方(剑指offer原16题)
- 解题思路：注意处理次方是负数的情况即可！
    ```
    class Solution
    {
    public:
        double Power(double base, int exponent){
            double res = 1;
            for(int i = 0; i < abs(exponent); i++){
                res *= base;
            }
            if(exponent < 0) res = 1 / res;
            return res;
        }
    };
    ```
#### 59.在O(1)的时间复杂度内删除链表结点（剑指offer原18题--题目一）
- 解题思路：此题不能使用常规方法！因为要删除的结点不是链表的最后一个结点，所以下一个结点一定不是空结点。删除的方法是：**用下一个结点的值去覆盖当前结点的值，然后将下一个结点的值删掉**。这种方法就不需要用到前驱结点了。
    ```
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };

    class Solution
    {
    public:
        void deleteNode(ListNode* node){
            node->val = node->next->val;
            node->next = node->next->next;
        }
    };
    ```
#### 60.删除链表中重复的结点（剑指offer原18题--题目二）
- 解题思路：**建议凡是可能会把头结点删掉的链表问题，一般来说都会增加一个虚拟头结点来简化代码**。使用两个指针，第一个指针p指向上一次保留的结点的最后一个位置，q指向的是下一段的第一个结点，q用来扫描下一段的所有结点。
    ```
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };

    class Solution{
    public:
        ListNode* deleteDuplication(ListNode* head){
            auto dummy = new ListNode(-1);
            dummy->next = head;

            auto p = dummy;
            while(p->next)
            {
                auto q = p->next;
                while(q && p->next->val == q->val){
                    q = q->next;
                }
                if(p->next->next == q) p = p->next;   // 下一段的长度是1，没有重复结点，不用删
                else p->next = q;   // 下一段的长度超过1，则删除重复结点
            }
            return dummy->next;
        }
    };
    ```
#### 61.正则表达式的匹配（剑指offer原19题）
- 题目：实现一个函数用来匹配包括.和\*的正则表达式。字符.表示任意一个字符；字符\*表示它前面的字符可以出现任意次（含0次）。
- 解题思路：**动态规划问题**。状态表示f[i][j]:s[i,...]和p[j,...]是相匹配的；状态转移：情况1：如果p[j]是正常字符，则f[i][j] = s[i] == p[j] && f[i + 1][j + 1]；情况2：p[j]是.，f[i][j] = f[i + 1][j + 1]；情况3：p[j + 1] = \*，\*表示的字符是0次或\*表示的字符匹配1次，则f[i][j] = f[i][j + 2] || f[i + 1][j]；边界问题：f[n][m] = true
    ```
    class Solution{
    public:
        int n, m;
        vector<vector<int>> f;
        string s, p;

        bool inMatch(string _s, string _p){
            s = _s, p = _p;
            n = s.size(), m = p.size();
            f = vector<vector<int>> (n + 1, vector<int>(m + 1, -1));
            return dp(0, 0);
        }

        bool dp(int x, int y){
            if(f[x][y] != -1) return f[x][y];
            if(y == m)
                return f[x][y] = x == n;
            bool first_match = x < n && (p[y] == '.' || s[x] == p[y]);  // 情况1和情况2

            if(y + 1 < m && p[y + 1] == '*'){  // 情况3
                f[x][y] = dp(x, y + 2) || dp(x + 1, y);
            }
            else{
                f[x][y] = first_match && dp(x + 1, y + 1);
            }
            return f[x][y];
        }
    };
    ```
#### 62.表示数值的字符串（剑指offer原20题）
- 解题思路：分各种情况讨论
    ```
    class Solution{
    public:
        bool isNumber(string s){
            int i = 0, j = s.size();
            // 删除字符串s中的前后空格
            while(i <= j && s[i] == ' ') i++;
            while(i <= j && s[j] == ' ') j--;

            if(i > j) return false;

            s = s.substr(i, j - i + 1);
            if(s[0] == '+' || s[0] == '-') s = s.substr(1);
            if(s.empty() || (s[0] == '.' && s.size() == 1)) return false;  // + - .

            int dot = 0, e = 0;   // 统计有多少个.和e
            for(int i = 0; i < s.size(); i++){
                if(s[i] >= '0' && s[i] <= '9');
                else if(s[i] == '.'){
                    dot++;
                    if(dot > 1 || e) return false;  // 3434.23232.4343, 23232e23232.2323
                }
                else if(s[i] == 'e' || s[i] == 'E'){
                    e++;
                    if(!i || i + 1 == s.size() || e > 1 || s[i - 1] == '.' && i == 1) return false; // e1223233, 11232e, 1212e32323e
                    if(s[i + 1] == '+' || s[i + 1] == '-'){
                        if(i + 2 == s.size()) return false;   // 12341e+
                        i++;
                    }
                }
                else return false;
            }
            return true;
        }
    };
    ```
#### 63.调整数组顺序使奇数位于偶数前面（剑指offer原21题）
- 题目：输入一个数组，实现数组中数字的顺序，使得所有的奇数位于数组的前半部分；所有的偶数位于后半部分。
- 解题思路：使用双指针，一个指针从前往后，另一个指针从后往前。保证第一个指针前面全部是奇数，第二个指针前面全部是偶数。
    ```
    class Solution{
    public:
        void reOrderArray(vector<int>& nums){
            int first = 0, second = nums.size() - 1;
            while(first <= second){
                while(first <= second && nums[first] % 2 == 1) first++;
                while(first <= second && nums[second] % 2 == 0) second--;
                if(first < second) swap(nums[first], nums[second]);
            }
        }
    };
    ```
#### 64.链表中倒数第k个节点（剑指offer原22题）
- 解题思路：由于单链表不能从后往前遍历的，只能从前往后遍历。因此首先求出整个链表的长度n，求倒数第k个节点相当于求正序的n-k+1个节点，然后从前往后遍历到n-k+1个节点就可以了。
    ```
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };

    class Solution{
    public:
        ListNode* findKthToTail(ListNode* head, int k){
            int n = 0;
            for(auto p = head; p; p = p->next) n++;
            if(k > n) return nullptr;

            auto p = head;
            for(int i = 0; i < n - k; i++) p = p->next;
            return p;
        }
    };
    ```
#### 65.链表中环的入口节点（剑指offer原23题）
- 解题思路：**使用快慢指针算法，用两个指针first和second分别从起点开始走，first每次走一步，second每次走两步。如果过程中second走到null，则说明不存在环；否则当first和second相遇后，让first返回起点，second待在原地不动，然后两个指针每次分别走一步，当相遇时，相遇点就是环的入口**。
    ```
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr){}
    };

    class Solution{
    public:
        ListNode* entryNodeOfLoop(ListNode* head){
            auto i = head, j = head; // i是慢指针，每次走一步;j是快指针，每次走两步
            while(i && j){
                i = i->next;
                j = j->next;
                if(j) j = j->next;

                if(i == j){  // i和j相遇了
                    i = head;  // 慢指针i回到起点
                    while(i != j){ // 慢指针和快指针同时向后移动一个位置
                        i = i->next;
                        j = j->next;
                    }
                    return i;   // 环入口的位置
                }
            }
            return nullptr;  // 无环存在
        }
    };
    ```
#### 66.找出数组中重复的数字（剑指offer原3题---题目一）
- 解题思路：从前往后遍历整个数组中的每个元素，如果元素的取值不在0到n-1范围内，就直接返回-1；如果元素的取值在0到n-1范围内时，检查数组下标是取值为该元素时的数组位置上存储的是哪个数字；如果存储的数字与其在数组中对应的下标相等，则找出了重复的数字，否则将两个位置上的数字进行交换，重复此步骤，直到存储的数字与其在数组中对应的下标相等为止。
    ```
    class Solution{
    public:
        int duplicateInArray(vector<int>& nums){
            for(auto x : nums){
                if(x < 0 || x >= nums.size())
                return -1;
            }

            for(int i = 0; i < nums.size(); i++){
                while(i != nums[i] && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
                if(nums[i] != i && nums[nums[i]] == nums[i]) return nums[i];
            }
            return -1;
        }
    };
    ```
#### 67.不修改数组，找出数组中重复的数字（剑指offer原3题---题目二）
- 解题思路：**根据抽屉原理**，至少有2个数字会重复！利用递归的思想，将这个数组一分为二，分别计算左右子数组两边的长度和元素的个数，至少有一边元素的个数会大于子数组的长度。递归上面的过程即可！
    ```
    class Solution{
    public:
        int duplicateInArray(vector<int>& nums){
            int l = 1, r = nums.size() - 1;
            while(l < r){
                int mid = l + r >> 1;  // [l, mid], [mid + 1, r]
                int s = 0;  // 统计元素的个数
                for(auto x : nums) s += x >= l && x <= mid;
                if(s > mid - l + 1) r = mid;
                else l = mid + 1;
            }
            return r;
        }
    };
    ```
#### 68.二维数组中的查找（剑指offer原4题）
- 解题思路：从二维数组右上角的位置开始查找，如果要查找的目标数字比右上角的数字要大，则目标数字出现在二维数组的右下角位置；如果要查找的目标数字比右上角的数字要小，则目标数字出现在二维数组的左上角位置。
    ```
    class Solution{
    public:
        bool searchArray(vector<vector<int>> array, int target){
            if(array.empty() || array[0].empty()) return false;

            int i = 0, j = array[0].size() - 1;
            while(i < array.size() && j >=0){
                if(array[i][j] == target) return true;
                if(array[i][j] > target) j--;
                else i++;
            }
            return false;
        }
    };
    ```
#### 69.替换空格（剑指offer原5题）
- 解题思路：开一个新的字符串，遍历原始的字符串，如果遇到空格字符，就将20%存储在新字符串中；否则，直接存储在新字符串中。
    ```
    class Solution{
    public:
        string replaceSpaces(string& str){
            string res;
            for(auto x : str){
                if(x == ' ')
                    res += "20%";
                else res += x;
            }
            return res;
        }
    };
    ```
#### 70.从尾到头打印链表（剑指offer原6题）
- 解题思路：先将整个链表遍历一遍，然后将整个链表翻转一下即可。
    ```
    class Solution{
    public:
        vector<int> printListReversingly(ListNode* head){
            vector<int> res;
            while(head){
                res.push_back(head->val);
                head = head->next;
            }
            return vector<int>(res.rbegin(), res.rend());
        }
    };
    ```
#### 71.重建二叉树（根据前序遍历和中序遍历来重建二叉树）（剑指offer原7题）
- 解题思路：首先，根据前序遍历确定当前区间的根节点是哪个；然后，根据已经确定的根节点，从中序遍历中找到根节点的位置在哪，从而确定二叉树的左右子树中分别包含的数字；最后，在已经确定的左右子树中递归执行前面的两个步骤，即可重建二叉树。
    ```
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    };


    class Solution{
    public:
        map<int, int> hash;   // 开一个hash表，记录每个节点在数组中的位置
        vector<int> preorder, inorder;

        TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder){
            preorder = _preorder, inorder = _inorder;
            for(int i = 0; i < inorder.size(); i++){
                hash[inorder[i]] = i;
            }
            return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
        }

        TreeNode* dfs(int pl, int pr, int il, int ir){
            if(pl > pr) return nullptr;
            auto root = new TreeNode(preorder[pl]);
            int k = hash[inorder[root->val]];
            auto left = dfs(pl + 1, pl + 1 + k - il - 1, il, k - 1);
            auto right = dfs(pl + k - il + 1, pr, k + 1, ir);
            root->left = left;
            root->right = right;
            return root;
        }
    };
    ```
#### 72.二叉树的下一个节点（剑指offer原8题）
- 题目：给定二叉树中的一个节点，找出**中序遍历序列**的下一个节点
- 解题思路：分情况进行讨论，情况1：如果给定的节点是存在右子树的，则下一个节点是右子树中最左边的节点；情况2：如果给定的节点是不存在右子树的，又分两种情况讨论：a.如果给定的节点存在父节点，并且给定的节点是父节点的左儿子的话，则下一个节点是给定节点的父节点；b.如果给定的节点存在父节点，并且给定的节点是父节点的右儿子的话，此时沿着父节点向上找，直到找到第一个节点是当前父节点的左儿子时停止，返回父节点。
    ```
    class Solution{
    public:
        TreeNode* inorderSuccessor(TreeNode* p){
            if(p->right){  // 情况1
                p = p->right;
                while(p->left) p = p->left;
                return p;
            }
            // 情况2
            while(p->father && p == p->father->right) p = p->father;
            return p->father;
        }
    };
    ```
#### 73.用两个栈实现一个队列（剑指offer原9题）
- 解题思路：先将元素依次压入栈1中，然后逐个弹出栈1中的元素，将每个元素依次压入栈2中。此时，**栈2中的栈顶元素就是栈1中的栈底元素**，再依次弹出栈2中的元素时，就实现了队列的先进先出功能（最先进入栈1中的元素，最先从栈2中弹出）。
    ```
    class MyQueue{
    public:
        stack<int> stk, cache;

        MyQueue(){

        }

        void push(int x){
            stk.push(x);
        }

        // 辅助函数
        void copy(stack<int>& a, stack<int>& b){
            while(a.size()){
                b.push(a.top());
                a.pop();
            }
        }

        int pop(){
            copy(stk, cache);
            int res = cache.top();
            cache.pop();
            copy(cache, stk);
            return res;
        }

        int peak(){
            copy(stk, cache);
            int res = cache.top();
            copy(cache, stk);
            return res;
        }

        bool empty(){
            return stk.empty();
        }
    };
    ```
#### 74.斐波那契数列数列（剑指offer原10题）
```
class Solution{
public:
    int Fibonacci(int n){
        int a = 0, b = 1;
        while(n--){
            int c = a + b;
            a = b, b = c;
        }
        return a;
    }
};
```
#### 75.旋转数组的最小数字（剑指offer原11题）
- 解题思路：利用**画图法**来解决。输入数组是0 1 2 2 2 2 3 4 5,则旋转后的数组是2 2 3 4 5 0 1 2 2。将旋转数组分成两部分2 2 3 4 5和0 1 2 2，两部分是单调的增加。首先将后半部分相同值删除，然后观察剩下的结果可知，所有的元素都比前半部分的第一个元素小。前半部分中后面的值都大于或等于第一个元素。**下面就可以使用二分法，找出后半部分中第一个比前半部分第一个元素小的那个数字，就是我们要找的最小数字**。
    ```
    class Solution{
    public:
        int findMin(vector<int>& nums){
            int n = nums.size() - 1;
            if(n < 0) return -1;

            while(n > 0 && nums[n] == nums[0]) n--;  // 去掉后半部分相等的数值
            if(nums[n] >= nums[0]) return nums[0];

            int l = 0, r = n;
            while(l < r){
                int mid = l + r >> 1;
                if(nums[mid] < nums[0]) r = mid;
                else l = mid + 1;
            }
            return nums[r];
        }
    };
    ```
#### 76.矩阵中的路径（剑指offer原12题）
- 解题思路：先枚举所有起点，然后枚举方向。直到走到不能走为止，这样就得到所有的路径。
    ```
    class Solution{
    public:
        bool hasPath(vector<vector<char>>& matrix, string str){
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(dfs(matrix, str, 0, i, j))  // 枚举所有起点i, j，从字符串str第0个字符串开始枚举
                        return true;
                }
            }
            return false;
        }

        bool dfs(vector<vector<char>>& matrix, string& str, int u, int x, int y){ // 当前字符串str中的第几个字符u，x和y是当前路径的坐标
            if(u == str.size()) return true;
            if(matrix[x][y] != str[u]) return false;
            // 枚举四个方向
            int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
            char t = matrix[x][y];  // 已经访问过的字符，不能重新访问
            matrix[x][y] = '*';
            for(int i = 0; i < 4; i++){
                int a = x + dx[i], b = y + dx[i];
                if(a >= 0 && a < matrix.size() && b >= 0 && b < matrix[a].size()){
                    if(dfs(matrix, str, u + 1, a, b)) return true;
                }
            }
            matrix[x][y] = t;
            return false;
        }
    };
    ```
