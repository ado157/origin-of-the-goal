//#include<iostream>
//#include<chrono>
//#include <thread>
//void printA(int value)
//{
//	if (value < 10)
//	{
//		std::cout << "A:000" << value << std::endl;
//	}
//	else if (10 <= value && value < 100)
//	{
//		std::cout << "A:00" << value << std::endl;
//	}
//	else if (100 <= value && value < 1000)
//	{
//		std::cout << "A:0" << value << std::endl;
//	}
//	else
//	{
//		std::cout << "A:" << value << std::endl;
//	}
//}
//void printB(int value)
//{
//	if (value < 10)
//	{
//		std::cout << "B:000" << value << std::endl;
//	}
//	else if (10 <= value && value < 100)
//	{
//		std::cout << "B:00" << value << std::endl;
//	}
//	else if (100 <= value && value < 1000)
//	{
//		std::cout << "B:0" << value << std::endl;
//	}
//	else
//	{
//		std::cout << "B:" << value << std::endl;
//	}
//}
//void CreateThread()
//{
//	using namespace std::chrono;
//	auto last = steady_clock::now();
//	int index = 0;
//	int A = 0;
//	int B = 1001;
//	while (index < 1000)
//	{
//
//		auto now = steady_clock::now();
//		if (duration_cast<milliseconds>(now - last).count() >= 200)
//		{
//			++A;
//			--B;
//			last = now;
//			printA(A);
//			printB(B);
//			index++;
//
//		}
//		//std::this_thread::sleep_for(milliseconds(1));
//	}
//
//}
//int main()
//{
//	CreateThread();
//}