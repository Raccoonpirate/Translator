/********************************************************************************
** Form generated from reading UI file 'translator.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSLATOR_H
#define UI_TRANSLATOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_translatorClass
{
public:
    QWidget *centralWidget;
    QTextEdit *EnterWindow;
    QTextEdit *ResultWindow;
    QPushButton *TranslateButton;
    QTextEdit *RomeNumber;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *translatorClass)
    {
        if (translatorClass->objectName().isEmpty())
            translatorClass->setObjectName(QString::fromUtf8("translatorClass"));
        translatorClass->resize(600, 400);
        centralWidget = new QWidget(translatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        EnterWindow = new QTextEdit(centralWidget);
        EnterWindow->setObjectName(QString::fromUtf8("EnterWindow"));
        EnterWindow->setGeometry(QRect(30, 20, 531, 41));
        ResultWindow = new QTextEdit(centralWidget);
        ResultWindow->setObjectName(QString::fromUtf8("ResultWindow"));
        ResultWindow->setGeometry(QRect(30, 210, 531, 41));
        TranslateButton = new QPushButton(centralWidget);
        TranslateButton->setObjectName(QString::fromUtf8("TranslateButton"));
        TranslateButton->setGeometry(QRect(230, 100, 101, 41));
        RomeNumber = new QTextEdit(centralWidget);
        RomeNumber->setObjectName(QString::fromUtf8("RomeNumber"));
        RomeNumber->setGeometry(QRect(30, 280, 531, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 180, 101, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 250, 91, 21));
        translatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(translatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        translatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(translatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        translatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(translatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        translatorClass->setStatusBar(statusBar);

        retranslateUi(translatorClass);

        QMetaObject::connectSlotsByName(translatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *translatorClass)
    {
        translatorClass->setWindowTitle(QApplication::translate("translatorClass", "translator", 0, QApplication::UnicodeUTF8));
        TranslateButton->setText(QApplication::translate("translatorClass", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("translatorClass", "\320\220\321\200\320\260\320\261\321\201\320\272\320\270\320\265 \321\206\320\270\321\204\321\200\321\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("translatorClass", "\320\240\320\270\320\274\321\201\320\272\320\270\320\265 \321\206\320\270\321\204\321\200\321\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class translatorClass: public Ui_translatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSLATOR_H
