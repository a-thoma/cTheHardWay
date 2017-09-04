#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'C';
	char first_name[] = "Alex";
	char last_name[] = "Thomason";

	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome superpowers.\n", super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have a first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs at the imaginary rate of %f.\n", bugs, bug_rate);
	// Lets make this next long painfully large until the compiler hates us.
	long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 7L;
	/*******************************************************************
	* If you really made this painfully long, the compiler will tell you
	* that it's going to print some bogus value. Essentially, signed
	* long will print a giant negative number, unsigned will print a 0.
	* HOWEVER, the compiler I'm using (CLANG) will not care, and will
	* simply give you the correct size in place of signed/unsigned.
	* This isn't true across all compilers.
	*/
	printf("The entire universe has %ld bugs.\n", universe_of_defects);

	double expected_bugs = bugs * bug_rate;

	printf("You are expected to have %f bugs.\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	/*********************************************************************
	* The above is painfully innacurate, dividing a double by a long.
	* So, print using %e, which is the conversion for scientific notation. 
	* Using %f to format the conversion will result in 0.000000, simply
	* because it's gonna be a ridiculously tiny number, hence why it
	* prints as something like 1.1117587e-07, (*10^-7).
	*/
	printf("That is only a %e portion of the universe.\n", part_of_universe);

	// This makes no sense, just a demo of something weird
	/************************************************************************
	* Actually, this is taking the null byte escape character, and
	* multiplying our value of bugs (100) by it, effectively multiplying
	* by zero, thus we get 0 when we print it as a conversion using printf.
	* Also, take note of the fact that we used %% to get a percent sign. This
	* is because we have taken % as a reserved character for printing
	* conversions, i.e. %d, %i, %f, %e, etc.
	*/
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%.\n", care_percentage);

	return 0;
}