#include <stdio.h>
#include <stdlib.h>

int get_user_input_distance(double* distance);
/*
PROMISES:
The user will input a distance and the function will determine if the
input is a valid positive double number type. If it is, it will return a 1, if not it 
will return a 0. The value returned will then be checked in the main function
in a loop where if a 1 is returned, the program will continue on to the next task
and if 0, will cause the function to be called again until the value entered returns
a 1. Once the value is returned as a 1, the user input will be sent to the distance variable.
*/
int get_user_input_speed(double* dspeed);
/*
PROMISES:
The user will input a speed and the function will determine if the
input is a valid positive double number type. If it is, it will return a 1, if not it 
will return a 0. The value returned will then be checked in the main function
in a loop where if a 1 is returned, the program will continue on to the next task
and if a 0 is returned, will cause the function to be called again until the value entered returns
a 1. Once the value is returned as a 1, the user input will be sent to the distance variable.
*/
void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes);
/*
REQUIRES:
The function will take a positive distance and a positive speed which were
entered by the user.
PROMISES:
The function will take the distance and speed provided and it will calculate 
the time it will take to travel the distance in hours and minutes.
*/
void display_info( double distance, double speed, double hour, double minutes);
/*
REQUIRES:
The function takes a distance, a speed, and a time in hours and seconds. The distance
and speed were entered by the user and the time was calculated from the function
travel_time_hours_and_minutes.
PROMISES:
The function will display the user's distance and speed that were previously
input and will also display the calculated time the trip will take in hours
and minutes.

*/
int main (void)
{
	char distanceBufferClear;
	char speedBufferClear;
	int isDistanceValid;
	int isSpeedValid;
	double distance;
	double speed;
	double hours;
	double minutes;

	while(1) 
	{
		isDistanceValid = get_user_input_distance(&distance);
		if (isDistanceValid == 1 && distance > 0)
			break;
		else
		{
			printf("ERROR: INPUT IVALID. PLEASE ENTER A POSITIVE NUMBER.\n");
			do
			{
				distanceBufferClear=getchar();
			}while(distanceBufferClear!= '\n' && distanceBufferClear != EOF);
		}
	}
	
	while(1)
	{
		isSpeedValid=get_user_input_speed(&speed);
		if (isSpeedValid == 1 && speed >0)
			break;
		else
		{
			printf("ERROR: INPUT IVALID. PLEASE ENTER A POSITIVE NUMBER.\n");
			do
			{
				speedBufferClear=getchar();
			}while(speedBufferClear!= '\n' && speedBufferClear != EOF);
		}
	}
	
	travel_time_hours_and_minutes(distance,speed,&hours,&minutes);
	display_info(distance,speed,hours,minutes);
	return 0;
}

int get_user_input_distance(double* distance)
{
	char c;
	printf("Please enter the travel distance in km: ");
	scanf("%lf",distance);
	c=fgetc(stdin);
	if(c != '\n')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
	
int get_user_input_speed(double* speed)
{
	char d;
	printf("Now enter the vehicle's average speed (km/hr): ");
	scanf("%lf",speed);
	d=fgetc(stdin);
	if(d != '\n' || d == '-')
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void travel_time_hours_and_minutes(double distance, double speed, double *hours, double *minutes)
{
	*hours=((int)(distance/speed))/1;
	*minutes=((distance/speed)*60)-(*hours*60);
}

void display_info( double distance, double speed, double hour, double minutes)
{
	printf("You have travelled %.2f (km) with a speed of %.2f (km/h) in %.2f hour(s) and %.2f minute(s).",distance,speed,hour,minutes);
}	