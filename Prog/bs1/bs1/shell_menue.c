#include<stdbool.h>
#include<stdio.h>

int main() {
	bool continueRun = true;
	while (continueRun)
	{
		int option = 0;
		printf("1. pwd\n2. clear\n3.ls\n4.exit\nAuswahl: ");
		scanf("%d", &option);
		printf("%d", option);
	}

	return 0;
}