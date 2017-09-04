#include <stdio.h>
// #include <stdbool.h> // For booleans, but could use own declaration below

// if you want to use booleans without having to include stdbool.h ...
typedef enum { false, true } bool;

int main(int argc, const char* argv[]) {
	
	// Define some variables
	bool test_bool_one = true;
	bool test_bool_two = false;
	int test_int = 69;
	int result; // Undeclared for fun things later
	float test_float = 420.69;

	// Test loops and stuff

	// The if-statement
	if(test_bool_one) {
		printf("My favorite number is %d.\n", test_int);
	} 
	if(test_bool_two) {
		printf("This is the worst language ever.");
	} else if(!test_bool_two) {
		// %.2f tells the conversion to be of precision 2
		printf("My other favorite number is %.2f.\n", test_float);
	}

	// Ternary operator to replace if statement
	if(test_bool_one) {
		result = 5;
	} else {
		result = 69;
	}
	printf("%d\n", result);

	// This can be written using ternary logic as:
	result = test_bool_one ? 10 : 70; // values are backwards, remember
	printf("%d\n", result);

	/* Fill in more of these if you want to test them and have fun,
	probably while you're making your flash cards. */


	return 0;
}