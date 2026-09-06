#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "matcha.h"

//qlist saves multiple objects in matcha
#include <QList>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

  private:
    void displayMatcha(const matcha& m, int cardNumber);
    void displayMatchas();

    //creates a list with matcha type
    QList<matcha> matchas;

    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
