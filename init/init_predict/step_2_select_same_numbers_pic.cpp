#include <bits/stdc++.h>
using namespace std;
char buff[1024];
vector<string> good;
vector<string> bad;
///data1/pic/Tumor_002/img/Tumor_002_0
long long mask = (1 << 20) - 1;
int id;
int main() {
	srand(time(0) + clock());
	FILE *fp = fopen("img_list.txt", "r");
	if (fp == 0) {
		puts("No img_list.txt!");
		exit(-1);
	}
	long long cnt = 0, cnt_good = 0, cnt_bad = 0, x, y, tmp;
	while (~fscanf(fp, "%s", buff)) {
		sscanf(buff, "/data1/pic/Tumor_%d/img/Tumor_%*d_%lld_", &id, &x);
		if (id == 99 || id == 83)
			continue;
		tmp = id % 10;
		if (tmp == 3 || tmp == 7 || tmp == 9 || tmp == 1);
		else {
			continue;
		}
		if (x == 0) {
			good.push_back(buff);
			cnt_good++;
			y = rand() % cnt_good;
			if (y != cnt_good - 1)
				swap(good[y], good[cnt_good - 1]);
		}
		if (x == 100) {
			bad.push_back(buff);
			cnt_bad++;
		}	

		if ((++cnt & mask) == 0) {
			printf("---- cnt = %lld, cnt_good = %lld, cnt_bad = %lld\n", cnt, cnt_good, cnt_bad);
			fflush(stdout);
		}
		if (cnt_good - cnt_bad >= 200000) {
			puts("make it balance...");
			good.resize(cnt_good -= 100000);
			printf("cnt_good = %lld, cnt_bad = %lld\n", cnt_good, cnt_bad);
			fflush(stdout);
		}
	}
	good.resize(cnt_good = cnt_bad);
	printf("cnt_good = cnt_bad = %lld\n", cnt_good);
	fflush(stdout);
	sort(good.begin(), good.end());
	sort(bad.begin(), bad.end());
	fclose(fp);
	if ((fp = fopen("good_list.txt", "w")) == 0) 
		exit(-1);
	for (auto i: good)
		fprintf(fp, "%s\n", i.c_str());
	fclose(fp);
	if ((fp = fopen("bad_list.txt", "w")) == 0) 
		exit(-1);
	for (auto i: bad)
		fprintf(fp, "%s\n", i.c_str());
	return 0;
}
