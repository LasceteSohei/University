#include <QApplication>
#include <ddd.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DDD demon;
    demon.show();

    return app.exec();
}
