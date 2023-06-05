#include "App.h"
#include "HPSocket.h"
#include "SocketInterface.h"

#include <unistd.h>
#define imsleep(microsecond) usleep(1000 * microsecond) // ms

// CListenerImpl s_listener;
// // CUdpClient s_client(&s_listener);


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