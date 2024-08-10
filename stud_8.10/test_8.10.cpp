#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
#include"HashTable.h"

void test_unorderer_map_set()
{
	unordered_set<int> st;
	st.insert(4);
	st.insert(3);
	st.insert(5);
	st.insert(0);
	st.insert(8);
	st.insert(29);
	
	unordered_set<int>::iterator it = st.begin();
	while (it != st.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict["string"] = "�ַ���";

	unordered_map<string, string>::iterator dictit = dict.begin();
	/*while (dictit != dict.end())
	{
		cout << dictit->first << ":" << dictit->second << endl;
		++it;
	}
	cout << endl;*/
	for (const auto& pair : dict) // ͬ�ϣ�ʹ�÷�Χforѭ��
	{
		cout << pair.first << ":" << pair.second << endl;
	}
	cout << endl;

}
void test_unordered_map_set2()
{
	unordered_set<string> authors; // �洢�������ֵļ���
	authors.insert("J.K. Rowling");
	authors.insert("George Orwell");
	authors.insert("Harper Lee");

	// �����������
	for (const auto& author : authors)
	{
		cout << author << endl;
	}

	unordered_map<string, string> books; // �洢�鼮��Ϣ��ӳ���
	books["1984"] = "George Orwell";
	books["Harry Potter and the Philosopher's Stone"] = "J.K. Rowling";
	books["To Kill a Mockingbird"] = "Harper Lee";

	// ����鼮��Ϣ
	cout << "Books and authors:" << endl;
	for (const auto& book : books)
	{
		cout << book.first << " by " << book.second << endl;
	}
}

void test_op()
{
	unordered_set<int> us;
	set<int> s;

	const int n = 10000000;
	vector<int> v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}
	size_t begin1 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.insert(v[i]);

	}
	size_t end1 = clock();
	cout << end1 - begin1 << "unorder_set.insert()" << endl;

	size_t begin2 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.insert(v[i]);

	}
	size_t end2 = clock();
	cout << end2 - begin2 << "set.insert()" << endl;

	size_t begin3 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.find(v[i]);

	}
	size_t end3 = clock();
	cout << end3 - begin3 << "unorder_set.find()" << endl;

	size_t begin4 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.find(v[i]);

	}
	size_t end4 = clock();
	cout << end4 - begin4 << "set.find()" << endl;

}

void test_performance()
{
	unordered_set<int> us;
	set<int> s;
	const int n = 10000000;
	vector<int> v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

	// �����������
	clock_t begin1 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.insert(v[i]);
	}
	clock_t end1 = clock();
	cout << "unordered_set insert: " << (double)(end1 - begin1) / CLOCKS_PER_SEC << "s" << endl;

	clock_t begin2 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.insert(v[i]);
	}
	clock_t end2 = clock();
	cout << "set insert: " << (double)(end2 - begin2) / CLOCKS_PER_SEC << "s" << endl;

	// ���Ҳ�������
	clock_t begin3 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.find(v[i]);
	}
	clock_t end3 = clock();
	cout << "unordered_set find: " << (double)(end3 - begin3) / CLOCKS_PER_SEC << "s" << endl;

	clock_t begin4 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.find(v[i]);
	}
	clock_t end4 = clock();
	cout << "set find: " << (double)(end4 - begin4) / CLOCKS_PER_SEC << "s" << endl;

	// ɾ����������
	clock_t begin5 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.erase(v[i]);
	}
	clock_t end5 = clock();
	cout << "unordered_set erase: " << (double)(end5 - begin5) / CLOCKS_PER_SEC << "s" << endl;

	clock_t begin6 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.erase(v[i]);
	}
	clock_t end6 = clock();
	cout << "set erase: " << (double)(end6 - begin6) / CLOCKS_PER_SEC << "s" << endl;

	// ���²������ԣ�ͨ��ɾ�������²���ʵ�֣�
	clock_t begin7 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.erase(v[i]);
		us.insert(v[i]);
	}
	clock_t end7 = clock();
	cout << "unordered_set update: " << (double)(end7 - begin7) / CLOCKS_PER_SEC << "s" << endl;

	clock_t begin8 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.erase(v[i]);
		s.insert(v[i]);
	}
	clock_t end8 = clock();
	cout << "set update: " << (double)(end8 - begin8) / CLOCKS_PER_SEC << "s" << endl;
}

//https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/description/
class Solution0 {
public:
	int repeatedNTimes(vector<int>& nums)
	{
		unordered_map<int, int> countMap; // ��ϣӳ�䣬���ڴ洢ÿ��Ԫ�صļ���
		for (auto e : nums) // ������������
		{
			countMap[e]++; // ����Ԫ�ؼ���
		}
		int N = nums.size() / 2; // Ҫ�ҵ����ĳ��ִ���
		for (auto kv : countMap) // ����ӳ���еļ�ֵ��
		{
			if (kv.second == N) // ���ֵ����N
			{
				return kv.first; // ���ض�Ӧ�ļ�
			}
		}
		return -1; // ���û���ҵ�������-1
	}
};

//https://leetcode.cn/problems/intersection-of-two-arrays/description/
class Solution1 {
public:
	// ����һ������������������������������������ǵĽ�������
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		// ����һ�����򼯺�s1�����ڴ洢nums1�е�Ԫ��
		unordered_set<int> s1;

		// ��������nums1����ÿ��Ԫ�ز��뵽����s1��
		for (auto e : nums1)
		{
			s1.insert(e);
		}

		// ����һ�����򼯺�s2�����ڴ洢nums2�е�Ԫ��
		unordered_set<int> s2;

		// ��������nums2����ÿ��Ԫ�ز��뵽����s2��
		for (auto e : nums2)
		{
			s2.insert(e);
		}

		// ����һ���������vRet�����ڴ洢����Ԫ��
		vector<int> vRet;

		// ��������s1�е�ÿ��Ԫ��
		for (auto e : s1)
		{
			// ���Ԫ��e�Ƿ��ڼ���s2�д���
			if (s2.find(e) != s2.end())
			{
				// ������ڣ���Ԫ��e��ӵ��������vRet��
				vRet.push_back(e);
			}
		}

		// ���ؽ������vRet
		return vRet;
	}
};




int main()
{
	//test_unorderer_map_set();
	//test_unordered_map_set2();
	//test_op();
	test_performance();
	return 0;
}
