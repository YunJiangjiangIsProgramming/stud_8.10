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
	dict.insert(make_pair("sort", "排序"));
	dict["string"] = "字符串";

	unordered_map<string, string>::iterator dictit = dict.begin();
	/*while (dictit != dict.end())
	{
		cout << dictit->first << ":" << dictit->second << endl;
		++it;
	}
	cout << endl;*/
	for (const auto& pair : dict) // 同上，使用范围for循环
	{
		cout << pair.first << ":" << pair.second << endl;
	}
	cout << endl;

}
void test_unordered_map_set2()
{
	unordered_set<string> authors; // 存储作者名字的集合
	authors.insert("J.K. Rowling");
	authors.insert("George Orwell");
	authors.insert("Harper Lee");

	// 输出作者名字
	for (const auto& author : authors)
	{
		cout << author << endl;
	}

	unordered_map<string, string> books; // 存储书籍信息的映射表
	books["1984"] = "George Orwell";
	books["Harry Potter and the Philosopher's Stone"] = "J.K. Rowling";
	books["To Kill a Mockingbird"] = "Harper Lee";

	// 输出书籍信息
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

	// 插入操作测试
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

	// 查找操作测试
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

	// 删除操作测试
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

	// 更新操作测试（通过删除后重新插入实现）
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
		unordered_map<int, int> countMap; // 哈希映射，用于存储每个元素的计数
		for (auto e : nums) // 遍历输入数组
		{
			countMap[e]++; // 增加元素计数
		}
		int N = nums.size() / 2; // 要找的数的出现次数
		for (auto kv : countMap) // 遍历映射中的键值对
		{
			if (kv.second == N) // 如果值等于N
			{
				return kv.first; // 返回对应的键
			}
		}
		return -1; // 如果没有找到，返回-1
	}
};

//https://leetcode.cn/problems/intersection-of-two-arrays/description/
class Solution1 {
public:
	// 定义一个函数，输入是两个整数向量，输出是它们的交集向量
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		// 创建一个无序集合s1，用于存储nums1中的元素
		unordered_set<int> s1;

		// 遍历数组nums1，将每个元素插入到集合s1中
		for (auto e : nums1)
		{
			s1.insert(e);
		}

		// 创建一个无序集合s2，用于存储nums2中的元素
		unordered_set<int> s2;

		// 遍历数组nums2，将每个元素插入到集合s2中
		for (auto e : nums2)
		{
			s2.insert(e);
		}

		// 创建一个结果向量vRet，用于存储交集元素
		vector<int> vRet;

		// 遍历集合s1中的每个元素
		for (auto e : s1)
		{
			// 检查元素e是否在集合s2中存在
			if (s2.find(e) != s2.end())
			{
				// 如果存在，则将元素e添加到结果向量vRet中
				vRet.push_back(e);
			}
		}

		// 返回结果向量vRet
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
