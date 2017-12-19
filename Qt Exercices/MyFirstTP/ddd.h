/**
 * @author LasceteSoheï
 * @file ddd.h
 * @date 5/12/2017
 * @brief Introduction to widgets in Qt.
 */

#ifndef DDD_H
#define DDD_H

#include <QMainWindow>
#include <QtWidgets>
#include <QLayout>
#include <QPalette>
#include <iostream>

class DDD : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor
     *
     * Default constructor of class DDD
     */
    DDD();

    /*!< Destructor*/
    ~DDD();
public slots:
    void testButtonP();
    void testButtonR();
    void testSlider(int x);
    void testRadioButton();
    void testColorDialog();
    void testComboBox(QString t);
    void loadFile();
    void saveFileAs();


private:

    QGridLayout *m_generalLayout;       /*!< Layout general du widget*/
    QWidget *m_myCentralWidget;         /*!< Widget central de la main window*/

    QRadioButton *m_testRadioButton1;   /*!< Bouton option 1*/
    QRadioButton *m_testRadioButton2;   /*!< Bouton option 2*/

    QLabel *m_resultTestButton;         /*!< Champ indiquant le résultat de l'action effectué avec le QPushButton*/
    QLineEdit *m_resultTestSlider;      /*!< Champ indiquant le résultat de l'action effectué avec le QSlider*/
    QLabel *m_resultTestRadioButton;    /*!< Champ indiquant le résultat de l'action effectué avec les QRadioButton*/
    QLabel *m_resultTestColorDialog;    /*!< Couleur choisis dans la QColorDialog*/
    QLabel *m_resultTestComboBox;       /*!< Champ indiquant le résultat de l'action effectué avec la QComboBox*/
};
#endif // DDD_H
