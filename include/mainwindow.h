#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <formdatacontainer.h>
#include <datapersister.h>

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
        \param fdc reference to the form data container that holds the input data from the user
        \param reference to the data persister used to save and load data to the form data container
    */
    MainWindow(FormDataContainer& fdc, DataPersister& dp, QWidget *parent = nullptr);

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

    //! Responds to the trigger by launching the gui saving protocol.
    void on_actionSaveAs_triggered();

    //! Responds to the trigger by launching the gui opening protocol.
    void on_actionOpen_triggered();

private:
    //! Updates the ui with respect to the content of the DataFormContainer
    void updateForm();

    //! pointer to the main window
    Ui::MainWindow *ui;

    //! Reference to the FormDataContainer that holds answers to the form from the user.
    FormDataContainer& fdc;

    //! Reference to the data persister that manages file opening and data saving to the operating system
    DataPersister& dp;

    //! Stores the file types to filter for the save/open dialog menu
    QString& saveFileTypes;
};
#endif // MAINWINDOW_H
