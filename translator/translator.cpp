#include "translator.h"

translator::translator(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.TranslateButton, SIGNAL(clicked()), this, SLOT(button_clicked()));
}

translator::~translator()
{

}

GroupItem groups[7][10];
QString PermitionGroup[25];
QString inputText;
QString GrammaErrors;
int MasLong[7];

void translator::button_clicked() {
	inputText = ui.EnterWindow->toPlainText();
	inputText = inputText.simplified();
	int Error = CheckQueue(inputText);
	if (!Error){
		int generalSumm;
		generalSumm = Summary(inputText);
		ui.ResultWindow->setText(QString::number(generalSumm));
		ui.RomeNumber->setText(Rome(generalSumm));
	}else 
		if (Error == 1){
			GrammaErrors = "Данные слова '" + GrammaErrors + "' содержат грамматические ошибки";
			ui.ResultWindow->setText(GrammaErrors);
			ui.RomeNumber->clear();
		}else
			if (Error == 22){
				ui.ResultWindow->setText("Нельзя писать два одинаковых разряда подрят");
				ui.RomeNumber->clear();
			}else
				if (Error == 42){
					ui.ResultWindow->setText("После любых десятичных разрядов ничего не может быть или неверный порядок слов");
					ui.RomeNumber->clear();
				}else
					if(Error == 43){
						ui.ResultWindow->setText("Перед und должны стоять единичные разряды");
						ui.RomeNumber->clear();
					}else
						if(Error == 44){
							ui.ResultWindow->setText("После und должны стоять десятичные разряды больше 19 или und является лишним");
							ui.RomeNumber->clear();
						}else
							if(Error == 45){
								ui.ResultWindow->setText("После едичных разрядов должны следовать либо сотни либо und");
								ui.RomeNumber->clear();
							}else
								if(Error == 46){
									ui.ResultWindow->setText("Перед hundert должны стоять единичные разряды больше 0");
									ui.RomeNumber->clear();
								}else
									if(Error == 47){
										ui.ResultWindow->setText("Можно писать либо десятичные разряды больше 19, либо от 10 до 19 ");
										ui.RomeNumber->clear();
									}

}


//Поиск величины числа
int translator::FindCost (QString str){
	for(int i = 0; i <= 6; i++) {
		for(int j = 0; j <= MasLong[i]; j++) {
			//Проверяю, есть ли данное слово в группах если есть вернется 0
			int notExistInGroups = QString::compare(str, groups[i][j].st, Qt::CaseInsensitive);
			if (!notExistInGroups) {
				//Если есть, то берем числовой эквивалент
				return groups[i][j].costs;
			}
		}
	}
}

//Сумма слов введеного числа
int translator::Summary(QString str){
	int Sum = 0;
	QStringList tokenizedInput = str.split(" ", QString::SkipEmptyParts);
	for (int i = 0; i < tokenizedInput.size(); i++){
		int costOfTokenNumber = 0;
		costOfTokenNumber = FindCost(tokenizedInput.at(i));
		if (costOfTokenNumber == 100) {
			if (Sum == 0){
				Sum = 100;
			}else
				Sum *= 100;
		}else{
			Sum += costOfTokenNumber;
		}
	}
	return Sum;
}


//Есть ли в списке разрешений такой порядок слов
int translator::CheckPermition(QString str){
	for (int i = 0; i < 25; i++){
		int notExistInGroups = QString::compare(str,PermitionGroup[i],Qt::CaseInsensitive);
		if (!notExistInGroups){
			return 0;
		}
	}
	return 42;
}
//Проверка глупого und
int translator::CheckOrder(QString str){
	//Проверка лишнего унда
	for (int i = 0; i < str.size(); i++){
		if (str.at(i) == '6'){
			if ((i == 0) || (str.at(i - 1) != '0') && (str.at(i - 1) != '2')){
				return 43;
			}else
				if ((i == str.size() - 1) || (str.at(i + 1) != '4')){
					return 44;
				}
		}
	//Проверка сотен
		if (str.at(i) == '5'){
			if ((i == 0) || (str.at(i - 1) != '0') && (str.at(i - 1) != '2')){
				return 46;
			}
		}
	}
	// Проверка единичных разрядов
	for (int i = 0; i < str.size() - 1; i++){
		if ((str.at(i) == '0') || (str.at(i) == '2')){
			if ((str.at(i + 1) != '6') && (str.at(i + 1) != '5')){
				return 45;
			}
		}
	}
	//Проверка на повтор десятичных разрядов
	for (int i = 0; i < str.size() - 1; i++){
		if (((str.at(i) == '3') && (str.at(i + 1) == '4')) || ((str.at(i) == '4') && (str.at(i + 1) == '3'))){
			return 47;
		}
	}
	//Проверка на наличие чего-либо после десятичных разрядов
	for (int i = 0; i < str.size(); i++){
		if ((str.at(i) == '3') || (str.at(i) == '4')){
			if (i != str.size() - 1){
				return 42;
			}//funf und zweizig funf
		}
	}

	return 0;

}

//Построение порядка слов в введенном предложении
int translator::CheckQueue(QString str){
	QStringList tokenizedInputQueue = str.split(" ", QString::SkipEmptyParts);
	QString InputQueue;
	int was = 0;
	GrammaErrors.clear();
	for (int token = 0; token< tokenizedInputQueue.size(); token++){
		bool Check = false;
		for(int j = 0; j < 7; j++){
			for(int i = 0; i <= MasLong[j]; i++){
				int notExistInGroup = QString::compare(tokenizedInputQueue.at(token), groups[j][i].st, Qt::CaseInsensitive);
				if (!notExistInGroup) {
					InputQueue.append(groups[j][i].queue);
					was++;
					Check = true;
					break;
				}
			}
			if (Check) break;
		}
		if (!Check) {
			GrammaErrors = GrammaErrors + ' ' + tokenizedInputQueue.at(token);
		}
	}
	//Проверка на грамматику
	if (was != (tokenizedInputQueue.size())){
		return 1;
	}
	//Проверка на тафтологию
	for (int i = 0; i < InputQueue.size() - 1; i++){
		if (InputQueue.at(i) == InputQueue.at(i + 1)){
			return 22;
		}
	}
	//Проверка на und
	int ErrOrder = CheckOrder(InputQueue);
	if (ErrOrder){
		return ErrOrder;
	}
	return CheckPermition(InputQueue);
}
//Перевод арабских цифр в римские
QString translator::Rome(int legion){
	QString names[12] = {"CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int numbers[12] =   {900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,     1};
	QString itog;
	for (int i = 0; i <= 12; i++){
		while (legion >= numbers[i]){
			itog = itog.append(names[i]);
			legion = legion - numbers[i];
		}
	}
	return itog;
}

//Заполнение словаря слов
void translator::FillGroup(){
	int i;
	//Единицы
	groups[0][0].st.append("zwei");
	groups[0][1].st.append("drei");
	groups[0][2].st.append("vier");
	groups[0][3].st.append("funf");
	groups[0][4].st.append("sechs");
	groups[0][5].st.append("sieben");
	groups[0][6].st.append("acht");
	groups[0][7].st.append("neun");
	for (i = 0; i <= 7; i++){
		groups[0][i].costs = i + 2;
		groups[0][i].queue = '0';
	}
	//Ноль и 1
	groups[1][0].st.append("null");
	groups[1][1].st.append("eins");
	groups[1][0].costs = 0;
	groups[1][1].costs = 1;
	groups[1][0].queue = '1';
	groups[1][1].queue = '1';
	//Единица
	groups[2][0].st.append("ein");
	groups[2][0].queue = '2';
	groups[2][0].costs = 1;
	//От 10 до 19
	groups[3][0].st.append("zehn");
	groups[3][1].st.append("elf");
	groups[3][2].st.append("zwolf");
	groups[3][3].st.append("dreizehn");
	groups[3][4].st.append("vierzehn");
	groups[3][5].st.append("funfzehn");
	groups[3][6].st.append("sechzehn");
	groups[3][7].st.append("siebzehn");
	groups[3][8].st.append("achtzehn");
	groups[3][9].st.append("neunzehn");
	for (i = 0; i <= 9; i++){
		groups[3][i].costs=i+10;
		groups[3][i].queue='3';
	}
	//Десятки
	groups[4][0].st.append("zweizig");
	groups[4][1].st.append("dreizig");
	groups[4][2].st.append("vierzig");
	groups[4][3].st.append("funfzig");
	groups[4][4].st.append("sechzig");
	groups[4][5].st.append("siebzig");
	groups[4][6].st.append("achtzig");
	groups[4][7].st.append("neunzig");
	for (i = 0; i<= 7; i++){
		groups[4][i].costs=(i+2)*10;
		groups[4][i].queue='4';
	}

	//Сотни
	groups[5][0].st.append("hundert");
	groups[5][0].costs=100;
	groups[5][0].queue='5';

	// und
	groups[6][0].st.append("und");
	groups[6][0].costs=0;
	groups[6][0].queue='6';

	MasLong[0]=8;
	MasLong[1]=2;
	MasLong[2]=1;
	MasLong[3]=9;
	MasLong[4]=8;
	MasLong[5]=1;
	MasLong[6]=1;
}

//Возможные последовательности
void translator::FillPermition(){
	PermitionGroup[0].append("0");
	PermitionGroup[1].append("1");
	PermitionGroup[2].append("3");
	PermitionGroup[3].append("4");
	PermitionGroup[4].append("5");
	PermitionGroup[5].append("05");
	PermitionGroup[6].append("50");
	PermitionGroup[7].append("51");
	PermitionGroup[8].append("53");
	PermitionGroup[9].append("54");
	PermitionGroup[10].append("25");
	PermitionGroup[11].append("264");
	PermitionGroup[12].append("251");
	PermitionGroup[13].append("253");
	PermitionGroup[14].append("254");
	PermitionGroup[15].append("054");
	PermitionGroup[16].append("064");
	PermitionGroup[17].append("050");
	PermitionGroup[18].append("051");
	PermitionGroup[19].append("053");
	PermitionGroup[20].append("250");
	PermitionGroup[21].append("25264");
	PermitionGroup[22].append("05064");
	PermitionGroup[23].append("05264");
	PermitionGroup[24].append("25064");
}