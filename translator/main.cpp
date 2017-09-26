#include "translator.h"
#include <conio.h>
#include <QtGui/QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
	QTextCodec *codec = QTextCodec::codecForName("CP1251");
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);
	QTextCodec::setCodecForTr(codec);

	QApplication a(argc, argv);
	translator w;

	w.FillGroup();
	w.FillPermition();
	
	w.show();
	return a.exec();
}
