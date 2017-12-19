/**
 * @author LasceteSoheï
 * @file mymainwindow.h
 * @date 5/12/2017
 * @brief Main window of application.
 */

#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QtWidgets>
#include <QWidget>
#include <QGraphicsScene>
#include <vector>
#include <iostream>
#include "TimeTable.h"
#include "IcsEvent.h"
#include "IcsReader.h"
#include "singleday_widget.h"


/**
 * @class myMainWidow mymainwindow.h
 * @brief Main window of application.
 *
 * The class displays the main windows with all widgets making the timetable inside.
 */
class myMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief Constructor.
     *
     * Default constructor of class.
     *
     * @param _name :  Name of the .ics file containing the timetable. By default _name is empty
     * @param parent : Pointer to parent widget of the window. By default pointer is null.
     */
    myMainWindow(QString _name = "", QWidget *parent = 0);

    /**
     * @brief Destructor
     *
     * Default destructor of class.
     *
     **/
    ~myMainWindow();

signals:

public slots:

private:
    TimeTable m_myTimetable;    /*!< Model containing the entire year of timetable data*/
    QGraphicsScene *m_myScene;  /*!< Contains all the widget singleDay_Widget of the timetable*/
    QGraphicsView *m_myView;    /*!< Used to display the items stored in m_myScene (QGraphicScene)*/

};

#endif // MYMAINWINDOW_H
