#include "App.h"
int main(int argc, char *argv[])
{ 
        Application * app = new Application();
        app->Init();
        app->Start();
        return 0;
}