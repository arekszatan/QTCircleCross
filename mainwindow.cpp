#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buttons[0][0] = ui->button00;
    buttons[0][1] = ui->button01;
    buttons[0][2] = ui->button02;
    buttons[1][0] = ui->button10;
    buttons[1][1] = ui->button11;
    buttons[1][2] = ui->button12;
    buttons[2][0] = ui->button20;
    buttons[2][1] = ui->button21;
    buttons[2][2] = ui->button22;


    for (int i = 0; i < 3; ++i) {
        for (int a = 0; a < 3; ++a) {
            state[i][a] = StateO;
            connect(buttons[i][a], &QPushButton::clicked, [&](bool){
                qInfo()<<"Button was clicked";

                });
        }
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button00_clicked()
{
    buttonsState(0, 0);
}


void MainWindow::on_button01_clicked()
{
    buttonsState(0, 1);
}


void MainWindow::on_button02_clicked()
{
    buttonsState(0, 2);
}


void MainWindow::on_button10_clicked()
{
    buttonsState(1, 0);
}


void MainWindow::on_button11_clicked()
{
    buttonsState(1, 1);
}


void MainWindow::on_button12_clicked()
{
    buttonsState(1, 2);
}


void MainWindow::on_button20_clicked()
{
    buttonsState(2, 0);
}


void MainWindow::on_button21_clicked()
{
    buttonsState(2, 1);
}


void MainWindow::on_button22_clicked()
{
    buttonsState(2, 2);
}

bool MainWindow::buttonsState(int col, int row)
{
    switch (state[col][row]) {
    case StateO:
        buttons[col][row]->setText("o");
        state[col][row] = BlockStateO;
        for (int i = 0; i < 3; ++i) {
            for (int a = 0; a < 3; ++a) {
                if (state[i][a] != BlockStateX and state[i][a] != BlockStateO){
                    state[i][a] = StateX;
                }
            }
        }
        break;
    case StateX:
        buttons[col][row]->setText("x");
        state[col][row] = BlockStateX;
        for (int i = 0; i < 3; ++i) {
            for (int a = 0; a < 3; ++a) {
                if (state[i][a] != BlockStateX and state[i][a] != BlockStateO){
                    state[i][a] = StateO;
                }
            }
        }
        break;
    case BlockStateX:
        qInfo()<<"Nothing to do";
        break;

    case BlockStateO:
        qInfo()<<"Nothing to do";
        break;

    case ResetState:
        buttons[col][row]->setText("");
        break;

    }

    qInfo()<<state[0][0]<<"|"<<state[0][1]<<"|"<<state[0][2];
    qInfo()<<"---------";
    qInfo()<<state[1][0]<<"|"<<state[1][1]<<"|"<<state[1][2];
    qInfo()<<"---------";
    qInfo()<<state[2][0]<<"|"<<state[2][1]<<"|"<<state[2][2];
    for (int i = 0; i < 3; ++i) {
        if (state[i][0] == BlockStateO and state[i][1] == BlockStateO and state[i][2] == BlockStateO){
            qInfo()<<"1";
            winGame(BlockStateO);
            return true;
        }
        if (state[0][i] == BlockStateO and state[1][i] == BlockStateO and state[2][i] == BlockStateO){
            qInfo()<<"2";
            winGame(BlockStateO);
            return true;
        }
        if (state[0][0] == BlockStateO and state[1][1] == BlockStateO and state[2][2] == BlockStateO){
            qInfo()<<"3";
            winGame(BlockStateO);
            return true;
        }
        if (state[0][2] == BlockStateO and state[1][1] == BlockStateO and state[2][0] == BlockStateO){
            qInfo()<<"4";
            winGame(BlockStateO);
            return true;
        }

        if (state[i][0] == BlockStateX and state[i][1] == BlockStateX and state[i][2] == BlockStateX){
            winGame(BlockStateX);
            return true;
        }
        if (state[0][i] == BlockStateX and state[1][i] == BlockStateX and state[2][i] == BlockStateX){
            winGame(BlockStateX);
            return true;
        }
        if (state[0][0] == BlockStateX and state[1][1] == BlockStateX and state[2][2] == BlockStateX){
            winGame(BlockStateX);
            return true;
        }
        if (state[0][2] == BlockStateX and state[1][1] == BlockStateX and state[2][0] == BlockStateX){
            winGame(BlockStateX);
            return true;
        }

    }
    for (int i = 0; i < 3; ++i) {
        for (int a = 0; a < 3; ++a) {
            if (state[i][a] == StateO or state[i][a] == StateX){
                qInfo()<<"tu";
                return false;
            }
        }
    }
    qInfo()<<"tu1";
    winGame(LoseGame);
    return false;
}

void MainWindow::winGame(int states)
{
    switch (states) {
    case BlockStateO:
        qInfo()<<"Win o";
        QMessageBox::information(this, "End Game", "O win the game");
        break;
    case BlockStateX:
        qInfo()<<"Win x";
        QMessageBox::information(this, "End Game", "X win the game");
        break;
    case LoseGame:
        qInfo()<<"Draw";
        QMessageBox::information(this, "End Game", "No one win the game");
        break;
    }
    for (int i = 0; i < 3; ++i) {
        for (int a = 0; a < 3; ++a) {
            state[i][a] = StateO;
            buttons[i][a]->setText("");
        }
    }
}

