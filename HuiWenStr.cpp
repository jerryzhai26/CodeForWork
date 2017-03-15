#include<iostream>
#include<string>
#include<algorithm>

/*
题目
给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。
*/
/*
解题思路：
（1）把字符串旋转形成另外一个字符串，称为旋转字符串；
（2）求原字符串s1与旋转字符串s2中，最长公共子串的长度；
（3）删除的字符数目 = 原字符串的长度 - 最长公共子串的长度。
需要解决的子问题：
求两个字符串s1和s2中最长公共子串的长度。
子问题的求解方式：动态规划
设 MaxLen(i,j)表示s1左边i个字符与s2左边j个字符的最长公共子串长度，则子问题的解为MaxLen(strlen(s1),strlen(s2));
MaxLen(i,j)的求解方式为：
若s1第i个字符与s2第j个字符相匹配，则 return 1+MaxLen(i-1,j-1);
否则：return max(MaxLen(i-1,j),MaxLen(i,j-1))
边界条件：
MaxLen(i,n)=0; for n in 0 to strlen(s2)
MaxLen(n,j)=0; for n in 0 to strlen(s1)
算法解释可以参考博主“万仓一黍”总结的博文
http://www.cnblogs.com/grenet/archive/2010/06/03/1750454.html
*/
/*不知道为啥牛课上通过了，但vs运行不成功*/
using namespace std;
int max_common_sub_list_len(string &str1, string &str2){
	int len1 = str1.size();
	int len2 = str2.size();
	const int MAX = 1001;
	int MAX_LEN[MAX][MAX] = { { 0 } };
	for (int i = 1; i <= len1; i++){
		for (int j = 1; j <= len2; j++){
			if (str1[i - 1] == str2[j - 1])
				MAX_LEN[i][j] = MAX_LEN[i - 1][j - 1] + 1;
			else
				MAX_LEN[i][j] = max(MAX_LEN[i - 1][j], MAX_LEN[i][j - 1]);
			//MAX_LEN[i][j] = (MAX_LEN[i - 1][j] > MAX_LEN[i][j - 1]) ? MAX_LEN[i - 1][j] : MAX_LEN[i][j - 1];
		}
	}
	return MAX_LEN[len1][len2];
}
int main(){
	string str;
	while (cin >> str){
		//cout << str << endl;
		string rstr = str;
		reverse(rstr.begin(), rstr.end());
		//cout << rstr << endl;
		int del_len = str.size() - max_common_sub_list_len(str, rstr);
		cout << del_len << endl;
	}
}