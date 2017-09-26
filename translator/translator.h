#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QtGui/QMainWindow>
#include <QDialogButtonBox>
#include <QPushButton>
#include <string.h>
#include "ui_translator.h"

class translator : public QMainWindow
{
	Q_OBJECT

public:
	translator(QWidget *parent = 0, Qt::WFlags flags = 0);
	~translator();
	
	void FillGroup();
	void FillPermition();

private:
	Ui::translatorClass ui;
	
	int CheckPermition(QString str);
	int CheckOrder(QString str);
	int FindCost(QString);
	int Summary(QString);
	int CheckQueue(QString);
	QString Rome(int);

public slots:
	void button_clicked();
};

struct GroupItem{
	QString st;
	int costs;
	char queue;
};

#endif // TRANSLATOR_H
