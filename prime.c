#include <stdio.h>
#include <sys/time.h>
#include <math.h>

long start       = 0;
long max_seconds = 30;
long i           = 2; // Start at 2
long found       = 0; // Number of primes we've found
long lastPrime   = 0;


int is_prime(long num) {
	  // Only have to check for divisible for the sqrt(number)
	  int upper = sqrt(num);
	  //
	  // Check if the number is evenly divisible (start at 2 going up)
	  for (long cnum = 2; cnum <= upper; cnum++) {
	  	long mod = num % cnum; // Remainder
	  	if (mod == 0) {
	  		return 0;
	  	} // If the remainer is 0 it's evenly divisible
	  }
	  return 1; // If you get this far it's prime
}


int main(int argc, char **argv)
{
	struct timeval start, stop;
	double running_seconds = 0;

	gettimeofday(&start, NULL);
	
	// Ready to loop
	while (1 == 1)
	{
		int prime = is_prime(i);
  		if (prime == 1) {
	      		// Serial.print(i);
	      		// Serial.println(" is prime ");
	      		lastPrime = i;
	      		found++;
		}
		gettimeofday(&stop, NULL);
		running_seconds = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
		if (max_seconds > 0 && (running_seconds >= max_seconds)) {
			printf("\nFound ");
			printf("%ld", found);
			printf(" primes in ");
			printf("%ld", max_seconds);
			printf(" seconds\n");
			printf("Highest prime found was: ");
			printf("%ld\n", lastPrime);
		//      delay(60000);
			i     = 2;
			found = 0;
			gettimeofday(&start, NULL);
			}
		i++;
	}
}
