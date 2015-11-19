#include<stdio.h>
#include"pi_funs.h"
#include"adjust.c"
#include"timer.c"
#include<math.h>

/* Here we use the two series found in pi_funs.h to find the number of terms needed
 * to ensure the absolute error of the calculated value of pi is below 1e-6.
 * The number of terms necessary for each series is recorded, and used to 
 * calculate the time needed for each function to obtain pi to within the 1e-6
 * error. 
*/
double pi_bbp (int n);
double pi_leibniz (int n);
void timer_start (void);
double timer_stop (void);

int main (void)
{
    int n;
    double abserr_l = 1., pi_l;

    printf ("\n              --Leibniz Series--\n\n");
    printf ("  -Iterations-      -Pi-              -Error-\n");


    for (n = 1; abserr_l > 0.000001; n *= 2)    // n doubles for each iteration as long as the absolute error is still greater than 1e-6.
    {
        pi_l = pi_leibniz (n);  // The function which performs the Leibniz series. 
        abserr_l = fabs (M_PI - pi_l);  // Definition of absolute error.
        printf ("%8d     %15.10f    %15.10f\n", n, pi_l, abserr_l);
    }

    printf ("\n         -Leibniz Iterations = %d\n\n", n / 2);


    int m;
    double abserr_b = 1., pi_b;

    printf ("        --Bailey-Borwein-Plouffe Series--\n\n");
    printf ("  -Iterations-      -Pi-              -Error-\n");


    for (m = 1; abserr_b > 0.000001; m *= 2)    // m doubles for each iteration, as above with Leibniz series. 
    {
        pi_b = pi_bbp (m);      // The function which performs the Bailey-Borwein-Plouffe series.
        abserr_b = fabs (M_PI - pi_b);  // Definition of absolute error.
        printf ("%8d     %15.10f    %15.10f\n", m, pi_b, abserr_b);
    }


    printf ("         -BBP Iterations = %d\n", m / 2);




    int count = 1000, l;        //count is the number of times the series will be evaluated.
    double time, tleibniz, tmin = 1., tmax = 2.;        // The range of total times needed to process the number of series evaluations is between 1 and 2 seconds.

    printf ("\n             --Leibniz Series Timing--\n");
    printf ("   -Time/count-          -Time-            -Count-\n");


    do
    {
        timer_start ();         // The timer is started.
        for (l = 0; l < count; l++)     // The series is evaluated "count" times. 
        {
            pi_leibniz (n / 2); // n/2 is the value for which the series obtained a value within 1e-6 error of the actual value of pi.
        }
        time = timer_stop ();   // The timer is stopped.
        tleibniz = time / count;        // The time per function call is calculated by dividing the total time by the number of times the function was called.
        printf (" %10.2f usec     %10.6f sec    %10d\n", tleibniz * 1.e6,
            time, count);
        count = adjust_rep_count (count, time, tmin, tmax);     // The count value is adjusted.
    }
    while ((time > tmax) || (time < tmin));     // This repeats until the total time is within the required range.



    printf ("        -Leibniz time = %fusec\n\n", tleibniz * 1.e6);

    printf ("       --Bailey-Borwein-Plouffe Series Timing--\n\n");
    printf ("   -Time/count-          -Time-            -Count-\n");
    int countbbp = 1000;
    int p;
    double tbbp, timebbp;


    do
    {
        timer_start ();         // The timer is started.
        for (p = 0; p < countbbp; p++)  // The function is called "countbbp" times.
        {
            pi_bbp (m / 2);     // m/2 is the value for which the function obtained a value within 1e-6 error of the value of pi.
        }
        timebbp = timer_stop ();        // The timer is stopped.
        tbbp = timebbp / countbbp;      // The time per function call is calculated as the total time divided by the number of function calls.
        printf (" %10.2f usec     %10.6f sec    %10d\n", tbbp * 1.e6, timebbp,
            countbbp);
        countbbp = adjust_rep_count (countbbp, timebbp, tmin, tmax);    // The number of function calls "countbbp" is adjusted. 
    }
    while ((timebbp > tmax) || (timebbp < tmin));       // This is repeated until the total time is within the desired range.



    printf ("       -bbp time = %f usec\n", tbbp * 1.e6);

    printf ("\n      Time Ratio Leibniz : Bailey-Borwein-Plouffe:\n");

    printf ("                   %f\n", tleibniz / tbbp);        // The ratio of times per function call for the leibniz series and BBP series is printed.

    return 0;
}
