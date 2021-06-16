#pragma once
#ifndef STOPWATCH_H_
#define STOPWATCH_H_

class StopWatch
{
private:
	long long StartTime;
	long long EndTime;

public:
	StopWatch();
	long long getStartTime() const { return StartTime; }
	long long getEndTime() const { return EndTime; }
	long long getElapsedTime();
	void start();
	void stop();
};

#endif // !STOPWATCH_H_
