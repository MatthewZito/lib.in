#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "libin.h"

int s = 1;

void mock_fn(int signum) {
	if (signum == SIGINT) {
		s = 0;
		return;
	}
}

void test_signal_capture(void) {
	sig_intercept(SIGINT, mock_fn, mock_fn);

	while (s) {
		sleep(1);
		raise(SIGINT);
	}
}

int main() {
	test_signal_capture();

	puts("E");
	return EXIT_SUCCESS;
}
