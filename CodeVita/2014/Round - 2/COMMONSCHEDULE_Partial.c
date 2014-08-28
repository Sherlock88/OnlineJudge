#include <stdio.h>

#define FREE 1
#define BUSY 0

int slots[5001][1441];
char hhmm[6];

int convertToMinute(char* strTime)
{
	int minute = 0;
	minute = ((strTime[0] - '0') * 10 + (strTime[1] - '0')) * 60 + (((strTime[3] - '0') * 10 + (strTime[4] - '0')));
	return minute;
}

char* convertToHHMM(int min)
{
	int hour, minute;
	
	hour = min / 60;
	minute = min - (hour * 60);
	sprintf(hhmm, "%02d:%02d", hour, minute);
	return hhmm;
}

int main()
{
	int N, I, i, j, startMaxMinute, stopMaxMinute, startMinMinute, stopMinMinute, freeMinutes, maxFreeTime, minFreeTime, startMinute, stopMinute, freeVector[1441];
	char strStart[6], strStop[6];
	
	scanf("%d", &N);
	
	for(i = 1; i <= N; i++)
		for(j = 1; j <= 1440; j++)
			slots[i][j] = FREE;
	for(j = 1; j <= 1440; j++)
		freeVector[j] = FREE;
	
	scanf("%d", &I);
	while(I != -1)
	{
		scanf("%s %s", strStart, strStop);
		for(i = convertToMinute(strStart); i < convertToMinute(strStop); i++)
			slots[I][i] = BUSY;
		scanf("%d", &I);
	}
	
	maxFreeTime = 0;
	minFreeTime = 1440;
	
	for(i = 1; i <= N; i++)
	{
		freeMinutes = 0;
		for(j = 1; slots[i][j]; j++);
		startMinute = j;
		//startMinute = 0; j = 1;
		
		for(; j <= 1440; j++)
		{
			if(slots[i][j])
				freeMinutes++;
			else
			{
				stopMinute = j;
				if(maxFreeTime < freeMinutes)
				{
					maxFreeTime = freeMinutes;
					startMaxMinute = startMinute;
					stopMaxMinute = stopMinute;
				}
				if(minFreeTime > freeMinutes && freeMinutes)
				{
					minFreeTime = freeMinutes;
					startMinMinute = startMinute;
					stopMinMinute = stopMinute;
				}
				freeMinutes = 0;
				startMinute = j + 1;
			}
		}
	}
	
	printf("%s ", convertToHHMM(startMaxMinute));
	printf("%s\n", convertToHHMM(stopMaxMinute));
	printf("%s ", convertToHHMM(startMinMinute));
	printf("%s \n", convertToHHMM(stopMinMinute));
	
	/////////////////////////////////////////////////////////////////////////////////
	
	for(i = 1; i <= N; i++)
		for(j = 1; j <= 1440; j++)
			freeVector[j] &= slots[i][j];
	
	freeMinutes = 0;
	maxFreeTime = 0;
	for(j = 1; freeVector[j]; j++);
	startMinute = j;
	//startMinute = 0; j = 1;
	
	for(; j <= 1440; j++)
	{
		if(freeVector[j])
			freeMinutes++;
		else
		{
			stopMinute = j;
			if(maxFreeTime < freeMinutes)
			{
				maxFreeTime = freeMinutes;
				startMaxMinute = startMinute;
				stopMaxMinute = stopMinute;
			}
			freeMinutes = 0;
			startMinute = j + 1;
		}
	}
	
	printf("%s ", convertToHHMM(startMaxMinute));
	printf("%s\n", convertToHHMM(stopMaxMinute));
	
	return 0;
}