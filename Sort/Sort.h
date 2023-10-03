#pragma once
#include <iostream>

#define maxsize 100

int a[maxsize] = {49, 38, 65, 97, 76, 13, 27, 49};

void insertDriect()
{
    int n = 8;

    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}

void binSort()
{
    int n = 8;
    for (int i = 1; i < n; i++) // 开始 以a[0]作为有序序列，从a[1]开始找到当前元素a[i]应该放置的位置
    {
        int low = 0, high = i - 1, mid; // 每次寻找a[i]的位置，都要更新这些数据
        while (low <= high)             // 二分思想循环寻找a[i]的位置
        {
            mid = low + ((high - low) / 2);
            if (a[i] <= a[mid])
            {
                high = mid - 1; // high指针减小
            }
            else
            {
                low = mid + 1; // low指针增加
            }
        } // 循环结束，low就是a[i]应该放置的位置

        int temp = a[i];
        for (int j = i; j > low; j--) // 将元素向后平移
        {
            a[j] = a[j - 1];
        }

        a[low] = temp; // 将元素temp = a[i] 放置到low位置
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    };

    return;
}

void shellSort()
{
    int gap, i, j;
    int temp;
    int n = 8;
    for (gap = n >> 1; gap > 0; gap >>= 1)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i - gap; j >= 0 && a[j] > temp; j -= gap)
            {
                a[j + gap] = a[j];
            }

            a[j + gap] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    };

    return;
}

void bubbleSort1()
{
    int n = 8;
    bool flag = true;
    while (flag)
    {
        flag = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                flag = true;
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    };

    return;
}

void bubbleSort2()
{
    int n = 8;
    int BOUND = n - 1; // 记录每趟冒泡的终止位置，由于书上的下标是从1开始，而这里是从0开始的，所以这里初值为n - 1

    while (BOUND) // 在终止位置不为0，即所有元素还未排序完毕之前循环
    {
        int t = 0; // t用来记录每次交换元素的位置
        for (int j = 0; j < BOUND; j++)
        {
            // 只有在a[j] > a[j+1]时才交换，可以保证算法的稳定性
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                t = j; // t = j 表示a[j]和a[j+1]交换了位置
            }
        }
        BOUND = t; // 此时a[BOUND]（不含自身）之后的元素都已经排序完毕
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}

void bubbleSort3()
{
    int n = 8;
    // i是排在末尾的大元素的指针，j是排在前面的小元素的指针，[i, j]区间内的元素为尚未排序的元素
    int i = n - 1, j = 0;
    int tag = -1; // tag为-1时进行大元素的上浮操作，tag为1时进行小元素的下沉操作
    while (i > j)
    {
        int flag = 0;
        if (tag == -1) // 大元素的上浮操作
        {
            for (int k = j; k < i; k++)
            {
                if (a[k] > a[k + 1])
                {
                    flag = 1;
                    int temp = a[k];
                    a[k] = a[k + 1];
                    a[k + 1] = temp;
                }
            }
            i--; // 每排完一个元素，记得移动指针
        }
        else if (tag == 1) // 小元素的下沉操作
        {
            for (int k = i; k > j; k--)
            {
                if (a[k] < a[k - 1])
                {
                    flag = 1;
                    int temp = a[k];
                    a[k] = a[k - 1];
                    a[k - 1] = temp;
                }
            }
            j++; // 每排完一个元素，记得移动指针
        }
        tag = -tag; // 更换下次的操作
        if (!flag)
            break; // 如果未发生交换，说明已经排序完毕，可以提前退出
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return;
}

int partition(int a[], int low, int high)
{
    // 这里可以视为在逻辑上移走了low位置的元素，之后low指向的是一个空元素
    int K = a[low]; // 用第一个元素作为枢轴，将待排序序列划分为左右两个部分

    // 何时移动low指针和high指针是有讲究的
    // 我们每次让指向空元素的指针固定不动，然后移动另外一个指针，再将找到的元素放到空元素位置
    // 因此让指向空元素的指针不动，可以视为用这个指针来记录空元素的位置，然后可以将找到的元素放到这里来
    // 而第一次进入大循环前，a[low]位置是空的，因此先移动high指针，之后每次大循环同理
    while (low < high)
    {
        // 在low和high指针移动的过程中，也要随时判断两者的大小关系
        while (low < high && a[high] >= K)
        {
            high--; // high指针不断左移直到找到一个比枢轴小的元素
        }
        // 这里可以视为在逻辑上移走了high位置的元素，之后high指向的是一个空元素
        a[low] = a[high]; // 把比枢轴小的元素移动到左端的空元素位置

        while (low < high && a[low] <= K)
        {
            low++; // low指针不断右移直到直到一个比枢轴大的元素
        }
        // 这里可以视为在逻辑上移走了low位置的元素，之后low指向的是一个空元素
        a[high] = a[low]; // 把比枢轴大的元素移动到右端的空元素位置
    }

    // 当最终low == high时，a[high]就是枢轴元素应该放置的地方
    a[high] = K; // 此时a[high]左边的元素都比K小，a[high]右边的元素都比K大，枢轴元素的最终位置已经确定
    return high;
}

void quicksort(int a[], int low, int high)
{
    if (low < high) // 递归跳出的条件
    {
        int mid = partition(a, low, high); // 划分
        quicksort(a, low, mid - 1);        // 划分左子表
        quicksort(a, mid + 1, high);       // 划分右子表
    }
}

void quickSort()
{
    int n = 8;
    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}

int partition2(int a[], int low, int high)
{
    int m = low;
    int K = a[low];
    high++; // 这里可以理解为在a[high + 1]处插入了一个无穷大的数
    while (low < high)
    {
        // 和上面的快速排序不一样的地方是，这种方法每趟排序时是先让low进行移动，再让high移动
        low++;
        while (a[low] <= K)
            low++; // 这里很关键，一定要有等于，不然结果会出错，我也不知道为什么
        high--;
        while (a[high] > K)
            high--; // 这里不需要等于
        if (low < high)
        {
            int temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
    int temp = a[high]; // 最终low = high - 1，a[m]应该放在high的位置，而不是low，我也不知道为什么
    a[high] = a[m];
    a[m] = temp;
    return high;
}

void quicksort2(int a[], int low, int high)
{
    if (low < high) // 递归跳出的条件
    {
        int mid = partition(a, low, high); // 划分
        quicksort(a, low, mid - 1);        // 划分左子表
        quicksort(a, mid + 1, high);       // 划分右子表
    }
}

void quickSort2()
{
    int n = 8;
    quicksort2(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}

void selectSort()
{
    int n = 8;
    // 每次将后面最小的元素放到前面，所以每趟形成的子序列一定是有序的，只需n - 1次循环
    for (int i = 0; i < n - 1; i++)
    {
        int t = i; // 记录最小元素的下标
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[t])
            {
                t = j;
            }
        }
        if (t != i)
        {
            int temp = a[t];
            a[t] = a[i];
            a[i] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}

// 对以元素k为根的子树进行调整，使其符合大根堆的定义：a[k] >= a[2k], a[k] >= a[2k+1]
void HeapAdjust(int a[], int k, int n)
{
    // n是最后一个结点的编号，而⌊n/2⌋就是其父结点的编号
    // 所以k <= n/2是k为分支结点的条件，如果是叶结点就不用调整了
    while (k <= n / 2)
    {
        // m记录关键字较大的儿子结点的下标，能进入这个循环说明k必有左儿子，先赋为左儿子下标
        int m = 2 * k;
        // 2 * k + 1 <= n是k的右儿子存在的条件，如果右儿子关键字比左儿子的大，就修改m
        if (2 * k + 1 <= n && a[2 * k] < a[2 * k + 1])
        {
            m = 2 * k + 1;
        }
        if (a[k] < a[m])
        {
            // 将k结点和m结点关键字交换，并继续向下调整
            int temp = a[m];
            a[m] = a[k];
            a[k] = temp;

            k = m;
        }
        else
            break;
    }
}

// 堆排序
void HeapSort(int a[], int n)
{
    // 建立大根堆
    // n是最后一个结点的编号，而⌊n/2⌋就是其父结点的编号
    // i <= n/2是i为分支结点的条件，对所有以分支结点为根的子树进行调整
    for (int i = n / 2; i >= 1; i--)
    {
        HeapAdjust(a, i, n);
    }
    // 由于每趟排序会确定一个结点的最终位置，因此只要n - 1趟即可排好
    for (int len = n; len > 1; len--)
    {
        // 每趟排序将堆顶元素加入有序子序列，即与待排序序列的最后一个元素交换
        int temp = a[1];
        a[1] = a[len];
        a[len] = temp;
        // 再将剩余len - 1个元素调整为大根堆，这里只需调用一次HeapAdjust函数，因为除了根节点外其他分支结点都满足大根堆的定义
        HeapAdjust(a, 1, len - 1);
    }
}

void heapSort()
{
    // 注意二叉树的顺序存储，首元素下标必须从1开始
    int n = 8;
    HeapSort(a, n);

    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}

int maxbit(int data[], int n) // 辅助函数，求数据的最大位数
{
    int maxData = data[0]; ///< 最大数
    /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
    for (int i = 1; i < n; ++i)
    {
        if (maxData < data[i])
            maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        // p *= 10; // Maybe overflow
        maxData /= 10;
        ++d;
    }
    return d;
}

void radixsort(int data[], int n) // 基数排序
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10]; // 计数器
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) // 进行d次排序
    {
        for (j = 0; j < 10; j++)
            count[j] = 0; // 每次分配前清空计数器
        for (j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; // 统计每个桶中的记录数
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; // 将tmp中的位置依次分配给每个桶
        for (j = n - 1; j >= 0; j--)            // 将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for (j = 0; j < n; j++) // 将临时数组的内容复制到data中
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

void merge(int *a, int low, int mid, int hight) // 合并函数
{
    int *b = new int[hight - low + 1]; // 用 new 申请一个辅助函数
    int i = low, j = mid + 1, k = 0;   // k为 b 数组的小标
    while (i <= mid && j <= hight)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++]; // 按从小到大存放在 b 数组里面
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid) // j 序列结束，将剩余的 i 序列补充在 b 数组中
    {
        b[k++] = a[i++];
    }
    while (j <= hight) // i 序列结束，将剩余的 j 序列补充在 b 数组中
    {
        b[k++] = a[j++];
    }
    k = 0;                             // 从小标为 0 开始传送
    for (int i = low; i <= hight; i++) // 将 b 数组的值传递给数组 a
    {
        a[i] = b[k++];
    }
    delete[] b; // 辅助数组用完后，将其的空间进行释放（销毁）
}
void mergesort(int *a, int low, int hight) // 归并排序
{
    if (low < hight)
    {
        int mid = (low + hight) / 2;
        mergesort(a, low, mid);       // 对 a[low,mid]进行排序
        mergesort(a, mid + 1, hight); // 对 a[mid+1,hight]进行排序
        merge(a, low, mid, hight);    // 进行合并操作
    }
}
int main()
{
    int n, a[100];
    cout << "请输入数列中的元素个数 n 为：" << endl;
    cin >> n;
    cout << "请依次输入数列中的元素：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n - 1);
    cout << "归并排序结果" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

// 归并排序（C-迭代版）
int min(int x, int y)
{
    return x < y ? x : y;
}
void merge_sort(int arr[], int len)
{
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg)
    {
        for (start = 0; start < len; start += seg + seg)
        {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
            {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }
            while (start1 < end1)
            {
                b[k++] = a[start1++];
            }
            while (start2 < end2)
            {
                b[k++] = a[start2++];
            }
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr)
    {
        int i;
        for (i = 0; i < len; i++)
        {
            b[i] = a[i];
        }
        b = a;
    }
    free(b);
}