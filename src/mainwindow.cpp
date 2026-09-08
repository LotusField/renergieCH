#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>

#include <QDesktopServices>
#include <QUrl>

#include "qfiledialog.h"

MainWindow::MainWindow(FormDataContainer& fdc, DataPersister& dp, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fdc(fdc)
    , dp(dp)
    , saveFileTypes("Fichiers CSV(*.csv);;Tous les fichiers(*))")
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered,
            this, &MainWindow::close);

    connect(&dp,
            &DataPersister::dataLoaded,
            this,
            &MainWindow::updateForm);


    updateForm();
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

void MainWindow::on_checkBoxTransformation_toggled(bool checked)
{
    qDebug() << "on_checkBoxTransformation_toggled received " << checked;
    qDebug() << "on_checkBoxTransformation_toggled initial state " << fdc.isTransformation();
    fdc.setTransformation(checked);
    qDebug() << "on_checkBoxTransformation_toggled final state " << fdc.isTransformation();
}

void MainWindow::updateForm()
{
    ui->checkBoxTransformation->setChecked(
        fdc.isTransformation()
        );

    // Future:
    // ui->checkBoxWhatever->setChecked(fdc.isWhatever());
    // ui->spinBoxWhatever->setValue(fdc.whatever());
    // ...
}

void MainWindow::on_actionSaveAs_triggered()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Sauvegarder un fichier"),"",saveFileTypes);
    if(!fileName.isEmpty())
    {
        std::string fileNameString(fileName.toStdString());
        dp.save(fileNameString);
        qDebug() << "on_actionSaveAs_triggered() saved " << fileNameString << " successfully";
    }
    else
    {
        qDebug() << "on_actionOpen_triggered() can't load from a file with an empty name";
    }
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Ouvrir un fichier"),"",saveFileTypes);
    if(!fileName.isEmpty())
    {
        std::string fileNameString(fileName.toStdString());
        dp.load(fileName.toStdString());
        qDebug() << "on_actionOpen_triggered() opened " << fileNameString << " successfully";
    }
    else
    {
        qDebug() << "on_actionOpen_triggered() can't load from a file with an empty name";
    }
}

