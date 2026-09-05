#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <formdatacontainer.h>

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
    MainWindow(FormDataContainer& fdc, QWidget *parent = nullptr);

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

    //! Responds to the trigger by setting the value of the fdc private attribute.
    /*!
    Takes a boolean for the check boxas paramter.
        \param checked the status of the check box.
    */
    void on_checkBoxTransformation_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    //! Reference to the FormDataContainer that holds answers to the form from the user.
    FormDataContainer& fdc;
};
#endif // MAINWINDOW_H
