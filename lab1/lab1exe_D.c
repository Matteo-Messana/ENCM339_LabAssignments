/*
*  lab1exe_D.c
*  ENCM 339 - Fall 2017 Lab 1, exercise D
*  Completed by: Matteo Messana
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.8   /* gravitation acceleration 9.8 m/s^2 */
#define PI 3.141592654

void create_table(double v);

/*REQUIRES a positive numerical value for the velocity, v
  for the projectile's motion.
  PROMISES a table with entries from an angle
  of 0 to 90, showing both the distance travelled by 
  the projectile and the time it took to travel based 
  on the velocity given.*/
double Projectile_travel_time(double a, double v);
/*REQUIRES an angle from 0 to 90 degrees that will be converted to radians
  and a positive velocity.
  PROMISES a calculated value for the time the projectile 
  took to travel by using the angle from the horizon from 0 to 90 degrees as well 
  as an initial velocity.*/
double Projectile_travel_distance(double a, double v);
/*REQUIRES an angle from 0 to 90 degrees 
  that will be converted to radians
  and a positive velocity.
  PROMISES the calculated value of the distance 
  travelled by the projectile from an initial positive velocity and
  an angle from the horizon from 0 to 90 degrees.
*/
double degree_to_radian(double d);
/*REQUIRES an angle from 0 to 90 degrees.
  PROMISES a conversion of the angle provided
  from degrees to radians.
*/

int main(void)
{
    int n;
    double velocity; 
    
    printf ("please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity); 
    
    return 0;
}

double Projectile_travel_time(double a, double v)
{
	double theta = degree_to_radian(a);
	double t = (2*v*sin(theta))/G;
	return t;
}

double Projectile_travel_distance(double a, double v)
{
	double theta = degree_to_radian(a);
	double d = (pow(v,2)*sin(2*theta))/G;
	return d;
}

double degree_to_radian(double d)
{
	double convert = d*(PI/180);
	return convert;
}

void create_table(double v)
{
	printf("Angle		t		d\n(deg)		(sec)		(m)\n");
	for(double i=0;i<=90;i+=5)
	{
		double distance = Projectile_travel_distance(i,v);
		double time = Projectile_travel_time(i,v);
		printf("%lf	%lf	%lf\n", i,time,distance);
	}
}



/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */

