/**
 * @author LasceteSoheï
 * @file ddd.cpp
 * @date 5/12/2017
 * @brief Introduction to widgets in Qt implementation.
 */
#include "ddd.h"
using namespace std;

/****************************************************************************************
 *                               CONSTRUCTEUR                                           *
 ***************************************************************************************/
DDD::DDD() : QMainWindow(0)
{
    setWindowTitle("Démonstration");
    m_myCentralWidget = new QWidget;
    setCentralWidget(m_myCentralWidget);

    ////////////////////////////////////////////////////////////////////////////
    /*!< COLONNE DE GAUCHE*/
    ////////////////////////////////////////////////////////////////////////////
    /*!< Premier Groupe */
    QGroupBox *GB1 = new QGroupBox("QPushButton");
    QPushButton *testButton = new QPushButton("Test");
    QGridLayout *layout1 = new QGridLayout;
    layout1->addWidget(testButton);
    GB1->setLayout(layout1);

    /*!< Second Groupe*/
    QGroupBox *GB2 = new QGroupBox("QSlider");
    QSlider *testSlider = new QSlider(Qt::Horizontal);
    testSlider->setRange(1,100);
    QGridLayout *layout2 = new QGridLayout;
    layout2->addWidget(testSlider);
    GB2->setLayout(layout2);


    /*!< Troisième Groupe*/
    QGroupBox *GB3 = new QGroupBox("QRadioButton");
    m_testRadioButton1 = new QRadioButton("Café");
    m_testRadioButton2 = new QRadioButton("Chocolat");
    QPushButton *confirmTestRB = new QPushButton("Valider");
    QGridLayout *layout3 = new QGridLayout;
    layout3->addWidget(m_testRadioButton1, 0, 0);
    layout3->addWidget(m_testRadioButton2, 1, 0);
    layout3->addWidget(confirmTestRB,2,1);
    GB3->setLayout(layout3);

    /*!< Quatrième Groupe*/
    QGroupBox *GB4 = new QGroupBox("QColorDialog");
    QPushButton *openColorDialog = new QPushButton("Sélectionner une couleur...");
    QGridLayout *layout4 = new QGridLayout;
    layout4->addWidget(openColorDialog);
    GB4->setLayout(layout4);

    /*!< Cinquième Groupe*/
    QGroupBox *GB5 = new QGroupBox("QComboBox");
    QComboBox *testComboBox = new QComboBox;
    testComboBox->addItem("Paris");
    testComboBox->addItem("Londres");
    testComboBox->addItem("Tokyo");
    QGridLayout *layout5 = new QGridLayout;
    layout5->addWidget(testComboBox);
    GB5->setLayout(layout5);

    ////////////////////////////////////////////////////////////////////////////
    /*!< COLONNE DE DROITE*/
    ////////////////////////////////////////////////////////////////////////////
    m_resultTestButton = new QLabel("Relaché");
    m_resultTestSlider= new QLineEdit("1");
    m_resultTestRadioButton = new QLabel("Café ou Chocolat");

    m_resultTestColorDialog = new QLabel;
    QPalette palette = m_resultTestColorDialog->palette();
    palette.setColor(m_resultTestColorDialog->backgroundRole(), QColor(Qt::white));
    m_resultTestColorDialog->setAutoFillBackground(true);
    m_resultTestColorDialog->setPalette(palette);

    m_resultTestComboBox = new QLabel("Destination?");
    QPushButton *terminer = new QPushButton("Terminer");
    QPushButton *save = new QPushButton("Enregistrer");

    ////////////////////////////////////////////////////////////////////////////
    /*!< LAYOUT GENERALE*/
    ////////////////////////////////////////////////////////////////////////////
    m_generalLayout = new QGridLayout;
    m_generalLayout->addWidget(GB1, 0,0);
    m_generalLayout->addWidget(m_resultTestButton, 0, 1);
    m_generalLayout->addWidget(GB2, 1, 0);
    m_generalLayout->addWidget(m_resultTestSlider, 1, 1);
    m_generalLayout->addWidget(GB3, 2, 0);
    m_generalLayout->addWidget(m_resultTestRadioButton, 2,1);
    m_generalLayout->addWidget(GB4, 3, 0);
    m_generalLayout->addWidget(m_resultTestColorDialog, 3, 1);
    m_generalLayout->addWidget(GB5, 4, 0);
    m_generalLayout->addWidget(m_resultTestComboBox, 4, 1);
    m_generalLayout->addWidget(terminer, 5, 1);
    m_generalLayout->addWidget(save,5,0);

    m_myCentralWidget->setLayout(m_generalLayout);

    ////////////////////////////////////////////////////////////////////////////
    /*!< INITIALISATION MENU*/
    ////////////////////////////////////////////////////////////////////////////
    QAction *a_saveFileAs = new QAction("Enregistrer sous...", this);
    QAction *a_loadFile = new QAction("Ouvrir fichier...", this);
    QMenu *fileMenu = new QMenu;
    fileMenu = menuBar()->addMenu("Fichier");
    fileMenu->addAction(a_loadFile);
    fileMenu->addAction(a_saveFileAs);
    connect(a_loadFile, &QAction::triggered, this, &DDD::loadFile);
    connect(a_saveFileAs, &QAction::triggered, this, &DDD::saveFileAs);



    ////////////////////////////////////////////////////////////////////////////
    /*!< SLOTS CONNECTION*/
    ////////////////////////////////////////////////////////////////////////////
    QObject::connect(testButton, SIGNAL(pressed()), this, SLOT(testButtonP()));
    QObject::connect(testButton, SIGNAL(released()), this, SLOT(testButtonR()));
    QObject::connect(testSlider,SIGNAL(valueChanged(int)), this, SLOT(testSlider(int)));
    QObject::connect(confirmTestRB, SIGNAL(clicked()), this, SLOT(testRadioButton()));
    QObject::connect(openColorDialog, SIGNAL(clicked()), this, SLOT(testColorDialog()));
    QObject::connect(testComboBox, SIGNAL(activated(QString)), this, SLOT(testComboBox(QString)));
    QObject::connect(save, SIGNAL(clicked()), this, SLOT(saveFileAs()));
    QObject::connect(terminer,SIGNAL(clicked()), qApp, SLOT(quit()));
}


/****************************************************************************************
 *                          IMPLEMENTATION SLOTS                                        *
 ***************************************************************************************/
/**
* @brief Indique dans m_resultTestButton si le boutton est pressé.
*/
void DDD::testButtonP(){
    m_resultTestButton->setText("Pressé");
}

/**
* @brief Indique dans m_resultTestButton si le boutton est relaché.
*/
void DDD::testButtonR(){
    m_resultTestButton->setText("Relaché");
}

/**
* @brief Change la valeur de m_resultTestSlider en fonction du slider.
*/
void DDD::testSlider(int x){
    m_resultTestSlider->setText(QString::number(x));
}

/**
* @brief Change le statut de m_resultTestRadioButton en fonction du choix utilisateur.
*/
void DDD::testRadioButton(){
    if(m_testRadioButton1->isChecked())
        m_resultTestRadioButton->setText(m_testRadioButton1->text());
    else
        m_resultTestRadioButton->setText(m_testRadioButton2->text());
}

/**
* @brief Ouvre une QColorDialog, récupère la couleur et l'affiche dans un QLabel.
*/
void DDD::testColorDialog()
{
    /*!< Récupération de la couleur*/
    QColor color = QColorDialog::getColor(Qt::white, this);

    if(color.isValid())
    {
        /*!< Affectation de la couleur au background d'un QLabel*/
        QPalette palette = m_resultTestColorDialog->palette();
        palette.setColor(m_resultTestColorDialog->backgroundRole(), color);
        m_resultTestColorDialog->setAutoFillBackground(true);
        m_resultTestColorDialog->setPalette(palette);
    }
}

/**
* @brief Change le statut de  m_resultTestComboBox en fonction du pays choisis par l'utilisateur.
*/
void DDD::testComboBox(QString t){
    m_resultTestComboBox->setText(t);
}

/**
* @brief Enregistre la session actuelle.
* @todo  La fonction n'enregistre pas l'état des éléments de la colonne de gauche.
*/
void DDD::saveFileAs(){

    QString nameOfFile = QFileDialog::getSaveFileName(this, "Enregistrer sous...", "/home/hadrien");
    if(nameOfFile.isEmpty())
        return;
    else
    {
        QFile myFile(nameOfFile);
        if(!myFile.open(QIODevice::WriteOnly))
            return;
        else
        {
            QTextStream out(&myFile);
            out << "DDP" << "\n";
            out << m_resultTestButton->text() << "\n";
            out << m_resultTestSlider->text() << "\n";
            out << m_resultTestRadioButton->text() << "\n";
            out << m_resultTestComboBox->text() << "\n";
            out << m_resultTestColorDialog->palette().color(QWidget::backgroundRole()).red() << "\n";
            out << m_resultTestColorDialog->palette().color(QWidget::backgroundRole()).green() << "\n";
            out << m_resultTestColorDialog->palette().color(QWidget::backgroundRole()).blue() << "\n";
        }
    }
}

/**
* @brief Ouvre une session à partir d'un fichier ' *.ddp '.
* @todo  La fonction ne permet pas de charger les états des éléments de la colonne de gauche.
*/
void DDD::loadFile()
{
    QString nameOfFile = QFileDialog::getOpenFileName(this, "Ouvrir la session...", "/home/hadrien", "*.ddp");
    if(nameOfFile.isEmpty())
        return;
    else
    {
        QFile myFile(nameOfFile);
        if(!myFile.open(QIODevice::ReadOnly))
            return;
        else{
            QTextStream in(&myFile);
            if(in.read(3) == "DDP")
            {
                in.readLine();
                m_resultTestButton->setText(in.readLine());
                m_resultTestSlider->setText(in.readLine());
                m_resultTestRadioButton->setText(in.readLine());
                m_resultTestComboBox->setText(in.readLine());

                QPalette palette = m_resultTestColorDialog->palette();
                int r(in.readLine().toInt()), g(in.readLine().toInt()), b(in.readLine().toInt());
                palette.setColor(m_resultTestColorDialog->backgroundRole(), QColor(r,g,b));
                m_resultTestColorDialog->setAutoFillBackground(true);
                m_resultTestColorDialog->setPalette(palette);

            }
        }
    }
}


/****************************************************************************************
 *                               DESTRUCTEUR                                            *
 ***************************************************************************************/
DDD::~DDD(){}
