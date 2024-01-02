#include "iostream"
#include "vector"

using namespace std;


void print(vector<int> &nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}


void bubbleSort(vector<int> &nums)
//内外两个循环，外循环控制内循环什么时候截止，内循环每次把最大元素移到最后
{
    int n = nums.size();
    bool flag;
    for (int i = 0; i < n - 1; ++i)
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
        print(nums);
    }
}


void insertionSort(vector<int> &nums)
//内外两个循环，外循环控制数组前面顺序的位置，内循环每次把最小元素移到合适位置
{
    int n = nums.size();
    for (int i = 1; i < n; ++i)
    {
        if (nums[i] < nums[i - 1])
        {
            int x = nums[i];
            while (x < nums[i - 1] && i >= 1)
            {
                nums[i] = nums[i - 1];
                i--;
            }
            nums[i] = x;
        }
        cout << i << endl;
        print(nums);
    }
    cout<<endl;
}


//内外两个循环，外循环让gap从一半开始除以2，内循环让i从gap开始，一半一半的排序。j+gap
void shellSortCore(vector<int>& nums, int gap, int i) {
	int inserted = nums[i];//2,7。
	int j;
	for (j = i - gap; j >= 0 && inserted < nums[j]; j -= gap) {//0,1。0,1,2
		nums[j + gap] = nums[j];//nums[2]=9;
	}
	nums[j + gap] = inserted;//nums[0]=2;
}
void shellSort(vector<int>& nums) {
	int n = nums.size();
	for (int gap = n / 2; gap > 0; gap /= 2) {//2,1
		for (int i = gap; i < n; ++i) {//2,3/1,2,3
			shellSortCore(nums,gap,i);
            print(nums);
            cout<<i<<endl;
		}
	}
}


//建立大根堆之后，把根节点（最大值）放到最后，然后维护堆的性质
void heapifyCore(vector<int>& nums, int n, int i)
{
	int l = i * 2 + 1, r = i * 2 + 2;
	int max = i;
	if (l<n && nums[l]>nums[max]) max = l;
	if (r<n && nums[r]>nums[max]) max = r;
	if (max != i)
	{
		swap(nums[max], nums[i]);
		heapifyCore(nums, n, max);
	}
}
void heapifySort(vector<int>& nums, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)	heapifyCore(nums, n, i);
	for (int i = 0; i < n; i++)
	{
		swap(nums.front(), nums[n - i - 1]);
		heapifyCore(nums, n - i - 1, 0);
	}
}


//内外两个循环，外循环控制内循环什么时候截止，内循环每次把最小元素移到最前
void selectSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[j] < nums[minIndex]) minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
        print(nums);
    }
}


// int maxbit(int data[], int n) //辅助函数，求数据的最大位数
// {
//     int maxData = data[0];		///< 最大数
//     /// 先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
//     for (int i = 1; i < n; ++i)
//     {
//         if (maxData < data[i])
//             maxData = data[i];
//     }
//     int d = 1;
//     int p = 10;
//     while (maxData >= p)
//     {
//         //p *= 10; // Maybe overflow
//         maxData /= 10;
//         ++d;
//     }
//     return d;
// /*    int d = 1; //保存最大的位数
//     int p = 10;
//     for(int i = 0; i < n; ++i)
//     {
//         while(data[i] >= p)
//         {
//             p *= 10;
//             ++d;
//         }
//     }
//     return d;*/
// }
// void radixsort(int data[], int n) //基数排序
// {
//     int d = maxbit(data, n);
//     int *tmp = new int[n];
//     int *count = new int[10]; //计数器
//     int i, j, k;
//     int radix = 1;
//     for(i = 1; i <= d; i++) //进行d次排序
//     {
//         for(j = 0; j < 10; j++)
//             count[j] = 0; //每次分配前清空计数器
//         for(j = 0; j < n; j++)
//         {
//             k = (data[j] / radix) % 10; //统计每个桶中的记录数
//             count[k]++;
//         }
//         for(j = 1; j < 10; j++)
//             count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
//         for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
//         {
//             k = (data[j] / radix) % 10;
//             tmp[count[k] - 1] = data[j];
//             count[k]--;
//         }
//         for(j = 0; j < n; j++) //将临时数组的内容复制到data中
//             data[j] = tmp[j];
//         radix = radix * 10;
//     }
//     delete []tmp;
//     delete []count;
// }


// void mergeSortCore(vector<int> &nums, vector<int> &numsTemp, int low, int high)
// {

//     if (low >= high)
//         return;
//     int n = high - low, mid = low + n / 2;
//     int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
//     mergeSortCore(nums, numsTemp, start1, end1);
//     mergeSortCore(nums, numsTemp, start2, end2);
//     int index = low;
//     while (start1 <= end1 && start2 <= end2)
//     {
//         numsTemp[index++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
//     }

//     while (start1 <= end1)
//     {
//         numsTemp[index++] = nums[start1++];
//     }

//     while (start2 <= end2)
//     {
//         numsTemp[index++] = nums[start2++];
//     }

//     for (index = low; index <= high; ++index)
//     {
//         nums[index] = numsTemp[index];
//         print(nums);
//     }
// }

// void mergeSort(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> numsTemp(n, 0);
//     mergeSortCore(nums, numsTemp, 0, n - 1);
// }

// void quickSort(vector<int>& nums, int begin, int end) {
// 	if (begin >= end) return;
// 	int low = begin, high = end, key = nums[begin];
// 	while (low < high) {
// 		while (low < high && nums[high] >= key) {
// 			high--;

// 		}
// 		if (low < high)  nums[low++] = nums[high];

// 		while (low < high && nums[low] <= key) {
// 			low++;

// 		}
// 		if (low < high)  nums[high--] = nums[low];
// 	}

// 	nums[low] = key;
// 	print(nums);

// 	quickSort(nums, begin, low - 1);
// 	quickSort(nums, low + 1, end);

// }

// function bucketSort(arr, bucketSize) {
//     if (arr.length === 0) {
//       return arr;
//     }
 
//     var i;
//     var minValue = arr[0];
//     var maxValue = arr[0];
//     for (i = 1; i < arr.length; i++) {
//       if (arr[i] < minValue) {
//           minValue = arr[i];                // 输入数据的最小值
//       } else if (arr[i] > maxValue) {
//           maxValue = arr[i];                // 输入数据的最大值
//       }
//     }
 
//     // 桶的初始化
//     var DEFAULT_BUCKET_SIZE = 5;            // 设置桶的默认数量为5
//     bucketSize = bucketSize || DEFAULT_BUCKET_SIZE;
//     var bucketCount = Math.floor((maxValue - minValue) / bucketSize) + 1;
//     var buckets = new Array(bucketCount);
//     for (i = 0; i < buckets.length; i++) {
//         buckets[i] = [];
//     }
 
//     // 利用映射函数将数据分配到各个桶中
//     for (i = 0; i < arr.length; i++) {
//         buckets[Math.floor((arr[i] - minValue) / bucketSize)].push(arr[i]);
//     }
 
//     arr.length = 0;
//     for (i = 0; i < buckets.length; i++) {
//         insertionSort(buckets[i]);                      // 对每个桶进行排序，这里使用了插入排序
//         for (var j = 0; j < buckets[i].length; j++) {
//             arr.push(buckets[i][j]);
//         }
//     }

//     return arr;
// }


// void CountSort(vector<int>& vecRaw, vector<int>& vecObj)
// {
// 	// 确保待排序容器非空
// 	if (vecRaw.size() == 0)
// 		return;

// 	// 使用 vecRaw 的最大值 + 1 作为计数容器 countVec 的大小
// 	int vecCountLength = (*max_element(begin(vecRaw), end(vecRaw))) + 1;
// 	vector<int> vecCount(vecCountLength, 0);

// 	// 统计每个键值出现的次数
// 	for (int i = 0; i < vecRaw.size(); i++)
// 		vecCount[vecRaw[i]]++;
	
// 	// 后面的键值出现的位置为前面所有键值出现的次数之和
// 	for (int i = 1; i < vecCountLength; i++)
// 		vecCount[i] += vecCount[i - 1];

// 	// 将键值放到目标位置
// 	for (int i = vecRaw.size(); i > 0; i--)	// 此处逆序是为了保持相同键值的稳定性
// 		vecObj[--vecCount[vecRaw[i - 1]]] = vecRaw[i - 1];
// }

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        vector<int> nums = {9, 5, 2, 7};
        int n=nums.size(); // 9, 5, 2, 7, 3, 9, 8, 6
        // vector<int> nums = {2,5,7,9};//9, 5, 2, 7, 3, 9, 8, 6
        print(nums);
        if (i == 0)
            bubbleSort(nums);
        if (i == 1)
            insertionSort(nums);
        if (i == 2)
            shellSort(nums);
        if (i == 3)
            heapifySort(nums,n);
        if (i == 4)
            selectSort(nums);
        // if (i == 5)
        //     radixsort(nums,n);
        // if (i == 6)
        //     mergeSort(nums);
        // if (i == 7)
        //     quickSort(nums);
        // if (i == 8)
        //     bucketSort(nums);
        // if (i == 9){
        //     vector<int> vecObj(nums.size(), 0);
        //     CountSort(vecObj,nums);
        // }
        cout << endl;
    }
    return 0;
}
