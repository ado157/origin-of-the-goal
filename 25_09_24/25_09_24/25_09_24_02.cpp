#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
class Person {
public:
	Person(string name, int score) {
		this->m_Name = name;
		this->m_Score = score; 
	}
	string m_Name;
	int m_Score;
};
void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_Score = avg;
	}
}
void createPerson(vector<Person>& v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name = name + nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}
void test1() {
	vector<Person>v;
	createPerson(v);
	setScore(v);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名:" << (*it).m_Name << "分数：" << (*it).m_Score << endl;

	}
}

int main() {
	test1();
	return 0;

}