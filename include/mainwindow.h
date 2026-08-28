#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! Default MainWindow constructor
    /*!
    Takes a pointer to a parent class as parameter.
        \param *parent the pointer to the parent class.
    */
    MainWindow(QWidget *parent = nullptr);

    //! Destructor
    ~MainWindow();

protected:
    //! Responds to the quit button by asking if the user really wants to quit.
    /*!
    Takes a pointer to the close event as paramter.
        \param *event the close event requested.
    */
    void closeEvent(QCloseEvent *event) override;

private slots:
    //! Responds to the trigger by opening the repository url in a web browser.
    void on_actionRepository_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
