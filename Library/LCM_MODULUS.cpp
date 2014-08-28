/* 
* LCM Modulus calculation by factorization method
* The program makes use of Sieve of Eratosthenes to factor numbers in a given range. 
* Unlike ordinary sieves, the sieve grid stores the least primer factor for a composite number.
* If the number is prime itself, the sieve stores zero.
* The method implemented is illustrated in Wikipedia page (A method using a table): 
* http://en.wikipedia.org/wiki/Least_common_multiple#Computing_the_least_common_multiple
* The program exploits the fact that MODULUS(%) operation is distributive over Multiplication(*)
* i.e. (a * b) % c = (a % c) * (b % c)
* After iteratively factoring all the numbers, highest indices for each of the prime factors
* are collected in a Map. To compute LCM, each factor is raised to required power and multiplied together.
* At each step, if the product happens to exceed LCMMOD quantity, Modulus is taken to shave it off.
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define SIEVELIMIT 317
#define SIEVERANGE 100000
#define LCMMOD 1000000007

unsigned long sieve[SIEVERANGE + 1];

/* Accelerates sieve calculation by pre-computing squares of the numbers in [1,...SIEVELIMIT] */
unsigned long inner[] = {0,0,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841,900,961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,8281,8464,8649,8836,9025,9216,9409,9604,9801,10000,10201,10404,10609,10816,11025,11236,11449,11664,11881,12100,12321,12544,12769,12996,13225,13456,13689,13924,14161,14400,14641,14884,15129,15376,15625,15876,16129,16384,16641,16900,17161,17424,17689,17956,18225,18496,18769,19044,19321,19600,19881,20164,20449,20736,21025,21316,21609,21904,22201,22500,22801,23104,23409,23716,24025,24336,24649,24964,25281,25600,25921,26244,26569,26896,27225,27556,27889,28224,28561,28900,29241,29584,29929,30276,30625,30976,31329,31684,32041,32400,32761,33124,33489,33856,34225,34596,34969,35344,35721,36100,36481,36864,37249,37636,38025,38416,38809,39204,39601,40000,40401,40804,41209,41616,42025,42436,42849,43264,43681,44100,44521,44944,45369,45796,46225,46656,47089,47524,47961,48400,48841,49284,49729,50176,50625,51076,51529,51984,52441,52900,53361,53824,54289,54756,55225,55696,56169,56644,57121,57600,58081,58564,59049,59536,60025,60516,61009,61504,62001,62500,63001,63504,64009,64516,65025,65536,66049,66564,67081,67600,68121,68644,69169,69696,70225,70756,71289,71824,72361,72900,73441,73984,74529,75076,75625,76176,76729,77284,77841,78400,78961,79524,80089,80656,81225,81796,82369,82944,83521,84100,84681,85264,85849,86436,87025,87616,88209,88804,89401,90000,90601,91204,91809,92416,93025,93636,94249,94864,95481,96100,96721,97344,97969,98596,99225,99856,100489};


void sieveofEratosthenes()
{
	unsigned long i, j;
	sieve[1] = 1;
	for(i = 2; i <= SIEVELIMIT; i++)
		if(!sieve[i])
			for (j = inner[i]; j <= SIEVERANGE; j += i)
				if(!sieve[j])
					sieve[j] = i;
}


unsigned long lcmModulo(unsigned long numbers[], unsigned long numberCount)
{
	unsigned long long lcmMod = 1;
	unsigned long lastDistinctNumber = 0, currentNumber, factor, lastFactor, factorCount, i, j;
	map <unsigned long, unsigned long> lcmFactors;
	map <unsigned long, unsigned long>::iterator itrFactors;
	
	sort(numbers, numbers + numberCount);
	for(i = 1, j = 0; i < numberCount; i++)
	{ 
		currentNumber = numbers[i];
		if(lastDistinctNumber != currentNumber)
		{
			lastDistinctNumber = currentNumber;
			numbers[++j] = currentNumber;
		}
	}
	numberCount = ++j;
	
	for(i = 0; i < numberCount; i++)
	{
		currentNumber = numbers[i];
		factorCount = 0;
		factor = sieve[currentNumber];
		lastFactor = factor;
		while(currentNumber != 1)
		{
			factor = sieve[currentNumber];
			if(factor)
				currentNumber /= factor;
			else
			{
				factor = currentNumber;
				currentNumber = 1;
			}
				
			if(factor != lastFactor)
			{
				if(lcmFactors[lastFactor] < factorCount)
					lcmFactors[lastFactor] = factorCount;
				lastFactor = factor;
				factorCount = 1;
			}
			else
				factorCount++;
		}		
		lcmFactors[factor] = factorCount;
	}
	
	for(itrFactors = lcmFactors.begin(); itrFactors != lcmFactors.end(); itrFactors++)
	{
		unsigned long factor = itrFactors->first, index = itrFactors->second;
		for(j = 0; j < index; j++)
		{
			lcmMod *= (unsigned long long)factor;
			if(lcmMod > LCMMOD)
				lcmMod %= LCMMOD;
		}
	}
	return lcmMod;
}


void startInnerLoop(unsigned long sieveLimit)
{
	/* Populate inner[] array from the output of this method */
	unsigned long i, lcmMod;
	cout << "unsigned long inner[] = {0,0,";
	for(i = 2; i <= sieveLimit; i++)
		cout << i * i << ',';
	cout << "\b};\n";
}


/* Driver routine */
int main()
{
	unsigned long n = 100000, sieveLimit;
	
	/* Test Cases */
	//unsigned long numbers[] = { 10001, 10001, 526, 5264, 263, 263, 526, 569 };
	//unsigned long numbers[] = { 1, 12, 15, 18 };
	unsigned long numbers[] = { 16007,16033,16061,16273,16369,16361 };	// Result: 746141104
	
	/* Calculation of MACRO values and generation of inner[] array */
	sieveLimit = (unsigned long)(ceil(sqrt(n)));
	startInnerLoop(sieveLimit);
	sieveofEratosthenes();
	
	cout << "SIEVERANGE: " << n << endl;
	cout << "SIEVELIMIT: " << sieveLimit << endl;
	cout << "LCMMOD: " << lcmModulo(numbers, sizeof(numbers)/sizeof(unsigned long));
	
	return 0;
}