#include "counter.h"
#include "progress.h"
#include "lcd.h"
#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QtWidgets>
#include <QBoxLayout>

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Q_INIT_RESOURCE(res);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "lesson_2_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    //ProgressBar ----------------------------------------------------------------------------------------------------------------------
    Progress Progress;

    Progress.show();

    //===================================================================================================================================



    //Click to 5 and this close----------------------------------------------------------------------------------------------------------

    QWidget* widg = new QWidget();
    QScrollArea* sca = new QScrollArea;
    QVBoxLayout* lay_main = new QVBoxLayout();

    lay_main->setContentsMargins(10,10,10,10);

    QBoxLayout* lay1 = new QBoxLayout(QBoxLayout::TopToBottom);
    QPushButton* but1 = new QPushButton("A");
    QPushButton* but2 = new QPushButton("B");
    QPushButton* but3 = new QPushButton("C");

    lay1->setSpacing(30);
    lay1->addWidget(but1,1);
    //lay1->addStretch(2);
    lay1->addWidget(but2,2);
    //lay1->addStretch(2);
    lay1->addWidget(but3,3);

    QHBoxLayout* lay2 = new QHBoxLayout();
    QLabel* lbl = new QLabel("0");
    QPushButton* cmd = new QPushButton;
    Counter counter;


    lay_main->addLayout(lay1);
    lay_main->addLayout(lay2);

    QPixmap pix(":/new/prefix1/images/cyrsor.png");
    QCursor cur(pix);

    sca->setWidget(widg);
    sca->resize(350,200);
    lay2->addWidget(lbl);
    lay2->addWidget(cmd);

    widg->setLayout(lay_main);
    widg->setCursor(cur);

    QPalette pal1;
    pal1.setBrush(lbl->backgroundRole(),QBrush(QPixmap(":/new/prefix1/images/wallpap_free.jpg")));
    lbl->setPalette(pal1);
    lbl->resize(40,20);
    lbl->move(25,25);
    lbl->setAutoFillBackground(true);
    // lbl->show();

    QPixmap pix1(":/new/prefix1/images/wallpaper_eight.jpg");
    cmd->setIcon(pix1);
    cmd->setFixedSize(400,200);
    cmd->setIconSize(cmd->size());
    cmd->move(50,50);
    cmd->setAutoFillBackground(true);
    // cmd->show();

    QPalette pal3;
    pal3.setBrush(widg->backgroundRole(),QBrush(QPixmap(":/new/prefix1/images/wallpap_two.jpg")));
    widg->setPalette(pal3);
    widg->resize(660,450);
    widg->setAutoFillBackground(true);
    sca->show();
    //===================================================================================================================================



    //HTML page -------------------------------------------------------------------------------------------------------------------------

    QLabel label(
        "<h1><center>QReZeroTwo - C++ Monstr</center></h1>"
        "<h2><center>IconIk</center></h2>"
        "<center><img src=\":/new/prefix1/images/re_zero_skyrim_dragon.png\"></center>" // Исправлено: src, убраны лишние кавычки
        "<h2><center>Skils</center></h2>"
        "<ol><li>Poop</li>"
        "<li>Sleep</li>"
        "<li>Eat</li></ol>"
        "<h2><center>Robert Styles</center></h2>"
        "<center><font color=red>"
        "<b>Zir</b>, <i>Upal</i>, <u>Zemlya</u>"
        "</font></center>"
        "<h2><center>TaBlica</center></h2>"
        "<center><table>"
        "<tr bgcolor=#ff00ff>" // Исправлено: bgcolor, #ff00ff
        "<td>Ya</td><td>LY</td><td>Bl</td><td>YA</td>"
        "</tr>"
        "<tr bgcolor=yellow>"
        "<td>FR</td><td>I</td><td>EN</td><td>DS</td>"
        "</tr>"
        "<tr bgcolor=#00ff00>"  // Исправлено: bgcolor, #00ff00
        "<td>FA</td><td>MI</td><td>L</td><td>LY</td>"
        "</tr>"
        "</table></center>"
        );
    label.show();
    //===================================================================================================================================



    //decimal to hexadecimal or binary---------------------------------------------------------------------------------------------------
    lcd lcd;
    lcd.show();
    //===================================================================================================================================


    QObject::connect(cmd, SIGNAL(clicked()),&counter,SLOT(slotInc()));

    QObject::connect(&counter,SIGNAL(counterChanged(int)),lbl,SLOT(setNum(int)));

    QObject::connect(&counter,SIGNAL(goodbye()),&a,SLOT(quit()));

    return a.exec();
}
