#pragma once
#include <QWidget>
#include <QtWidgets>

class lcd : public QWidget {
    Q_OBJECT

public:
    lcd(QWidget *parent = nullptr) : QWidget(parent) {
        lineEdit = new QLineEdit(this);
        lcdNumber = new QLCDNumber(12);
        btn_change = new QPushButton("chage");

        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber->setMode(QLCDNumber::Hex);

        // Создаем layout и добавляем виджеты
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(lcdNumber);
        layout->addWidget(lineEdit);
        layout->addWidget(btn_change);

        // Подключаем сигнал textChanged к слоту updateLCDNumber
        connect(lineEdit, &QLineEdit::textChanged, this, &lcd::updateLCDNumber);
        connect(btn_change, &QPushButton::clicked, this, &lcd::chageDEx);
    }

private slots:
    void updateLCDNumber(const QString &text) {
        // Преобразуем текст в число
        bool ok;
        int value = text.toInt(&ok);

        // Если преобразование прошло успешно, обновляем QLCDNumber
        if (ok) {
            lcdNumber->display(value);
        } else {
            // Обработка ошибки преобразования (необязательно)
            lcdNumber->display(0);
        }
    }
    void chageDEx(){
        if(Dex_or_Hex){//Dex_or_Hex == dex
            lcdNumber->setMode(QLCDNumber::Bin);
            Dex_or_Hex = false;
        }
        else{//Dex_or_Hex == bin
            lcdNumber->setMode(QLCDNumber::Hex);
            Dex_or_Hex = true;
        }
    }

private:
    QLineEdit *lineEdit;
    QLCDNumber *lcdNumber;
    QPushButton *btn_change;
    bool Dex_or_Hex = true;
};
