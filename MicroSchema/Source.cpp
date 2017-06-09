#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iomanip> 

using namespace std;
const int MAXN = 100; // ����� ������
const int INF = 1000000000; // ���������-�������������
int N, K;
vector <int> pvk_elem, pin_elem;
vector<vector<int>> graph_main;

struct edge {
	int a, b, cap, flow;
};

int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void add_edge(int a, int b) {
	edge e1 = { a, b, 1, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back((int)e.size());
	e.push_back(e1);
	g[b].push_back((int)e.size());
	e.push_back(e2);
}

bool bfs() {
	int qh = 0, qt = 0;
	q[qt++] = s;
	memset(d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i = 0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}

int dfs(int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset(ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs(s, INF))
			flow += pushed;
	}
	return flow;
}

void read_from_file()
{
	int N, K;
	ifstream ifs("input.txt");
	ifs >> N >> K;
	vector<int> vec_el1,vec_el2,tmp_vec;
	int el1,el2;
	tmp_vec.resize(K);
	for (int i = 0;i < K;++i)
	{
		ifs >> el1;
		vec_el1.emplace_back(el1);
	}
	for (int i = 0;i < K;++i)
	{
		ifs >> el2;
		vec_el2.emplace_back(el2);
		int tmp;
		tmp = vec_el1[i] * N + vec_el2[i];
		pvk_elem.emplace_back(tmp);
	}

	vec_el1.clear();

	for (int i = 0;i < K;++i)
	{
		ifs >> el1;
		vec_el1.emplace_back(el1);
	}
	for (int i = 0;i < K;++i)
	{
		ifs >> el2;
		vec_el2.emplace_back(el2);
		int tmp;
		tmp = vec_el1[i] * N+ vec_el2[i]+N*N;
		pin_elem.emplace_back(tmp);
	}

	ifs.close();
}

void check_edge(int tmp,int i,int j)
{
	int up = tmp - N*N;
	if (i==0 && )
	add_edge(tmp, tmp - N*N);
}

void build_graph()
{
	num = 2 * N*N + 2; //������ ������ ���������
	for (int i = 0;i < K;i++)
	{
		for (int j = 0;j < K;j++)
		{
			int tmp = i*N + j + N*N;
			check_edge(tmp,i,j);
			//if (res_check)
				
		}
			

	}
}

int main()
{
	read_from_file();
	return 0;
}