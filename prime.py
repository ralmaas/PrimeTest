import time
import math

start = time.time()
max_seconds = 30
i = 2
found = 0
lastPrime = 0

def is_prime(num):
   upper = math.ceil(math.sqrt(num))
   for cnum in range(2,upper):
      mod = math.fmod(num, cnum)
      if (mod == 0):
         return (0)
   return (1)


while(1):
   prime = is_prime(i)
   if (prime == 1):
       lastPrime = i
       found = found + 1
   running_seconds = time.time() - start
   if ((max_seconds > 0) and (running_seconds >= max_seconds)):
      print("Found " + str(found) + " primes in " + str(max_seconds))
      print("Highest prime found was " + str(lastPrime))
      i = 2
      found = 0
      start = time.time()
   i = i + 1