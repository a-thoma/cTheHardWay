#include <stdio.h>

int main(int argc, char* argv[]) {
	
	int age = 10;
	int height = 72;
	int days; // uninitialized integer, initially null/0

	printf("I am %d years old.\n", age);
	printf("I am %d inches tall.\n", height);
	printf("My dick is %d feet long.\n");      // prints garbage
	printf("I have had %d bad days.\n\n", days); // prints 0

	printf("This is extra credit\t");
	printf("Crazy formatting shit.\n\t\n");
	printf("W\vO\vA\vH\v H\vE\vL\vL\vO\v\n\n");
	printf("ESCAPE CHARACTERS!\n");
	printf("BEEP\a h\bell\bo BOOO\bLIN \x0a\x0a");
	printf("\tT\vh\vi\vs\v \n\t I S \n\n\t S\fP\fA\fR\fT\fA\f!!!\n");

	return 0;
}