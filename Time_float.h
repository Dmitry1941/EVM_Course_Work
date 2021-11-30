#pragma once
#include <iostream>
#include <random>
#include <cstdlib>
#include <intrin.h>
#include <Windows.h>
#include <thread>

#include <chrono>

using namespace std;
using namespace std::chrono;
int flag_thread_float = 0;
long long cnt_multicore_float1;
long long  cnt_multicore_float2;
long long cnt_multicore_float3;
long long cnt_multicore_float4;
long long cnt_multicore_float5;
long long cnt_multicore_float6;
long long cnt_multicore_float7;
int flag_thread_multicore_float = 0;
void mySleep_float()
{

	Sleep(1000);
	flag_thread_float = 1;
}
void mySleep_multicore_float()
{
	Sleep(1000);
	flag_thread_multicore_float = 1;
}
double random_float(double a)
{
	srand(time(0) + a);
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	if (time(0) % 2 == 0)
	{
		return static_cast<double>(rand() * fraction * (10000.0000 - 1.0000 + 1.0000) + 0.0000);
	}
	else
	{
		return static_cast<double>(rand() * fraction * (10000.0000 - 1.0000 + 1.0000) + 0.0000) * (-1.0000);
	}
}
auto float_add_memory()
{
	float one = random_float(0);
	float two = random_float(one);
	float v;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			/* FLD  [one]

			 FST [edi]
			 mov v, edi*/
			 /*mov eax, one
			 mov ebx, two
			 fadd
			 mov v, eax*/
			 //finit
			fld one
			fld two
			fadd
			fstp v


		}

	}

	auto end = high_resolution_clock::now();
	printf("First number - %f ", one);
	printf("Second number - %f ", two);
	printf("Answer - %f ", v);



	printf("Type float(memory) ~ Operation add: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_sub_memory()
{
	float one = random_float(0);
	float two = random_float(one);
	float v;
	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			fld one
			fld two
			fsub
			fstp v


		}

	}

	auto end = high_resolution_clock::now();
	printf("First number - %f ", one);
	printf("Second number - %f ", two);
	printf("Answer - %f ", v);



	printf("Type float(memory) ~ Operation sub: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_mul_memory()
{
	float one = random_float(0);
	float two = random_float(one);
	float v;

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			fld one
			fld two
			fmul
			fstp v


		}

	}

	auto end = high_resolution_clock::now();
	printf("First number - %f ", one);
	printf("Second number - %f ", two);
	printf("Answer - %f ", v);



	printf("Type float(memory) ~ Operation mul: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_div_memory()
{
	float one = random_float(0);
	float two = random_float(one);

	if (two == 0)
	{
		while (two == 0)
		{
			two = random_float(one);
		}

	}
	float v = 0;

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			fld one
			fld two
			fdiv
			fstp v


		}

	}

	auto end = high_resolution_clock::now();
	printf("First number - %f ", one);
	printf("Second number - %f ", two);
	printf("Answer - %f ", v);



	printf("Type float(memory) ~ Operation div: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_neg_memory()
{
	float one = random_float(0);
	float v = 0;

	auto start = high_resolution_clock::now();
	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{

			fld one

			fchs
			fstp v


		}

	}

	auto end = high_resolution_clock::now();
	printf("First number - %f ", one);

	printf("Answer - %f ", v);



	printf("Type float(memory) ~ Operation neg: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_add_register()
{

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			/* FLD  [one]

			 FST [edi]
			 mov v, edi*/
			 /*mov eax, one
			 mov ebx, two
			 fadd
			 mov v, eax*/
			 //finit

			fadd



		}

	}

	auto end = high_resolution_clock::now();






	printf("Type float(register) ~ Operation add: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_sub_register()
{

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			/* FLD  [one]

			 FST [edi]
			 mov v, edi*/
			 /*mov eax, one
			 mov ebx, two
			 fadd
			 mov v, eax*/
			 //finit

			fsub



		}

	}

	auto end = high_resolution_clock::now();






	printf("Type float(register) ~ Operation sub: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_mul_register()
{

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			/* FLD  [one]

			 FST [edi]
			 mov v, edi*/
			 /*mov eax, one
			 mov ebx, two
			 fadd
			 mov v, eax*/
			 //finit

			fmul



		}

	}

	auto end = high_resolution_clock::now();






	printf("Type float(register) ~ Operation mul: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_div_register()
{

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			/* FLD  [one]

			 FST [edi]
			 mov v, edi*/
			 /*mov eax, one
			 mov ebx, two
			 fadd
			 mov v, eax*/
			 //finit

			fdiv



		}

	}

	auto end = high_resolution_clock::now();






	printf("Type float(register) ~ Operation div: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}

auto float_neg_register()
{

	auto start = high_resolution_clock::now();

	for (int i = 0; i != 100000000; i++)
	{


		__asm
		{
			/* FLD  [one]

			 FST [edi]
			 mov v, edi*/
			 /*mov eax, one
			 mov ebx, two
			 fadd
			 mov v, eax*/
			 //finit

			fchs



		}

	}

	auto end = high_resolution_clock::now();






	printf("Type float(register) ~ Operation neg: %E\n", ((end - start) / 100000000).count());

	return ((end - start) / 100000000).count();
}
void single_float_perfomance_memory()
{
	unsigned long long cnt = 0;

	float one;
	float two;
	float v;
	int v1;

	thread mythread(mySleep_float);


	mythread.detach();
	while (flag_thread_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		__asm
		{
			fld one
			fld two
			fadd
			fstp v


		}
		cnt += 1;
	}

	thread mythread1(mySleep_float);
	mythread1.detach();
	flag_thread_float = 0;
	while (flag_thread_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		__asm
		{

			fld one
			fld two
			fsub
			fstp v


		}
		cnt += 1;
	}
	thread mythread2(mySleep_float);
	mythread2.detach();
	flag_thread_float = 0;
	while (flag_thread_float == 0)
	{
		one = random_float(0);
		two = random_float(one);

		__asm
		{
			fld one
			fld two
			fmul
			fstp v


		}
		cnt += 1;
	}
	thread mythread3(mySleep_float);
	mythread3.detach();
	flag_thread_float = 0;
	while (flag_thread_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		if (two == 0)
		{
			while (two == 0)
			{
				two = random_float(one);
			}

		}
		__asm
		{
			fld one
			fld two
			fdiv
			fstp v


		}




		cnt += 1;
	}

	thread mythread4(mySleep_float);
	mythread4.detach();
	flag_thread_float = 0;
	while (flag_thread_float == 0)
	{
		one = random_float(0);


		__asm
		{

			fld one

			fchs
			fstp v


		}




		cnt += 1;
	}


	thread mythread5(mySleep_float);
	mythread5.detach();
	flag_thread_float = 0;
	while (flag_thread_float == 0)
	{
		one = random_float(0);
		two = random_float(one);

		__asm
		{
			fld one
			fld two
			fmul
			fstp v


		}
		cnt += 1;





	}

	thread mythread6(mySleep_float);
	mythread6.detach();
	flag_thread_float = 0;
	while (flag_thread_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		if (two == 0)
		{
			while (two == 0)
			{
				two = random_float(one);
			}

		}
		__asm
		{
			fld one
			fld two
			fdiv
			fstp v


		}




		cnt += 1;
	}
	printf("%d\n", cnt);








}


void float_add_memory_multicore()
{
	float one;
	float two;
	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		_asm
		{
			fld one
			fld two
			fadd
			fstp v
		}
		cnt_multicore_float1++;

	}
}
void float_sub_memory_multicore()
{
	float one;
	float two;
	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		_asm
		{
			fld one
			fld two
			fsub
			fstp v
		}
		cnt_multicore_float2++;

	}
}
void float_mul_memory_multicore()
{
	float one;
	float two;
	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		_asm
		{
			fld one
			fld two
			fmul
			fstp v
		}
		cnt_multicore_float3++;

	}
}

void float_div_memory_multicore()
{
	float one;
	float two;
	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		if (two == 0)
		{
			while (two == 0)
			{
				two = random_float(one);
			}

		}
		_asm
		{
			fld one
			fld two
			fdiv
			fstp v
		}
		cnt_multicore_float4++;

	}
}

void float_neg_memory_multicore()
{
	float one;

	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);

		_asm
		{
			fld one

			fchs
			fstp v
		}
		cnt_multicore_float5++;

	}
}
void float_mul2_memory_multicore()
{
	float one;
	float two;
	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		_asm
		{
			fld one
			fld two
			fmul
			fstp v
		}
		cnt_multicore_float6++;

	}
}


void float_div2_memory_multicore()
{
	float one;
	float two;
	float v;
	while (flag_thread_multicore_float == 0)
	{
		one = random_float(0);
		two = random_float(one);
		if (two == 0)
		{
			while (two == 0)
			{
				two = random_float(one);
			}

		}
		_asm
		{
			fld one
			fld two
			fdiv
			fstp v
		}
		cnt_multicore_float7++;

	}
}

void multicore_float_perfomance_memory()
{
	long long cnt = 0;
	flag_thread_multicore_float = 0;
	cnt_multicore_float1 = 0;
	cnt_multicore_float2 = 0;
	cnt_multicore_float3 = 0;
	cnt_multicore_float4 = 0;
	cnt_multicore_float5 = 0;
	cnt_multicore_float6 = 0;
	cnt_multicore_float7 = 0;
	thread mythread_timer(mySleep_multicore_float);
	thread mythread1(float_add_memory_multicore);
	thread mythread2(float_sub_memory_multicore);
	thread mythread3(float_mul_memory_multicore);
	thread mythread4(float_mul2_memory_multicore);
	thread mythread5(float_div_memory_multicore);
	thread mythread6(float_div2_memory_multicore);
	thread mythread7(float_neg_memory_multicore);

	mythread_timer.join();
	mythread1.detach();
	mythread2.detach();
	mythread3.detach();
	mythread4.detach();
	mythread5.detach();
	mythread6.detach();
	mythread7.detach();
	cnt = cnt_multicore_float1 + cnt_multicore_float2 + cnt_multicore_float3 + cnt_multicore_float4 + cnt_multicore_float5 + cnt_multicore_float6 + cnt_multicore_float7;
	printf("%d\n", cnt);

}