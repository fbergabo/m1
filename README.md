Filip Bergabo PHYS 2200 Midterm Project 1

In this project, the Leibniz series and the Bailey-Borwein-Plouffe series are both used to estimate the value of pi. 
First, each series is calculated for an increasing number of terms until both series obtain a value that is within 1e-6 
of the actual value of pi. The terms needed to achieve this level of accuracy for each series is recorded. Each series 
is then timed to compare the speed at which each series obtains this level of accuracy. This is done by allowing the 
two functions to evaluate the two series several times until the total time necessary is between 1 and 2 seconds. The
total time is then divided by the number of times each function was called, to find the average time needed to compute
each function. The average time needed for each function are then compared as a ratio in order to find which series 
achieves the accuracy needed in the fastest time.

The program finds that the Bailey-Borwein-Plouffe series obtains the accuracy roughly 100000 times faster than the Leibniz series. 
