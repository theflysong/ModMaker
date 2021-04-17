#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ModMaker; }
QT_END_NAMESPACE

class ModMaker : public QMainWindow
{
    Q_OBJECT

public:
    ModMaker(QWidget *parent = nullptr);
    ~ModMaker();

private:
    Ui::ModMaker *ui;
};
#endif // MAINWINDOW_H
