#include<iostream>
#include<string>
#include<algorithm>

/*
��Ŀ
����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
�����Ҫɾ�����ַ�������
*/
/*
����˼·��
��1�����ַ�����ת�γ�����һ���ַ�������Ϊ��ת�ַ�����
��2����ԭ�ַ���s1����ת�ַ���s2�У�������Ӵ��ĳ��ȣ�
��3��ɾ�����ַ���Ŀ = ԭ�ַ����ĳ��� - ������Ӵ��ĳ��ȡ�
��Ҫ����������⣺
�������ַ���s1��s2��������Ӵ��ĳ��ȡ�
���������ⷽʽ����̬�滮
�� MaxLen(i,j)��ʾs1���i���ַ���s2���j���ַ���������Ӵ����ȣ���������Ľ�ΪMaxLen(strlen(s1),strlen(s2));
MaxLen(i,j)����ⷽʽΪ��
��s1��i���ַ���s2��j���ַ���ƥ�䣬�� return 1+MaxLen(i-1,j-1);
����return max(MaxLen(i-1,j),MaxLen(i,j-1))
�߽�������
MaxLen(i,n)=0; for n in 0 to strlen(s2)
MaxLen(n,j)=0; for n in 0 to strlen(s1)
�㷨���Ϳ��Բο����������һ���ܽ�Ĳ���
http://www.cnblogs.com/grenet/archive/2010/06/03/1750454.html
*/
/*��֪��Ϊɶţ����ͨ���ˣ���vs���в��ɹ�*/
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