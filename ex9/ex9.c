#include <stdio.h>

int main(int argc, const char *argv[]) {
	
	int i = 0;

	while (i < 25) {

		printf("%d ", i);
		i++;
	}

	while(i < 0) {

		printf("%d ", i);
		i--;
	}

	// If you don't want an infinite loop, change the last 1 to a 0.
	while(1 && 0 && 0 ^ 1? 1 : 0) {

		printf("What the fuck even is that logic? OH GOD ITS A FOREVER LOOP");
	}

	// Same thing, but as a do-while loop.
	do {

		printf("J U S T D O I T ");
	} while (1 && 0 && 0 ^ 1? 1 : 0);

	return 0;
}