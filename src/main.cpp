#include "App.h"
#include <unistd.h>
#define imsleep(microsecond) usleep(1000 * microsecond) // ms

int main(int argc, char *argv[])
{ 
        Application * app = new Application();
		app->Init();
		app->Start();
        for (;;)
        {
            imsleep(1);
        }
        return 0;
}