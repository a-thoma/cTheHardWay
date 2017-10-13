#include <stdio.h>

struct Node {
	int x;
	float y;
};

typedef struct Node Node;

typedef struct buttPlus {
	
	char *str;
} buttPlus;

int main(int argc, const char *argv[]) {
	
	/* prototype node initialized */
	Node z = {.x = 69, .y = 4.20};

	printf("%d, %f\n", z.x, z.y);

	buttPlus butts = {.str = "Hello, I'm buttplus!\n"};

	printf("%s\n", butts.str);

	return 0;
}