#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QHBoxLayout>

class Progress : public QWidget{
    Q_OBJECT
private:
    QProgressBar* m_pbar;
    int m_nstep;
public:
    Progress(QWidget* pobj = 0);

public slots:
    void slotStep();
    void slotReset();
};
