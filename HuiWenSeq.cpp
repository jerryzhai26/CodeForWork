#include<iostream>
using namespace std;
//��Ŀ1
/*���һ��������������֮���ԭ������һ���ľͳ���������������Ϊ�������С����磺
{1, 2, 1}, { 15, 78, 78, 15 }, { 112 } �ǻ�������,
{ 1, 2, 2 }, { 15, 78, 87, 51 }, { 112, 2, 11 } ���ǻ������С�
���ڸ���һ���������У�����ʹ��һ��ת��������
ѡ�������������ڵ�����Ȼ��������Ƴ������������������������ֵĺͲ��뵽��������֮ǰ��λ��(ֻ����һ����)��
���ڶ�����������Ҫ���������Ҫ���ٴβ������Խ����ɻ������С�*/
//˼·
/*
����˼·��һ�ֵ�����һ�ֵݹ�
��������κ�������󶼻��ɻ������У���Ϊ�ӵ�ֻʣһ������ʱ����ǻ����ˡ�
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