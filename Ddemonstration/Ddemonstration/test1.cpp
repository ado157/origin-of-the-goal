#include<iostream>
#include<vector>
int main()
{
	int head = 0, tail = 5;
	std::vector<char> q = {'p','r','i','n','t'};
	while (head < tail)
	{
		if (q.size() >= 20)break;
		if (head %3==0)
		{
			std::cout << q[head]<<std::endl;
		}
		else
		{
			q.push_back(q[head]);
			++tail;
		}
		++head;
	}
}