#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>

void runCmd(char *cmd) {
	pid_t retval = fork();
	if (retval < 0) {
		// Fehler
		perror("Der Prozess kann nich erzeugt werden");
		exit(errno);
	}
	else if (0 == retval) {
		//Kind
		if (execlp(cmd, cmd, NULL) < 0) {
			perror("Das Kommando \"%s\" kann leider nicht durchgeführt werden", cmd);
			exit(errno);
		}
	}
	else {
		// Eltern
		printf("PID von %s: %d\n", cmd, retval);
	}
}


int main(int argc, char **argv) {
	bool continueRun = true;
	while (continueRun)
	{
		int option = 0;
		printf("1. pwd\n2. clear\n3.ls\n4.exit\nAuswahl: ");
		if (scanf("%s", &option)<1){
			printf("Fehler bei scanf!\n");
			exit(1);
		}
		char *cmdList[] = { "pwd","clear","ls","exit" };
		if (option < 1 || option > 4) {
			printf("Es wurde kein Programm durchgeführt, da Sie eine ungültiges Kommando eingeben!\n");
			exit(1);
		}
		printf("Es wurde %s gewählt\n", cmdList[option - 1]);
		if (4 == option) {
			continueRun = false;
		}
		else {
			runCmd(cmdList[option - 1]);
		}
	}

	return 0;
}