#include <iostream>
#include <random>
#include <cstdlib>
#include <intrin.h>
#include <Windows.h>
#include <thread>

#include <chrono>
using namespace std;
using namespace std::chrono;
int flag_thread = 0;
long long cnt_multicore1;
long long  cnt_multicore2;
long long cnt_multicore3;
long long cnt_multicore4;
long long cnt_multicore5;
long long cnt_multicore6;
long long cnt_multicore7;
int flag_thread_multicore = 0;






int random(int a)
{

	srand(time(0) + a);
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	if (time(0) % 2 == 0)
	{
		return static_cast<int>(rand() * fraction * (10000 - 1 + 1) + 0);
	}
	else
	{
		return static_cast<int>(rand() * fraction * (10000 - 1 + 1) + 0) * (-1);
	}
}

auto int_add_memory()
{
	int one = random(0);
	int two = random(one);
	int v = 0;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			mov ebx, two
			add eax, ebx
			mov v, eax


		}

	}

	auto end = high_resolution_clock::now();
	//printf("First number - %d ", one);
	//printf("Second number - %d ", two);
	//printf("Answer - %d ", v);



	printf("Type int(memory) ~ Operation add: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_sub_memory()
{
	int one = random(0);
	int two = random(one);
	int v = 0;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			mov ebx, two
			sub eax, ebx



		}

	}
	;
	auto end = high_resolution_clock::now();
	//printf("First number - %d ", one);
	//printf("Second number - %d ", two);
	//printf("Answer - %d ", v);
	printf("Type int(memory) ~ Operation sub: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_mul_memory()
{
	int one = random(0);
	if (one < 0)
	{
		one = abs(one);
	}
	int two = random(one);
	if (two < 0)
	{
		two = abs(two);
	}
	int v = 0;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			mov ebx, two
			mul ebx
			/*mov v, eax*/


		}

	}


	auto end = high_resolution_clock::now();
	/*printf("First number - %d ", one);
	printf("Second number - %d ", two);
	printf("Answer - %d ", v);*/
	printf("Type int(memory) ~ Operation mul: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_imul_memory()
{
	int one = random(0);
	int two = random(one);
	int v = 0;
	int v1 = 0;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			mov ebx, two
			imul eax, ebx
			/*	mov v, eax
				mov edx, v1*/


		}

	}
	/*printf("%d\n", v);
	printf("%d\n", v1);*/
	auto end = high_resolution_clock::now();
	//printf("First number - %d ", one);
	//printf("Second number - %d ", two);
	//printf("Answer - %d ",v);
	printf("Type int(memory) ~ Operation imul: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_div_memory()
{
	int one = random(0);
	int two = random(one);
	if (one < 0)
	{
		one = abs(one);
	}
	if (two < 0)
	{
		two = abs(two);
	}
	if (two == 0)
	{
		while (two == 0)
		{
			two = random(one);
		}
		if (two < 0)
		{
			two = abs(two);
		}
	}
	unsigned int v = 0;
	unsigned int v1 = 0;

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			mov ebx, two
			cdq
			div ebx
			/*mov v, eax
			mov v1, edx*/


		}

	}

	auto end = high_resolution_clock::now();
	/*printf("First number - %d ", one);
	printf("Second number - %d ", two);
	printf("Answer - Whole:%d, Remainder:%d ", v,v1);*/
	printf("Type int(memory) ~ Operation div: %E\n\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_idiv_memory()
{
	int one = random(0);

	int two = random(one);

	if (two == 0)
	{
		while (two == 0)
		{
			two = random(one);
		}

	}
	int v = 0;
	int v1 = 0;

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			mov ebx, two
			cdq
			idiv ebx
			/*	mov v, eax
				mov v1, edx*/


		}

	}

	auto end = high_resolution_clock::now();
	//“.к. остаток имеет тот же знак, что и делимое
	if (one < 0 && one / two > 0)
	{
		v1 = abs(v1);
	}
	/*printf("First number - %d ", one);
	printf("Second number - %d ", two);
	printf("Answer - Whole:%d, Remainder:%d ", v, v1);*/
	printf("Type int(memory) ~ Operation idiv: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_neg_memory()
{
	int one = random(0);

	int v = 0;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov eax, one
			neg eax
			/*mov v, eax*/



		}

	}

	auto end = high_resolution_clock::now();
	//printf("First number - %d ", one);
	//printf("Answer - %d ", v);
	printf("Type int(memory) ~ Operation neg: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

void mySleep()
{

	Sleep(1000);
	flag_thread = 1;
}
void mySleep_multicore()
{
	Sleep(1000);
	flag_thread_multicore = 1;
}
void int_add_memory_multicore()
{
	int one;
	int two;
	int v;
	while (flag_thread_multicore == 0)
	{
		one = random(0);
		two = random(one);
		_asm
		{
			mov eax, one
			mov ebx, two
			add eax, ebx
			mov v, eax
		}
		cnt_multicore1++;

	}
}
void int_sub_memory_multicore()
{
	int one;
	int two;
	int v;


	while (flag_thread_multicore == 0)
	{
		one = random(0);
		two = random(one);

		__asm
		{
			mov eax, one
			mov ebx, two
			sub eax, ebx



		}
		cnt_multicore2++;

	}
}
void int_mul_memory_multicore()
{
	int one;
	int two;
	int v;
	while (flag_thread_multicore == 0)
	{
		one = random(0);
		two = random(one);
		if (one < 0)
		{
			one = abs(one);
		}

		if (two < 0)
		{
			two = abs(two);
		}
		__asm
		{
			mov eax, one
			mov ebx, two
			mul ebx
			mov v, eax


		}
		cnt_multicore3++;
	}
}
void int_imul_memory_multicore()
{
	int one;
	int two;
	int v;
	int v1;

	while (flag_thread_multicore == 0)
	{
		one = random(0);
		two = random(one);

		__asm
		{
			mov eax, one
			mov ebx, two
			imul eax, ebx
			mov v, eax
			mov edx, v1


		}




		cnt_multicore4++;
	}
}
void int_div_memory_multicore()
{
	int one;
	int two;
	int v;
	int v1;
	while (flag_thread_multicore == 0)
	{
		one = random(0);
		two = random(one);
		if (one < 0)
		{
			one = abs(one);
		}
		if (two < 0)
		{
			two = abs(two);
		}
		if (two == 0)
		{
			while (two == 0)
			{
				two = random(one);
			}
			if (two < 0)
			{
				two = abs(two);
			}
		}

		__asm
		{
			mov eax, one
			mov ebx, two
			cdq
			div ebx
			mov v, eax
			mov v1, edx



		}




		cnt_multicore5++;
	}

}
void int_idiv_memory_multicore()
{
	int one;
	int two;
	int v;
	int v1;

	while (flag_thread_multicore == 0)
	{
		one = random(0);
		two = random(one);
		if (two == 0)
		{
			while (two == 0)
			{
				two = random(one);
			}

		}
		__asm
		{
			mov eax, one
			mov ebx, two
			cdq
			idiv ebx
			mov v, eax
			mov v1, edx


		}




		cnt_multicore6++;
	}
}
void int_neg_memory_multicore()
{
	int one;
	int v;
	while (flag_thread_multicore == 0)
	{
		one = random(0);


		__asm
		{
			mov eax, one
			neg eax
			mov v, eax


		}




		cnt_multicore7++;
	}
}
void single_int_perfomance_memory()
{
	unsigned long long cnt = 0;

	int one;
	int two;
	int v;
	int v1;

	thread mythread(mySleep);


	mythread.detach();
	while (flag_thread == 0)
	{
		one = random(0);
		two = random(one);
		__asm
		{
			mov eax, one
			mov ebx, two
			add eax, ebx
			mov v, eax


		}
		cnt += 1;
	}

	thread mythread1(mySleep);
	mythread1.detach();
	flag_thread = 0;
	while (flag_thread == 0)
	{
		one = random(0);
		two = random(one);
		__asm
		{
			mov eax, one
			mov ebx, two
			sub eax, ebx
			mov v, eax


		}
		cnt += 1;
	}
	thread mythread2(mySleep);
	mythread2.detach();
	flag_thread = 0;
	while (flag_thread == 0)
	{
		one = random(0);
		two = random(one);
		if (one < 0)
		{
			one = abs(one);
		}

		if (two < 0)
		{
			two = abs(two);
		}
		__asm
		{
			mov eax, one
			mov ebx, two
			mul ebx
			mov v, eax


		}
		cnt += 1;
	}
	thread mythread3(mySleep);
	mythread3.detach();
	flag_thread = 0;
	while (flag_thread == 0)
	{
		one = random(0);
		two = random(one);

		__asm
		{
			mov eax, one
			mov ebx, two
			imul eax, ebx
			mov v, eax
			mov edx, v1


		}




		cnt += 1;
	}

	thread mythread4(mySleep);
	mythread4.detach();
	flag_thread = 0;
	while (flag_thread == 0)
	{
		one = random(0);
		two = random(one);
		if (one < 0)
		{
			one = abs(one);
		}
		if (two < 0)
		{
			two = abs(two);
		}
		if (two == 0)
		{
			while (two == 0)
			{
				two = random(one);
			}
			if (two < 0)
			{
				two = abs(two);
			}
		}

		__asm
		{
			mov eax, one
			mov ebx, two
			cdq
			div ebx
			mov v, eax
			mov v1, edx



		}




		cnt += 1;
	}


	thread mythread5(mySleep);
	mythread5.detach();
	flag_thread = 0;
	while (flag_thread == 0)
	{
		one = random(0);
		two = random(one);
		if (two == 0)
		{
			while (two == 0)
			{
				two = random(one);
			}

		}
		__asm
		{
			mov eax, one
			mov ebx, two
			cdq
			idiv ebx
			mov v, eax
			mov v1, edx


		}




		cnt += 1;
	}

	thread mythread6(mySleep);
	mythread6.detach();
	flag_thread = 0;
	while (flag_thread == 0)
	{
		one = random(0);


		__asm
		{
			mov eax, one
			neg eax
			mov v, eax


		}




		cnt += 1;
	}
	printf("%d", cnt);








}
void multicore_int_perfomance_memory()
{
	long long cnt = 0;
	flag_thread_multicore = 0;
	cnt_multicore1 = 0;
	cnt_multicore2 = 0;
	cnt_multicore3 = 0;
	cnt_multicore4 = 0;
	cnt_multicore5 = 0;
	cnt_multicore6 = 0;
	cnt_multicore7 = 0;
	thread mythread_timer(mySleep_multicore);
	thread mythread1(int_add_memory_multicore);
	thread mythread2(int_sub_memory_multicore);
	thread mythread3(int_mul_memory_multicore);
	thread mythread4(int_imul_memory_multicore);
	thread mythread5(int_div_memory_multicore);
	thread mythread6(int_idiv_memory_multicore);
	thread mythread7(int_neg_memory_multicore);

	mythread_timer.join();
	mythread1.detach();
	mythread2.detach();
	mythread3.detach();
	mythread4.detach();
	mythread5.detach();
	mythread6.detach();
	mythread7.detach();
	cnt = cnt_multicore1 + cnt_multicore2 + cnt_multicore3 + cnt_multicore4 + cnt_multicore5 + cnt_multicore6 + cnt_multicore7;
	printf("%d", cnt);

}
auto int_add_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			add eax, ebx



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation add: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_sub_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			sub eax, ebx



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation sub: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_mul_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			mul ebx



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation mul: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_imul_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			imul eax, ebx



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation imul: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_div_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			mov ebx, 5
			cdq
			div ebx



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation div: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_idiv_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			mov ebx, 5
			cdq
			idiv ebx



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation idiv: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
auto int_neg_register()
{
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			neg eax



		}

	}

	auto end = high_resolution_clock::now();

	printf("Type int(register) ~ Operation neg: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
