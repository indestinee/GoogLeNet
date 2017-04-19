#include <bits/stdc++.h>
using namespace std;
vector<string> good, bad;
char buff[1024];
int n;
void work(FILE *fp, vector<string> &v, const string &type, const string &save) {
	printf("start run %s\n", type.c_str());
	int cnt = 0, t;
	if (fp == 0) {
		puts("Error fp");
		exit(-4);
	}
	while (~fscanf(fp, "%s", buff)) {
		cnt++;
		t = rand() % cnt;
		if (t < n) {
			if (cnt <= n) {
				v.push_back(buff);
				if (cnt - 1 != t)
					swap(v[t], v[cnt - 1]);
			} else {
				v[t] = buff;
			}
		}
	}
	sort(v.begin(), v.end());
	fclose(fp);
	fp = fopen(save.c_str(), "w");
	if (fp == 0)
		exit(-3);
	cnt = 0, t = v.size();
	for (auto i: v) {
		fprintf(fp, "cp %s ./%s\n", i.c_str(), type.c_str());
		if (++cnt % 500 == 0)
			fprintf(fp, "echo copyed '('%d / %d')'\n", cnt, t);
	}
	fclose(fp);
}
int main(int argc, char **argv) {
	srand(time(0) + clock());
	if (argc != 2) {
		puts("please input 1 argument for number of pic");
		exit(-1);
	}
	sscanf(argv[1], "%d", &n);
	FILE *good_fp, *bad_fp;
	if ((good_fp = fopen("good_list.txt", "r")) == 0 || (bad_fp = fopen("bad_list.txt", "r")) == 0) {
		puts("Cannot open good_list or bad_list.");
		exit(-2);
	}
	work(good_fp, good, "good", "step_4_cp_good.sh");
	work(bad_fp, bad, "bad", "step_4_cp_bad.sh");
}
