#include "libin.h"

#include <signal.h>

void sig_intercept(int sig_target, void(*sigerr_callback)(int), void(*sig_callback)(int)) {
	if (signal(sig_target, sig_callback) == SIG_ERR) {
		perror("Signal error");
		sigerr_callback(-1);
	}
}
