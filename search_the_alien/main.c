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
	if (scanf_s("%4s", intro, 5) != 1) {
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
}