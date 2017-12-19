/** @author LasceteSoheï
  * @file singleday_widget.h
  * @date 5/12/2017
  * @brief A  custom widget.
  */

#ifndef SINGLEDAY_WIDGET_H
#define SINGLEDAY_WIDGET_H

#include <QtWidgets>
#include <QWidget>
#include <vector>
#include "TimeTable.h"
#include "IcsEvent.h"
#include "IcsReader.h"

/**
 * @class singleDay_Widget singleday_widget.h
 * @brief A class representing a single day in our calendar.
 *
 * The class draws a custom widget using the events of the day.
 * Those events are taken from an .ics normalized file containing the student timetable.
 */
class singleDay_Widget : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief Constructor
     *
     * Constructor of class singleDay_Widget
     *
     * @param myDayEvents : A vector containing all the events of the day.
     */
    singleDay_Widget(std::vector<IcsEvent> &myDayEvents);

    /**
     * @brief Override of paintEvent.
     *
     * Draws instructions in order to make our custom widget.
     */
    void paintEvent(QPaintEvent *);

    /**
     * @brief Time to rectangle conversion.
     *
     * Creation of a rectangle from two QTime variables. The rectangle is used to represent an event where each
     * QTime is one of the limits of the event.
     *
     * @param timeStart :   When does the event starts.
     * @param timeEnd :     When does the event ends.
     * @return QRectF :     The rectangle created from the time informations.
     */
    QRectF timeToRect(QTime timeStart, QTime timeEnd);

    /**
     * @brief   Color chooser
     *
     * Choose a color depending the type of event.
     * In our application there is 5 type of events : 'CM', 'TP', 'TD', 'RES', 'DS'.
     *
     * @param   s : Type of the event in QString form.
     * @return  QColor of the corresponding type of event
     */
    QColor whatBrush(QString s);

    /**
     * @brief Destructor
     *
     * Default destructor of class.
     */
    ~singleDay_Widget();

private:
    std::vector<IcsEvent> m_myDayEvents; /*!< Event list of the day*/

};

#endif // SINGLEDAY_WIDGET_H
