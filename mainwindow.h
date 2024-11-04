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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_PowerUsageEdit_editingFinished();

    void on_PowerCostEdit_editingFinished();

    void on_HourBox_editingFinished();

    void on_MinBox_editingFinished();

    void on_SecBox_editingFinished();

    void on_Calculate_clicked();

    void on_FilamentCostEdit_editingFinished();

    void on_FilamentUsageEdit_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
