#include "tictactoe.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    TicTacToeWidget ticTacToe;
    mainWindow.setCentralWidget(&ticTacToe);

    QObject::connect(&ticTacToe, &TicTacToeWidget::gameOver, [&](TicTacToeWidget::CellState winner) {
        QMessageBox::information(&mainWindow, "Game Over", winner == TicTacToeWidget::CellState::Cross ? "Cross won!" : "Circle won!");
        ticTacToe.initBoard();
    });

    mainWindow.show();
    return app.exec();
}
