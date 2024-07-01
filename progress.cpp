#include "progress.h"

Progress::Progress(QWidget* pwgt/*= 0*/) : QWidget(pwgt), m_nstep(0){
    m_pbar = new QProgressBar;
    m_pbar->setRange(0,5);
    m_pbar->setMinimumWidth(200);
    m_pbar->setAlignment(Qt::AlignCenter);

    QPushButton* pcmdStep = new QPushButton("&Step");
    QPushButton* pcmdReset = new QPushButton("&Reset");

    QObject::connect(pcmdStep,SIGNAL(clicked()),SLOT(slotStep()));
    QObject::connect(pcmdReset,SIGNAL(clicked()),SLOT(slotReset()));

    QHBoxLayout* phbxLayout = new QHBoxLayout;
    phbxLayout->addWidget(m_pbar);
    phbxLayout->addWidget(pcmdStep);
    phbxLayout->addWidget(pcmdReset);
    setLayout(phbxLayout);
}

void Progress::slotStep(){
    m_pbar->setValue(++m_nstep);
}

void Progress::slotReset(){
    m_nstep = 0;
    m_pbar->reset();
}
