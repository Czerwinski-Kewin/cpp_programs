#include <iostream>
#include <string>
#include <ranges>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	
	vector<int> numbers = { 0, 3, 3, 2, 1, 0, 1, 3 };	//2 0 2 4
	auto pominiecie = ranges::views::drop(numbers, 3);
	auto odwrot = ranges::views::reverse(pominiecie);
	auto pominiecie2 = ranges::views::drop(odwrot, 1);
	auto przeszktalcenie = ranges::views::transform(pominiecie2, [](int x) {return x * 2; });
	for (int c : przeszktalcenie)
		cout << c << " ";
	
}