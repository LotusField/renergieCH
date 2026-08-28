#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered,
            this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(
        this,
        tr("Quitter"),
        tr("Voulez vous vraiment quitter ?"),
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}


void MainWindow::on_actionRepository_triggered()
{
    QDesktopServices::openUrl(
        QUrl("https://github.com/LotusField/renergieCH")
        );
}
