#include <GUI/GUI.hpp>
#include <StoreManager/StoreManager.hpp>
#include <FileManager/FileManager.hpp>
#include <Analytics/Analytics.hpp>

int main() {
	//These are also forward declared, learn about forward declaration
    StoreManager storeManager;
    FileManager fileManager;
    Analytics analytics;

    GUI app;

    app.initGUI(&storeManager, &fileManager, &analytics);

    return 0;
}