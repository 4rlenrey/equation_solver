#include "../include/core.h"

void Eget_set::fill_vector(std::vector<std::string> &v,  std::string equation, const int start, int end, int x,std::unordered_set<char> se)
{
	for (int i = start; i < end; i++)
	{
		v[i] = Esolve::main(equation, x, se);
		x++;
	}
}

std::vector<std::string> Eget_set::main(std::string equation, const std::pair<int, int> &range, int &threads, const std::unordered_set<char> &se)
{
	//number of threads must be limited
	if (threads <= 0)
		threads = 0;
	else if (threads > 5)
		threads = 5;
	int range_th = range.second - range.first;
	std::vector<std::string> all(range_th);

	int leftover = range_th % threads;
	range_th -= leftover;
	range_th = range_th / threads; //range for a single thread
	int f_x = range.first; //x for a thread
	int start_filling = 0; //starting index for filling

	std::thread t[threads];

	for (int i = 0; i < threads; i++)
	{
		t[i] = std::thread(Eget_set::fill_vector, std::ref(all), equation, start_filling , (start_filling + range_th), f_x, se);
		start_filling += range_th;
		f_x += range_th;
	}
	for (int i = 0; i < threads; i++)
	{
		t[i].join();
	}
	while(leftover)
	{
		all[start_filling] = Esolve::main(equation, f_x, se);
		start_filling++;
		f_x++;
		leftover--;
	}
	return all;
}
