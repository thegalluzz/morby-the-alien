#include <stdio.h>

int my_strcmp(const char* str1, const char* str2) {
	while (*str1 && (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int main() {
	printf("Hi X, are you seeking the truth? (type yes or no) \n");

	char intro[5];
	if (scanf_s("%s", intro, 5) != 1) {
		printf("failed to read instruction\n");
		return 1;
	};

	if (my_strcmp(intro, "yes") == 0 || my_strcmp(intro, "y") == 0) {
		printf("Let's start searching \n");
	}
	else if (my_strcmp(intro, "no") == 0 || my_strcmp(intro, "n") == 0) {
		printf("You are not ready, aren't you? \n");
		return 1;
	}

	printf("Where do you want to start your search from? (Choose 1)\n");
	printf("a)  The woods \n");
	printf("b)  The grass field \n");
	printf("c)  The lake \n");

	char search[12];
	if (scanf_s("%s", search, 12) != 1) {
		printf("failed to read instruction \n");
		return 1;
	};

	if (my_strcmp(search, "a") == 0 || my_strcmp(search, "The woods") == 0 || my_strcmp(search, "the woods")) {
		printf("Ok you enter into the woods \n");
	}
	else if (my_strcmp(search, "b") == 0 || my_strcmp(search, "The grass field") == 0 || my_strcmp(search, "the grass field") == 0) {
		printf("Ok, you enter into the grassfield \n");
	}
	else if (my_strcmp(search, "c") == 0 || my_strcmp(search, "The lake") == 0 || my_strcmp(search, "the lake") == 0) {
		printf("Ok, you get to the shore of the lake \n");
	}
	else {
		printf("I don't udnerstand \n");
	}

}