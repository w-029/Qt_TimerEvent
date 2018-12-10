#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_nTimerId = this->startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_nTimerId != 0) {
        this->killTimer(m_nTimerId);
    }
}

void MainWindow::timerEvent(QTimerEvent* event)
{
    if (event->timerId() == m_nTimerId) {
        if (ui->radioButton->isChecked()) {
            ui->radioButton->setChecked(false);
        } else {
            ui->radioButton->setChecked(true);
        }
    }
}
