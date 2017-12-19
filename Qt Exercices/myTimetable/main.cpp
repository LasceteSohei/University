#include <QApplication>
#include <iostream>
#include "TimeTable.h"
#include "IcsEvent.h"
#include "IcsReader.h"
#include "singleday_widget.h"
#include "mymainwindow.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    myMainWindow mainWindow("Edt.ics");     /*!< Declaration Main Window*/
    mainWindow.showMaximized();             /*!< Take all space in screen*/

    return app.exec();
    return 0;
}
