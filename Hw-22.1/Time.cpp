#include "Time.h"

Time_::Time_()
{
	time_t now = time(0);          
	tm* ltm = localtime(&now);     

	hour = ltm->tm_hour;
	minutes = ltm->tm_min;
	seconds = ltm->tm_sec;

	format = true;
}

Time_::Time_(int hour, int minutes, int seconds, bool format)
{
	this->hour = hour;
	this->minutes = minutes;
	this->seconds = seconds;
	this->format = format;
}

Time_::Time_(const Time_& obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	this->format = obj.format;	
}

Time_& Time_::operator=(const Time_& obj)
{
	if (this != &obj) {
		hour = obj.hour;
		minutes = obj.minutes;
		seconds = obj.seconds;
		format = obj.format;
	}
	return *this;
}

Time_::~Time_()
{

}

void Time_::setHour(int hour)
{
	this->hour = hour;
}

int Time_::getHour() const
{
	return hour;
}

void Time_::setMinutes(int minutes)
{
	this->minutes = minutes;
}

int Time_::getMinutes() const
{
	return minutes;
}

void Time_::setSeconds(int seconds)
{
	this->seconds = seconds;
}

int Time_::getSeconds() const
{
	return seconds;
}

void Time_::setFormat(bool format)
{
	this->format = format;
}

bool Time_::getFormat() const
{
	return format;
}

bool Time_::valid() const
{
	return (hour >= 0 && hour < 24 &&
		minutes >= 0 && minutes < 60 &&
		seconds >= 0 && seconds < 60);
}

void Time_::tickTime()
{
	seconds++;

	if (seconds >= 60) {
		seconds = 0;
		minutes++;

		if (minutes >= 60) {
			minutes = 0;
			hour++;

			if (hour >= 24) {
				hour = 0;
			}
		}
	}
}

void Time_::untickTime()
{
	seconds--;

	if (seconds < 0) {
		seconds = 59;
		minutes--;

		if (minutes < 0) {
			minutes = 59;
			hour--;

			if (hour < 0) {
				hour = 23;
			}
		}
	}
}

void Time_::showTime() const
{
	if (format) {
		cout << (hour < 10 ? "0" : "") << hour << ":"
			<< (minutes < 10 ? "0" : "") << minutes << ":"
			<< (seconds < 10 ? "0" : "") << seconds << endl;
	}
	else {
		int h = hour % 12;
		if (h == 0) h = 12;

		cout << (h < 10 ? "0" : "") << h << ":"
			<< (minutes < 10 ? "0" : "") << minutes << ":"
			<< (seconds < 10 ? "0" : "") << seconds
			<< (hour >= 12 ? " PM" : " AM") << endl;
	}
}
