#include "Time_int.h"
#include "Time_float.h"
#pragma warning(disable: 4996)


int main(void)
{

	
	//time_clock();
	/*
		int_add_register();
		int_sub_register();
		int_mul_register();
		int_imul_register();
		int_div_register();
		int_idiv_register();
		int_neg_register();

		int_add_memory();
		int_sub_memory();
		int_mul_memory();
		int_imul_memory();
		int_div_memory();
		int_idiv_memory();
		int_neg_memory();*/

	/*int one = 0;
	int two = 25;
	__asm
	{
		add eax, ebx
		mov one, eax
	}
	printf("%d", one);*/
	/*system("pause");
	single_int_perfomance_register();
	*/
	/*int_mul_register();*/
	/*for (int i = 0; i != 100; i++)
	{
		float_add_memory();
		float_sub_memory();
	}*/

	/*float_add_register();
	float_sub_register();
	float_neg_register();
	float_mul_register();
	float_div_register();*/
	single_float_perfomance_memory();
	multicore_float_perfomance_memory();
	
}

