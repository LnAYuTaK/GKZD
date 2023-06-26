#include "App.h"
#include <unistd.h>
#define imsleep(microsecond) usleep(1000 * microsecond) // ms
int main(int argc, char *argv[])
{ 
	    app()->init();
		app()->start();
        for (;;)
        {
            imsleep(1);
        }
        return 0;
}