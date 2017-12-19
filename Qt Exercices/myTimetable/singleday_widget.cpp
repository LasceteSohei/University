/** @author LasceteSoheï
  * @file singleday_widget.cpp
  * @date 5/12/2017
  * @brief A  custom widget implementation.
  */

#include "singleday_widget.h"
using namespace std;


/********************
 *    Constructor   *
 *******************/
singleDay_Widget::singleDay_Widget(vector<IcsEvent>& myDayEvents) : QWidget(),
    m_myDayEvents(myDayEvents)
{
    setFixedSize(300, 660);                                                         /*!< Fixed size of widget*/
}

/*************************************
 *     paintEvent method override    *
 ************************************/
void singleDay_Widget::paintEvent(QPaintEvent* )
{


    /***************************************
     *            BASIC OPTIONS            *
     **************************************/

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing );   /*!< Hints for better quality*/
    int width = size().width();                                                     /*!< Our fixed width*/
    int height = size().height();                                                   /*!< Our fixed height*/
    painter.fillRect(0, 0, width, height, QColor(255,255,255));                     /*!< Background color*/


    /***************************************
     *       TITLE BAR IMPLEMENTATION      *
     **************************************/

    QString myDate = m_myDayEvents[0].date().toString(Qt::SystemLocaleLongDate)     /*!< Normalized date for the Title Bar*/
            + " (S - "
            + QString::number(m_myDayEvents[0].date().weekNumber())
            + ")";
    painter.drawText(QRectF(0,0,width,40),Qt::AlignCenter,myDate);                  /*!< Drawing date*/
    QPen boldPen;                                                                   /*!< Drawing bold line under the title*/
    boldPen.setWidth(2);
    painter.setPen(boldPen);
    painter.drawLine(0, 40, width, 40);

    /********************************************
     *       DRAWING HOURS MARKER LINE          *
     *******************************************/

    painter.setPen(QPen());
    QString hour;
    for(int i = 0; i < 24; i+=2)
    {
        hour = QString::number(i/2 + 8) + "h";
        painter.drawLine(0, 60 + (height/26) * i, 15, 60 + (height/26) * i);
        painter.drawRoundRect(15, 50 + (height/26) * i, 30, 20, 50, 50);
        painter.drawText(QRectF(15, 50 + (height/26) * i,30,20),Qt::AlignCenter,hour);
        painter.drawLine(45, 60 + (height/26) * i, width, 60 + (height/26) * i);
    }

    /*************************************************
     *       DRAWING HALF HOURS MARKER LINE          *
     ************************************************/

    QPen dotPen;
    dotPen.setStyle(Qt::DotLine);
    painter.setPen(dotPen);
    for(int i = 1; i < 24; i+=2)
        painter.drawLine(0, 60 + (height/26) * i , width, 60 + (height/26) * i);

    /********************************************
     *       DRAWING EVENTS RECTANGLES          *
     *******************************************/

    for(auto it : m_myDayEvents)
    {
        QBrush myBrush(whatBrush(it.what().remove(2, 100)));                    /*!< Setting brush depending the event*/
        painter.setPen(QPen(myBrush, 1));
        painter.setBrush(myBrush);

        QPainterPath path;                                                      /*!< Creating path for myBrush to follow and fill*/
        path.addRoundedRect(timeToRect(it.start(), it.stop()), 15, 15);
        painter.fillPath(path, myBrush);
        painter.drawPath(path);
    }


    /********************************************
     *       WRITING EVENTS RECTANGLES          *
     *******************************************/

    painter.setPen(QPen(Qt::black, 1));                                         /*!< Setting QPen*/
    painter.setFont(QFont("Helvetica [Cronyx]", 6));                            /*!< Setting the font of text*/
    for(auto it : m_myDayEvents)
    {
        QString event(it.what() + "\n");                                        /*!< Writing in event rectangle the info about the event*/
        event += it.where() + "\n" + it.prof();
        painter.drawText(timeToRect(it.start(), it.stop()),                     /*!< Flags for text organisation inside events rectangles*/
                         Qt::TextWordWrap | Qt::AlignCenter,                    /*!< Align and Wrap if too big*/
                         event);
    }

}


/****************************
 *     timeToRect method    *
 ***************************/
QRectF singleDay_Widget::timeToRect(QTime timeStart, QTime timeEnd)
{
    int height = size().height();

    /*!< Top left corner point of our Rectangle*/
    QPointF topLeft(50,
                    60 + (2*height/26) * (timeStart.hour() - 8) + (double(timeStart.minute())/30) * (height/26));

    /*!< Bottom right corner point of our Rectangle*/
    QPointF bottomRight(size().width() - 5,
                        60 + (2*height/26) * (timeEnd.hour() - 8) + (double(timeEnd.minute())/30) * (height/26));

    return QRectF(topLeft, bottomRight);
}

/****************************
 *     whatBrush method     *
 ***************************/
QColor singleDay_Widget::whatBrush(QString s)
{    if(s == "TD")
    {
        return QColor(70,130,180,200);
    }
    else if(s == "CM")
    {
        return QColor(QColor(60,179,113,200));
    }
    else if(s == "TP")
    {
        return QColor(QColor(228,82,82,200));
    }
    else if(s == "DS" || s == "RE")
    {
        return QColor(QColor(255,116,86,200));
    }
    else return QColor(QColor(211,211,211,200));
}

/********************
 *     Destructor   *
 *******************/
singleDay_Widget::~singleDay_Widget()
{

}
