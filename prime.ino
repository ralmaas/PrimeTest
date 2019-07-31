/*
 * Test program for finding primes in 30 seconds.
 * Published by Ralp S Bacon
 * Also made a quick transfer for running on Raspberry
 * Initial testing:
 * 
 * UNO       3850  =  100
 * ESP8266  28012  =  728
 * ESP32   180045  = 4676
 * RPi ZW  185766  = 4825
 * RPi 3B  246945  = 6414
 * 
 * More stuff:
 * https://github.com/RalphBacon/
 * https://ralphbacon.blog/
 */
long start       = 0;
long max_seconds = 30;
long i           = 2; // Start at 2
long found       = 0; // Number of primes we've found
long lastPrime   = 0;

void setup() {
  Serial.begin(57600);

  while (!Serial) { }

  Serial.println("Prime calculation starting.");

  start = millis();
}

void loop() {
  int prime = is_prime(i); // Check if the number we're on is prime

  if (prime == 1) {
    //Serial.print(i);
    //Serial.println(" is prime ");
    lastPrime = i;
    found++;
  }

  int running_seconds = (millis() - start) / 1000;

  if (max_seconds > 0 && (running_seconds >= max_seconds)) {
    Serial.print("\nFound ");
    Serial.print(found);
    Serial.print(" primes in ");
    Serial.print(max_seconds);
    Serial.println(" seconds");
    Serial.print("Highest prime found was: ");
    Serial.println(lastPrime);
    delay(60000);

    i     = 2;
    found = 0;
    start = millis();
  }

  i++;
}

int is_prime(long num) {
  // Only have to check for divisible for the sqrt(number)
  int upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (long cnum = 2; cnum <= upper; cnum++) {
    long mod = num % cnum; // Remainder

    if (mod == 0) {
      return 0;
    } // If the remainer is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
}
