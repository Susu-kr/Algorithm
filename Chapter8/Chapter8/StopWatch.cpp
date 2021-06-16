#include "StopWatch.h"
#include <ctime>
StopWatch::StopWatch()
{
	StartTime = 0;
	EndTime = 0;
}

long long StopWatch::getElapsedTime()
{
	return EndTime - StartTime;
}

void StopWatch::start()
{
	StartTime = clock();
}

void StopWatch::stop()
{
	EndTime = clock();
}
