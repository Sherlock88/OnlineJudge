/*
* http://www.geeksforgeeks.org/implement-itoa/
*
* itoa function converts integer into null-terminated string. It can convert negative numbers too.
* The standard definition of itoa function is give below:-
*
* char* itoa(int num, char* buffer, int base)
*
* The third parameter base specify the conversion base. For example:- if base is 2,
* then it will convert the integer into its binary compatible string or if base is 16, 
* then it will create hexadecimal converted string form of integer number.
*
* If base is 10 and value is negative, the resulting string is preceded with a minus sign (-).
* With any other base, value is always considered unsigned.
*
* Reference: http://www.cplusplus.com/reference/cstdlib/itoa/?kw=itoa
*
* Examples:
*
*  itoa(1567, str, 10) should return string "1567"
*  itoa(-1567, str, 10) should return string "-1567"
*  itoa(1567, str, 2) should return string "11000011111"
*  itoa(1567, str, 16) should return string "61f"
* Individual digits of the given number must be processed and their corresponding characters must 
* be put in the given string. Using repeated division by the given base, we get individual digits
* from least significant to most significant digit. But in the output, these digits are needed 
* in reverse order. Therefore, we reverse the string obtained after repeated division and return it.
*/


#include <stdio.h>
#include <stdbool.h>


char* itoa(int num, char* buffer, int base)
{
	int c = 0, i, rem;
	bool isNegative = false;
	char t;
	
	if(num == 0)
		buffer[c++] = '0';
	
	if(num < 0)
	{
		if(base == 10)
		{
			isNegative = true;
			num = -num;
		}
		else
			return NULL;
	}
	
	while(num != 0)
	{
		rem = num % base;
		buffer[c++] =  (rem <= 9) ? rem + '0' : rem - 10 + 'A';
		num /= base;
	}
	
	if(isNegative)
		buffer[c++] = '-';
		
	for(i = 0; i <= c/2-1; i++)
	{
		t = buffer[i];
		buffer[i] = buffer[c - i - 1];
		buffer[c - i - 1] = t;
	}
	
	buffer[c] = '\0';
	return buffer;
}


int main()
{
	int num, base;
	char buffer[10];
	
	printf("Enter Integer: ");
	scanf("%d", &num);
	printf("Enter Base: ");
	scanf("%d", &base);
	printf("itoa(%d): %s\n", num, itoa(num, buffer, base));
	
	return 0;
}