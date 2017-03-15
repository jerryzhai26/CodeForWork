#include<iostream>
using namespace std;
//题目1
/*如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, { 15, 78, 78, 15 }, { 112 } 是回文序列,
{ 1, 2, 2 }, { 15, 78, 87, 51 }, { 112, 2, 11 } 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。*/
//思路
/*
两种思路，一种迭代，一种递归
这道题中任何序列最后都会变成回文序列，因为加到只剩一个数的时候就是回文了。
*/

int main(void){
	int n;
	cin >> n;
	int nums[50] = { 0 };
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int head = 0;
	int tail = n - 1;
	int left = nums[head];
	int right = nums[tail];
	int times = 0;
	while (head < tail){
		if (left < right){
			left += nums[++head];
			times++;
		}
		else if (left>right){
			right += nums[--tail];
			times++;
		}
		else{
			head++;
			tail--;
			left = nums[head];
			right = nums[tail];
		}
	}
	cout << times << endl;
	cout << times << endl;
	return 0;
}
int find_times(int* nums, int head, int tail){
	if (head >= tail)
		return 0;
	int left = nums[head];
	int right = nums[tail];
	int times = 0;
	while (left != right && head < tail){
		if (left < right){
			left += nums[++head];
			times++;
		}
		else{
			right += nums[--tail];
			times++;
		}
	}
	if (left == right){
		times += find_times(nums, ++head, --tail);
	}
	return times;

}

int main(){
	int n;
	cin >> n;
	int nums[50] = {0};
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int times = find_times(nums, 0, n - 1);
	cout << times << endl;
	return 0;
}