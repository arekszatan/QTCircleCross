#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPushButton>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button00_clicked();

    void on_button01_clicked();

    void on_button02_clicked();

    void on_button10_clicked();

    void on_button11_clicked();

    void on_button12_clicked();

    void on_button20_clicked();

    void on_button21_clicked();

    void on_button22_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *buttons[3][3];
    int state[3][3];
    enum StateOX {
        StateO,
        StateX,
        BlockStateX,
        BlockStateO,
        ResetState,
        LoseGame
    };
    bool buttonsState(int, int);
    void winGame(int state);
};
#endif // MAINWINDOW_H
