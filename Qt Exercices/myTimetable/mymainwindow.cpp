/** @author LasceteSoheï
  * @file mymainwindow.cpp
  * @date 5/12/2017
  * @brief Main window implementation.
  */
#include "mymainwindow.h"

using namespace std;

/********************
 *    Constructor   *
 *******************/
myMainWindow::myMainWindow(QString _name, QWidget *parent) : QMainWindow(parent)
{


    /**********************
     *    LOAD ICS FILE   *
     *********************/

    TimeTable m_myTimetable;
    QString filename = m_myTimetable.searchTTFile(_name);
    m_myTimetable.loadFile(filename);


    /***********************
     *    CREATING SCENE   *
     **********************/

    QGraphicsScene *m_myScene = new QGraphicsScene;
    int count(0), strtPos(0);                                       /*!< Count and strtPos are used for keeping track of today's day*/
    vector<QDate> eventDateList = m_myTimetable.getEventDateList();
    QDate aDayBefore = eventDateList[0].addDays(-1);                /*!< Used to know if there is a day between two dates in the
                                                                     *   timetable. Ex :  Saturdays and Sundays*/

    /***********************
     *    FILLING SCENE    *
     **********************/
    for(auto it : eventDateList)
    {

        if((it.weekNumber() == QDate::currentDate().weekNumber())   /*!< Is it today?*/
                && (it.day() == QDate::currentDate().day()) )
            strtPos = count;

        if(aDayBefore.daysTo(it) != 1)                              /*!< Are they Saturdays? Sundays? Holydays? etc...*/
        {
            for(int i = 1; i < aDayBefore.daysTo(it); i++)          /*!< Filling the no events day as blank widget*/
            {
                QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;
                vector<IcsEvent> noEventDay;
                noEventDay.push_back(IcsEvent (QString(),QString(), QDateTime(aDayBefore.addDays(i))));
                proxy->setWidget(new singleDay_Widget(noEventDay));
                proxy->moveBy((310 * count),0);
                m_myScene->addItem(proxy);
                if((aDayBefore.addDays(i).weekNumber() == QDate::currentDate().weekNumber())    /*!< Is it today?*/
                        && (aDayBefore.addDays(i).day() == QDate::currentDate().day()))
                    strtPos = count;
                ++count;
            }

        }

        QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget;     /*!< Generating widget for the days with events*/
        proxy->setWidget(new singleDay_Widget(m_myTimetable.getEventList(it)));
        proxy->moveBy((310 * count),0);
        m_myScene->addItem(proxy);
        ++count;

        aDayBefore = it;                                            /*!< Keep track of the day before*/
    }

    /************************************
     *    CREATING VIEW & DISPLAYING    *
     ***********************************/
    QGraphicsView *m_myView = new QGraphicsView;
    m_myView->setScene(m_myScene);
    m_myView->setStyleSheet( "QGraphicsView { border-style: none; max-height: 674px }" );       /*!< No borders*/
    m_myView->setBackgroundBrush(QBrush(Qt::gray, Qt::SolidPattern));                           /*!< Background color of view*/
    m_myView->centerOn(qreal(310*strtPos), 0);                                                  /*!< Starting position = today*/
    m_myView->setDragMode(QGraphicsView::ScrollHandDrag);                                       /*!< Allowing hand drag*/

    /***************************************
     *    GENERAL DISPLAY OF MAIN WINDOW   *
     **************************************/
    QGridLayout *genLayout = new QGridLayout();
    QWidget *center = new QWidget();
    QPalette *backgroundPal = new QPalette();

    genLayout->addWidget(m_myView,0,0);
    backgroundPal->setColor(QPalette::Background, Qt::gray);
    center->setAutoFillBackground(true);
    center->setPalette(*backgroundPal);
    this->setCentralWidget(center);
    center->setLayout(genLayout);
}




/********************
 *     Destructor   *
 *******************/
myMainWindow::~myMainWindow()
{

}
