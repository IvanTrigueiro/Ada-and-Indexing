#include "bits/stdc++.h"
using namespace std;
map<string, int>mp;
struct No
{
	int freq;
	bool final;
	No* lista[26];
};
No* create()
{
	No* newNo = (No*)malloc(sizeof(No));
	newNo->freq = 0;
	newNo->final = 0;
	for (int i = 0; i < 26; i++)newNo->lista[i] = 0;
	return newNo;
}
void insert(No* cabeca, string s)
{
	int l = s.length();
	No* temp = cabeca;
	for (int i = 0; i < l; i++)
	{
		if (!temp->lista[s[i] - 'a']) {
			temp->lista[s[i] - 'a'] = create();
		}
		temp = temp->lista[s[i] - 'a'];
		temp->freq = temp->freq + 1;
	}
	temp->final = 1;
}
int search(No* cabeca, string s)
{
	No* temp = cabeca;
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		if (temp->lista[s[i] - 'a'])temp = temp->lista[s[i] - 'a'];
		else return 0;
	}
	return temp->freq;
}

int main()
{
	No* cabeca = create();
	int n, q;
	scanf("%d%d", &n, &q);
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		insert(cabeca, s);
	}
	while (q--)
	{
		cin >> s;
		printf("%d\n",search(cabeca, s));
	}
	return 0;
}
